# Exercice 3

## Thingspeak platform

Now, it was the biggest part in the TP. We want to read analog values from the potentiometer which is connected to the ESP 32 with the platform Thingspeak.
The informations of the potentiometer are sended by the ESP32 which is connected to my own WIFI. The information are send by internet and they are display on the platform Thingspeak.

You can see the result on the image below that the curve can reach 4096 cause the ESP32 is better than the arduino.

The issue of this exercice is that we didn't realize the right enbranchment and we forgot to change the code to read the analog values.

## Code WriteSingleField

This code was provided in an example of the ESP 32 library. We just change the value that was sending to send the value that we read with the potentiometer.

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
 
 ## Code Secret.h
 
```C

// Use this file to store all of the private credentials 
// and connection details

#define SECRET_SSID "lucke77"		// replace MySSID with your WiFi network name
#define SECRET_PASS "27121999"	// replace MyPassword with your WiFi password

#define SECRET_CH_ID 1252108			// replace 0000000 with your channel number
#define SECRET_WRITE_APIKEY "VWAGHVFJU64HAQOW"   // replace XYZ with your channel write API Key

 ```
 
## Images
We can see the result of the third exercice below in this image.
![Image](https://github.com/efrei-paris-sud/2020-H-Team-of-2/blob/main/lab/4/Exercise/3/Ex3.jpg)

We can see the curve of the third exercice on Thingspeak below in this image.
![Image](https://github.com/efrei-paris-sud/2020-H-Team-of-2/blob/main/lab/4/Exercise/3/Ex3bis.PNG)
