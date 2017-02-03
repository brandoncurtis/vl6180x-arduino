/* This minimal example shows how to get single-shot range
measurements from the VL6180X.

The range readings are in units of mm. */

#include <Wire.h>
#include <VL6180X.h>

VL6180X sensor;

void setup() 
{
  Serial.begin(115200);
  Wire.begin();
  
  sensor.init();
  sensor.configureDefault();
  sensor.setTimeout(20);
}

void loop() 
{
  long before = millis();
  int myvar = sensor.readRangeContinuous();
  //int myvar = sensor.readRangeContinuousMillimeters();
  //int myvar = sensor.readRangeSingleMillimeters();
  long after = millis();

  Serial.print(before);
  Serial.print(',');
  Serial.print(after);
  Serial.print(',');
  Serial.print(myvar);
  Serial.print(',');
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  
  
  //long before2 = millis();
  sensor.startRangeMeasurement();
  //long after2 = millis();

  //Serial.print(',');
  //Serial.print(before2);
  //Serial.print(',');
  //Serial.print(after2);
  Serial.println();

  
  //delay(5);
}
