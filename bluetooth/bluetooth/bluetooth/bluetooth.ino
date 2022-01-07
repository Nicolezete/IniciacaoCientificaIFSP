#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
void robot_forward(unsigned char v);
void robot_backward(unsigned char v);
void robot_left(unsigned char v);
void robot_right(unsigned char v);
void robot_stop(unsigned char v);
unsigned char velocidade = 0x00;

char command;

void setup()
{
  velocidade = 0xFF;
  Serial.begin(9600);
}

void loop()
{
  while (Serial.available() ){

    command = Serial.readString().charAt(0);
  }
  
     if (command == 'f'){
      robot_forward(velocidade);
     }

     if (command == 't'){
      robot_backward(velocidade);
     }

     if (command == 'd'){
       robot_right(velocidade);
     }

     if (command == 'e'){
      robot_left(velocidade);
     }
     
     if (command == 'p'){
      robot_stop(velocidade);
     }
}
 
void robot_forward(unsigned char v)
{
     motor1.setSpeed(v);
     motor1.run(FORWARD);
     motor2.setSpeed(v);
     motor2.run(FORWARD);
     motor3.setSpeed(v);
     motor3.run(FORWARD);
     motor4.setSpeed(v);
     motor4.run(FORWARD);
}

void robot_backward(unsigned char v)
{
     motor1.setSpeed(v);
     motor1.run(BACKWARD);
     motor2.setSpeed(v);
     motor2.run(BACKWARD);
     motor3.setSpeed(v);
     motor3.run(BACKWARD);
     motor4.setSpeed(v);
     motor4.run(BACKWARD);
}

void robot_left(unsigned char v)
{
     motor1.setSpeed(v);
     motor1.run(FORWARD);
     motor2.setSpeed(v);
     motor2.run(FORWARD);
     motor3.setSpeed(v);
     motor3.run(BACKWARD);
     motor4.setSpeed(v);
     motor4.run(BACKWARD);
}

void robot_right(unsigned char v)
{
     motor1.setSpeed(v);
     motor1.run(BACKWARD);
     motor2.setSpeed(v);
     motor2.run(BACKWARD);
     motor3.setSpeed(v);
     motor3.run(FORWARD);
     motor4.setSpeed(v);
     motor4.run(FORWARD);
}

void robot_stop(unsigned char v)
{
     motor1.setSpeed(v);
     motor1.run(RELEASE);
     motor2.setSpeed(v);
     motor2.run(RELEASE);
     motor3.setSpeed(v);
     motor3.run(RELEASE);
     motor4.setSpeed(v);
     motor4.run(RELEASE);
}
