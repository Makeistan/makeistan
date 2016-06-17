/* collisiondetection.ino
 *   
 * Detects the distance using HC-SR04 UltraSonic Sensor
 * If the distance is less than the given amount
 * a buzzer is played.
 *  
 *    
 *  The circuit:
 * VCC connection of the sensor attached to +5V
 * GND connection of the sensor attached to ground
 * TRIG connection of the sensor attached to digital pin 2
 * ECHO connection of the sensor attached to digital pin 4
 *  Original code for Ping))) example was created by David A. Mellis
 *  Adapted for HC-SR04 by Tautvidas Sipavicius
 *  This example code is in the public domain.
 */


const int trigPin = 12;
const int echoPin = 13;
const int buzzerPin = 8;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  // prints the distance
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if (cm <= 4) {
    buzz();
    Serial.println("Object Detected");
  } else {
    Serial.println("No object detected");  
  }
  
  delay(100);
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

void buzz () {
  tone(buzzerPin, 400); // play 400 Hz tone for 500 ms
  delay(500);
  tone(buzzerPin, 800); // play 800Hz tone for 500ms
  delay(500);
  tone(buzzerPin, 400); // play 400 Hz tone for 500 ms
  delay(500);
  tone(buzzerPin, 800); // play 800Hz tone for 500ms
  delay(500);
  tone(buzzerPin, 400); // play 400 Hz tone for 500 ms
  delay(500);
  tone(buzzerPin, 800); // play 800Hz tone for 500ms
  delay(500);
  noTone(buzzerPin);
}
