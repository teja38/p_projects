#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

const char* ssid = "WIFI SSID"; // provide wifi ssid and password
const char* password = "PASSWORD";
const char* mqtt_server = "LOCAL_MQTT_HOST(RPi ip)"; // Update the local mqtt server address here

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

int wall_light=16;
int dim_light=5;
int sumpmotor=4;
int socket=0;
int gate=2;
int tv=14;
int bath_light=12;
int geyser=13;

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  char message[30]="";
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
     message[i]=(char)payload[i];
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character

  
  String msg=message,topicname=topic;
 /*************  Light ****************/
  if(msg.compareTo("on")==0 && topicname.compareTo("lhome/outdoor/light")==0) {
        digitalWrite(wall_light, LOW);  
        Serial.println("----------PIN number-----------");
        Serial.println(wall_light);
      } 
  if(msg.compareTo("off")==0 && topicname.compareTo("lhome/outdoor/light")==0){
        digitalWrite(wall_light, HIGH);  // Turn the LED off by making the voltage HIGH
        Serial.println("----------PIN number-----------");
        Serial.println(wall_light);
        }
 /*************  DIM LIGHT ****************/
 
  if(msg.compareTo("on")==0 && topicname.compareTo("lhome/outdoor/dimlight")==0) {
        digitalWrite(dim_light, LOW);  
        Serial.println("----------PIN number-----------");
        Serial.println(dim_light);
        } 
  if(msg.compareTo("off")==0 && topicname.compareTo("lhome/outdoor/dimlight")==0){
        digitalWrite(dim_light, HIGH);  // Turn the LED off by making the voltage HIGH
        Serial.println("----------PIN number-----------");
        Serial.println(dim_light);
        }

  /***************** sumpmotor**********************/      
  if(msg.compareTo("on")==0 && topicname.compareTo("lhome/outdoor/sumpmotor")==0) {
        digitalWrite(sumpmotor, LOW);  
        Serial.println("----------PIN number-----------");
        Serial.println(sumpmotor);
      } 
  if(msg.compareTo("off")==0 && topicname.compareTo("lhome/outdoor/sumpmotor")==0){
        digitalWrite(sumpmotor, HIGH);  // Turn the LED off by making the voltage HIGH
        Serial.println("----------PIN number-----------");
        Serial.println(sumpmotor);
        }

    // Socket    
  if(msg.compareTo("on")==0 && topicname.compareTo("lhome/outdoor/socket")==0) {
        digitalWrite(socket, LOW);  
        Serial.println("----------PIN number-----------");
        Serial.println(socket);
        } 
  if(msg.compareTo("off")==0 && topicname.compareTo("lhome/outdoor/socket")==0){
        digitalWrite(socket, HIGH);  // Turn the LED off by making the voltage HIGH
        Serial.println("----------PIN number-----------");
        Serial.println(socket);
      }
    // GATE
  if(msg.compareTo("open")==0 && topicname.compareTo("lhome/outdoor/gate")==0) {
        digitalWrite(gate, LOW);  
        Serial.println("----------PIN number-----------");
        Serial.println(gate);
      } 
  if(msg.compareTo("close")==0 && topicname.compareTo("lhome/outdoor/gate")==0){
        digitalWrite(gate, HIGH);  // Turn the LED off by making the voltage HIGH
        Serial.println("----------PIN number-----------");
        Serial.println(gate);
    }
  
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266ClientRoom1";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("lhome/dash/outdoor/status", "Connected-Device-Outdoor");
      
      // ... and resubscribe
      client.subscribe("lhome/outdoor/#");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {

      pinMode(wall_light, OUTPUT);    // D0   --> Wall Light
      pinMode(dim_light, OUTPUT);     // D1   --> Dim Light 
      pinMode(sumpmotor, OUTPUT);     // D2   --> sumpmotor
      pinMode(socket, OUTPUT);     // D3   --> socket
      pinMode(gate, OUTPUT);     // D4   --> gate
      pinMode(tv, OUTPUT);    // D5   --> tv 
      //pinMode(temple, OUTPUT);    // D6   --> bath_light
      //pinMode(chimney, OUTPUT);    // D7   --> geyser
      //pinMode(15, OUTPUT);    // D8   -->
      // turn off board leds
      digitalWrite(wall_light, HIGH);     
      digitalWrite(gate, HIGH);  
  // Initialize the BUILTIN_LED pin as an output
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
 
  char buffer [33];
    if (value>101)
     value=0;
    Serial.println(value);
    itoa(value,buffer,10);
    //client.publish("lhome/dash/outdoor/temp",buffer );
    itoa(value+10,buffer,10);
    //client.publish("lhome/dash/outdoor/humid",buffer );
  }
}
