#include <SoftwareSerial.h>
//// software serial #1: RX = digital pin 0, TX = digital pin 1
SoftwareSerial esp8266(0,1);

//paper button
#define BUTTON1 6
#define BUTTON2 5
#define BUTTON3 4
#define BUTTON4 3

int btn1Read = 0;
int btn2Read = 0;
int btn3Read = 0;
int btn4Read = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  esp8266.begin(9600); // your esp's baud rate might be different
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  Serial.println("good");
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonCheck();
  
}
void buttonCheck(){
    //버튼을 눌렀을 때 데이터 전송, 볼 반짝?
  btn1Read = digitalRead(BUTTON1);
  btn2Read = digitalRead(BUTTON2);
  btn3Read = digitalRead(BUTTON3);
  btn4Read = digitalRead(BUTTON4);
  if( btn1Read == LOW ) Serial.println("1000won");
  else if(btn2Read == LOW) Serial.println("5000won");
  else if(btn3Read == LOW) Serial.println("10000won");
  else if(btn4Read == LOW) Serial.println("50000won");
  else Serial.println("error");
  delay(10000);
}
