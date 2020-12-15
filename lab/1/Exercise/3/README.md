# Exercice 3 

## Read a Digital Value
The objective is to turning the LED on the Arduino with the help of a button.

But we decide directly to use a LED on the circuit.

When we press the button the LED turn on and when we release the pression on the button the LED turn off.

## Code


 ```C
const int buttonPin = 6; // The button port
const int led = 4; // the LED port

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
  buttonState = digitalRead(buttonPin);     
}
 
// the loop routine runs over and over again forever:
void loop() {

  if (buttonState == HIGH)
  {
  digitalWrite(led, HIGH);   
    }
  else{
    digitalWrite(led, LOW);
    }
}
```

## Image
We forgot to take the image of the circuit but we did the same circuit in the Lesson 6 with an additional LED.
