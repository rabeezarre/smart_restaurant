#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h> // библиотека "RFID".
#define SS_PIN 10
#define RST_PIN 9

int sost=0;

MFRC522 mfrc522(SS_PIN, RST_PIN);
unsigned long uidDec, uidDecTemp;  // для храниения номера метки в десятичном формате
Servo servo;

void setup() {
  Serial.begin(9600);
  Serial.println("Waiting for card...");
  SPI.begin();  //  инициализация SPI / Init SPI bus.
  mfrc522.PCD_Init();     // инициализация MFRC522 / Init MFRC522 card.
  servo.attach(6);
     servo.write(0);
  // устанавливаем серву в закрытое сосотояние
}
void loop() {
  // Поиск новой метки
 
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Выбор метки
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  uidDec = 0;
  // Выдача серийного номера метки.
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    uidDecTemp = mfrc522.uid.uidByte[i];
    uidDec = uidDec * 256 + uidDecTemp;
  }
  Serial.println("Card UID: ");
  Serial.println(uidDec); // Выводим UID метки в консоль.
  
  if ((uidDec == 1440419976)&&(sost==0)) // Сравниваем Uid метки, если он равен заданому то серва открывает.
  {
    tone(8, 2000, 500); // Делаем звуковой сигнал, Открытие
    delay(1000);
    servo.write(90); // Поворациваем серво на угол 90 градусов (Отпираем какой либо механизм: задвижку, поворачиваем ключ и т.д.)
    sost=1;
  }
  
   else if((uidDec == 1440419976)&&(sost==1)) // Сравниваем Uid метки, если он равен заданому то серва открывает.
  {
    tone(8, 500, 500); // Делаем звуковой сигнал,  Закрытие
    delay(1000);
    servo.write(0); 
    sost=0;
  }
}
