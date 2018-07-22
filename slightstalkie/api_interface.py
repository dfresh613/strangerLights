import requests
from requests.exceptions import ConnectionError
import sys


class ApiInterface:

    def __init__(self, host):
        self.address = "http://{}/messagereceiver".format(host)
        self.queue_uri = self.address+'/queue'
        self.next_message_uri = self.queue_uri+'/next'

    def get_json(self, uri, expected_status_code):
        """ Generic method for using requests to get json, and
        validating the status code is correct """
        try:
            resp = requests.get(uri)
        except ConnectionError:
            print("Unable to connect to : {}".format(uri))
            return None

        if resp.status_code != expected_status_code:
            print("Expected status code: {} did not match "
                  "returned status code: {} when querying: {}"
                  .format(expected_status_code,
                          resp.status_code, uri))
            return None
        data = resp.json()
        return data

    def get_queue(self):
        """
        Get's the entire queue of messages available
        :return:
        """
        json = self.get_json(self.queue_uri, 200)
        print("queue: {}".format(json))
        print(json)
        return json

    def get_next_message(self):
        """
        Gets ony the next message in the queue
        :return:
        """
        data = self.get_json(self.next_message_uri, 200)
        return extract_message_and_pos(data)

    def post_message(self, message="", author="The Demagorgon"):
        """
        Post a message to the upside down message queue
        :param message: Message to send
        :param author: author to display
        :return:
        """
        pass  # TODO

    def remove_message(self, queue_pos):
        """
        Remove a message from the queue
        :param queue_pos:
        :return:
        """
        print("Removing id {} from queue".format(queue_pos))
        data = self.get_json(self.address+'/'+str(queue_pos)+'/remove', 200)

        if data['success']:
            print("Succesfully removed message from queue!")
            return True
        else:
            print("Unable to remove message from queue")
            print(data)

        return False


def extract_message_and_pos(data):
    """
    Extracts message and queue position from json data,
    defaults if expectatiosn aren't met
    :param data:
    :return:
    """
    random_fallback_response = "Random", -1
    if not data or data.get('success') is not True:
        print("There was an error parsing the message somewhere, "
              "just sending random")
        return random_fallback_response

    q_pos = None

    message = data.get('message')
    if not message:
        print("WARNING - no message present in response")
        message = "Unknown"

    q_pos = data.get('id')
    if not q_pos:
        print("WARNING - no queue position present in response")
        q_pos = -1

    print("Succesfully got the next message: {}. Queue pos: {}".
          format(message, q_pos))
    return message, q_pos

