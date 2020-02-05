/****************************************
Sound Meter LED matrix 8x8 for the 
Adafruit Microphone Amplifier
****************************************/

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

// Include the Matrix code for display

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

const int maxScale = 8;
const int redZone = 4;

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample; 

void setup() 
{
   Serial.begin(9600);  // set serial speed connection 

   matrix.begin(0x70);  // pass in the address
}


void loop() 
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level

   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;

   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(2); 
      if (sample < 1024)  // get rid of unrealistic values
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the MAX levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the MIN levels
         }
      }
   }
   
   peakToPeak = signalMax - signalMin;

   // maping the peakTopeak values from 0 to maxScale for determining which LED has
   // to be turnend on
   
   int displayPeak = map(peakToPeak, 0, 1023, 0, maxScale);

   // Update the display:
   
   for (int i = 0; i < 7; i++)  // shift the display left
   {
      matrix.displaybuffer[i] = matrix.displaybuffer[i+1];
   }

   // draw the new sample
   for (int i = 0; i <= maxScale; i++)
   {
      if (i >= displayPeak)  // blank these pixels
      {
         matrix.drawPixel(i, 7, 0);
      }
      else if (i < redZone) // draw in yellow
      {
         matrix.drawPixel(i, 7, LED_YELLLOW;
      }
      else // Red Alert!
      {
         matrix.drawPixel(i, 7, LED_RED;
      }
   }
   matrix.writeDisplay();  // write the changes we just made to the display
}