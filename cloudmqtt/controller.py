import time
import paho.mqtt.client as paho
import ssl

#define callbacks
def on_message(client3, userdata, message):
 #------------------------------------------------------------------------   
 # ------------------------Hall-------------------------------------------
 #------------------------------------------------------------------------
   #-- Weather
 if str(message.topic)=="lhome/dash/hall/temp" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client.publish("home/dash/hall/temp",str(message.payload.decode("utf-8")))
   else :
    client.publish("home/dash/hall/temp",str(message.payload.decode("utf-8")))
 if str(message.topic)=="lhome/dash/hall/humid" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client.publish("home/dash/hall/humid",str(message.payload.decode("utf-8")))
   else :
    client.publish("home/dash/hall/humid",str(message.payload.decode("utf-8")))
   #--Switches
 if str(message.topic)=="home/hall/light" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/hall/light","on")
   else :
    client2.publish("lhome/hall/light","off")
 if str(message.topic)=="home/hall/ac" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
       client2.publish("lhome/hall/ac","on")
   else : 
    client2.publish("lhome/hall/ac","off")
   
 if str(message.topic)=="home/hall/fan" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/hall/fan","on")
   else :
    client2.publish("lhome/hall/fan","off")
 if str(message.topic)=="home/hall/dimlight" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/hall/dimlight","on")
   else : 
    client2.publish("lhome/hall/dimlight","off")
 if str(message.topic)=="home/hall/tv" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/hall/tv","on")
   else : 
    client2.publish("lhome/hall/tv","off")
#---------------------------- HALL END -------------------------
#-------------------------------------------------------------------------
#-----------------------------ROOM 1 (North EAST)-------------------------

   #-- Weather
 if str(message.topic)=="lhome/dash/room1/temp" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client.publish("home/dash/room1/temp",str(message.payload.decode("utf-8")))
   else :
    client.publish("home/dash/room1/temp",str(message.payload.decode("utf-8")))
 if str(message.topic)=="lhome/dash/room1/humid" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client.publish("home/dash/room1/humid",str(message.payload.decode("utf-8")))
   else :
    client.publish("home/dash/room1/humid",str(message.payload.decode("utf-8")))
   #--Switches
 if str(message.topic)=="home/room1/light" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/room1/light","on")
   else :
    client2.publish("lhome/room1/light","off")
 if str(message.topic)=="home/room1/dimlight" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/room1/dimlight","on")
   else :
    client2.publish("lhome/room1/dimlight","off")
 if str(message.topic)=="home/room1/fan" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/room1/fan","on")
   else :
    client2.publish("lhome/room1/fan","off")
 if str(message.topic)=="home/room1/ac" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/room1/ac","on")
   else :
    client2.publish("lhome/room1/ac","off")
 if str(message.topic)=="home/room1/bathroom/light" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/room1/bathroom/light","on")
   else :
    client2.publish("lhome/room1/bathroom/light","off")
 if str(message.topic)=="home/room1/bathroom/geyser" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/room1/bathroom/geyser","on")
   else :
    client2.publish("lhome/room1/bathroom/geyser","off")
#------------------------------ ROOM 1 END -------------------------------
#-------------------------------------------------------------------------
#-------------------------------------------------------------------------
#--------------------------------KITCHEN START ---------------------------

 if str(message.topic)=="home/kitchen/exhaust" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/kitchen/exhaust","on")
   else :
    client2.publish("lhome/kitchen/exhaust","off")
 if str(message.topic)=="home/kitchen/light" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/kitchen/light","on")
   else :
    client2.publish("lhome/kitchen/light","off")
 if str(message.topic)=="home/kitchen/oven" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/kitchen/oven","on")
   else :
    client2.publish("lhome/kitchen/oven","off")

 if str(message.topic)=="home/kitchen/socket" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/kitchen/socket","on")
   else :
    client2.publish("lhome/kitchen/socket","off")
 if str(message.topic)=="home/kitchen/chimney" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/kitchen/chimney","on")
   else :
    client2.publish("lhome/kitchen/chimney","off")
 if str(message.topic)=="home/kitchen/dimlight" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/kitchen/dimlight","on")
   else :
    client2.publish("lhome/kitchen/dimlight","off")
#--------------------------------KITCHEN END -----------------------------
#-------------------------------------------------------------------------
#--------------------------------OUTDOOR/MISCALLANEOUS--------------------
#-------------------------------------------------------------------------

 if str(message.topic)=="home/outdoor/compound" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/outdoor/light","on")
   else :
    client2.publish("lhome/outdoor/light","off")
 if str(message.topic)=="home/outdoor/pump" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/outdoor/sumpmotor","on")
   else :
    client2.publish("lhome/outdoor/sumpmotor","off")
 if str(message.topic)=="home/outdoor/parking" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="on":
     client2.publish("lhome/outdoor/dimlight","on")
   else :
    client2.publish("lhome/outdoor/dimlight","off")
 if str(message.topic)=="home/outdoor/gate" :
   print("Portion of the House -->=",str(message.topic))
   print("Message from CloudMqtt =",str(message.payload.decode("utf-8")))
   if str(message.payload.decode("utf-8"))=="open":
     client2.publish("lhome/outdoor/gate","open")
   else :
    client2.publish("lhome/outdoor/gate","close")
#----------------------------------END -----------------------------------
def on_log(client, userdata, level, buf):
 print("log: ",buf)

def on_connect(client, userdata, flags, rc):
 if str(rc)=="0":
  client.publish("home/hall/notice","connected!",)
  print(" ------- CONNECTED TO -----> ",client.userdata)

def on_subscribe(mosq, obj, mid, granted_qos):
 print("This means broker has acknowledged my subscribe request")
 print("Subscribed: " + str(mid) + " " + str(granted_qos))  


client=paho.Client()
client.userdata="CLOUD_MQTT_BROKER"
client.on_message=on_message
#client.on_log=on_log
client.on_connect=on_connect
client.on_subscribe = on_subscribe
print("connecting to cloudmqtt broker")
client.tls_set("cloudmqttcert.crt", tls_version=ssl.PROTOCOL_TLSv1_2)
client.tls_insecure_set(True)
client.username_pw_set("username", "password")
client.connect('tailor.cloudmqtt.com', 22135, 60)   


client2=paho.Client() 
client2.on_message=on_message
client2.userdata="LOCAL_MQTT_BROKER"
client.on_log=on_log
client2.on_connect=on_connect
client2.on_subscribe = on_subscribe
print("connecting to local mosquitto broker")
client2.connect('umbrellapix', 1883, 60)   
client2.loop_start()
##start loop to process received messages
client.loop_start()
#wait to allow publish and logging and exit
time.sleep(5)
client.loop_start()
client2.loop_start()
# Controller topic names from the android app to control
client.subscribe ("home/#" ,0 )
client2.subscribe("lhome/dash/#",0)
count=0
run = True
while run:
 count+=1
 if count > 50 :
  count=0
 time.sleep(1)
