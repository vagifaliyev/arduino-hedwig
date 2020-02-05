#include <Servo.h>

long int rsensorpin = A0;    // analog input pin for right sensor
long int rsensorvalue = 0; // variable to store the value of right sensor

long int lsensorpin = A1;    // analog input pin for left sensor
long int lsensorvalue = 0;   // variable to store the value of left sensor

long int difference = 0;

void setup()
{
   // set up our connection to Processing at the given baud rate
   Serial.begin(115200);
}

void loop()
{
  
  rsensorvalue = analogRead(rsensorpin); // read right sensor value
  
  lsensorvalue = analogRead(lsensorpin); // read left sensor value 
  
  difference = rsensorvalue - lsensorvalue; // calculate the difference of the values
  
  Serial.print(rsensorvalue);
  Serial.print(" and, ");
  Serial.print(lsensorvalue);
  Serial.print(", difference is ");
  Serial.println(difference);

  delay(100);

}