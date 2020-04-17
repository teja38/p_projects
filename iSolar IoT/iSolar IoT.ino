#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
//#include<FirebaseArduino.h>
//#include <PubSubClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "Nokia_5110.h"
#include <SimpleDHT.h>
#include <SoftwareSerial.h>
#include <BlynkSimpleEsp8266.h>

// Software SPI (slower updates, more flexible pin options):
// pin 14 - Serial clock out (SCLK)
// pin 12 - Serial data out (DIN)
// pin 3 - Data/Command select (D/C)
// pin 14 - LCD chip select (CS)
// pin 3 - LCD reset (RST)

char auth[] = ""; // blynk authorization code
char ssid[] = ""; // wifi ssid
char pass[] = ""; // wifi password

int pinDHT11 = 1; // tx pin
int ldrPin = 10;  //sd3 pin
/****    14-D5 , 12-D6 , 13-D7,15-D8 , 3-RX ****/
Adafruit_PCD8544 display = Adafruit_PCD8544(14, 12, 13, 15, 3);
SimpleDHT11 dht11(pinDHT11);
int lightSensor = 0;
int email_flag,V6_value = 1;
String V5_value="";

void setup() {
  Serial.begin(9600);
  display.begin();
  // init done
  display.clearDisplay();   // clears the screen and buffer
  funcDrawlines();
  display.display();
  display.setContrast(40);

  pinMode(ldrPin, INPUT);
  Blynk.begin(auth, ssid, pass);
  
 
  // you can change the contrast around to adapt the display
  // for the best viewing!
  // display.display(); // show splashscreen
  
  /*pinMode(Relay1,OUTPUT);
    pinMode(Relay2,OUTPUT);
    pinMode(Relay3,OUTPUT);
    pinMode(Relay4,OUTPUT);
    pinMode(Relay5,OUTPUT);
  */
  pinMode(16, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  digitalWrite(16, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(0, HIGH);
  digitalWrite(2, HIGH);
  // draw many lines
  funcDrawlines();
  display.display();
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.println("Welcome");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  Blynk.run();
  String timeString = getTime();
  display.clearDisplay();
  display.setRotation(0);  // rotate 90 degrees counter clockwise, can also use values of 2 and 3 to go further.
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(10, 0);
  String tempHumid = getTemp();
  display.println("Temperature");
  display.setTextSize(5);
  display.setCursor(10, 10);
  display.println(tempHumid.substring(0, 2));
  Blynk.virtualWrite(V0, (String)tempHumid.substring(0, 2));
  display.setCursor(70, 10);
  display.setTextSize(2);
  display.println("o");
  display.setCursor(70, 30);
  display.setTextSize(2);
  display.println("C");
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(18, 0);
  display.println("Humidity");
  display.setTextSize(5);
  display.setCursor(10, 10);
  display.print(tempHumid.substring(3));
  Blynk.virtualWrite(V1, (String)tempHumid.substring(3));
  display.setCursor(70, 30);
  display.setTextSize(2); display.println("%");
  display.display();
  delay(2000);

  lightSense();
  float voltageValue=getVoltage();

  /********** Display voltage for the A0 ports ***********/
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(18, 0);
  display.println("Voltage");
  display.setTextSize(2);
  display.setCursor(10, 13);
  display.println(voltageValue);
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.println("Time " + timeString);
  Blynk.virtualWrite(V2, voltageValue);
  display.display();
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(18, 0);
  display.println("DASHBOARD");
  int relay1 = digitalRead(5); // D1
  int relay2 = digitalRead(4); // D2
  int relay3 = digitalRead(0); // D3
  int relay4 = digitalRead(2); // D4
  int relay5 = digitalRead(16); // D0
  display.println("--------------");

  String status = "";
  String htmlTag="<html><body style=\"background-color:#000066;\"><p style=\"font-size:15px;font-weight:bold;color:white\"> Hola,</p><div><ul style=\"list-style-type:circle;font-size:15px;font-weight:bold;color:white\">";
  
  /***************** SOCKET PIN CONTROLER1 ( OUTPUT 1 ) D1-5 ****************/
  
  if (relay1 == 0) {
    display.println(" Outdoor ON");
    status = status + "  Outdoor ON\n";
    htmlTag=htmlTag+"<li>Outdoor ON</li>";
  }
  else {
    display.println(" Outdoor OFF");
    status = status + "  Outdoor OFF\n";
    htmlTag=htmlTag+"<li>Outdoor OFF</li>";
  }

/************************** Charging Handling D2-GPIO=4************************/

  if(V6_value==1) {
  if ((timeString.substring(0,2).toInt()<=16 && timeString.substring(0,2).toInt()>=7)) {
    
    digitalWrite(4, LOW); 
    display.println(" Charge(A) ON");
    status = status + "  Charge(A) ON\n";
    htmlTag=htmlTag+"<li>Charge(A) ON</li>";
  
     }
  else
      {
        digitalWrite(4, HIGH); 
        display.println(" Charge(A) OFF");
        status = status + "  Charge(A) OFF\n";
        htmlTag=htmlTag+"<li>Charge(A) OFF</li>";
       }

  }

     else if (V6_value==2) {
      digitalWrite(4, LOW); 
    display.println(" Charge(M) ON");
    status = status + "  Charge(M) ON\n";
    htmlTag=htmlTag+"<li>Charge(M) ON</li>";
      
     }

    else {

       digitalWrite(4, HIGH); 
        display.println(" Charge(M) OFF");
        status = status + "  Charge(M) OFF\n";
        htmlTag=htmlTag+"<li>Charge(M) OFF</li>";
    }

 /************************** ( LIGHT 1 / DIM Light ) OUTPUT 2  D3-0****************************/    
 if (relay3 == 0) {
    display.println(" HallLight ON");
    status = status + "  HallLight ON\n";
    htmlTag=htmlTag+"<li>HallLight ON</li>";
  }
  else {
    display.println(" HallLight OFF");
    status = status + "  HallLight OFF\n";
    htmlTag=htmlTag+"<li>HallLight OFF</li>";
  }

 
 
 /************************** ( LIGHT 2 / DIM Light ) OUTPUT 3 D4-2****************************/    
       
       
  if (relay4 == 0) {
    display.println(" Kitchen ON");
    status = status + "  Kitchen ON\n";
    htmlTag=htmlTag+"<li>Kitchen ON</li>";
  }
  else {
    display.println(" Kitchen OFF");
    status = status + "  Kitchen OFF\n";
    htmlTag=htmlTag+"<li>Kitchen OFF</li>";
  }
 
  
  if (relay5 == 0)
    {
    status = status + "  LCD OFF\n";
    htmlTag=htmlTag+"<li>LCD OFF</li>";
    }
  else
    {
    status = status + "  LCD ON\n";
    htmlTag=htmlTag+"<li>LCD ON</li>";
    }

  htmlTag=htmlTag+"<li>"+(String)voltageValue+"</li><li>"+timeString+"</li>";

  if (lightSensor == 1) {
    //digitalWrite(16, LOW);
    //digitalWrite(2, HIGH);
    status = status + "  Hall is BRIGHT \n";
    htmlTag=htmlTag+"<li>Hall is Bright</li></ul></div></body></html>";
        
        
     if(email_flag==0 ||( email_flag!=2 && email_flag==3)){
        Blynk.email("Umbrella Solar Controller - DayLight ",htmlTag);
        email_flag=1;
        }
        else
        email_flag=2; 
   
  }
  else {
    //digitalWrite(16, HIGH);
    //digitalWrite(2, LOW);
    status = status + "  Hall is DARK \n";
    htmlTag=htmlTag+"<li>Hall is DARK</li></ul></div></body></html>";
      
      
      if(email_flag==0 || email_flag==2){
          Blynk.email("Umbrella Solar Controller - Dark Knight",htmlTag);
        email_flag=1;
        }
        else
        email_flag=3;
  }
  
  
  status = status + "  Charging Voltage - " + (String)voltageValue + "v\n  Time " + timeString + "\n";
  Blynk.virtualWrite(V4, status);

  display.display();
  delay(2000);
  display.clearDisplay();

  if (voltageValue > 15.25) {

    Blynk.email("Umbrella Solar Controller - Battery Status ", String("<html><body style=\"background-color:#000066;\"><p style=\"font-size:15px;font-weight:bold;color:white\"> Hola,</p><div><b>Battery is charged !!</b></body>"));

    delay(5000);
  }



}

  BLYNK_CONNECTED(){
    Blynk.syncVirtual(V5);
     Blynk.syncVirtual(V6);
  }
  

  BLYNK_WRITE(V6){

      V6_value=param.asInt();

  }
  BLYNK_WRITE(V5){

      V5_value=param.asString();

  }


void lightSense() {
  int val = digitalRead(ldrPin);

  WidgetLED led1(V3);

  if (val == HIGH ) {
    //Blynk.virtualWrite(V3,(String)"DARK");
    Serial.println("DARK");
    Blynk.setProperty(V3, "color", "#f5f5f2");
    lightSensor = 0;
  }
  else {
    // Blynk.virtualWrite(V3,(String)"LIGHT");
    Serial.println("LIGHT");
    Blynk.setProperty(V3, "color", "#49dd1a");
    lightSensor = 1;
  }


}


float getVoltage() {
  int sensorValue = analogRead(A0);
  float correctionfactor = 8;
  float vout = 0.0;
  float vin = 0.0;
  // two resistors 30K and 7.5k ohm
  float R1 = 30000;  //
  float R2 = 7500; //
  int value = 0;
  value = analogRead(A0);
  vout = (value * 5.0) / 1023.0; // see text
  vin = vout / (R2 / (R1 + R2));
  vin = vin - correctionfactor;
  if(vin<0.0)
  vin=0.0;
  
  return vin;

}

String getTemp() {
  byte temperature = 0;
  byte humidity = 0;
  String result = "";
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err=");
    Serial.println(err);
    delay(1000);
    return "00|00";
  }
  result = (String)temperature + "|" + (String)humidity;
  return result;
}

/*********************************************************/

String getTime()
{
  WiFiUDP ntpUDP;
  NTPClient timeClient(ntpUDP, "asia.pool.ntp.org", 19800, 60000);
  timeClient.begin();
  timeClient.update();
  //timeClient.setTimeOffset(19800);
  Serial.println(timeClient.getFormattedTime());

  String TimeTo = timeClient.getFormattedTime();
  //TimeTo.replace(":","-");

  //TimeTo.replace(":","-");

  return TimeTo;
}




/********************  Animation ************************/



void funcDrawlines() {
  for (int16_t i = 0; i < display.width(); i += 4) {
    display.drawLine(0, 0, i, display.height() - 1, BLACK);
    display.display();
  }
  for (int16_t i = 0; i < display.height(); i += 4) {
    display.drawLine(0, 0, display.width() - 1, i, BLACK);
    display.display();
  }
  delay(250);

  display.clearDisplay();
  for (int16_t i = 0; i < display.width(); i += 4) {
    display.drawLine(0, display.height() - 1, i, 0, BLACK);
    display.display();
  }
  for (int8_t i = display.height() - 1; i >= 0; i -= 4) {
    display.drawLine(0, display.height() - 1, display.width() - 1, i, BLACK);
    display.display();
  }
  delay(250);

  display.clearDisplay();
  for (int16_t i = display.width() - 1; i >= 0; i -= 4) {
    display.drawLine(display.width() - 1, display.height() - 1, i, 0, BLACK);
    display.display();
  }
  for (int16_t i = display.height() - 1; i >= 0; i -= 4) {
    display.drawLine(display.width() - 1, display.height() - 1, 0, i, BLACK);
    display.display();
  }
  delay(250);

  display.clearDisplay();
  for (int16_t i = 0; i < display.height(); i += 4) {
    display.drawLine(display.width() - 1, 0, 0, i, BLACK);
    display.display();
  }
  for (int16_t i = 0; i < display.width(); i += 4) {
    display.drawLine(display.width() - 1, 0, i, display.height() - 1, BLACK);
    display.display();
  }
  delay(250);
}
