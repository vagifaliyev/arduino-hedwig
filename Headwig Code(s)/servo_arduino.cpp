#include <Servo.h>  // Servo library

Servo myservo;        // The servo object
int servoPin = 9;     // The control pin that we're using to control the servo motor

int incomingByte = 0; // used to hold the byte that comes from Processing

/**
 *
 * setup
 *
 * run once when the program starts
 *
 * used to initialise variables, servo objects etc.
 */
void setup() 
{
  // tell the arduino which pin we're using to control the servo
  myservo.attach(servoPin);
  
  // set up our connection to Processing at the given baud rate
  Serial.begin(9600);  
}



/**
 *
 * loop
 *
 * run all the time after the program starts
 *
 * used to recieve incoming byte and move the servo according to incoming byte
 */
void loop() 
{
  if (Serial.available() > 0) // if something is being detected
  {
    // read the incoming byte:
    incomingByte = Serial.read();
    if (incomingByte == 1)
    {  
     // 1 = value that is comming from processing -> rotate clockwise    
         myservo.write(180);
    }

    if (incomingByte == 2)
    {
      // 2 = value that is comming from processing -> rotate anticlockwise    
         myservo.write(0);
    } 
    if (incomingByte == 3)
    {
            // 3 = value that is comming from processing -> stop the motor    
         myservo.write(90);
    }
  } 
}