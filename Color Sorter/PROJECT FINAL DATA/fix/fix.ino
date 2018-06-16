
#include <Servo.h>
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
Servo topServo;
Servo bottomServo;
int frequency = 0;
int color=0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  topServo.attach(7);
  bottomServo.attach(8);
  Serial.begin(9600);
}
void loop() {
  topServo.write(105);
  delay(500);
  
  for(int i = 105; i > 58; i--) {
    topServo.write(i);
    delay(15);
  }
  delay(1000);
  
  color = readColor();
  delay(10);  
  switch (color) {
    case 1:
    bottomServo.write(50);
    break;
    case 2:
    bottomServo.write(75);
    break;
    case 3:
    bottomServo.write(100);
    break;
    case 4:
    bottomServo.write(125);
    break;
    
    case 0:
    break;
  }
  delay(300);
  
  for(int i = 58; i > 29; i--) {
    topServo.write(i);
    delay(15);
  } 
  delay(1000);
  
  for(int i = 29; i < 105; i++) {
    topServo.write(i);
    delay(15);
  }
  color=0;
}
// Custom Function - readColor()
int readColor() {
  color = 0;
  while(color == 0){
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  
  delay(50);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  
  delay(50);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  delay(50);
  if(R<800 & R>750 & G<1600 & G>1500){
    color = 1; // Red
    Serial.print(1,DEC);
  }
  else if(R<1100 & R>1000 & G<1100 & G>1000){
    color = 2; // Green
    Serial.print(2,DEC);
  }
  else if(R<600 & R>500 & G<800 & G>700){
    color = 3; // Yellow
    Serial.print(3,DEC);
  }
  else if (G<1010 & G>900 & B<700 & B>600){
    color = 4; // Blue
    Serial.print(4,DEC);
  }
  }
  delay(500);
  return color; 
}
