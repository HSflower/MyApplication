#include <SoftwareSerial.h>
 
int bluetoothTx = 3;
int bluetoothRx = 2;
 
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
    pinMode(8, OUTPUT);    //HC-05

  //Setup usb serial connection to computer
  Serial.begin(9600);
  bluetooth.begin(9600); //38400
  //digitalWrite(8,HIGH);
  
  Serial.println("ATcommand");  //ATcommand Start

}
 
 
void loop()
{ 
  //Read from bluetooth and write to usb serial 
  if(bluetooth.available())
  {
    char toSend = (char)bluetooth.read();
    Serial.write(toSend);
    Serial.print(toSend);
  }
  
  //Read from usb serial to bluetooth
  if(Serial.available())
  {
    //bluetooth.write(Serial.read());
    char toSend = (char)Serial.read();
    bluetooth.print(toSend);
  }

}


