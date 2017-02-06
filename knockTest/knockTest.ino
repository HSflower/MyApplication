int knockSensor = 0;               
byte val = 0;
int THRESHOLD = 100;

void setup() {
  pinMode( knockSensor, INPUT);
 Serial.begin(9600);
}

void loop() {
  val = analogRead(knockSensor);     
  //val = digitalRead(knockSensor);
  Serial.println(val);
  if (val >= THRESHOLD) {
    Serial.println("Knock!");
  }

  delay(100);  // we have to make a delay to avoid overloading the serial port
}

