
# Smart Lock

 **Description**: Our project name is Smart Lock. It's a lock (for a door for example) that works with a fingerprint system.

The system works with an ESP 32 that is connected in Wifi to send data.

The fingerprint are memorize in the module AS 308 and we can manage them through 2 basics programs to add or delete fingerprint. 
We also have implemented a door sensor that allow us to know if someone open or close the door. When the door sensor is trigger it's send a mail to notify that the door is open. It's like a quite alarm. 
The fingerprint system simulates the outside of the house and a simple button simulates the inside of the house.

 - [x] When the fingerprint module will detect a good fingerprint it will open the lock. If it's not good it will not open. And the informations are display on a LCD ;
 - [x] If you are already inside and want to leave you just need tu use the push button inside to open the lock ;
 - [x] The door sensor send an email when it's open ;
 - [x] We can observe in real time when the lock is open from outside and get the historic on a google sheet ;
 - [x] The transmission will use an ESP32 for the Wi-Fi connection.

Please use a gif format for the cover photo like this: (you can create gif using https://ezgif.com/maker)
![Cover GIF](doc/Arduino_LED.gif?raw=true)


[Team Report]

[Team Presentation](https://github.com/efrei-paris-sud/2020-H-Team-of-2/blob/main/project/doc/Iot%20Smart%20Lock%201%20ppt.pptx)

# Working Video

 [![Example Video of the porject](https://github.com/efrei-paris-sud/2020-H-Team-of-2/blob/main/project/doc/youtubelogo_large.png)](https://www.youtube.com/watch?v=3tVcI_w2x9o&feature=youtu.be&ab_channel=LuckeNguyen)

# Components

You can find below the list of components that we used. We put the link for the component.

- 1 x [Battery case](https://www.amazon.fr/ADAPTATEUR-SUPPORT-PILES-BATTERY-HOLDER/dp/B06XWSFY7X/ref=sr_1_6?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=1DLSEWX17195H&dchild=1&keywords=pile+arduino&qid=1610280721&sprefix=pile+ardui%2Caps%2C143&sr=8-6) (1)
- 1 x [ESP32](https://www.amazon.fr/AZDelivery-ESP-32-Dev-compris-eBook/dp/B07Z83MF5W/ref=sr_1_3_sspa?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dchild=1&keywords=ESP32&qid=1609856750&sr=8-3-spons&psc=1&smid=A1X7QLRQH87QA3&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUFMTkxaWDU0SVMzSUYmZW5jcnlwdGVkSWQ9QTA0NzM1NjIyUjQ4U0tKSTQyREtJJmVuY3J5cHRlZEFkSWQ9QTA1NTUzMDQyQlgwNVlZR1YxN0gxJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==) (2)
- 1 x [Fingerprint Reader AS608](https://www.banggood.com/fr/AS608-Fingerprint-Reader-Sensor-Module-Optical-Fingerprint-Module-Locks-Serial-Communication-Interface-p-1565798.html?rmmds=search&cur_warehouse=CN) (3)
- 1 x [Door Sensor MC 38](https://www.amazon.fr/ARCELI-D%C3%A9tecteur-Fen%C3%AAtre-Filaire-Magn%C3%A9tique/dp/B07DN21G36/ref=sr_1_3?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dchild=1&keywords=MC-38&qid=1607008136&sr=8-3) (4)
- 1 x [Electronic lock](https://fr.aliexpress.com/item/32820530084.html?src=google&albch=shopping&acnt=248-630-5778&isdl=y&slnk=&plac=&mtctp=&albbt=Gploogle_7_shopping&aff_atform=google&aff_short_key=UneMJZVf&gclsrc=aw.ds&&albagn=888888&&ds_e_adid=438856512841&ds_e_matchtype=&ds_e_device=c&ds_e_network=u&ds_e_product_group_id=743612850874&ds_e_product_id=fr32820530084&ds_e_product_merchant_id=107793888&ds_e_product_country=FR&ds_e_product_language=fr&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&ds_dest_url=https://fr.aliexpress.com/item/32820530084.html?&albcp=10191220517&albag=107473525088&gclid=Cj0KCQiA5bz-BRD-ARIsABjT4ngLcrbz76fVJdS3s3NXZILdxpqviB7cDmCuHv-OyQ5QIJkoy1qYk40aAn1sEALw_wcB) (5)
- 1 x [LCD OLED i2C](https://www.amazon.fr/azdelivery-64-Pixel-pouces-Arduino-Raspberry/dp/B078J78R45/ref=sr_1_2_sspa?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=JL1P23KVWKIV&dchild=1&keywords=lcd+arduino&qid=1609857311&sprefix=LCD+a%2Caps%2C162&sr=8-2-spons&psc=1&smid=A1X7QLRQH87QA3&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUFOODYzMlhOOUlMWVgmZW5jcnlwdGVkSWQ9QTEwMTcwNTUySzlZRlY2OUFCWlMxJmVuY3J5cHRlZEFkSWQ9QTAxODUxNjU1NkxPTFI5SlhFRTkmd2lkZ2V0TmFtZT1zcF9hdGYmYWN0aW9uPWNsaWNrUmVkaXJlY3QmZG9Ob3RMb2dDbGljaz10cnVl) (6)
- 1 x [Push button](https://www.amazon.fr/Youmile-Miniature-Momentary-Commutateur-Bouton-Poussoir/dp/B07Q1BXV7T/ref=sr_1_5?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=1BPEMXFGJT11T&dchild=1&keywords=push+button+arduino&qid=1609857398&sprefix=push+button+%2Caps%2C163&sr=8-5) (7)
- Wires (8)
- 1 x [Relay 5V](https://www.amazon.fr/Keenso-dExtension-D%C3%A9clencheur-Optocoupleur-Arduino/dp/B07Q1H63D6/ref=sr_1_43?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=1QOIYNZW61V32&dchild=1&keywords=relay+5v+arduino&qid=1610284984&sprefix=relay+5v+ar%2Caps%2C152&sr=8-43) (9)
- 1 x Breadboard

# Schematic
![Fritzing](https://github.com/efrei-paris-sud/2020-H-Team-of-2/blob/main/assets/Fritzing%20smarlock%20iot.PNG)

# Overview on the code

Here you can find the principle program that manage the lock. You can find the programs to add and delete fingerprint [here](https://github.com/efrei-paris-sud/2020-H-Team-of-2/tree/main/project/src). You can also find the file of the main program on the same link.

``` C
/***************************************************
This code is edited by Sachin Soni for the project called
IoT Attendance System 
whose tutorial video is uploaded his YouTube Channel
Visit techiesms YouTube channel to see this and many other project tutorials
http://www.youtube.com/techiesms
       techiesms
explore | learn | share 
****************************************************/
// This code is adapted for the Smart Lock project By Luc-Eric Nguyen and Nathan Thoams
 
// Initialize library and const 
#include <Adafruit_GFX.h>
#include <Adafruit_Fingerprint.h>
#include <HardwareSerial.h>
#include <WiFi.h>
#include <Adafruit_SH1106.h>
#include <Wire.h>
#include "WiFi.h"
#include <WebServer.h>
#include <WiFiClient.h>


const char* NAME;
const char* ID;
const int buttonPin = 4;
const int doorSensorPin = 2;
const int doorLockPin = 23; 
int buttonState = 0;

Adafruit_SH1106 display(23);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Serial2);

// Initialize IFTTT request
String Event_Name = "Lock_attendance";
String Event_Name2 = "MailDoor";

String Key = "d8l1LfZCIf1yR4uvghuvGF";

// Replace with your unique IFTTT URL resource
String resource = "/trigger/" + Event_Name + "/with/key/" + Key;
String resource2 = "/trigger/" + Event_Name2 + "/with/key/" + Key;

// Maker Webhooks IFTTT
const char* server = "maker.ifttt.com";

// Replace with your SSID and Password
const char* ssid     = "SFR_8388"; // set your WIFI SSID and password
const char* password = "5gdw28vxnm2xbx75izth"; 

//Setup function
void setup()
{
   //Setup components
  Serial.begin(115200);
  Serial2.begin(115200);
  pinMode(doorSensorPin, INPUT_PULLUP);
  pinMode(buttonPin,INPUT);
  pinMode(doorLockPin, OUTPUT);

  digitalWrite(doorLockPin, LOW);
  while (!Serial);
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");
  display.begin();
  display.clearDisplay();
  
  // set the data rate for the sensor serial port
  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) {
      delay(1);
    }
  }

  finger.getTemplateCount();
  Serial.print("Sensor contains "); 
  Serial.print(finger.templateCount); 
  Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
  digitalWrite(doorLockPin, LOW);
  //Setup WIFI connection
  Serial.print("Connecting to: ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);

  int timeout = 10 * 4; // 10 seconds
  while (WiFi.status() != WL_CONNECTED  && (timeout-- > 0)) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Failed to connect, going back to sleep");
  }

  Serial.print("WiFi connected in: ");
  Serial.print(millis());
  Serial.print(", IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(doorLockPin, LOW);
}

void loop()                    
{
  //set display
   display.clearDisplay();
   display.setTextColor(WHITE);
   display.setTextSize(1); //default value
   display.setCursor(40,30);
   display.println("Hello");
   display.display();
   delay(3500);
   display.clearDisplay();
  
  int tps = 0;
 
  // Check if the door sensor is open or close
  while ( tps != 10){
    int doorSensor = digitalRead(doorSensorPin);
    if (doorSensor == LOW) {
      display.clearDisplay();
      display.setCursor(5,30);
      display.println("Door sensor is close");
      display.display();
      delay(200);
    }
    else if (doorSensor == HIGH){
      display.clearDisplay();
      display.setCursor(5,30);
      display.println("door sensor is open");
      display.display();
      NAME = "Door";
      ID = "1";
      makeIFTTTRequest2();
      tps = 9;
      delay(2000);
    }
    tps++;
  }

  //Check if the button of inside is use
  tps = 0;
  while(tps != 10){
    
      buttonState = digitalRead(buttonPin);
      display.clearDisplay();
      display.setCursor(5,30);
      display.println("Check for button entrance");
      display.display();
      delay(100);

    if (buttonState == HIGH){
      digitalWrite(doorLockPin, HIGH);
      display.clearDisplay();
      display.setCursor(10,30);
      display.println("door open by inside");
      display.display();
      delay(3000);
      digitalWrite(doorLockPin, LOW);
      tps = 9;
    }
    tps++;
  }

  // Search if the fingerprint is in the database of the component
  getFingerprintIDez();

  //Setup the ID to identity each people
  if (finger.fingerID == 1) {

    Serial.print("!!--");
    Serial.println(finger.fingerID);
    NAME = "Nathan";
    ID = "1";
    if (finger.confidence >= 60) {
      Serial.print("Attendace Marked for "); 
      Serial.println(NAME);
      digitalWrite(doorLockPin, HIGH);
      delay(2000);
      digitalWrite(doorLockPin, LOW);
      makeIFTTTRequest();
     
    }
    else{
      display.clearDisplay();
      display.println("not enough confidence");
      display.display();
      delay(3000);  
    }

  }

  else if (finger.fingerID == 11 ) {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
    NAME = "Luc Eric";
    ID = "11";
    if (finger.confidence >= 60) {
      Serial.print("Attendace Marked for "); 
      Serial.println(NAME);
      digitalWrite(doorLockPin, HIGH);
      delay(2000);
      digitalWrite(doorLockPin, LOW);
      makeIFTTTRequest();
      }
    else{
      display.clearDisplay();
      display.println("not enough confidence");
      display.display();     
      delay(3000);
    }
  }
  finger.fingerID = 0;
}

// Function of searching that can return error if there is a problem
uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!
  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  // found a match!
  Serial.print("Found ID #"); 
  Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); 
  Serial.println(finger.confidence);

  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // found a match!
  Serial.print("Found ID #"); 
  Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); 
  Serial.println(finger.confidence);
  return finger.fingerID;
}

// Make an HTTP request to the IFTTT web service
// UPdate the Gsheet
void makeIFTTTRequest() {
  Serial.print("Connecting to ");
  Serial.print(server);

  WiFiClient client;
  int retries = 5;
  while (!!!client.connect(server, 80) && (retries-- > 0)) {
    Serial.print(".");
  }
  Serial.println();
  if (!!!client.connected()) {
    Serial.println("Failed to connect...");
  }

  Serial.print("Request resource: ");
  Serial.println(resource);

  //First client send data on gsheet
  String jsonObject = String("{\"value1\":\"") + NAME + "\",\"value2\":\"" + ID
                      + "\"}";

  client.println(String("POST ") + resource + " HTTP/1.1");
  client.println(String("Host: ") + server);
  client.println("Connection: close\r\nContent-Type: application/json");
  client.print("Content-Length: ");
  client.println(jsonObject.length());
  client.println();
  client.println(jsonObject);

  int timeout = 5 * 10; // 5 seconds
  while (!!!client.available() && (timeout-- > 0)) {
    delay(100);
  }
  if (!!!client.available()) {
    Serial.println("No response...");
  }
  while (client.available()) {
    Serial.write(client.read());
    
    //Print on display the ID that enter
    display.clearDisplay();
    display.setCursor(20,30);
    display.println(ID);
    display.print("est entre");
    display.display();
    delay(3000);
    display.clearDisplay();
  }
  Serial.println("\nclosing connection");
  client.stop();
}

// Make an HTTP request to the IFTTT web service
// Send email when door sensor is open
void makeIFTTTRequest2() {
  Serial.print("Connecting to ");
  Serial.print(server);

  WiFiClient client;
  int retries = 5;
  while (!!!client.connect(server, 80) && (retries-- > 0)) {
    Serial.print(".");
  }
  Serial.println();
  if (!!!client.connected()) {
    Serial.println("Failed to connect...");
  }

  Serial.print("Request resource: ");
  Serial.println(resource2);

  //First client send data on gsheet
  String jsonObject = String("{\"value1\":\"") + NAME + "\",\"value2\":\"" + ID + "\"}";
  client.println(String("POST ") + resource2 + " HTTP/1.1");
  client.println(String("Host: ") + server);
  client.println("Connection: close\r\nContent-Type: application/json");
  client.print("Content-Length: ");
  client.println(jsonObject.length());
  client.println();
  client.println(jsonObject);

  int timeout = 5 * 10; // 5 seconds
  while (!!!client.available() && (timeout-- > 0)) {
    delay(100);
  }
  if (!!!client.available()) {
    Serial.println("No response...");
  }
  while (client.available()) {
    Serial.write(client.read());
    
    //Print on display the ID that enter
    display.clearDisplay();
    display.setCursor(5,30);
    display.println("Door sensor was open (IFTTT)");
    display.display();
    delay(3000);
    display.clearDisplay();
  }
  Serial.println("\nclosing connection");
  client.stop();
}
``` 


