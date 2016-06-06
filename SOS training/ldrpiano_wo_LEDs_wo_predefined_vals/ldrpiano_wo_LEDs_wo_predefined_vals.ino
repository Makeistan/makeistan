const int buzzerPin= 9;
const int ldrPin=A0;
int ldrValue=1;


void setup() {
  // put your setup code here, to run once:
for (int i=0; i<15; i++)
{
  tone(buzzerPin,ldrValue*100, 500);
}
  
  Serial.begin(9600);
}

void loop() {
   ldrValue=analogRead(ldrPin);
   Serial.println(ldrValue);
   frequency=ldrValue;
   tone(buzzerPin,frequency, 500);
   delay(50);
  // put your main code here, to run repeatedly:
}

