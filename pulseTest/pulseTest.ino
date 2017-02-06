#define trig 9
#define echo 8
//2cm이상부터 정확
//최소 1cm단위 가능, 투입구의 간격은 2cm정도
void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT); // 센서 Trig 핀
  pinMode(echo, INPUT); // 센서 Echo 핀
}

void loop()
{
  long duration, cm;

  digitalWrite(trig, HIGH); // 센서에 Trig 신호 입력
  delayMicroseconds(10); // 10us 정도 유지
  digitalWrite(trig, LOW); // Trig 신호 off

  duration = pulseIn(echo, HIGH); // Echo pin: HIGH->Low 간격을 측정
  cm = microsecondsToCentimeters(duration); // 거리(cm)로 변환

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(300); // 0.3초 대기 후 다시 측정
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
} 
