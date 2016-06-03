int frequencies []= {262, 294, 330, 349, 392, 415, 440, 466, 740, 784, 831, 988, 1109, 1175, 2093};
const int buzzerPin= 9;
const int ldrPin=A0;
int ldrValue=0;


void setup() {
  // put your setup code here, to run once:
for (int i=0; i<15; i++)
{
  tone(buzzerPin,frequencies [i], 500);
  Serial.begin(9600);
  delay(500);
   
  }
}

void loop() {
   ldrValue=analogRead(ldrPin);
   Serial.println(ldrValue);
   ldrValue=map(ldrValue,50,800,0,14);
   //Serial.println(ldrValue);
   tone(buzzerPin,frequencies [ldrValue], 500);
   delay(500);
  // put your main code here, to run repeatedly:
}
