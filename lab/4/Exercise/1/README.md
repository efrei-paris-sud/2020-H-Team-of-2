# Exercice 1

## Installing ESP32 Add-on in Arduino IDE & Upload blinking LED code

After installing the ESP32, we just need to put the same code the same way as the Lab 1. We just need to change the pin of LED we choose on the ESP 32. After that we charge the code on the ESP 32 and it's working fine
There is no issue during this exercice

## Code provided

```C
#include <Arduino.h>
#include <oled.h>
const int led = 12;
 
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}
 
// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);      // turn the LED on (HIGH is the voltage level)
  delay(500);                  // wait for a second
  digitalWrite(led, LOW);       // turn the LED off by making the voltage LOW
  delay(500);                  // wait for a second
}
 ```

## Image
We can see the result of the first exercice below in this image.
![Image](https://github.com/Gaffeur/IoT_TP1/blob/main/LabOne/Exercise/1/Exercice%201.jpg)

