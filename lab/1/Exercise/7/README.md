# Exercice 7

## Fun: RGB LED

In this lesson, we learn how to use a RGB (Red Green Blue) LED with an Arduino.

We will use the analogWrite function of Arduino to control the color of the LED.

The LED has 4 pins, 3 for primary colors and the last for the ground.

We create a function to define the color of each pin.

After that, in the loop we just play with the modulation between the 3 colors.

## Code

```C
const int ledR =  11;
const int ledG =  10;
const int ledB =  9;

void setup() {
 
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);

}

void loop() {

    setColor(20,10,48);
    delay(2000);

    setColor(150,100,55);
    delay(2000);

    setColor(80,129,79);
    delay(2000);

    setColor(38,200,179);
    delay(2000);

    setColor(70,120,120);
    delay(2000);
}

void setColor(int red, int green, int blue){

  analogWrite(ledR, red);
  analogWrite(ledG, green);
  analogWrite(ledB, blue);
}
```
## Image
![Image](https://github.com/efrei-paris-sud/2020-H-Team-of-2/blob/main/lab/1/Exercise/7/RGB.jpg)
