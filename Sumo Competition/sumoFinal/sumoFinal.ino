#include <Servo.h>
#define sensor A0

int distCount = 0;

Servo one; //stop for all is 95
Servo two;
Servo three;
Servo four;
Servo five;
int frd = 0;
void setup(void) 
{
  Serial.begin(9600);
  delay(5100);
  five.attach(5);
  one.attach(1);
  two.attach(2);
  three.attach(3);
  four.attach(4);
  
}

void loop(void)
{
  //five.write(90);
  right();
  for (int i = 0; i <= 6000; i = i + 100)
  {
    delay(100);
    checkDist();
  }
  if(frd < 5000)
  {
  forward();
  for (int i = 0; i <= 500; i = i + 100)
  {
    delay(100);
    frd += 100;
    checkDist();
  }
  }
  left();
  for (int i = 0; i <= 6000; i = i + 100)
  {
    delay(100);
    checkDist();
  }
  if(frd < 5000)
  {
  forward();
  for (int i = 0; i <= 500; i = i + 100)
  {
    delay(100);
    checkDist();
    frd += 100;
  }
  }
  
  //poke();
}

void checkDist()
{
  float volts = analogRead(sensor)*0.0048828125;
  int distance = 13*pow(volts, -1);
  if(distance <= 30)
  {
    Serial.println(distance);
  }
  if (distance < 15)
  {
    distCount++;
  }
  else
  {
    distCount = 0;
  }
  if (distCount > 10)
  {
    forward();
    frd += 1000;
    five.write(135);
    delay(500);
    five.write(45);
    delay(500);
    five.write(95);
  }
}

void poke()
{
  five.write(135);
  delay(1000);
  five.write(45);
  delay(1000);
  five.write(97);
}

void forward()
{
  one.write(135);
  two.write(45);
  three.write(95);
  four.write(95);
}

void back()
{
  one.write(45);
  two.write(135);
  three.write(95);
  four.write(95);
}

void right()
{
  one.write(94);
  two.write(95);
  three.write(45);
  four.write(135);
}

void left()
{
  one.write(94);
  two.write(95);
  three.write(135);
  four.write(45);
}
