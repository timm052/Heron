#include <Arduino.h>
#include <SPI.h>

/*Test Program for ESP32 SPI Comms.*/

/*
SPI library works primarily through two classes - Settings and Bus.

Settings:
Settings classes operate like a profile for your transaction, that is passed to a function within your bus class at the start of any transaction.
Needs three things - Clock speed, MSB or LSB first, and 'SPI Mode' (Clock polarity, clock phase, output edge, data capture edge).

Bus:
Bus class defines things like the pins, slave select settings, clock divider, and contains the actual functions for communications.
Can just be passed the default 'VSPI' or 'HSPI' bus settings.

General Process:
Define classes for settings and buses (remember scoping for future projects - define early and use pointers).
Use [SPIClass].begin to initialise the bus - don't need to pass anything for default.
Use [SPIClass].beginTransaction to open a channel for comms.
Use [SPIClass].transfer to transfer data - takes integer data and can also take integer 'size', unsure of use of size atm.
      Note: transfer is uint8, can also use .transfer16 & .transfer32
            There are also other functions (transferBytes/Bits, write/16/32/Bytes/Pixels/Pattern). Unsure of use - to investigate.


*/

#define SPIspeed 1000000 //SPI Speed (1MHz)


void setup() {
}

void loop() {

  //
  SPISettings dfltSPI(SPIspeed,MSBFIRST,SPI_MODE0);
  SPIClass vspi(VSPI);
  vspi.begin();
  
  vspi.beginTransaction(dfltSPI);
  vspi.transfer(7);
  vspi.endTransaction();
}
