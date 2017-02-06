int s0 = 6, s1 = 5, s2 = 4, s3 = 3;  
//selection pin 
int out = 2;  
//signal pin 
int led_r = 8, led_g = 9, led_b = 10 ;  
//led pin 
int flag = 0;  
//what color reading now 
byte counter = 0;  
//signal data 
byte countR = 0, countG = 0, countB = 0;  
//signal data about color 
void setup() {  
  Serial.begin(9600);
  pinMode(s0, OUTPUT);  //set pin out  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  //pinMode(led_r, OUTPUT) ;  pinMode(led_g, OUTPUT) ;  pinMode(led_b, OUTPUT) ;
} 
  
void TCS() {  
  flag = 0;  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  attachInterrupt(0, ISR_INTO, CHANGE);  
  timer0_init(); 
} 
void ISR_INTO() {  counter++; } 
void timer0_init(void) {  
  TCCR2A = 0x00;  
  TCCR2B = 0x07; //the clock frequency source 1024 points  
  TCNT2 = 100;   //10 ms overflow again  
  TIMSK2 = 0x01; //allow interrupt 
} 
ISR(TIMER2_OVF_vect)  {
//the timer 2, 10ms interrupt overflow again. Internal overflow interrupt executive function  
  TCNT2 = 100;  
  flag++;  
  if (flag == 1)  {    
    countR = counter;    
//    if (countR > 120) Serial.println("red counter");  //if countR is bigger than 120, HIGH, not LOW    
//    else Serial.println(countR);
    Serial.print("red counter: ");
    Serial.println(countR, DEC);  
    digitalWrite(s2, HIGH);    
    digitalWrite(s3, HIGH);  
  }  else if (flag == 2)  {    
    countG = counter;    
//    if (countG > 110) Serial.println("green counter");    
//    else Serial.println(countG);
    Serial.print("Green counter: ");
    Serial.println(countG, DEC);  
    digitalWrite(s2, LOW);    
    digitalWrite(s3, HIGH);  
  }  else if (flag == 3)  {    
    countB = counter;    
    //if (countB > 115) Serial.println("blue counter") ;  
    //else
    Serial.print("blue counter: ");
    Serial.println(countB,DEC);  
    digitalWrite(s2, LOW);    
    digitalWrite(s3, LOW);    
    flag = 0 ;  
  }  
  counter = 0; 
}

void loop() {  
  TCS();  //start interrupt routine  
  while (1);  //infinite loop 
}
 
