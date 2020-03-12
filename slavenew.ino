#include <AFMotor.h>
#include<Wire.h>
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
char data;
void setup()
{      
 Wire.begin(9); 
 // Attach a function to trigger when something is received.
 Serial.begin(9600);
 Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes)
{
  data=Wire.read();
  Serial.println(data);
}
void loop(){
  switch (data)
    {
      case '1': //FORWARD
      forward();
      delay(2000);
      break;
      case '2'://REVERSE
      backward();
      delay(2000);
      break;
      case '3': //FORWARD LEFT
      left();
      delay(1000);
      forward();
      delay(2000);
      break;
      case '4': //FORWARD RIGHT
      right();
      delay(1500);
      forward();
      delay(2000);
      break;
      
      case '5': //REVERSE LEFT
        right();
        delay(1500);
        backward();
        delay(2000);
        break;
      case '6': //REVERSE RIGHT
        left();
        delay(1500);
        backward();
        delay(2000);
        break;
        default: //If bluetooth module receives any value not listed above,then all the four motors stop running
        motor1.run(RELEASE); 
        motor2.run(RELEASE); 
        motor3.run(RELEASE); 
        motor4.run(RELEASE);
    }
  }
  void forward()
  {
      motor1.setSpeed(127); //set motor1 to half speed max speed=255, min speed=0,half speed=127
      motor1.run(FORWARD); //rotate the motor clockwise
      motor2.setSpeed(127); //set motor2 to half speed
      motor2.run(FORWARD); //rotate the motor clockwise
      motor3.setSpeed(127); //set motor3 to half speed
      motor3.run(FORWARD); //rotate the motor clockwise
      motor4.setSpeed(127); //set motor4 to half speed
      motor4.run(FORWARD); //rotate the motor clockwise
    
  }
  void backward()
  {
   
      motor1.setSpeed(127); //set motor1 to half speed max speed=255, min speed=0,half speed=127
      motor1.run(BACKWARD); //rotate the motor clockwise
      motor2.setSpeed(127); //set motor2 to half speed
      motor2.run(BACKWARD); //rotate the motor clockwise
 
      motor3.setSpeed(127); //set motor3 to half speed
      motor3.run(BACKWARD); //rotate the motor clockwise
      motor4.setSpeed(127); //set motor4 to half speed
      motor4.run(BACKWARD);
  }
  void left()
  {
      motor1.setSpeed(127); //set motor1 to half speed max speed=255, min speed=0,half speed=127
      motor1.run(BACKWARD); //rotate the motor clockwise
      motor2.setSpeed(127); //set motor2 to half speed
      motor2.run(BACKWARD); //rotate the motor clockwise
      motor3.setSpeed(127); //set motor3 to half speed
      motor3.run(FORWARD); //rotate the motor clockwise
      motor4.setSpeed(127); //set motor4 to half speed
      motor4.run(FORWARD);
  }
  void right()
  {
      motor1.setSpeed(127); //set motor1 to half speed max speed=255, min speed=0,half speed=127
      motor1.run(FORWARD); //rotate the motor clockwise
      motor2.setSpeed(127); //set motor2 to half speed
      motor2.run(FORWARD); //rotate the motor clockwise
      motor3.setSpeed(127); //set motor3 to half speed
      motor3.run(BACKWARD); //rotate the motor clockwise
      motor4.setSpeed(127); //set motor4 to half speed
      motor4.run(BACKWARD);
  }
 
