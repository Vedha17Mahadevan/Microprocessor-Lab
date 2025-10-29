#include <Servo.h>

Servo myServo;
int servoPin = 10;   
int ledPin = 9;   
int angle = 0;     
int brightness = 0; 

void setup() {
  myServo.attach(servoPin);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (angle = 0; angle <= 180; angle += 10) {
    myServo.write(angle);
    brightness = map(angle, 0, 180, 0, 255);
    analogWrite(ledPin, brightness);
    delay(100);
  }

  for (angle = 180; angle >= 0; angle -= 10) {
    myServo.write(angle);
    brightness = map(angle, 0, 180, 0, 255);
    analogWrite(ledPin, brightness);
    delay(100);
  }
}
