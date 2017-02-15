#include <Servo.h>

Servo one; //stop value is 95
Servo two;
Servo three;
Servo four;

int switch1 = 6;
int light = 13;
//int switch2 = 6;

void setup()
{
  one.attach(1);
  two.attach(2);
  three.attach(3);
  four.attach(4);
  pinMode(light,OUTPUT);
  digitalWrite(light, HIGH);
  //pinMode(switch2, INPUT);
}

void loop()
{
 if (digitalRead(switch1) == 0) 
 {
    digitalWrite(light, HIGH);
    one.write(45);
    two.write(135);
    three.write(95);
    four.write(95);
    delay(2000);
    one.write(135);
    two.write(135);
    three.write(135);
    four.write(135);
    delay(1000);
 }
 else {
    digitalWrite(light, LOW);
    one.write(135);
    two.write(45);
    three.write(95);
    four.write(95);
    delay(10);
 }
}
