/*
Analog:
void setup() {
 Serial.begin(9600);
}
void loop() {
 Serial.println(analogRead(A0));
 delay(50);
}
*/
//Digital:
#define LB 8
void setup() {
 Serial.begin(9600);
}
void loop() {
 Serial.println(digitalRead(LB)?"HIGH":"LOW");
 delay(10);
}
