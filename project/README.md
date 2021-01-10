
# Smart Lock

 **Description**: Our project name is Smart Lock. It will be a lock (for a door for example) that will work with a fingerprint system. 
 
For the cloud part, the access will be manage through a database and not directly in the Arduino card. 

It will allow us to modify permission with our interface that will probably be a web site. We will implement a door sensor that will allow us to know if someone open or close the door without using the fingerprint system. It will work like an alarm. If needed, it will send a notification.

 - [x] When the fingerprint module will detect a good fingerprint it will open the lock. If it's not good it will not open.
 - [x] If the alarm is still trigger and the door sensor detect that the door is open, it will send a notification.
 - [x] We will manage a part of the database from a web site.
 - [x] The transmission will use an ESP 8266 for the Wi-Fi connection.

Please use a gif format for the cover photo like this: (you can create gif using https://ezgif.com/maker)
![Cover GIF](doc/Arduino_LED.gif?raw=true)


[Team Report]

[Team Presentation]

# Working Video

 [![Example Video of the porject](https://img.youtube.com/vi/ucZl6vQ_8Uo/0.jpg)](https://www.youtube.com/watch?v=ucZl6vQ_8Uo)

# Components

You can find below the list of components that we used. We put the link for the component that we needed to buy, the others were present in the Arduino starter kit that we have. 

- 1 x [Battery case](https://www.amazon.fr/ADAPTATEUR-SUPPORT-PILES-BATTERY-HOLDER/dp/B06XWSFY7X/ref=sr_1_6?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=1DLSEWX17195H&dchild=1&keywords=pile+arduino&qid=1610280721&sprefix=pile+ardui%2Caps%2C143&sr=8-6) (1)
- 1 x [ESP32](https://www.amazon.fr/AZDelivery-ESP-32-Dev-compris-eBook/dp/B07Z83MF5W/ref=sr_1_3_sspa?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dchild=1&keywords=ESP32&qid=1609856750&sr=8-3-spons&psc=1&smid=A1X7QLRQH87QA3&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUFMTkxaWDU0SVMzSUYmZW5jcnlwdGVkSWQ9QTA0NzM1NjIyUjQ4U0tKSTQyREtJJmVuY3J5cHRlZEFkSWQ9QTA1NTUzMDQyQlgwNVlZR1YxN0gxJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==) (2)
- 1 x [Fingerprint Reader AS608](https://www.banggood.com/fr/AS608-Fingerprint-Reader-Sensor-Module-Optical-Fingerprint-Module-Locks-Serial-Communication-Interface-p-1565798.html?rmmds=search&cur_warehouse=CN) (3)
- 1 x [Door Sensor MC 38](https://www.amazon.fr/ARCELI-D%C3%A9tecteur-Fen%C3%AAtre-Filaire-Magn%C3%A9tique/dp/B07DN21G36/ref=sr_1_3?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dchild=1&keywords=MC-38&qid=1607008136&sr=8-3) (4)
- 1 x [Electronic lock](https://fr.aliexpress.com/item/32820530084.html?src=google&albch=shopping&acnt=248-630-5778&isdl=y&slnk=&plac=&mtctp=&albbt=Gploogle_7_shopping&aff_atform=google&aff_short_key=UneMJZVf&gclsrc=aw.ds&&albagn=888888&&ds_e_adid=438856512841&ds_e_matchtype=&ds_e_device=c&ds_e_network=u&ds_e_product_group_id=743612850874&ds_e_product_id=fr32820530084&ds_e_product_merchant_id=107793888&ds_e_product_country=FR&ds_e_product_language=fr&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&ds_dest_url=https://fr.aliexpress.com/item/32820530084.html?&albcp=10191220517&albag=107473525088&gclid=Cj0KCQiA5bz-BRD-ARIsABjT4ngLcrbz76fVJdS3s3NXZILdxpqviB7cDmCuHv-OyQ5QIJkoy1qYk40aAn1sEALw_wcB) (5)
- 1 x [LCD OLED i2C](https://www.amazon.fr/azdelivery-64-Pixel-pouces-Arduino-Raspberry/dp/B078J78R45/ref=sr_1_2_sspa?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=JL1P23KVWKIV&dchild=1&keywords=lcd+arduino&qid=1609857311&sprefix=LCD+a%2Caps%2C162&sr=8-2-spons&psc=1&smid=A1X7QLRQH87QA3&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUFOODYzMlhOOUlMWVgmZW5jcnlwdGVkSWQ9QTEwMTcwNTUySzlZRlY2OUFCWlMxJmVuY3J5cHRlZEFkSWQ9QTAxODUxNjU1NkxPTFI5SlhFRTkmd2lkZ2V0TmFtZT1zcF9hdGYmYWN0aW9uPWNsaWNrUmVkaXJlY3QmZG9Ob3RMb2dDbGljaz10cnVl) (6)
- 1 x [Push button](https://www.amazon.fr/Youmile-Miniature-Momentary-Commutateur-Bouton-Poussoir/dp/B07Q1BXV7T/ref=sr_1_5?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=1BPEMXFGJT11T&dchild=1&keywords=push+button+arduino&qid=1609857398&sprefix=push+button+%2Caps%2C163&sr=8-5) (7)
- Wires (8)
- 1 x [Relay 5V](https://www.amazon.fr/Keenso-dExtension-D%C3%A9clencheur-Optocoupleur-Arduino/dp/B07Q1H63D6/ref=sr_1_43?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=1QOIYNZW61V32&dchild=1&keywords=relay+5v+arduino&qid=1610284984&sprefix=relay+5v+ar%2Caps%2C152&sr=8-43) (9)
- 1 x Breadboard

# Schematic
![Fritzing](https://github.com/efrei-paris-sud/2020-H-Team-of-2/blob/main/assets/Fritzing%20smarlock%20iot.PNG)

# Overview on the code
Please provide a high level algorithm of your code. if you need to mention some part of the code you can do it like:
```Arduino
	Serial.println('bla bla'); // This line is used to print sth in the serial port
``` 


