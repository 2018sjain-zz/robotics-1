#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Servo.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55);

int count = 1;
double accelx = 0;
double accely = 0;

void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Orientation Sensor Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
    
  bno.setExtCrystalUse(true);
}

//.58 and .66

void loop(void) 
{
  /* Get a new sensor event */ 
  sensors_event_t event; 
  bno.getEvent(&event);
  imu::Vector<3> accel = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  /* Display the floating point data */
  Serial.print("AX: ");
  Serial.print(accel.x());
  Serial.print("\tAY: ");
  Serial.print(accel.y());
  Serial.println("");
  accelx = accelx + accel.x();
  accely = accely + accel.y();
  Serial.print("mX: ");
  Serial.print(accelx/count);
  Serial.print("\tmY: ");
  Serial.print(accely/count);
  Serial.println("");
  count++;
  delay(10);
}
