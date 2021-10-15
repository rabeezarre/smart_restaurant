#include <Ultrasonic.h>

Ultrasonic ultrasonic(6, 7);
int IN3 = 5; // Input3 подключен к выводу 5 
int IN4 = 4;
int ENB = 3;
int s = 50;
int cm;
int temp;
void setup()
{
 pinMode (ENB, OUTPUT); 
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);
 Serial.begin(9600);
}
void loop(){
  Serial.print("Distance in CM: ");
  Serial.println(ultrasonic.distanceRead());
  cm = ultrasonic.distanceRead();
  delay(500);
if ((cm<10)&&(temp == 0)) {
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite(ENB,s);
  delay(3000);
  digitalWrite (IN3, 0);
  digitalWrite (IN4, 0);
  temp = 1;
}

else if ((cm>10)&&(temp == 1)) {
  digitalWrite (IN3, 0);
  digitalWrite (IN4, 1);
  analogWrite(ENB,s);
  delay(3000);
  digitalWrite (IN3, 0);
  digitalWrite (IN4, 0);
    temp = 0;
}

}
