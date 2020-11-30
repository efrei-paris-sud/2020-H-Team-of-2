# Exercise 2

## Understand the I2C communciation

In this question, we need to read and understand how works the I2C communication. 

This protocol works with 2 channels, one for the clock (named SCL for synchronous clock line) and the other for the transmission of data (named SDA for synchronous data line).
In this protocol, one device would be the master and would give an action for each other devices that will be called "slaves". If the master want information, he will say 
to the correct device, to send him information on X bytes and then he will wait. Because just the correct device uses the SDA channel, the information won't be loose or face an 
information in the opposite direction.

Finally, the pin for the SDA is the pin A4 on the arduino card.
And for the SCL it's the pin A5. 

We find this information from the schema of the arduino card in the TP1.
