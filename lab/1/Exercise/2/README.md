# Exercice 2

## Turning on/off an LED in port 4

For this step, first, it doesn't work with the port 4.

Why? Because the program setup only the port 6 ! And we connect the led on the port 4.

So, the solution is : we need to setup the port 4 as output to make the circuit work. So we just need to change few lines in our first code in Exercice 1.

## Code

The only change you can see is "const int led = 4" now to change the output.

```C
const int led = 4;
 
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
The only one change that differt from the first exercice that we change the wire in the port 4 instead of 6.
![image](https://github.com/Gaffeur/IoT_TP1/blob/main/LabOne/Exercise/2/Exercice%202.jpg)
