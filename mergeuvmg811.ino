#include <Wire.h>
#include "Adafruit_SI1145.h"
Adafruit_SI1145 uv = Adafruit_SI1145();

#include "CO2Sensor.h"
CO2Sensor co2Sensor(A0, 0.99, 100);

void setup() {
Serial.begin(9600);
co2Sensor.calibrate();
}

void loop() {
  
int val = co2Sensor.read();
  Serial.print("CO2 value: ");
  Serial.println(val);
  //Serial.print("Vis: "); Serial.println(uv.readVisible());
  //Serial.print("IR: "); Serial.println(uv.readIR());
  float UVindex = uv.readUV();
  // the index is multiplied by 100 so to get the
  // integer index, divide by 100!
  UVindex /= 100.0;  
  Serial.print("UV Value: ");  Serial.println(UVindex);
  if(UVindex==0.00||UVindex==655.35)
  {
    uv.begin();
  }
  Serial.println();
  delay(1000);
}
