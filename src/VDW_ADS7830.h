#ifndef VDW_ADS7830_H
#define VDW_ADS7830_H

#include "Particle.h"

enum ConversionType {
  Differential,
  SingleEnded = 0x80,
};

#ifndef DEBUG_VDW_ADS7830
#define DEBUG_VDW_ADS7830 0
#endif

class VDW_ADS7830
{
public:

  VDW_ADS7830(uint8_t address)
    : _address(address)
    {}

  void init(){
    // Initialize the I2C bus if not already enabled
    if (!Wire.isEnabled()) {
      Wire.begin();
    }
  }

  uint8_t read(ConversionType type, uint8_t pin, bool PDinternalRef=false, bool PDADC=true);

private:
  uint8_t _address;

  #if DEBUG_VDW_ADS7830
    void printBinary(uint8_t byte){
      Serial.print("0b");
      for(int i=7; i>=0; i--){
        Serial.print(byte>>i & 0x01);
        if(i==4) Serial.print(" ");
      }
      Serial.println();
    }
  #endif
};

#endif