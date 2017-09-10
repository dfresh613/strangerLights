import requests

class ApiInterface:

    def __init__(self, host):
        self.address = "http://{}/messagereceiver".format(host)
        self.queue_uri = self.address+'/queue'
        self.next_message_uri = self.queue_uri+'/next'

    def get_json(self, uri, expected_status_code):
        """ Generic method for using requests to get json, and validating the status code is correct """
        resp = requests.get(uri)
        if resp.status_code != expected_status_code:
            raise Exception("Expected status code: {} did not match returned status code: {} when querying: {}"
                            .format(expected_status_code, resp.status_code, uri))
        try:
            data = resp.json()
        except:
            print "Error: Unable to retrieve any data from URL: {}".format(self.address)
            print "Response Code: {}".format(resp.status_code)
            return "Random", -1
        return data

    def get_queue(self):
        """
        Get's the entire queue of messages available
        :return:
        """
        print(self.get_json(self.queue_uri), 200)

    def get_next_message(self):
        """
        Gets ony the next message in the queue
        :return:
        """
        data = self.get_json(self.next_message_uri, 200)
        q_pos = None
        #If there's any exceptions in getting the next message, catch and return random
        try:
            if data['success']:
                message = data['message']
                q_pos = data['id']
                print "Succesfully got the next message: {}. Queue pos: {}".format(message,q_pos)
                return message, q_pos
            else:
                print "Unable to pull the next message, perhaps there's nothing in the queue"
                return "Random", -1
        except:
            if q_pos is None:
                q_pos = -1
            print "There was an error parsing the message somewhere, just sending random"
            return "Random", q_pos

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
        print "Removing id {} from queue".format(queue_pos)
        data = self.get_json(self.address+'/'+str(queue_pos)+'/remove', 200)

        if data['success']:
            print "Succesfully removed message from queue!"
        else:
            print "Unable to remove message from queue"
            print data

"""
if __name__ == "__main__":
    api_comm = ApiInterface()
    (message, q_pos) = api_comm.get_next_message()
    if q_pos > -1:
        api_comm.remove_message(q_pos)
"""
