#include <Servo.h>

Servo one; //stop for all is 95
Servo two;
Servo three;
Servo four;

void setup()
{
  one.attach(1);
  two.attach(2);
  three.attach(3);
  four.attach(4);
}

void loop()
{
  //allStop();
  forward();
  right();
  back();
  left();
  back();
  right();
  forward();
  left();
}

void forward()
{
  one.write(135);
  two.write(45);
  three.write(95);
  four.write(95);
  delay(1000);
}

void back()
{
  one.write(45);
  two.write(135);
  three.write(95);
  four.write(95);
  delay(1000);
}

void right()
{
  one.write(95);
  two.write(95);
  three.write(45);
  four.write(135);
  delay(1000);
}

void left()
{
  one.write(95);
  two.write(95);
  three.write(135);
  four.write(45);
  delay(1000);
}

void allStop()
{
  one.write(95);
  two.write(95);
  three.write(95);
  four.write(95);
}

