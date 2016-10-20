from ArduinoInterface import ArduinoInterface
from ApiInterface import ApiInterface

api_comm= ApiInterface()
arduino_comm= ArduinoInterface()

def generateRandom():
    pass

q_pos=-1
# Always loop listening for message from arduino
while True:        
    arduino_comm.ser.readLine()
    if q_pos != -1:
        api_comm.remove_message(q_pos)
        
    (message, q_pos) = api_comm.get_next_message()
    
    arduino_comm.push_message(message)
