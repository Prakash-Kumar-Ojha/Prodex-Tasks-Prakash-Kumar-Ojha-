#include <Servo.h>
Servo horizontalServo; 
Servo verticalServo;  

int ldrTopLeft = A0;
int ldrTopRight = A1;
int ldrBottomLeft = A2;
int ldrBottomRight = A3;

int horizontalAngle = 90;
int verticalAngle = 90;

int threshold = 20;

void setup() {
  Serial.begin(9600);
  
  
  horizontalServo.attach(10);
  verticalServo.attach(9);
  
  horizontalServo.write(horizontalAngle);
  verticalServo.write(verticalAngle);
}

void loop() {
  int tl = analogRead(ldrTopLeft);
  int tr = analogRead(ldrTopRight);
  int bl = analogRead(ldrBottomLeft);
  int br = analogRead(ldrBottomRight);
  
  
  int avgTop = (tl + tr) / 2;
  int avgBottom = (bl + br) / 2;
  int avgLeft = (tl + bl) / 2;
  int avgRight = (tr + br) / 2;


  int verticalDifference = avgTop - avgBottom;
  if (abs(verticalDifference) > threshold) {
    if (avgTop > avgBottom) {
      verticalAngle++;
    } else {
      verticalAngle--;
    }
    verticalServo.write(verticalAngle);
  }

  int horizontalDifference = avgLeft - avgRight;
  if (abs(horizontalDifference) > threshold) {
    if (avgLeft > avgRight) {
      horizontalAngle--; 
    } else {
      horizontalAngle++;
    }
    horizontalServo.write(horizontalAngle);
  }

  delay(100);
}

