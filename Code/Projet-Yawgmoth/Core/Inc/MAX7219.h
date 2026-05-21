#ifndef MAX7219H
#define MAX7219H
    #include "SPI.h"
    void MAX7219_Init();
    void MAX7219_Display(unsigned char digit, unsigned char value);
#endif