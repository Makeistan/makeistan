
#include <Servo.h>
void SmallMotor(); //declaring function names that will be explained below

//declaring the servos on arduino pins

int SmallMotorPin = 10;//Pin 9 of Arduino
Servo SmallMotorVal;//servo Names

void setup()
{
  
  SmallMotorVal.attach(SmallMotorPin);//Attaching motor to pin
  Serial.begin(9600);//of no use
}
void loop(){
  /*the program will run 25 times.
  It means that the servos will rotate 25 times according to the
  program written*/
  
  for(int i=0;i<=25;i++){

    SmallMotor(500); //delay 500ms after each 180 to 10 degree shift

  }
  
}
void SmallMotor(int delayTime)
{     // The small will draw arc of described angle
  int angle1 = 120;
  // 0 to 180-ish


  SmallMotorVal.write(angle1);//making an angle shift of 180 degree each time
  delay(delayTime);
  SmallMotorVal.write(10);  //shifting angle to 10 degree
  //the servo will start from 10 degree just to protect servo gear from shocks
  delay(delayTime);

}

