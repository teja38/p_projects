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
int exhaust=4;
int socket=0;
int oven=2;
int fridge=14;
int temple=12;
int chimney=13;

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
  if(msg.compareTo("on")==0 && topicname.compareTo("lhome/kitchen/light")==0) {
        digitalWrite(wall_light, LOW);  
        Serial.println("----------PIN number-----------");
        Serial.println(wall_light);
      } 
  if(msg.compareTo("off")==0 && topicname.compareTo("lhome/kitchen/light")==0){
        digitalWrite(wall_light, HIGH);  // Turn the LED off by making the voltage HIGH
        Serial.println("----------PIN number-----------");
        Serial.println(wall_light);
        }
 /*************  DIM LIGHT ****************/
 
  if(msg.compareTo("on")==0 && topicname.compareTo("lhome/kitchen/dimlight")==0) {
        digitalWrite(dim_light, LOW);  
        Serial.println("----------PIN number-----------");
        Serial.println(dim_light);
        } 
  if(msg.compareTo("off")==0 && topicname.compareTo("lhome/kitchen/dimlight")==0){
        digitalWrite(dim_light, HIGH);  // Turn the LED off by making the voltage HIGH
        Serial.println("----------PIN number-----------");
        Serial.println(dim_light);
        }

  /***************** exhaust**********************/      
  if(msg.compareTo("on")==0 && topicname.compareTo("lhome/kitchen/exhaust")==0) {
        digitalWrite(exhaust, LOW);  
        Serial.println("----------PIN number-----------");
        Serial.println(exhaust);
      } 
  if(msg.compareTo("off")==0 && topicname.compareTo("lhome/kitchen/exhaust")==0){
        digitalWrite(exhaust, HIGH);  // Turn the LED off by making the voltage HIGH
        Serial.println("----------PIN number-----------");
        Serial.println(exhaust);
        }

    // Socket    
  if(msg.compareTo("on")==0 && topicname.compareTo("lhome/kitchen/socket")==0) {
        digitalWrite(socket, LOW);  
        Serial.println("----------PIN number-----------");
        Serial.println(socket);
        } 
  if(msg.compareTo("off")==0 && topicname.compareTo("lhome/kitchen/socket")==0){
        digitalWrite(socket, HIGH);  // Turn the LED off by making the voltage HIGH
        Serial.println("----------PIN number-----------");
        Serial.println(socket);
      }
    // AC
  if(msg.compareTo("on")==0 && topicname.compareTo("lhome/kitchen/oven")==0) {
        digitalWrite(oven, LOW);  
        Serial.println("----------PIN number-----------");
        Serial.println(oven);
      } 
  if(msg.compareTo("off")==0 && topicname.compareTo("lhome/kitchen/oven")==0){
        digitalWrite(oven, HIGH);  // Turn the LED off by making the voltage HIGH
        Serial.println("----------PIN number-----------");
        Serial.println(oven);
    }
  // TV
        if(msg.compareTo("on")==0 && topicname.compareTo("lhome/kitchen/fridge")==0) {
              digitalWrite(fridge, LOW);  
              Serial.println("----------PIN number-----------");
              Serial.println(fridge);
            } 
        if(msg.compareTo("off")==0 && topicname.compareTo("lhome/kitchen/fridge")==0){
              digitalWrite(fridge, HIGH);  // Turn the LED off by making the voltage HIGH
              Serial.println("----------PIN number-----------");
              Serial.println(fridge);
          }
      
   // chimney
          if(msg.compareTo("on")==0 && topicname.compareTo("lhome/kitchen/chimney")==0) {
              digitalWrite(chimney, LOW);  
              Serial.println("----------PIN number-----------");
              Serial.println(chimney);
            } 
        if(msg.compareTo("off")==0 && topicname.compareTo("lhome/kitchen/chimney")==0){
              digitalWrite(chimney, HIGH);  // Turn the LED off by making the voltage HIGH
              Serial.println("----------PIN number-----------");
              Serial.println(chimney);
          }
  // Templelight

        if(msg.compareTo("on")==0 && topicname.compareTo("lhome/kitchen/templelight")==0) {
              digitalWrite(temple, LOW);  
              Serial.println("----------PIN number-----------");
              Serial.println(temple);
            } 
        if(msg.compareTo("off")==0 && topicname.compareTo("lhome/kitchen/templelight")==0){
              digitalWrite(temple, HIGH);  // Turn the LED off by making the voltage HIGH
              Serial.println("----------PIN number-----------");
              Serial.println(temple);
          }
      

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266ClientKitchen";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("lhome/dash/kitchen/status", "Connected-Device-Kitchen");
      
      // ... and resubscribe
      client.subscribe("lhome/kitchen/#");
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
      pinMode(exhaust, OUTPUT);     // D2   --> exhaust
      pinMode(socket, OUTPUT);     // D3   --> socket
      pinMode(oven, OUTPUT);     // D4   --> oven
      pinMode(fridge, OUTPUT);    // D5   --> fridge 
      pinMode(temple, OUTPUT);    // D6   --> temple
      pinMode(chimney, OUTPUT);    // D7   --> chimney
      pinMode(15, OUTPUT);    // D8   -->
      // turn off board leds
      digitalWrite(wall_light, HIGH);     
      digitalWrite(oven, HIGH);  
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


  // Update the below snippet for your sensor retrieved data
  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
 
  char buffer [33];
    if (value>101)
     value=0;
    Serial.println(value);
    itoa(value,buffer,10);
    //client.publish("lhome/dash/kitchen/temp",buffer );
    itoa(value+10,buffer,10);
    //client.publish("lhome/dash/kitchen/humid",buffer );
  }
}
