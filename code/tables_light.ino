
#include <DHT.h>
#include <Wire.h> // библиотека для управления устройствами по I2C 
#include <LiquidCrystal_I2C.h> // подключаем библиотеку для LCD 1602
#define trigPin 11
#define echoPin 13
#define led 9

#define DHTTYPE DHT11
const int pirPin = 13;// постоянная переменная для присвоения датчику порта
const int ledPin = 5;
int value; // переменная для считывания данных с датчика




const int dhtPin = 2;
DHT dht(dhtPin, DHTTYPE);

LiquidCrystal_I2C lcd(0x27,16,2); // присваиваем имя lcd для дисплея 20х2


int buzzer = 4;

int buttonPin1 = 12;
int buttonPin2 = 7;
int buttonPin3 = 8;

int buttonState1;
int buttonState2;
int buttonState3;

void setup() {
Serial.begin(9600);
lcd.begin(); // инициализация LCD дисплея
  lcd.backlight(); // включение подсветки дисплея
   
  lcd.setCursor(0,0); // ставим курсор на 1 символ первой строки
  lcd.clear();

  lcd.print("Temperature: ");
   pinMode(4, OUTPUT);
   pinMode(buttonPin1, INPUT);
   pinMode(buttonPin2, INPUT);
   pinMode(buttonPin3, INPUT);
    pinMode(pirPin, INPUT);
    pinMode(ledPin, OUTPUT);
  Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led, OUTPUT);
}

void loop() {
 float h, t; // put your main code here, to run repeatedly:
h = dht.readHumidity();
t = dht.readTemperature();

if (isnan(h) or isnan(t))
{
 // Serial.println("Filed to read from DHT");
}
else 
{

lcd.setCursor(12,0);
 lcd.print( t);
 
if (t > 25)
{
  tone(4, 500, 1000);
}
}
//delay(500);




  buttonState1 = digitalRead(buttonPin1);
   // Serial.println(buttonState1);
   
   if (buttonState1 == 1)
{
 
   lcd.setCursor(0,1);
  lcd.print("Table 1");
  delay (200);
}
    buttonState2 = digitalRead(buttonPin2);
 // Serial.println(buttonState2);

  if (buttonState2 == 1)
{
   lcd.setCursor(0,1);
  lcd.print("Table 2");
  delay (200);
}
   buttonState3 = digitalRead(buttonPin3);
 // Serial.println(buttonState3);
  
if (buttonState3 == 1)
{
   lcd.setCursor(0,1);
  lcd.print("Table 3");
  delay (200);
}
  
     long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 15) {  // This is where the LED On/Off happens
    analogWrite(led,255); // When the Red condition is met, the Green LED should turn off
//  digitalWrite(led2,LOW);
}
  else {
    analogWrite(led,0);
   // digitalWrite(led2,HIGH);
  }
  if (distance >= 200 || distance <= 0){
      analogWrite(led,0);
     
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}

