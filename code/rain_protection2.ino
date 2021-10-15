/* Дмитрий Осипов. http://www.youtube.com/user/d36073?feature=watch
 
 v.01 вправо влево Arduino Шаговый двигатель 28BYJ-48 – 5V Stepper Motor
 
 Так как этот маломощный шаговый двигатель питается 5V, я не использовал
 драйвер для шагового двигателя, а подключил его напрямую к Pins Arduino.
 
 1 тест) Подключаем шаговый двигатель к 4 Pins Arduino, 
 покрутим "туда сюда обратно" (360 градусов).
 
 2 тест) Добавим кнопку, нажимаем на кнопку меняем направление вращения.
 
 3 тест) добавим переменный резистор, крутим резистор меняем скорость вращения.
 ----------------------------------------
 Скачать sketch.
 v.01 вправо влево Arduino Шаговый двигатель 28BYJ-48 – 5V Stepper Motor
 
 
 v.01 button resistor Arduino Шаговый двигатель 28BYJ-48 – 5V Stepper Motor
 
 */

//-----------------

// красный +5V не использовал.
// declare variables for the motor pins
int motorPin1 = 10; // Blue / Синий   - 28BYJ48 pin 1
int motorPin2 = 11; // Pink  / Розовый  - 28BYJ48 pin 2
int motorPin3 = 12; // Yellow / Желтый - 28BYJ48 pin 3
int motorPin4 = 13; // Orange  / Оранжевый - 28BYJ48 pin 4
// установить скорость шагового двигателя.
//variable to set stepper speed.
int motorSpeed = 1200;  

// Кол-во сделанных шагов.
// count of steps made.
int count = 0;          

// Необходимое количество шагов, для одного полного оборота, на (360 градусов).
// number of steps per full revolution.
int countsperrev = 512; 

int lookup[8] = {
  B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

//////////////////////////////////////////////////////////////////////////////
void setup() {
  // declare the motor pins as outputs.
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  // Serial.begin(9600);
}

void loop(){
  if(count < countsperrev )
    clockwise();
  else if (count == countsperrev * 2)
    count = 0;
  else
    anticlockwise();
  count++;
}

//set pins to ULN2003 high in sequence from 1 to 4
//delay "motorSpeed" between each pin setting (to determine speed)
// функция поворачивает мотор против часовой стрелки.
void anticlockwise()
{
  for(int i = 0; i < 8; i++)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

// функция поворачивает мотор по часовой стрелке.
void clockwise()
{
  for(int i = 7; i >= 0; i--)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void setOutput(int out)
{
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
}



