# strangerLights
StrangerLights is an arduino/raspberry pi implementation to spell messages out with LEDs. A raspberry pi provides
a django based web interface for users to queue LED messages to send to the Arduino.

###ArduinoTalker
Contains 'Will.py' and dependencies, a script which will actively pull from the web interface's API and send messages
through the serial interface to the Arduino to display via LEDs

###StrangerWeb
Django based web Interface providing APIs for users to queue messages, remove messages, and get messages.

###StrangerArduino
Arduino sketch code which creates a char to int hashmap of letters to LED positions. Actively listens through serial connection
for messages and uses the hashmap to display them with the displayMessage() function. If no messages are present, it will simply
do a random glowing routine (some of which were originally defined by bxl4662).

Quick youtube POC:
https://www.youtube.com/watch?v=IDPV9tJOkKA&feature=youtu.be
