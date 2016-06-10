int frequencies1 []= {262, 294, 330};
int frequencies2 []= {349, 392, 415};
int frequencies3 []= {440, 466, 740};
int frequencies4 []= {784, 831, 988};
int frequencies5 []= {1109, 1175, 2093};
const int buzzerPin= 9;

int buttonState=0;
int buttonState2=0;
int buttonState3=0;
int buttonState4=0;
int buttonState5=0;

void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(buzzerPin,OUTPUT);
for (int i=0; i<3; i++)
{
  tone(buzzerPin,frequencies1 [i], 500);
  Serial.begin(9600);
  delay(500);
   
  }
}

void loop() {

  buttonState=digitalRead(2);
  buttonState2=digitalRead(3);
  buttonState3=digitalRead(4);
  buttonState4=digitalRead(5);
  buttonState5=digitalRead(6);
  Serial.println(buttonState);
  Serial.println(buttonState2);
  Serial.println(buttonState3);
  Serial.println(buttonState4);
  Serial.println(buttonState5);
   if(buttonState==1){
    
    for (int i=0; i<3; i++)
{
  tone(buzzerPin,frequencies1 [i], 500);
  
  delay(500);
   
  }} 
   if(buttonState2==1){
    
    for (int i=0; i<3; i++)
{
  tone(buzzerPin,frequencies2 [i], 500);
  
  delay(500);
   
  }} 
   if(buttonState3==1){
    
    for (int i=0; i<3; i++)
{
  tone(buzzerPin,frequencies3 [i], 500);
  
  delay(500);
   
  } }
   if(buttonState4==1){
    
    for (int i=0; i<3; i++)
{
  tone(buzzerPin,frequencies4 [i], 500);
  
  delay(500);
   
  }} 
   if(buttonState5==1){
    
    for (int i=0; i<3; i++)
{
  tone(buzzerPin,frequencies5 [i], 500);
  
  delay(500);
   
  } 
   }
 
 delay(500); // put your main code here, to run repeatedly:
   }
