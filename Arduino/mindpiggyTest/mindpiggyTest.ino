//여러개의 LED제어
//배열을 이용하여 핀을 한번에 선언
int ledPins[] = {2,3}; //2번핀과 3번핀을 이용
//초음파센서 핀 설정
int trig = 8;
int echo = 9;
//조도센서 아날로그 A1핀
int cds = A1;
//색 판별은 컬러센서 사용

void setup() {
  // put your setup code here, to run once:
  int index; //배열을 핀번호 저장할 변수
  for(index = 0; index<2 ; index++){
    pinMode(ledPins[index], OUTPUT); //LED핀을 OUTPUT으로 설정
  }
  Serial.begin(9600); //센서 동작 상태 확인용 시리얼 통신 설정(전송속도 9600bps)
  pinMode(trig, OUTPUT); //초음파센서의 송신부 핀을 OUTPUT으로 설정
  pinMode(echo, INPUT); //초음파센서의 수신부 핀을 INPUT으로 설정
}

void loop() {
  // put your main code here, to run repeatedly:무한반복
  // 동전이 입력되면 인식거리가 짧게 측정
  sensorCoin();
  sensorCdS();
}

void ledTwinkle(){
    //for문 사용시 두개의 불에 시간 차 발생
      digitalWrite(ledPins[0], HIGH); //켜기
      digitalWrite(ledPins[1], HIGH); //켜기
      delay(1000);
  
      digitalWrite(ledPins[0], LOW); //끄기
      digitalWrite(ledPins[1], LOW); //끄기
}

/*http://ohm.co.kr/m/board.html?code=OHMRNC25_board28&page=1&type=v&num1=999989&num2=00000&number=16&lock=N
 * 수행결과 : 현재 센서 HC-SR04로는 센서 전체를 가려야 하므로 동전에 적합하지 않음.
 * ? 계속 대고 있어도 불은 한번만 깜빡거림
 */
void sensorCoin(){
  digitalWrite(trig, LOW); //송신부 잡음제거 (전류차단)
  digitalWrite(echo, LOW); //수신부 잡음제거
  delayMicroseconds(2); //2ms동안 초음파발생
  digitalWrite(trig, HIGH); //초음파 발생
  delayMicroseconds(10);  
  digitalWrite(trig, LOW); //초음파 중지

  unsigned long duration = pulseIn(echo, HIGH); //수신부의 초기 로직레벨 HIGH설정 & LOW레벨이 되기 전까지의 시간 측정
  //float distance = duration /29.0 /2.0; //초음파속도 1cm/29ms, 이동거리 = (왕복시간)duration/2
  float distance = ((float)(340*duration) /10000) /2; //초음파속도 340m/s - distance(cm)
  Serial.print(distance);
  Serial.println("cm");

  if(distance>4) { //측정거리 1cm이하
    ledTwinkle();
  } else{
    
  }
  delay(200);
}

void sensorCdS(){
  //출처 : http://www.kocoafab.cc/tutorial/view/356
  // 회로도는 http://zelkun.tistory.com/49 이용
  int cdsValue = analogRead(cds); //입력전압의 크기(0-5V)에 따라 0-1023범위의 값으로 변환되어 반환
  // * 조도센서는 안 저항때문인가 값이 제대로 안나오네.. 
  // * 컬러센서로 해보자
  Serial.print("cds = "); //측정된 밝기 값을 출력
  Serial.println(cdsValue);

  if(cdsValue <300) {
    // default 상태
  } else {
    // 지폐가 들어와서 어두운 상태
    ledTwinkle();
    //색 판별 - 컬러센서
    //1. http://www.hardcopyworld.com/ngine/aduino/index.php/archives/586
    //2. http://blog.naver.com/PostView.nhn?blogId=ubicomputing&logNo=220647673406
    //3. 조도센서와 LED이용 : http://www.kocoafab.cc/tutorial/view/466
  }
  delay(200);  
}


