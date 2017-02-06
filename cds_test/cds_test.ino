float cds_volt0;
float cds_volt1;
int adc_value0 = 0;
int adc_value1 = 0;
int CDS_SENSOR0 = 0;
int CDS_SENSOR1 = 1;
//int LED = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(CDS_SENSOR0, INPUT);
  pinMode(CDS_SENSOR1, INPUT);
//  pinMode(LED, OUTPUT);
}

void loop() {
  // 조도센서와 LED
  int CdS_State0 = analogRead(CDS_SENSOR0);
  int CdS_State1 = analogRead(CDS_SENSOR1);
  adc_value0 = analogRead(CDS_SENSOR0);
  cds_volt0 = adc_value0 * (5.0/1023.0);
//  analogWrite(LED, CdS_State0/4);
  adc_value1 = analogRead(CDS_SENSOR1);
  cds_volt1 = adc_value1 * (5.0/1023.0);
//  analogWrite(LED, CdS_State1/4);
//0
  Serial.print("CdS volt0 : ");
  Serial.print(cds_volt0);
  Serial.print("(V) ->ADC0 : ");
  Serial.print(adc_value0);
  Serial.print(" ->CdS0 : ");
  Serial.println(CdS_State0);
//1
  Serial.print("CdS volt1 : ");
  Serial.print(cds_volt1);
  Serial.print("(V) ->ADC1 : ");
  Serial.print(adc_value1);
  Serial.print(" ->CdS1 : ");
  Serial.println(CdS_State1);

  delay(500);
/*  
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
*/
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
