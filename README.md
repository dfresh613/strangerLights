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

### Deploying
Both the web application and the message handler are available as docker containers: 
https://hub.docker.com/r/drfresh613/strangerweb/

https://hub.docker.com/r/drfresh613/slightstalkie/

Full stack deployment is possible with docker-compose, using the compose files available in this repo. Simply find the compose file for your cpu (arm, or x86_64 supported, and copy it to your system

Once the compose file has been copied to the system, connect your arduino to it with a serial cable, and use docker-compose to start the stack. 

Note: You may need to modify the ARDUINO_SERIAL environment variable in the compose file, if the arduino isn't available on the default device

Quick youtube POC:
https://www.youtube.com/watch?v=IDPV9tJOkKA&feature=youtu.be

### Testing

Unit tests are implemented for the slightstalkie library, and utilize tox to run against python2 and python35 environmentss.

To run the unit tests execute the `tox` command from the repository root directory.