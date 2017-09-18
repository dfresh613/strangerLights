# strangerLights
StrangerLights is an arduino/raspberry pi implementation to spell messages out with LEDs. A raspberry pi provides
a django based web interface for users to queue LED messages to send to the Arduino.

### slights-talkie
Contains libraries to communicate with both the web application api and the arduino serial listener. This allows for
sending and retrieving messages from both interfaces. `Will.py` uses these libraries to inform the arduino serial interface what
messages is next in the queue

Executables:
`strangerlights` - performs active querying/pushing of messages between api and connected serial interface. Assumes an arduino is attached,
also should be provided the host of the running api (if not localhost)

`strangerapi` - script for quickly querying the message queue, inserting messages, or pushing a message to an attached arduino


### StrangerWeb
Django based web Interface providing APIs for users to queue messages, remove messages, and get messages.

### StrangerArduino
Arduino sketch code which creates a char to int hashmap of letters to LED positions. Actively listens through serial connection
for messages and uses the hashmap to display them with the displayMessage() function. If no messages are present, it will simply
do a random glowing routine

Quick youtube POC:
https://www.youtube.com/watch?v=IDPV9tJOkKA&feature=youtu.be
