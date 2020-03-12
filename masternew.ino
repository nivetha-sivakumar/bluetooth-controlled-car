#include<Wire.h>
#include <SoftwareSerial.h>
char data;
SoftwareSerial softserial(0, 1); 
void setup() {
  softserial.begin(9600);
  Wire.begin(); 
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  Serial.begin(9600);
}

void loop() {
  if(softserial.available())
  {
    data = softserial.read();
    Serial.print(data);
    Wire.beginTransmission(9); // transmit to device #9
    Wire.write(data);              // sends the data
    Wire.endTransmission();    // stop transmitting
  }
  delay(500);
}
