#include <Servo.h>
const int rainPin = A0;      
const int buttonOpen = 2;    
const int buttonClose = 3;   
const int ledPin = 13;       
const int servoPin = 9;      

Servo myServo;

int posOpen = 0;    
int posClose = 180; 
int threshold = 500; 

void setup() {
  pinMode(rainPin, INPUT);
  pinMode(buttonOpen, INPUT_PULLUP); 
  pinMode(buttonClose, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  
  myServo.attach(servoPin);
  myServo.write(posOpen); 
  
  Serial.begin(9600);
}

void loop() {
  int rainValue = analogRead(rainPin);
  bool btnOpenState = digitalRead(buttonOpen);
  bool btnCloseState = digitalRead(buttonClose);

  if (rainValue < threshold) { 

    myServo.write(posClose);
    digitalWrite(ledPin, HIGH); 
    Serial.println("Troi mua! Dang thu quan ao...");
  } 
 
  else {
    digitalWrite(ledPin, LOW);
    
    if (btnOpenState == LOW) { 
      myServo.write(posOpen);
      Serial.println("Nut nhan: Dang phoi do.");
      delay(200); 
    }
    
    if (btnCloseState == LOW) { 
      myServo.write(posClose);
      Serial.println("Nut nhan: Dang thu do.");
      delay(200);
    }
  }

  delay(100); 
}