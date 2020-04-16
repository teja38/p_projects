NOTE :: This project is for learning purpose only


This controller.py is for communicating the messages between local broker to cloud broker.


1. Update the port,username and password for the cloudmqtt broker


2. Execute this source below mentioned below,

	$ python3 controller.py

3. **follow the instructions by reading README file in each folder for each section



--------------------------------- Sample output ----------------------------
connecting to cloudmqtt broker
connecting to local mosquitto broker
 ------- CONNECTED TO ----->  LOCAL_MQTT_BROKER
log:  Received CONNACK (0, 0)
log:  Sending PUBLISH (d0, q0, r0, m1), 'b'home/hall/notice'', ... (9 bytes)
 ------- CONNECTED TO ----->  CLOUD_MQTT_BROKER
log:  Sending SUBSCRIBE (d0, m2) [(b'home/#', 0)]
This means broker has acknowledged my subscribe request
Subscribed: 2 (0,)
log:  Sending PUBLISH (d0, q0, r0, m3), 'b'home/outdoor/notice'', ... (16 bytes)
log:  Received SUBACK
This means broker has acknowledged my subscribe request
Subscribed: 2 (0,)
log:  Received PUBLISH (d0, q0, r1, m0), 'home/hall/chand', ...  (3 bytes)
log:  Received PUBLISH (d0, q0, r1, m0), 'home/hall/light', ...  (2 bytes)
Portion of the House -->= home/hall/light
Message from CloudMqtt = on
log:  Received PUBLISH (d0, q0, r1, m0), 'home/hall/ac', ...  (2 bytes)
Portion of the House -->= home/hall/ac
Message from CloudMqtt = on
log:  Received PUBLISH (d0, q0, r1, m0), 'home/hall/fan', ...  (3 bytes)
Portion of the House -->= home/hall/fan
Message from CloudMqtt = off
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/compound', ...  (2 bytes)
Portion of the House -->= home/outdoor/compound
Message from CloudMqtt = on
