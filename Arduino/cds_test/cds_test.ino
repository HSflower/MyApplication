float cds_volt;
int adc_value = 0;
int CDS_SENSOR = 5;
int LED = 13;

//초음파센서 변수
int TRIG = 2;
int ECHO = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(CDS_SENSOR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  // 조도센서와 LED
  int CdS_State = analogRead(CDS_SENSOR);
  adc_value = analogRead(CDS_SENSOR);
  cds_volt = adc_value * (5.0/1023.0);
  analogWrite(LED, CdS_State/4);

  Serial.print("CdS volt : ");
  Serial.print(cds_volt);
  Serial.print("(V) ->ADC : ");
  Serial.print(adc_value);
  Serial.print(" ->CdS : ");
  Serial.println(CdS_State);
  delay(500);
  
  //초음파센서
  long duration, cm;
  digitalWrite(TRIG, HIGH); // 센서에 trig 신호입력
  delayMicroseconds(10); //10us
  digitalWrite(TRIG, LOW); //trig 신호 off
  duration = pulseIn(3,HIGH); // echo의 HIGH에서 LOW간격
  cm = microsecondsToCentimeters(duration); //duration to cm

  Serial.print(cm);
  Serial.println("cm");
  delay(300);
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
