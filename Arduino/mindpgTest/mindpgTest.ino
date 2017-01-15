//cds pin
#define CDS0 0
#define CDS1 1
//cds2,3 pin2,3
#define CDSVALUE 800
//led 4-5 digital pin
int LED1 = 7;
int LED2 = 11;
int LED3 = 12;
int LED4 = 13;
//switch digital pin
int BTN = 8;
int btnRead = 0;
#define LEDRED1 9
#define LEDRED2 10
//cds read value
int value0 = 0;
int value1 = 0;
//color sensor
#define S0 6
#define S1 5
#define S2 4
#define S3 3
#define sensorOut 2
int frequency1 = 0;
int frequency2 = 0;
int frequency3 = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);  
  pinMode(BTN, INPUT);
  
  pinMode(LEDRED1, OUTPUT);
  pinMode(LEDRED2, OUTPUT);
  pinMode(CDS0, INPUT);
  pinMode(CDS1, INPUT);    

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
}

int btnFlag = -1; //OFF;
void loop() {
  btnRead = digitalRead(BTN);
  if(btnRead == LOW){
    if(btnFlag == 1) {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      Serial.println("on");
      btnFlag = -1;
    }
    else {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      Serial.println("off");
      btnFlag = 1;
    }
    while(digitalRead(BTN) == LOW) { //버튼이 눌릴 때까지 반복
      cdsCheck(); // 무드등이 꺼진상태에서만 동전 불빛 나도록? (같이나도 괜찮을 듯
      //cds check led
      /*
      //if(value0>970 || value1>740) { //최대 1023
        digitalWrite(LEDRED1, HIGH);
        digitalWrite(LEDRED2, HIGH);
      } else {
        digitalWrite(LEDRED1, LOW);
        digitalWrite(LEDRED2, LOW);
      }
      */
      colorCheck(); //
      //color check led
      //한번 넣고, 그 다음은? 지폐한장에 한번 인식
      if((frequency1<400&&frequency1>0) && (frequency2<1500&&frequency2>0) && (frequency3<1500&&frequency3>800) && value1<CDSVALUE){
        digitalWrite(LEDRED1, LOW);
        digitalWrite(LEDRED2, LOW);
        Serial.println("no input");
      } else if((frequency1<700&&frequency1>400) && (frequency2<1400&&frequency2>1000) && (frequency3<1400&&frequency3>1000)){
        digitalWrite(LEDRED1, HIGH);
        digitalWrite(LEDRED2, HIGH);
        Serial.println("1000won");
      } else if((frequency1<700&&frequency1>400) && (frequency2<1900&&frequency2>1400) && (frequency3<1900&&frequency3>1300)){
        digitalWrite(LEDRED1, HIGH);
        digitalWrite(LEDRED2, HIGH);
        Serial.println("5000won"); 
        //아래랑 너무 비슷해ㅜㅜ
      } else if((frequency1<800&&frequency1>500) && (frequency2<1600&&frequency2>1300) && (frequency3<1800&&frequency3>1400)){
        digitalWrite(LEDRED1, HIGH);
        digitalWrite(LEDRED2, HIGH);
        Serial.println("10000won");
      } else if(frequency1<1000&&frequency1>600 && frequency2<2500&&frequency2>1600 && frequency3>1500&&frequency3<2700){
        digitalWrite(LEDRED1, HIGH);
        digitalWrite(LEDRED2, HIGH);
        Serial.println("50000won");
      } else if(value1 >CDSVALUE){
        digitalWrite(LEDRED1, HIGH);
        digitalWrite(LEDRED2, HIGH);
        Serial.println("coin in.");
      }
      delay(1000);
    }
  }
}

void cdsCheck() {
  value0 = analogRead(CDS0);
  value1 = analogRead(CDS1);
  Serial.print("0: ");Serial.print(value0);
  Serial.print(", 1: ");Serial.println(value1);
  delay(100);
}

void colorCheck(){
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency1 = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency1);//printing RED color frequency
  delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency2 = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("  G= ");//printing name
  Serial.print(frequency2);//printing RED color frequency
  delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency3 = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("  B= ");//printing name
  Serial.println(frequency3);//printing RED color frequency
  delay(100);
}

