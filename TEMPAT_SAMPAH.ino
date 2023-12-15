#include <HCSR04.h>
int buzz = 4;
#include <Servo.h>

Servo myservo;
UltraSonicDistanceSensor distanceSensor(3, 2); 
int pos = 0;
void setup () {
  Serial.begin(9600);  
  pinMode(buzz, OUTPUT);
  myservo.attach(10);
  myservo.write(120);
}

void loop () {
  Serial.println(distanceSensor.measureDistanceCm());
  if (distanceSensor.measureDistanceCm() <= 10.00) {
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(100);
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(100);
    myservo.write(0);
    delay(3000);
  } else {
    digitalWrite(buzz, LOW);
    myservo.write(120);
  }
}
