import paho.mqtt.client as paho
import os
import socket
import ssl
import time

def on_connect(client, userdata, flags, rc):
    if str(rc)=="0":
        print("Connected to ",client.userdata)
        awsclient.connected_flag=True
    # Subscribing in on_connect() means that if we lose the connection and
    # reconnect then subscriptions will be renewed.
    if str(client.userdata)== "AWS_Client":   
     awsclient.subscribe("home/#" , 1 )

def on_message(client, userdata, message):
 print("topic: "+message.topic)
 print("payload: "+str(message.payload))
 if str(message.topic)=="home/hall" :
  print("Portion of the House -->=",str(message.topic))
  print("INDICATION TO -->",str(message.payload.decode("utf-8")))
  if str(message.payload.decode("utf-8"))=="hall_wall_light_on":
   client2.publish("lhome/hall/light","on")
  elif str(message.payload.decode("utf-8"))=="hall_wall_light_off" :
   client2.publish("lhome/hall/light","off")
  elif str(message.payload.decode("utf-8"))=="hall_dim_light_on":
   client2.publish("lhome/hall/dimlight","on")
  elif str(message.payload.decode("utf-8"))=="hall_dim_light_off" :
   client2.publish("lhome/hall/dimlight","off")
  elif str(message.payload.decode("utf-8"))=="hall_fan_on":
   client2.publish("lhome/hall/fan","on")
  elif str(message.payload.decode("utf-8"))=="hall_fan_off" :
   client2.publish("lhome/hall/fan","off")
  elif str(message.payload.decode("utf-8"))=="hall_ac_on":
   client2.publish("lhome/hall/ac","on")
  elif str(message.payload.decode("utf-8"))=="hall_ac_off" :
   client2.publish("lhome/hall/ac","off")
  elif str(message.payload.decode("utf-8"))=="hall_socket_on":
   client2.publish("lhome/hall/socket","on")
  elif str(message.payload.decode("utf-8"))=="hall_socket_off" :
   client2.publish("lhome/hall/socket","off")
  elif str(message.payload.decode("utf-8"))=="hall_tv_on":
   client2.publish("lhome/hall/tv","on")
  elif str(message.payload.decode("utf-8"))=="hall_tv_off" :
   client2.publish("lhome/hall/tv","off")
 
 if str(message.topic)=="home/kitchen" :
   print("Portion of the House -->=",str(message.topic))
   print("INDICATION TO -->",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="kitchen_wall_light_on":
    client2.publish("lhome/kitchen/light","on")
   elif str(message.payload.decode("utf-8"))=="kitchen_wall_light_off":  
    client2.publish("lhome/kitchen/light","off")
   elif str(message.payload.decode("utf-8"))=="kitchen_dim_light_on" :
    client2.publish("lhome/kitchen/dimlight","off")
   elif str(message.payload.decode("utf-8"))=="kitchen_dim_light_off":
    client2.publish("lhome/kitchen/dimlight","off")
   elif str(message.payload.decode("utf-8"))=="kitchen_exhaust_on" :
    client2.publish("lhome/kitchen/exhaust","on")
   elif str(message.payload.decode("utf-8"))=="kitchen_exhaust_off" :
    client2.publish("lhome/kitchen/exhaust","off")
   elif str(message.payload.decode("utf-8"))=="kitchen_oven_on" :
    client2.publish("lhome/kitchen/oven","on")
   elif str(message.payload.decode("utf-8"))=="kitchen_oven_off":
    client2.publish("lhome/kitchen/oven","off")
    
   elif str(message.payload.decode("utf-8"))=="kitchen_fridge_on" :
    client2.publish("lhome/kitchen/fridge","on")
   elif str(message.payload.decode("utf-8"))=="kitchen_fridge_off" :
    client2.publish("lhome/kitchen/fridge","off")
   elif str(message.payload.decode("utf-8"))=="kitchen_chimney_on" :
    client2.publish("lhome/kitchen/chimney","on")
   elif str(message.payload.decode("utf-8"))=="kitchen_chimney_off":
    client2.publish("lhome/kitchen/chimney","off")
   elif str(message.payload.decode("utf-8"))=="kitchen_socket_on" :
    client2.publish("lhome/kitchen/socket","on")
   elif str(message.payload.decode("utf-8"))=="kitchen_socket_off" :
    client2.publish("lhome/kitchen/socket","off")
   elif str(message.payload.decode("utf-8"))=="templelight_on" :
    client2.publish("lhome/kitchen/templelight","on")
   elif str(message.payload.decode("utf-8"))=="templelight_off" :
    client2.publish("lhome/kitchen/templelight","off")

 if str(message.topic)=="home/room1" :# Master Bed Room
   print("Portion of the House -->=",str(message.topic))
   print("INDICATION TO --> =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="room1_wall_light_on":
    client2.publish("lhome/room1/light","on")
   elif str(message.payload.decode("utf-8"))=="room1_wall_light_off":  
    client2.publish("lhome/room1/light","off")
   elif str(message.payload.decode("utf-8"))=="room1_dim_light_on" :
    client2.publish("lhome/room1/dimlight","on")
   elif str(message.payload.decode("utf-8"))=="room1_dim_light_off" :
    client2.publish("lhome/room1/dimlight","off")
   elif str(message.payload.decode("utf-8"))=="room1_fan_on" :
    client2.publish("lhome/room1/fan","on")
   elif str(message.payload.decode("utf-8"))=="room1_fan_off" :
    client2.publish("lhome/room1/fan","off")
   elif str(message.payload.decode("utf-8"))=="room1_ac_on" :
    client2.publish("lhome/room1/ac","on")
   elif str(message.payload.decode("utf-8"))=="room1_ac_off" :
    client2.publish("lhome/room1/ac","off")
   elif str(message.payload.decode("utf-8"))=="room1_socket_on" :
    client2.publish("lhome/room1/socket","on")
   elif str(message.payload.decode("utf-8"))=="room1_socket_off" :
    client2.publish("lhome/room1/socket","off")
   elif str(message.payload.decode("utf-8"))=="room1_bath_light_on" :
    client2.publish("lhome/room1/bathroom/light","on")
   elif str(message.payload.decode("utf-8"))=="room1_bath_light_off" :
    client2.publish("lhome/room1/bathroom/light","off")
   elif str(message.payload.decode("utf-8"))=="room1_geyser_on" :
    client2.publish("lhome/room1/bathroom/geyser","on")
   elif str(message.payload.decode("utf-8"))=="room1_geyser_off" :
    client2.publish("lhome/room1/bathroom/geyser","off")

 if str(message.topic)=="home/room2" :# Parents Bed Room
   print("Portion of the House -->=",str(message.topic))
   print("INDICATION TO --> =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="room2_wall_light_on":
    client2.publish("lhome/room2/light","on")
   elif str(message.payload.decode("utf-8"))=="room2_wall_light_off":  
    client2.publish("lhome/room2/light","off")
   elif str(message.payload.decode("utf-8"))=="room2_dim_light_on" :
    client2.publish("lhome/room2/dimlight","on")
   elif str(message.payload.decode("utf-8"))=="room2_dim_light_off" :
    client2.publish("lhome/room2/dimlight","off")
   elif str(message.payload.decode("utf-8"))=="room2_fan_on" :
    client2.publish("lhome/room2/fan","on")
   elif str(message.payload.decode("utf-8"))=="room2_fan_off" :
    client2.publish("lhome/room2/fan","off")
   elif str(message.payload.decode("utf-8"))=="room2_ac_on" :
    client2.publish("lhome/room2/ac","on")
   elif str(message.payload.decode("utf-8"))=="room2_ac_off" :
    client2.publish("lhome/room2/ac","off")
   elif str(message.payload.decode("utf-8"))=="room2_socket_on" :
    client2.publish("lhome/room2/socket","on")
   elif str(message.payload.decode("utf-8"))=="room2_socket_off" :
    client2.publish("lhome/room2/socket","off")
   elif str(message.payload.decode("utf-8"))=="room2_bath_light_on" :
    client2.publish("lhome/room2/bathroom/light","on")
   elif str(message.payload.decode("utf-8"))=="room2_bath_light_off" :
    client2.publish("lhome/room2/bathroom/light","off")

 if str(message.topic)=="home/room3" :# Family Bed Room
   print("Portion of the House -->=",str(message.topic))
   print("INDICATION TO --> =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="room3_wall_light_on":
    client2.publish("lhome/room3/light","on")
   elif str(message.payload.decode("utf-8"))=="room3_wall_light_off":  
    client2.publish("lhome/room3/light","off")
   elif str(message.payload.decode("utf-8"))=="room3_dim_light_on" :
    client2.publish("lhome/room3/dimlight","on")
   elif str(message.payload.decode("utf-8"))=="room3_dim_light_off" :
    client2.publish("lhome/room3/dimlight","off")
   elif str(message.payload.decode("utf-8"))=="room3_fan_on" :
    client2.publish("lhome/room3/fan","on")
   elif str(message.payload.decode("utf-8"))=="room3_fan_off" :
    client2.publish("lhome/room3/fan","off")
   elif str(message.payload.decode("utf-8"))=="room3_ac_on" :
    client2.publish("lhome/room3/ac","on")
   elif str(message.payload.decode("utf-8"))=="room3_ac_off" :
    client2.publish("lhome/room3/ac","off")
   elif str(message.payload.decode("utf-8"))=="room3_socket_on" :
    client2.publish("lhome/room3/socket","on")
   elif str(message.payload.decode("utf-8"))=="room3_socket_off" :
    client2.publish("lhome/room3/socket","off")
   elif str(message.payload.decode("utf-8"))=="room3_bath_light_on" :
    client2.publish("lhome/room3/bathroom/light","on")
   elif str(message.payload.decode("utf-8"))=="room3_bath_light_off" :
    client2.publish("lhome/room3/bathroom/light","off")
   elif str(message.payload.decode("utf-8"))=="room3_geyser_on" :
    client2.publish("lhome/room3/bathroom/geyser","on")
   elif str(message.payload.decode("utf-8"))=="room3_geyser_off" :
    client2.publish("lhome/room3/bathroom/geyser","off")
   elif str(message.payload.decode("utf-8"))=="room3_tv_on" :
    client2.publish("lhome/room3/tv","on")
   elif str(message.payload.decode("utf-8"))=="room3_tv_off" :
    client2.publish("lhome/room3/tv","off")


 if str(message.topic)=="home/outdoor" :# Outdoor Bed Room
   print("Portion of the House -->=",str(message.topic))
   print("INDICATION TO --> =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="outdoor_wall_light_on":
    client2.publish("lhome/outdoor/light","on")
   elif str(message.payload.decode("utf-8"))=="outdoor_wall_light_off":  
    client2.publish("lhome/outdoor/light","off")
   elif str(message.payload.decode("utf-8"))=="outdoor_dim_light_on" :
    client2.publish("lhome/outdoor/dimlight","on")
   elif str(message.payload.decode("utf-8"))=="outdoor_dim_light_off" :
    client2.publish("lhome/outdoor/dimlight","off")
   elif str(message.payload.decode("utf-8"))=="callingbell_on" :
    client2.publish("lhome/outdoor/bell","on")
   elif str(message.payload.decode("utf-8"))=="callingbell_off" :
    client2.publish("lhome/outdoor/bell","off")
   elif str(message.payload.decode("utf-8"))=="outdoor_sump_motor_on" :
    client2.publish("lhome/outdoor/sumpmotor","on")
   elif str(message.payload.decode("utf-8"))=="outdoor_sump_motor_off" :
    client2.publish("lhome/outdoor/sumpmotor","off")
   elif str(message.payload.decode("utf-8"))=="outdoor_socket_on" :
    client2.publish("lhome/outdoor/socket","on")
   elif str(message.payload.decode("utf-8"))=="outdoor_socket_off" :
    client2.publish("lhome/outdoor/socket","off")
   elif str(message.payload.decode("utf-8"))=="outdoor_borewell_pump_on" :
    client2.publish("lhome/outdoor/borewell","on")
   elif str(message.payload.decode("utf-8"))=="outdoor_borewell_pump_off" :
    client2.publish("lhome/outdoor/borewell","off")
   elif str(message.payload.decode("utf-8"))=="outdoor_gate_open" :
    client2.publish("lhome/outdoor/gate","open")
   elif str(message.payload.decode("utf-8"))=="outdoor_gate_close" :
    client2.publish("lhome/outdoor/gate","close")
   elif str(message.payload.decode("utf-8"))=="car_sensor_set" :
    client2.publish("lhome/car/sensor","set")
   elif str(message.payload.decode("utf-8"))=="car_sensor_detach" :
    client2.publish("lhome/car/sensor","detach")


#def on_log(client, userdata, level, msg):
#    print(msg.topic+" "+str(msg.payload))


client2=paho.Client()
client2.userdata="Mosquitto Client(Local)"
client2.on_connect = on_connect
client2.connect('Local MQTT broker IP', 1883, 60)
client2.loop_start()

awsclient = paho.Client()
awsclient.userdata="AWS_Client"
awsclient.on_connect = on_connect
awsclient.on_message = on_message
awsclient.connected_flag=False
#mqttc.on_log = on_log

awsport = 8883
clientId = "41234" # thingname 
thingName = "41234" # thingname 
awshost = "<change me>.amazonaws.com" # connection host url
caPath = "<path>/AmazonRootCA1.pem"
certPath = "<path>-certificate.pem.crt.txt"
keyPath = "<path>-private.pem.key"

awsclient.tls_set(caPath, certfile=certPath, keyfile=keyPath, cert_reqs=ssl.CERT_REQUIRED, tls_version=ssl.PROTOCOL_TLSv1_2, ciphers=None)
awsclient.connect(awshost, awsport, keepalive=60)
awsclient.loop_forever()
while not awsclient.connected_flag:
 print("in wait loop")
 time.sleep(1)
 awsclient.loop_stop() 


