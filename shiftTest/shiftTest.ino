/*
Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
*/
 
int latchPin = 12;      //Pin connected to ST_CP of 74HC595
int clockPin = 11;   //Pin connected to SH_CP of 74HC595
int dataPin = 13;    //Pin connected to DS of 74HC595

int btnPin = 10;
int btn = 0;
int btnFlag = -1;
 
byte leds = 0;
 
void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(btnPin, INPUT);
}
 
void loop() {
  leds = 0;
  //updateShiftRegister();
  btn = digitalRead(btnPin);
  if(btn == LOW){
    if(btnFlag == 1){
     for (int i = 0; i < 8; i++)  {
      bitSet(leds, i);
      onShiftRegister();
     } 
     Serial.println("on");
     btnFlag = -1;
    } else {
      for (int i = 0; i < 8; i++)  {
      bitClear(leds, i);
      offShiftRegister();
     } 
     Serial.println("off");
     btnFlag = 1;
    }
  }
  delay(500);
}
 
void onShiftRegister() {
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}

void offShiftRegister() {
   digitalWrite(latchPin, HIGH);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, LOW);
}
