// This system contains:
// Capacitative Moisture sensor => Analog Comparator 
// 16 x 2 LCD Display => I2C
// HC-05 Bluetooth Module => UART || OR || ESP32 for Bluetooth  & Wi-Fi (SPI bus from TM123GH6PM to Arduino)

#include <inttypes.h>
#include <float.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "clock.h"
#include "eeprom.h"
#include "uart0.h"
#include "tm4c123gh6pm.h"
#include "wait.h"
#include "sortEvent.h"
#include "getInput.h"

#define C0_PIN PORTC,7
#define C0_MASK 128         // Port C7 for Analog Comparator

void initHW()
{
    initSystemClockTo40Mhz();

    enablePort(PORTC);
    selectPinAnalogInput(C0_PIN);

    initUart0();                                         // Enable UART
    setUart0BaudRate(115200, 40e6);
    _delay_cycles(3);

    COMP_ACREFCTL_R |= COMP_ACREFCTL_EN;                 // Enable the reference module
    COMP_ACREFCTL_R &= ~COMP_ACREFCTL_RNG;               // Setting internal reference to high range
    COMP_ACREFCTL_R |= 0xF;                              // Use internal voltage reference of 2.469
    COMP_ACCTL0_R |= COMP_ACCTL0_CINV | COMP_ACCTL0_ISEN_RISE | COMP_ACCTL0_ASRCP_REF;  //CINV - invert, ISEN_RISE - RIsing edge, ASRCP_REF - Internal VREF
}

int main(void)
{
    initHW();
    char data;
    while(true)
    {
        if(isCommand(&data, "ON", 0))
        {
            
        }
    }
}