const int buttonPin = 4; 
const int buttonPin2 = 2; 
int ledPin = 3;    
int ledPin2 = 5;
int tem = 0;
int tem2 = 0;
int buttonState = 0;
int buttonState2 = 0;
int buttonPushCounter = 0;  
int buttonPushCounter2 = 0; 

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
    Serial.begin(9600);
}

void loop() {
    
   buttonState2 = digitalRead(buttonPin2);
   if (buttonState2 == HIGH){
    buttonPushCounter2++;
    delay(1000);
          Serial.print("number of button2 pushes: ");
      Serial.println(buttonPushCounter2);
   }
   
 if (buttonPushCounter2  % 2 != 0){
          analogWrite(ledPin2, 255);
 }
 
 if (buttonPushCounter2 % 2 != 1){
          analogWrite(ledPin2, 0);
 }

   
   buttonState = digitalRead(buttonPin);
   if (buttonState == HIGH){
    buttonPushCounter++;
    delay(1000);
          Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
   }
   
     if (buttonPushCounter == 1){
          analogWrite(ledPin, 255);
   }


  if (buttonPushCounter == 2){
          //buttonPushCounter++;
        // fade in from min to max in increments of 5 points:
        for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
          // sets the value (range from 0 to 255):
          analogWrite(ledPin, fadeValue);
          // wait for 30 milliseconds to see the dimming effect
          delay(30);
        }
      
        // fade out from max to min in increments of 5 points:
        for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
          // sets the value (range from 0 to 255):
          analogWrite(ledPin, fadeValue);
          // wait for 30 milliseconds to see the dimming effect
          delay(30);
        }
   }

  if (buttonPushCounter == 3){
          //buttonPushCounter++;
        // fade in from min to max in increments of 5 points:
        for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 20) {
          // sets the value (range from 0 to 255):
          analogWrite(ledPin, fadeValue);
          // wait for 30 milliseconds to see the dimming effect
          delay(30);
        }
      
        // fade out from max to min in increments of 5 points:
        for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 20) {
          // sets the value (range from 0 to 255):
          analogWrite(ledPin, fadeValue);
          // wait for 30 milliseconds to see the dimming effect
          delay(30);
        }   
   }

     if (buttonPushCounter == 4){
          //buttonPushCounter++;
        // fade in from min to max in increments of 5 points:
        for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 50) {
          // sets the value (range from 0 to 255):
          analogWrite(ledPin, fadeValue);
          // wait for 30 milliseconds to see the dimming effect
          delay(30);
        }
      
        // fade out from max to min in increments of 5 points:
        for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 50) {
          // sets the value (range from 0 to 255):
          analogWrite(ledPin, fadeValue);
          // wait for 30 milliseconds to see the dimming effect
          delay(30);
        }   
     }
             if (buttonPushCounter == 5){
          //buttonPushCounter++;
        // fade in from min to max in increments of 5 points:
        for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 80) {
          // sets the value (range from 0 to 255):
          analogWrite(ledPin, fadeValue);
          // wait for 30 milliseconds to see the dimming effect
          delay(30);
        }
      
        // fade out from max to min in increments of 5 points:
        for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 80) {
          // sets the value (range from 0 to 255):
          analogWrite(ledPin, fadeValue);
          // wait for 30 milliseconds to see the dimming effect
          delay(30);
        }   
   }



if (buttonPushCounter == 6){
    buttonPushCounter = 0;
}
   
}
