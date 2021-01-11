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
