
#include <Servo.h>

Servo lservo; 
Servo rservo; 

void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);

  lservo.attach(9);
  rservo.attach(11);
  lservo.write(90);
  rservo.write(90);
}

unsigned char x,y,z,j =0;
int val = 0;

void loop()
{
  if (Serial.available() >= 4) {
    x = Serial.read();        
    y = Serial.read();   
    z = Serial.read();   
    j = Serial.read();   

    if (j == 7) { // HandLeft
      lservo.write(180-y);                  // sets the servo position according to the scaled value 
      delay(10);                           // waits for the servo to get there 
    }

    if (j == 11) { // HandRight
      rservo.write(y);                  // sets the servo position according to the scaled value 
      delay(10);                           // waits for the servo to get there 
    }

  }
}








