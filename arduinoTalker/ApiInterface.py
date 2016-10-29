import requests
import json


class ApiInterface:

    def __init__(self): 
        self.address = "http://localhost:80/messagereceiver"
        self.queue_uri = self.address+'/queue'
        self.next_message_uri = self.queue_uri+'/next'

    def get_next_message(self):
        resp = requests.get(self.next_message_uri)
        print resp.json()
        data = resp.json()
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

    def remove_message(self, queue_pos):
        print "Removing id {} from queue".format(queue_pos)
        resp = requests.get(self.address+'/'+str(queue_pos)+'/remove')
        data = resp.json()

        if data['success']:
            print "Succesfully removed message from queue!"
        else:
            print "Unable to remove message from queue"
            print data
    

if __name__ == "__main__":
    api_comm = ApiInterface()
    (message, q_pos) = api_comm.get_next_message()
    if q_pos > -1:
        api_comm.remove_message(q_pos)
