#ifndef MAX7219H
#define MAX7219H
    #include "SPI.h"
    void MAX7219_Init(SPI_HandleTypeDef hspi1);
    void MAX7219_Display(SPI_HandleTypeDef hspi1, unsigned char digit, unsigned char value);
    void MAX7219_Clear(SPI_HandleTypeDef hspi1);
#endif