# Exercice 5

## Write an Analog Value
The circuit is the same as the Exercice 1 and 2. 

The objective here, is to turn of the LED gradually, increase in intensity in the LED. 

Starting with the LED turn off, after turn on a little the LED and the light will grow more and more. 

We use the principle of fading in this exercice.

## Code

```C
const int led =  13; //LED on Arduino but we use a another LED
int value = 0;

void setup() {
 
  pinMode(led, OUTPUT);
  
}
void loop() {

    while(value <= 255){ // loop While to grow up the value, so the intensity of the LED
    analogWrite(led, value);
    value += 10;
    delay(100);
    }
    value = 0;

}
```

## Image 
Same image for Exercice 1 & 2 but the principle is different
![Image](https://github.com/Gaffeur/IoT_TP1/blob/main/LabOne/Exercise/5/Exercice5.jpg)
