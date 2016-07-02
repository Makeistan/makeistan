// ultrasonic sensor
const int VCC = 10;
const int trig = 11;
const int echo = 12;
const int GND = 13;

// necessory variables
long duration, inches, cm, distance;

void setup()
{
  pinMode(VCC,OUTPUT);
  pinMode(GND,OUTPUT);
  
  digitalWrite(VCC,HIGH);
  digitalWrite(GND,LOW);
  
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  CheckDistance();

  if(distance>15)                  //Check if distance is greater then 15 centimeter
  {
    //dshjfdsadfghj
  }

  Serial.println(cm);
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
  delay(500);
}
