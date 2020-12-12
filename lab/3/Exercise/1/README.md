# Exercise 1

## Find I2C devices

For the step 1 and 2, the objective was to realize the circuit and install the correct library.
In this question, the aim was to use the code that we have in the example to find the hexadecimal address of our OLED screen. The address was 0x3C. 

## Code

Here you can find the code to scan the address of your I2C devices. We took it from this [link](https://playground.arduino.cc/Main/I2cScanner/).

``` C

#include <Wire.h>
 
 
void setup()
{
  Wire.begin();
 
  Serial.begin(9600);
  while (!Serial);             // Leonardo: wait for serial monitor
  Serial.println("\nI2C Scanner");
}
 
 
void loop()
{
  byte error, address;
  int nDevices;
 
  Serial.println("Scanning...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
 
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
 
  delay(5000);           // wait 5 seconds for next scan
}
```


## Image of the circuit

Here you can see our circuit. We correctly wire the I2C cable by starting of A4 and A5 on this arduino card.

![Image](https://github.com/efrei-paris-sud/2020-H-Team-of-2/blob/main/lab/3/Exercise/1/OLED%20Circuit.jpg)
