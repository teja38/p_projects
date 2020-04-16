#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "WIFI SSID"; // provide wifi ssid and password
const char* password = "PASSWORD";
const char* mqtt_server = "LOCAL_MQTT_HOST(RPi ip)"; // Update the local mqtt server address here
WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;
// Appliances PIN list

int wall_light=16;  // D0   --> Wall Light
int dim_light=5;    // D1   --> Dim Light 
int fan=4;   // D2   --> fan
int socket=0;  // D3   --> socket
int ac=2;   // D4   --> ac
int tv=14; // D5   --> tv 
int temple=12; // Only for kitchen
int chimney=13; // only for kitchen

void setup_wifi() {

  delay(10);

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


  
  String msg=message,topicname=topic;
 // LIGHT
  if(msg.compareTo("on")==0 && topicname.compareTo("lhome/hall/light")==0) {
        digitalWrite(wall_light, LOW);  
        Serial.println("----------PIN number-----------");
        Serial.println(wall_light);
      } 
  if(msg.compareTo("off")==0 && topicname.compareTo("lhome/hall/light")==0){
        digitalWrite(wall_light, HIGH);  // Turn the LED off by making the voltage HIGH
        Serial.println("----------PIN number-----------");
        Serial.println(wall_light);
        }
 // DIM LIGHT
 
  if(msg.compareTo("on")==0 && topicname.compareTo("lhome/hall/dimlight")==0) {
        digitalWrite(dim_light, LOW);  
        Serial.println("----------PIN number-----------");
        Serial.println(dim_light);
        } 
  if(msg.compareTo("off")==0 && topicname.compareTo("lhome/hall/dimlight")==0){
        digitalWrite(dim_light, HIGH);  // Turn the LED off by making the voltage HIGH
        Serial.println("----------PIN number-----------");
        Serial.println(dim_light);
        }

  // FAN
  if(msg.compareTo("on")==0 && topicname.compareTo("lhome/hall/fan")==0) {
        digitalWrite(fan, LOW);  
        Serial.println("----------PIN number-----------");
        Serial.println(fan);
      } 
  if(msg.compareTo("off")==0 && topicname.compareTo("lhome/hall/fan")==0){
        digitalWrite(fan, HIGH);  // Turn the LED off by making the voltage HIGH
        Serial.println("----------PIN number-----------");
        Serial.println(fan);
        }

  // Socket    
  if(msg.compareTo("on")==0 && topicname.compareTo("lhome/hall/socket")==0) {
        digitalWrite(socket, LOW);  
        Serial.println("----------PIN number-----------");
        Serial.println(socket);
        } 
  if(msg.compareTo("off")==0 && topicname.compareTo("lhome/hall/socket")==0){
        digitalWrite(socket, HIGH);  // Turn the LED off by making the voltage HIGH
        Serial.println("----------PIN number-----------");
        Serial.println(socket);
      }
 
  // AC
  if(msg.compareTo("on")==0 && topicname.compareTo("lhome/hall/ac")==0) {
        digitalWrite(ac, LOW);  
        Serial.println("----------PIN number-----------");
        Serial.println(ac);
      } 
  if(msg.compareTo("off")==0 && topicname.compareTo("lhome/hall/ac")==0){
        digitalWrite(ac, HIGH);  // Turn the LED off by making the voltage HIGH
        Serial.println("----------PIN number-----------");
        Serial.println(ac);
    }
  // TV
        if(msg.compareTo("on")==0 && topicname.compareTo("lhome/hall/tv")==0) {
              digitalWrite(tv, LOW);  
              Serial.println("----------PIN number-----------");
              Serial.println(tv);
            } 
        if(msg.compareTo("off")==0 && topicname.compareTo("lhome/hall/tv")==0){
              digitalWrite(tv, HIGH);  // Turn the LED off by making the voltage HIGH
              Serial.println("----------PIN number-----------");
              Serial.println(tv);
          }
      
   

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266ClientHall";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("lhome/dash/hall/status", "Connected-Device-Hall");
      
      // ... and resubscribe
      client.subscribe("lhome/hall/#");
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
      pinMode(fan, OUTPUT);     // D2   --> fan
      pinMode(socket, OUTPUT);     // D3   --> socket
      pinMode(ac, OUTPUT);     // D4   --> ac
      pinMode(tv, OUTPUT);    // D5   --> tv 
      pinMode(temple, OUTPUT);    // D6   
      pinMode(chimney, OUTPUT);    // D7   
      pinMode(15, OUTPUT);    // D8   
      // turn off board leds
      digitalWrite(wall_light, HIGH);     
      digitalWrite(ac, HIGH);  
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

  // Replace the below snippet with sensor retrieved data.
  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
 
    char buffer [33];
    if (value>101)
     value=0;
    Serial.println(value);
    itoa(value,buffer,10);
    client.publish("lhome/dash/hall/temp",buffer );
    itoa(value+10,buffer,10);
    client.publish("lhome/dash/hall/humid",buffer );
  }
}
