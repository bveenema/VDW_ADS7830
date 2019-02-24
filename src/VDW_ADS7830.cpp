#include "VDW_ADS7830.h"

uint8_t VDW_ADS7830::read(ConversionType type, uint8_t pin, bool PDinternalRef, bool PDADC){
    // Prevent operation if invalid channel
    if(pin > 7) return 0;

    // Create the command byte
    // type     --> MSB is 1 for SingleEnded conversion (0x80) and 0 for differential
    // pin%2<<6 --> Bit6 is 0 for even pins and 1 for odd pins
    // pin/2<<4 --> Bit5 and Bit4 represents a 2 bit number that is multipied by 2 and added to Bit6 to get pin number
    uint8_t commandByte = type | pin%2<<6 | pin/2<<4 | !PDinternalRef<<3 | !PDADC<<2;
    #if DEBUG_VDW_ADS7830
      printBinary(commandByte);
    #endif

    Wire.beginTransmission(_address);
    Wire.write(commandByte);
    Wire.endTransmission(false);

    uint8_t ADCRaw = 0;
    Wire.requestFrom(_address, 1);
    while(Wire.available()){
      ADCRaw = Wire.read();
    }
    return ADCRaw;
  }