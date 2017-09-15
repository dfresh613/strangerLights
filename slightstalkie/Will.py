from ArduinoInterface import ArduinoInterface
from ApiInterface import ApiInterface
import os
import argparse
import sys

# Available action constants for command line
ACTION_API_GET = "api-get"
ACTION_API_POST = "api-post"
ACTION_ARDUINO_RECEIVE = "arduino-receive"
ACTION_ARDUINO_SEND = "arduino-send"

def generateRandom():
    pass


def arg_parser(requires_action=False):
    """
    Parses args required for communicating with api
    :return:
    """
    action_options = [ACTION_API_GET, ACTION_API_POST, ACTION_ARDUINO_RECEIVE, ACTION_ARDUINO_SEND]

    parser = argparse.ArgumentParser(
        description="Provide parameters for interacting with the strangerlights api, or strangerarduino interface")
    parser.add_argument('-i', '--host', type=str, required=False, help='Hostname:port of the strangerthings web api.'
                                                                       ' Defaults to localhost',
                        default=os.getenv("SWEB_HOST", "localhost"))
    parser.add_argument('-s', '--serial', type=str, required=False, default=os.getenv('SARDUINO_SERIAL', '/dev/ttyACM0'),
                        help='Serial connection location for connected arduino. Defaults to /dev/ttyACM0')
    if requires_action:
        parser.add_argument('action', nargs='+', type=str, help='The action to take. Possible actions are: {}'
                            .format(action_options))

    args = parser.parse_args()


    if requires_action:
        if args.action[0] not in action_options:
            print "Error: chosen action: {} not an available action".format(args.action[0])
            sys.exit(5)

    return args


def perform_action():
    """
    Performs a particular action depending on args provided.
    :return:
    """
    args = arg_parser(requires_action=True)
    api_comm = ApiInterface(args.host)
    choosen_action = args.action[0]
    if choosen_action == ACTION_API_GET:
        print(api_comm.get_queue())
    elif choosen_action == ACTION_API_POST:
        try:
            message = args.action[1]
            print "posting {}".format(message)
            api_comm.post_message(message)
        except IndexError:
            print "You must send also specify a message to post, and optionally the author. Whitespace separated"
            sys.exit(5)
    elif choosen_action == ACTION_ARDUINO_SEND:
        try:
            arduino_comm = ArduinoInterface(args.serial)
            arduino_comm.push_message(args.action[1])
        except IndexError:
            print "You must specify the message to be sent to the arduino"
    elif choosen_action == ACTION_ARDUINO_RECEIVE:
        arduino_comm = ArduinoInterface(args.serial)
        arduino_comm.read_message()


def main():
    """
    main message passing method which Listens for messages from the web interface, and sends to
    """
    q_pos = -1
    args = arg_parser()
    api_comm = ApiInterface(args.host)
    arduino_comm = ArduinoInterface(args.serial)
    # Always loop listening for message from arduino
    while True:
        incoming_msg = arduino_comm.ser.readline()
        print "Received arduino message {} ".format(incoming_msg);
        if q_pos != -1:
            api_comm.remove_message(q_pos)

        (unparsed, q_pos) = api_comm.get_next_message()
        outgoing_message = ""
        for c in unparsed:
            if c.isalpha() or c.isspace():
                outgoing_message += c
        outgoing_message = outgoing_message.lower()
        print "sending message {}".format(outgoing_message)
        if len(outgoing_message) > 0:
            arduino_comm.push_message(outgoing_message)
