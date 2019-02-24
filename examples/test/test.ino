// Tests for VDW_ADS7830 library.
#define DEBUG_VDW_ADS7830 1
#include "VDW_ADS7830.h"

VDW_ADS7830 AnalogEXP(0x48);

void setup()
{
  AnalogEXP.init();

  Serial.begin(230400);
}

void loop()
{
  uint8_t data1 = AnalogEXP.read(SingleEnded, 7);
	uint8_t data2 = AnalogEXP.read(SingleEnded, 6);
	uint8_t test = AnalogEXP.read(Differential, 5);


  Serial.printlnf("ADC Raw: %d, %d, %d", data1, data2, data3);
  delay(1000);
}