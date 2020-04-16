This controller.py is for communicating the messages between local broker to cloud broker.


1. Update the port,username and password for the cloudmqtt broker


2. Execute this source below mentioned below,

	$ python3 controller.py




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
log:  Received PUBLISH (d0, q0, r1, m0), 'home/hall/dimlight', ...  (2 bytes)
Portion of the House -->= home/hall/dimlight
Message from CloudMqtt = on
log:  Received PUBLISH (d0, q0, r1, m0), 'home/room3/chand', ...  (3 bytes)
log:  Received PUBLISH (d0, q0, r1, m0), 'home/room3/light', ...  (2 bytes)
log:  Received PUBLISH (d0, q0, r1, m0), 'home/room3/bathroom/light', ...  (3 bytes)
log:  Received PUBLISH (d0, q0, r1, m0), 'home/room3/ac', ...  (3 bytes)
log:  Received PUBLISH (d0, q0, r1, m0), 'home/kitchen/light', ...  (3 bytes)
Portion of the House -->= home/kitchen/light
Message from CloudMqtt = off
log:  Received PUBLISH (d0, q0, r1, m0), 'home/kitchen/chimney', ...  (3 bytes)
Portion of the House -->= home/kitchen/chimney
Message from CloudMqtt = off
log:  Received PUBLISH (d0, q0, r1, m0), 'home/kitchen/rooflight', ...  (3 bytes)
log:  Received PUBLISH (d0, q0, r1, m0), 'home/kitchen/dimlight', ...  (3 bytes)
Portion of the House -->= home/kitchen/dimlight
Message from CloudMqtt = off
log:  Received PUBLISH (d0, q0, r1, m0), 'home/kitchen/exhaust', ...  (3 bytes)
Portion of the House -->= home/kitchen/exhaust
Message from CloudMqtt = off
log:  Received PUBLISH (d0, q0, r1, m0), 'home/kitchen/oven', ...  (3 bytes)
Portion of the House -->= home/kitchen/oven
Message from CloudMqtt = off
log:  Received PUBLISH (d0, q0, r1, m0), 'home/kitchen/stove', ...  (2 bytes)
log:  Received PUBLISH (d0, q0, r1, m0), 'home/kitchen/socket', ...  (2 bytes)
Portion of the House -->= home/kitchen/socket
Message from CloudMqtt = on
log:  Received PUBLISH (d0, q0, r1, m0), 'home/outdoor/pump', ...  (3 bytes)
Portion of the House -->= home/outdoor/pump
Message from CloudMqtt = off
log:  Received PUBLISH (d0, q0, r1, m0), 'home/outdoor/gate', ...  (5 bytes)
Portion of the House -->= home/outdoor/gate
Message from CloudMqtt = close
log:  Received PUBLISH (d0, q0, r1, m0), 'home/outdoor/parking', ...  (3 bytes)
Portion of the House -->= home/outdoor/parking
Message from CloudMqtt = off
log:  Received PUBLISH (d0, q0, r1, m0), 'home/outdoor/compound', ...  (2 bytes)
Portion of the House -->= home/outdoor/compound
Message from CloudMqtt = on
log:  Received PUBLISH (d0, q0, r1, m0), 'home/compound/light', ...  (3 bytes)
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/notice', ...  (16 bytes)
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/gate', ...  (4 bytes)
Portion of the House -->= home/outdoor/gate
Message from CloudMqtt = open
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/gate', ...  (5 bytes)
Portion of the House -->= home/outdoor/gate
Message from CloudMqtt = close
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/compound', ...  (3 bytes)
Portion of the House -->= home/outdoor/compound
Message from CloudMqtt = off
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/compound', ...  (2 bytes)
Portion of the House -->= home/outdoor/compound
Message from CloudMqtt = on
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/compound', ...  (3 bytes)
Portion of the House -->= home/outdoor/compound
Message from CloudMqtt = off
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/parking', ...  (2 bytes)
Portion of the House -->= home/outdoor/parking
Message from CloudMqtt = on
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/parking', ...  (3 bytes)
Portion of the House -->= home/outdoor/parking
Message from CloudMqtt = off
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/pump', ...  (2 bytes)
Portion of the House -->= home/outdoor/pump
Message from CloudMqtt = on
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/pump', ...  (3 bytes)
Portion of the House -->= home/outdoor/pump
Message from CloudMqtt = off
log:  Sending PINGREQ
log:  Received PINGRESP
log:  Sending PUBLISH (d0, q0, r0, m4), 'b'home/outdoor/notice'', ... (24 bytes)
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/notice', ...  (24 bytes)
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/gate', ...  (4 bytes)
Portion of the House -->= home/outdoor/gate
Message from CloudMqtt = open
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/gate', ...  (5 bytes)
Portion of the House -->= home/outdoor/gate
Message from CloudMqtt = close
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/compound', ...  (2 bytes)
Portion of the House -->= home/outdoor/compound
Message from CloudMqtt = on
log:  Received PUBLISH (d0, q0, r0, m0), 'home/outdoor/compound', ...  (3 bytes)
Portion of the House -->= home/outdoor/compound
Message from CloudMqtt = off
