# Exercice 4

## Read an Analog Value

In this exercice, we will use a potentiometer. 

With the help of the potentiometer we will change the delay to turning ON and OFF the LED on the Arduino. 

This delay will increase when we continue to turn the potentiomer. 

The delay can be faster or slower.

The potentiometer is connect on the port 0, the LED port 13 is the LED that is already on the Arduino.

And we need to create a value the will change and take the value from the position of the potentiometer.
## Code 

  ```C
const int potentialPin = 0; // Potentiometer connect on the port 0
const int led =  13; // This is the LED that is already on the Arduino
int value = 0; // Starting value that we will evolve when we turn the Potentiometer

void setup() {
 
  pinMode(led, OUTPUT); // The state of the LED
  pinMode(potentialPin, INPUT); // The state of the Potentiometer
  
}
void loop() {

    value = analogRead(potentialPin); // Constantly read the state of the Potentiometer
    
    digitalWrite(led, HIGH);
    delay(value);
    digitalWrite(led, LOW);
    delay(value);


}
```
## Image
![Example](https://github.com/efrei-paris-sud/2020-H-Team-of-2/blob/main/lab/1/Exercise/4/Exercice4.jpg)
