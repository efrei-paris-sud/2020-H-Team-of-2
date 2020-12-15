# Exercice 6

## Buzzer

Now in this exercice we use a Buzzer. 

Our objective is to turn ON the buzzer with a duration and a frequency that we provide.

After we decide to turn OFF the buzzer during 5000ms. And the loop will continue to do this action.

## Code

```C
void setup() {

}

void loop() {

    tone(5, 100); // Turn ON the buzzer on the port 5 with a frequency equal to 100Hz
    delay(1000); // Wait 1000ms
    noTone(5); //Turn OFF the buzzer on the port 5
    delay(5000); // Wait 5000ms
}
```

## Image
![Example](https://github.com/efrei-paris-sud/2020-H-Team-of-2/blob/main/lab/1/Exercise/6/Buzzer.jpg)
