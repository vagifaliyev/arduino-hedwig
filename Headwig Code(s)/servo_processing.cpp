import processing.serial.*;

Serial myPort;

color colorButtonR = #222222; // color of right button
color colorButtonL = #222222; // color of left button
color colorButtonM = #000000; // color of middle button


void setup()
{
  size(400, 300);  // size of the window
  
  println(Serial.list()); // print serial list and select the correct one 
  
  myPort = new Serial(this, Serial.list()[5], 9600);  // connecting to serial 
  
  noStroke(); // Disables drawing the stroke (outline)
  smooth(); // improve image quality.

}

void draw()
{
  background(0); // set background color
  
  // create and fill the right button
  fill(colorButtonR); 
  rect(width-100, 0, 100, height);
  
  // create and fill the left button
  fill(colorButtonL); 
  rect(0, 0, 100, height);
  
   // create and fill the left button
  fill(colorButtonM); 
  rect(width-300, 0, 200, height);
  
  
  if(mouseX<100) // if left button is pressed 
  {
    cursor(HAND);
    if(mousePressed)
    {
      // change the color of the button to indicate that the it is being pressed
      colorButtonL = #284c56;
      myPort.write(1);  // send 1 to the serial port
    }
    else
    {
      colorButtonL = #222222; // if not pressed color it back to original 
    }  
  }
  else if(mouseX>width-100) //if right button pressed
  {
    cursor(HAND);
    if(mousePressed)
    {    
      // change the color of the button to indicate that the it is being pressed
      colorButtonR = #284c56; 
      myPort.write(2);  // send 2 to the serial port    
    }
    else
    {
      colorButtonR = #222222;  // if not pressed color it back to original 
    }  
  }
  else if(mouseX<width-100 & mouseX>100) //if middle button pressed
  {
    cursor(HAND);
    if(mousePressed)
    {    
      // change the color of the button to indicate that the it is being pressed
      colorButtonM = #284c56; 
      myPort.write(3);  // send 3 to the serial port    
    }
    else
    {
      colorButtonM = #000000;  // if not pressed color it back to original 
    }  
  }
  else
  {
    cursor(ARROW);
  }  
}