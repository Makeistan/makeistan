// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;

// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

// ultrasonic sensor
const int trig = 12;
const int echo = 11;

// necessory variables
long duration, inches, cm, distance;

void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() 
{
  CheckDistance();

  if(distance>15)                  //Check if distance is greater then 15 centimeter
  {
    MoveForward();
  }
}

void CheckDistance()
{  
  digitalWrite(trig, LOW);  
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  
  inches = duration / 74 / 2;     //converts the time duration into inches
  cm = duration / 29 / 2;         //converts the time duration to cm
  distance = cm;
}

void MoveForward()
{
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   analogWrite(enA, 150);
   
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
   analogWrite(enB, 150);
    
   delay(1000);
}
