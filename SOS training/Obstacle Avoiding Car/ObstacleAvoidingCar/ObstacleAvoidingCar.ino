// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;

// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

// ultrasonic sensor
const int trig = 11;
const int echo = 12;

// necessory variables
long duration, inches, cm, distance;

void setup()
{
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() 
{
  CheckDistance();
  Serial.println(distance);
  
  if(distance<50)
  {
    Stop();
  }
  if(distance>50)
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
}

void Stop()
{
   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
   analogWrite(enA, 0);
   
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);
   analogWrite(enB, 0);

   delay(500);
}

/*
void MoveBackward()
{
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  analogWrite(enA, 150);
  
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  
  analogWrite(enB, 150);
}
void MoveLeft()
{ 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW); 
  analogWrite(enA, 150);
  analogWrite(enB, 0);
}

void MoveRight()
{
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  analogWrite(enB, 150);
  analogWrite(enA, 0);
}
*/
