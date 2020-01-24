/*
Simple test program for configuring UART ports and conducting basic transmission (not receiving) of serial communications with a ESP32-WROOM
23/1/2020
*/

#include <Arduino.h> //Arduino
#include <string.h>  //I use a string below



void setup()
{
    //Need to setup all 3 UARTS, used in main.
    Serial.begin(9600); //Using default settings (inc. pins) for UART0, so just setting baud.
    Serial1.begin(9600,SERIAL_8N1,9,18); //Setting baud, config (8 data bits, no parity, 1 stop bit), RX Pin, TX Pin. Not setting 'invert' our 'timeout'
    Serial2.begin(9600,SERIAL_8N1,16,19); //As above.

    return;
}



void loop() 
{
    while(1){  

       //Middle-A note over MIDI channel 3 with a velocity of 79 Send over Serial 0&1

       //Binary - Split into 8 bit messages - serial functions won't do this automatically.
       Serial.write(0b10010011);//1001 - Note on, 0011 - Channel 3
       Serial.write(0b01000101);//01000101 - Decimal 69 (nice), Middle A
       Serial.write(0b01001111);//01001111 - Velocity, 79
       delay(100);

       //Hex - As above.
       Serial1.write(0x93);
       Serial1.write(0x45);
       Serial1.write(0x4F);
       delay(100);

       //String for comparison.
       //Serial2.write("Serial23456789");
       Serial2.write(0b101010101010101);
       delay(100);
       };


    return;
}