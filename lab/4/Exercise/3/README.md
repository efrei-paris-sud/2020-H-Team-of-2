# Exercice 3

## Thingspeak platform

After installing the ESP32, we just need to put the same code the same way as the Lab 1. We just need to change the pin of LED we choose on the ESP 32. After that we charge the code on the ESP 32 and it's working fine
There is no issue during this exercice

## Code WriteSingleField

```C

#include "ThingSpeak.h"
#include "secrets.h"
#include <WiFi.h>

char ssid[] = SECRET_SSID;   // your network SSID (name) 
char pass[] = SECRET_PASS;   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;

unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

const int potentialPin = 39;
int number = 0;

void setup() {
  Serial.begin(115200);  //Initialize serial

  WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Initialize ThingSpeak

  pinMode(potentialPin, OUTPUT);

}

void loop() {

  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }

 number = analogRead(potentialPin);
  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
  // pieces of information in a channel.  Here, we write to field 1.
  int x = ThingSpeak.writeField(myChannelNumber, 1, number, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  
  // change the value
  
  
  
  if (number>1024) {
    number = 0;
  }
  delay(20000); // Wait 20 seconds to update the channel again
}
 ```
 
 ## Code Secret
 
```C

// Use this file to store all of the private credentials 
// and connection details

#define SECRET_SSID "lucke77"		// replace MySSID with your WiFi network name
#define SECRET_PASS "27121999"	// replace MyPassword with your WiFi password

#define SECRET_CH_ID 1252108			// replace 0000000 with your channel number
#define SECRET_WRITE_APIKEY "VWAGHVFJU64HAQOW"   // replace XYZ with your channel write API Key

 ```
 
## Image
We can see the result of the first exercice below in this image.
![Image](https://github.com/efrei-paris-sud/2020-H-Team-of-2/blob/main/lab/4/Exercise/1/Ex1.jpg)

