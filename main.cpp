/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

#include "TextLCD.h"


TextLCD lcd(PB_14, PB_13, PA_0, PA_1, PA_4, PB_0); // rs, e, d4-d7

int i=0;

int main()
{
    lcd.cls();
    wait_us(1000);
    lcd.printf("Universidad Distrital Francisco Jose de caldas\n");
    for (int i=0;i<15;i++)
    {
    lcd.writeCommand(0x18);
    wait_us(500e3);
    }

    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);

    while (true) {
        lcd.locate(0, 1);    
        lcd.printf("El conteo es: %u", i++);

        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}
