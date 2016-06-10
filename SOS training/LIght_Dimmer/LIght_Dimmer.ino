const int ledPin= 9;
const int dimmerPin=A0;
int dimmerValue=0;

void setup() {
pinMode(ledPin, OUTPUT);

}

void loop() {
   dimmerValue=analogRead(dimmerPin);
   analogWrite(ledPin,dimmerValue);
   delay(50);
  // put your main code here, to run repeatedly:
}

