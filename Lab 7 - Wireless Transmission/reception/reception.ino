#include <Servo.h>
#include <SoftwareSerial.h>

Servo a;
Servo b;
Servo e;
Servo d;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  a.attach(0);
  b.attach(1);
  e.attach(2);
  d.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*CR.write(180);
  while (xbee.available() > 0)
  {
    int c = xbee.read();
    CR.write(c);
    Serial.println(c);
  }*/
  //Serial.println(Serial1.available());
  while (Serial1.available() > 0)
  {
    int c = Serial1.read();
    Serial.println(c);
    String thing = (String)c;
    for (int x = thing.length(); x <= 9; x++)
    {
      thing = "0" + thing;
    }
    int one = ((thing.substring(0,3).toInt()));
    int two = ((thing.substring(3,6).toInt()));
    int three = ((thing.substring(6).toInt()));

    a.write(one);
    b.write(two);
    e.write(three);
    
    
  }
  

  delay(10);
}
