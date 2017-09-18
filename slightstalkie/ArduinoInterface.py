import serial
import sys
from serial.serialutil import SerialException
class ArduinoInterface:
    """
    Class providing various communication methods for interacting with an arduino connected serially
    """
    def __init__(self, serial_str):
        """
        Initialize the class
        :param serial_str: serial connection location.
        """
        try:
            self.ser = serial.Serial(serial_str, 9600)
        except SerialException:
            print("Unable to connect to arduino on serial connection: {}".format(serial_str))
            sys.exit(5)

    def push_message(self, message):
        self.ser.write(message.encode())

    def read_message(self):
        print("Waiting for arduino to send message")
        return self.ser.readline();


