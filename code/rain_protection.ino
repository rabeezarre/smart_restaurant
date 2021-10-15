#include <Servo.h>
int rainSensePin= 0; // аналоговый вход 0 для сигнала датчика
int curCounter= 0; // счётчик - инкрементируется на 1 каждую секунду после срабатывания датчика
Servo servomotor;
Servo servomotor1;
int rainPin = A0;
// пороговое значение настраивается тут:
int thresholdValue = 500;


void setup() 
{
  Serial.begin(9600);
  pinMode(rainSensePin, INPUT);
  servomotor.attach(9);
  servomotor1.attach(4);
  pinMode(rainPin, INPUT);
  Serial.begin(9600); 
}
void loop(){ 


//считываем входящие данные с аналогового контакта 0:
  int sensorValue = analogRead(rainPin);
  Serial.print(sensorValue);
  
  if(sensorValue < thresholdValue) {
    Serial.println(" - It's wet");  //  " - Мокро"
    servomotor.write(180);
    servomotor1.write(180);
    delay(1000);
}
  else {
    delay(2000);
    servomotor.write(0);  // срабатывание сигнализации
    servomotor1.write(0);  // срабатывание сигнализации
    delay(2000);
   }
}



