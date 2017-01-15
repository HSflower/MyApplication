// 적외선 센서 핀번호 선언
int motion = 2; 
// 13번 고정 LED 핀번호 선언
int light = 13; 

void setup() {
  // 적외선센서의 핀을 INPUT모드로 선언
    pinMode(motion,INPUT); 
    // 13번LED센서의 핀을 OUTPUT모드로 선언
    pinMode(light, OUTPUT); 
  // 시리얼 통신 속도 설정
    Serial.begin(9600);
}

void loop() {
  // 13번 LED off
  digitalWrite(light,LOW); 
  delay(1000);
  
  // 적외선 인체감지 센서에서 값을 읽는다
  int sensor = digitalRead(motion); 
  // 센서값을 시리얼 모니터에 출력
  Serial.println(sensor); //1, 0
  
  // 센서값이 HIGH(1)일 경우 13번 LED를 한번 깜빡인다
  if (sensor == HIGH) { 
    digitalWrite(light, HIGH); 
    Serial.println("sensor:on ");
    Serial.println(sensor);
    delay(500);
  } else {
    digitalWrite(light,LOW); 
    Serial.println("sensor:off ");
    Serial.println(sensor);
    delay(500);
  }
}
