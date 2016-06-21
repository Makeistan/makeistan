
#include <Servo.h>
void SmallMotor(); //declaring function names that will be explained below
void BigMotor();

//declaring the servos on arduino pins
int BigMotorPin = 10;//Pin 10 of Arduino
int SmallMotorPin = 9;//Pin 9 of Arduino
Servo SmallMotorVal, BigMotorVal;//servo Names
int bigMotorValue=0; /*variable to be incremented by 3 each time
to make 3 degree shifts each time*/
void setup()
{
  BigMotorVal.attach(BigMotorPin);//Attaching motor to pin
  SmallMotorVal.attach(SmallMotorPin);//Attaching motor to pin
  Serial.begin(9600);//of no use
}
void loop(){
  /*the program will run 25 times.
  It means that the servos will rotate 25 times according to the
  program written*/
  
  for(int i=0;i<=25;i++){

    BigMotor(900);//delay 900ms after each 3 degree shift
    delay(200);
    SmallMotor(500); //delay 500ms after each 180 to 10 degree shift

  }
  bigMotorValue=0; /*change BigMotor angle
  to 0 degree after running the program 25 time*/
  delay(5000);//delay 5 seconds after pattern is completed
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
void BigMotor(int delayTime){
  bigMotorValue+=3;//increment angle shift of 3 degree each time.
  int reading1 = bigMotorValue;
 
  // 0 to 180-ish
  
  //Large servo will rotate 3 degree each time
  //Just change the degrees and shape formed will be different
  BigMotorVal.write(reading1);
  delay(delayTime);

}

