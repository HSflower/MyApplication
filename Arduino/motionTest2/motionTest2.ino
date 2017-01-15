int pirPin = 2; //the digital pin connected to the PIR sensor's output
int ledPin = 13; 
int val = 0;

void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);
}

int n=0;
void loop(){

  val = digitalRead(pirPin);  // read input value
    if (val == HIGH) {            // check if the input is HIGH
      digitalWrite(ledPin, LOW);  // turn LED ON
      Serial.print("on");
    } else {
      digitalWrite(ledPin, LOW); // turn LED OFF
      Serial.print("off");
    }
//  digitalWrite(ledPin, digitalRead(pirPin));
  Serial.println(n);
  n++;
  delay(500);
}
