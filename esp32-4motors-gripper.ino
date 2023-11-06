#include <ESP32Servo.h>
Servo Gripper;

//Motor1 right
int motor1pin1 = 27;
int motor1pin2 = 26;
//Motor2 left
int motor2pin1 = 27;
int motor2pin2 = 26;
//Motor3 right
int motor3pin1 = 27;
int motor3pin2 = 26;
//Motor4 left
int motor4pin1 = 27;
int motor4pin2 = 26;


const int freq = 30000;
const int pwmChannel0 = 0;  //motor 1 Forward
const int pwmChannel1 = 1;  //motor 1 Bacward
const int pwmChannel2 = 2;  //motor 2 Forward
const int pwmChannel3 = 3;  //motor 2 Bacward
const int pwmChannel4 = 4;  //motor 3 Forward
const int pwmChannel5 = 5;  //motor 3 Bacward
const int pwmChannel6 = 6;  //motor 4 Forward
const int pwmChannel7 = 7;  //motor 4 Bacward
const int Resolution = 8;
int fast = 255;
int slow = 150;
int stop = 0;


void Stop()
{
  ledcWrite(pwmChannel0,stop);
  ledcWrite(pwmChannel1,stop);
  ledcWrite(pwmChannel2,stop);
  ledcWrite(pwmChannel3,stop);
  ledcWrite(pwmChannel4,stop);
  ledcWrite(pwmChannel5,stop);
  ledcWrite(pwmChannel6,stop);
  ledcWrite(pwmChannel7,stop);
}
void Forward()
{
  ledcWrite(pwmChannel0,fast);
  ledcWrite(pwmChannel1,stop);
  ledcWrite(pwmChannel2,fast);
  ledcWrite(pwmChannel3,stop);
  ledcWrite(pwmChannel4,fast);
  ledcWrite(pwmChannel5,stop);
  ledcWrite(pwmChannel6,fast);
  ledcWrite(pwmChannel7,stop);
}
void SForward()
{
  ledcWrite(pwmChannel0,slow);
  ledcWrite(pwmChannel1,stop);
  ledcWrite(pwmChannel2,slow);
  ledcWrite(pwmChannel3,stop);
  ledcWrite(pwmChannel4,slow);
  ledcWrite(pwmChannel5,stop);
  ledcWrite(pwmChannel6,slow);
  ledcWrite(pwmChannel7,stop);
}
void Backward()
{
  ledcWrite(pwmChannel0,stop);
  ledcWrite(pwmChannel1,fast);
  ledcWrite(pwmChannel2,stop);
  ledcWrite(pwmChannel3,fast);
  ledcWrite(pwmChannel4,stop);
  ledcWrite(pwmChannel5,fast);
  ledcWrite(pwmChannel6,stop);
  ledcWrite(pwmChannel7,fast);
}
void SBackward()
{
  ledcWrite(pwmChannel0,stop);
  ledcWrite(pwmChannel1,slow);
  ledcWrite(pwmChannel2,stop);
  ledcWrite(pwmChannel3,slow);
  ledcWrite(pwmChannel4,stop);
  ledcWrite(pwmChannel5,slow);
  ledcWrite(pwmChannel6,stop);
  ledcWrite(pwmChannel7,slow);
}
void Right()
{
  ledcWrite(pwmChannel0,stop);
  ledcWrite(pwmChannel1,stop);

  ledcWrite(pwmChannel2,fast);
  ledcWrite(pwmChannel3,stop);

  ledcWrite(pwmChannel4,stop);
  ledcWrite(pwmChannel5,stop);

  ledcWrite(pwmChannel6,fast);
  ledcWrite(pwmChannel7,stop);
}
void SRight()
{
  ledcWrite(pwmChannel0,stop);
  ledcWrite(pwmChannel1,stop);

  ledcWrite(pwmChannel2,slow);
  ledcWrite(pwmChannel3,stop);

  ledcWrite(pwmChannel4,stop);
  ledcWrite(pwmChannel5,stop);

  ledcWrite(pwmChannel6,slow);
  ledcWrite(pwmChannel7,stop);
}
void Left()
{
  ledcWrite(pwmChannel0,fast);
  ledcWrite(pwmChannel1,stop);

  ledcWrite(pwmChannel2,stop);
  ledcWrite(pwmChannel3,stop);

  ledcWrite(pwmChannel4,fast);
  ledcWrite(pwmChannel5,stop);

  ledcWrite(pwmChannel6,stop);
  ledcWrite(pwmChannel7,stop);
}
void SLeft()
{
  ledcWrite(pwmChannel0,slow);
  ledcWrite(pwmChannel1,stop);

  ledcWrite(pwmChannel2,stop);
  ledcWrite(pwmChannel3,stop);
  
  ledcWrite(pwmChannel4,slow);
  ledcWrite(pwmChannel5,stop);
  
  ledcWrite(pwmChannel6,stop);
  ledcWrite(pwmChannel7,stop);
}

void GripperExpand()
{
  for(int i = 0; i <= 180 ; i++)
  {
    Gripper.write(i);
  }
}

void GripperWrap()
{
  for(int i = 180; i >= 0; i--)
  {
    Gripper.write(i);
  }
}

void setup() {
  //Motor 1 Adjust
  pinMode(motor1pin1,OUTPUT);
  pinMode(motor1pin2,OUTPUT);
  ledcSetup(pwmChannel0, freq, Resolution);
  ledcAttachPin(motor1pin1, pwmChannel0);
  ledcSetup(pwmChannel1, freq, Resolution);
  ledcAttachPin(motor1pin2, pwmChannel1);
  //Motor 2 Adjust
  pinMode(motor2pin1,OUTPUT);
  pinMode(motor2pin2,OUTPUT);
  ledcSetup(pwmChannel2, freq, Resolution);
  ledcAttachPin(motor2pin1, pwmChannel2);
  ledcSetup(pwmChannel3, freq, Resolution);
  ledcAttachPin(motor2pin2, pwmChannel3);
  //Motor 3 Adjust
  pinMode(motor3pin1,OUTPUT);
  pinMode(motor3pin2,OUTPUT);
  ledcSetup(pwmChannel4, freq, Resolution);
  ledcAttachPin(motor3pin1, pwmChannel4);
  ledcSetup(pwmChannel5, freq, Resolution);
  ledcAttachPin(motor3pin2, pwmChannel5);
  //Motor 4 Adjust
  pinMode(motor4pin1,OUTPUT);
  pinMode(motor4pin2,OUTPUT);
  ledcSetup(pwmChannel6, freq, Resolution);
  ledcAttachPin(motor4pin1, pwmChannel6);
  ledcSetup(pwmChannel7, freq, Resolution);
  ledcAttachPin(motor4pin2, pwmChannel7);

}

void loop() {
  // put your main code here, to run repeatedly:

}
