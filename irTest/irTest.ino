#define IR 9
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR, OUTPUT);
}

void loop() {
  digitalWrite(IR, HIGH);
}
