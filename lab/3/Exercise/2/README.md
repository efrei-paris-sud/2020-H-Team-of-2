# Exercise 2

In this exercise, the aim was to find the code of an example that was displaying many thing (bitmap and figures) on the screen. Then, we had to understand how the code was working in order to be able
to do it by ourselves.

## Display shapes and bitmaps

The example is displaying many figures one after another. So first we need to connect the arduino to the oled. For this we use display.begin(SH1106_SWITCHCAPVCC, 0x3C) 
(name of the display, its address). Then we clear the display (with display.clearDisplay) in case we are making a loop to erase everything that was on the screen.

Now, let’s see some functions. For example, to draw a circle you can use the method fillCircle. In parameters you need to pass the coordinates for the center point: x and y, 
then the radius and finally the color of the circle. 

To launch the display you need to call the method display (so display.display) to display your image. 
In the example, some functions don't need any parameters because they are Overwrite in method, for example testdrawcircle() will draw the same circle as 
fillCircle(display.width()/2, display.height()/2, 10, WHITE).

So you can draw a triangle with testdrawtriangle() or with drawTriangle(x1,x2,x3,x4,x5,x6,COLOR). 
