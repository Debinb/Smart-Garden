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

#define C0_MASK 128         // Port C7 for Analog Comparator

void initHW()
{
    initSystemClockTo40Mhz();

    initUart0();
    setUart0BaudRate(115200, 40e6);
}