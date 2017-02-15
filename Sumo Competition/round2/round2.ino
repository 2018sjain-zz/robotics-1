#include <Servo.h>
#define sensor A0

int distCount = 0;
int scott = 0;
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
  five.write(97);
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
    int dist = 0;
    boolean up = true;
    while (1)
    {
      while (scott < 5){
        forward();
        frd += 1000;
        if(up)
        {
           five.write(135);
           dist += 80;
           if(dist > 1500)
          {
            up = false;
          }
        }
        else
        {
          five.write(45);
          dist -= 100;
          if(dist < 0)
          {
            up = true;
          }
        }
        delay(100);
        five.write(95);
        float volts = analogRead(sensor)*0.0048828125;
        int distance = 13*pow(volts, -1);
        Serial.println(distance);
        if(distance == 0  || distance > 20)
        {
          scott ++;
        }
      }
    scott = 0;
    back();
    delay(600);
    float volts = analogRead(sensor)*0.0048828125;
    int distance = 13*pow(volts, -1);
    int poop = 13*pow(volts, -1);
    int sachin = 0;
    int jain  = 0;
    boolean bad = false;
    while(poop == 0 || poop > 50)
    {
      float b = analogRead(sensor)*0.0048828125;
      int poo = 13*pow(volts, -1);
      poop = poo;
      Serial.println(distance);
      one.write(143);
      two.write(143);
      three.write(145);
      four.write(145);
      if(poop > 100)
        {
          if(jain == 0)
          {
          jain == poop;
          sachin += 1;
          }
          if(poop == jain)
          {
            sachin += 1;
          }
          else
          {
            sachin == 0;
          }
        }
        if(sachin > 5)
        {
          break;
        }
    }
    one.write(94);
    two.write(95);
    three.write(95);
    four.write(95);
  }
    
  }
}


void forward()
{
  one.write(143);
  two.write(45);
  three.write(95);
  four.write(95);
}

void back()
{
  one.write(45);
  two.write(143);
  three.write(95);
  four.write(95);
}

void right()
{
  one.write(94);
  two.write(95);
  three.write(45);
  four.write(145);
}

void left()
{
  one.write(94);
  two.write(95);
  three.write(145);
  four.write(45);
}
