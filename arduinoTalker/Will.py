from ArduinoInterface import ArduinoInterface
from ApiInterface import ApiInterface

api_comm= ApiInterface()
arduino_comm= ArduinoInterface()


def generateRandom():
    pass

q_pos = -1
# Always loop listening for message from arduino
while True:        
    incoming_msg=arduino_comm.ser.readline()
    print "Received arduino message {} ".format(incoming_msg);
    if q_pos != -1:
        api_comm.remove_message(q_pos)

    (unparsed, q_pos) = api_comm.get_next_message()
    outgoing_message = ""
    for c in unparsed:
        if c.isalpha():
            outgoing_message+=c
    outgoing_message = outgoing_message.lower()
    print "sending message {}".format(outgoing_message)
    if len(outgoing_message) > 0:
        arduino_comm.push_message(outgoing_message)
