#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial xbee(10,11);

int button1 = A1;
int button2 = A2;
int button3 = A3;
int button4 = A4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xbee.begin(9600);
  while (!Serial)
  {
    ;
  }
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);     
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(button1);
  int b= analogRead(button2);
  int c= analogRead(button3);
  int d= analogRead(button4);
  String one = thing((String)((9*a)/500));
  String two = thing((String)((9*b)/500));
  String three = thing((String)((9*c)/500));
  String four = thing((String)((9*d)/500));
  String thing = (one + two + three);

  Serial.println(thing.toInt());
  xbee.print(thing.toInt());
  delay(10);
}

String thing(String p)
{
  for (int x = p.length(); x < 3; x++)
  {
    p = "0" + p;
  }
  return p;
}

