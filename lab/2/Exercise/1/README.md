# Exercise 1

## Read a value from Serial Monitor

So, in this exercise the aim was to modify the value of the stone by using the Serial Monitor for the arduino IDE. To do this, we should initialize the discussion. Then in the loop, we must wait that a communication come, find the type (between int or byte) and use the new value to setup the buzzer.


## Code provided

```C
const int buzzer = 5;

void setup() {
 
  Serial.begin(9600); // initialize the serial discussion
}

void loop() {

    // wait for a discussion
    while(Serial.available() > 0) {

      //here we need to send a new value for the frequency with the serial monitor

      int i  = Serial.parseInt();    // look for the next valid integer in the incoming serial stream:
      byte b = Serial.read();    // look for the next valid byte in the incoming serial stream:


      if (i != 0){
        tone(buzzer,i); // set the value of the tone with the argument giving by the serial monitor
        delay(1000);
        Serial.print("Everything is working"); // response from the arduino card

      }
    }
}

```
## Image
This is the same circuit as the [exercise 6](https://github.com/Gaffeur/IoT_TP1/tree/main/LabOne/Exercise/6) in the TP1. We only connect the buzzer to the arduino card.

![Image](https://github.com/Gaffeur/IoT_TP1/blob/main/LabTwo/Exercise/1/Buzzer.jpg)
