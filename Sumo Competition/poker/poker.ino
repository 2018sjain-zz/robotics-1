#include <Servo.h>
Servo five;
void setup(void) 
{
  Serial.begin(9600);
  five.attach(5);
  delay(1);
}
void loop(void)
{
  poke();
}
void poke()
{
  five.write(137);
  delay(1000);
  five.write(57);
  delay(1000);
  five.write(97);
}
