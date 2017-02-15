#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Servo.h>
  
Adafruit_BNO055 bno = Adafruit_BNO055(55);

int count = 0;

Servo one; //stop for all is 95
Servo two;
Servo three;
Servo four;
Servo five;
void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Orientation Sensor Test");
  Serial.println("");
  one.attach(8);
  two.attach(9);
  three.attach(10);
  four.attach(11);
  
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(100);
    
  bno.setExtCrystalUse(true);
}

void loop(void) 
{
  /* Get a new sensor event */ 
  sensors_event_t event; 
  bno.getEvent(&event);
  /* Display the floating point data */
  forward();
  delay(1000);
  double x = event.orientation.x;
  double t = x;
  if (count < 3)
  {
  while (abs(t - x) < 90 or abs(t-x) > 270)
  {
    sensors_event_t ev;
    bno.getEvent(&ev);
    t = ev.orientation.x;
    spin();
    delay(10);
  }
  count++;
  }
  while (abs(t - x) < 90 or abs(t-x) > 270)
  {
    sensors_event_t ev;
    bno.getEvent(&ev);
    t = ev.orientation.x;
    spiner
    ();
    delay(10);
  }
}

void forward()
{
  one.write(135);
  two.write(45);
  three.write(95);
  four.write(95);
}

void spin()
{
  one.write(45);
  two.write(45);
  three.write(45);
  four.write(45);
}

void spiner()
{
  one.write(135);
  two.write(135);
  three.write(135);
  four.write(135);
}
