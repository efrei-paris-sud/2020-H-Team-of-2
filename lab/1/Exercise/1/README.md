# Exercice 1

## Turning on/off an LED

We did the same thing as the image and put the code provided in the arduino to turn on the LED

## Code provided

```C
const int led = 6;
 
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}
 
// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);      // turn the LED on (HIGH is the voltage level)
  delay(1000);                  // wait for a second
  digitalWrite(led, LOW);       // turn the LED off by making the voltage LOW
  delay(1000);                  // wait for a second
}
 ```

## Image
We can see the result of the first exercice below in this image
![Image](https://github.com/Gaffeur/IoT_TP1/blob/main/LabOne/Exercise/1/Exercice%201.jpg)

