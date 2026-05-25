#include "MAX7219.h"

void MAX7219_Init(SPI_HandleTypeDef hspi1) {
  // Initialize the MAX7219 display driver
  SPI_SendData(hspi1,0x09); // Decode mode register
  SPI_SendData(hspi1,0x00); // No decode for digits
  SPI_SendData(hspi1,0x0A); // Intensity register
  SPI_SendData(hspi1,0x0F); // Maximum intensity
  SPI_SendData(hspi1,0x0B); // Scan limit register
  SPI_SendData(hspi1, 0x07); // Display all digits
  SPI_SendData(hspi1, 0x0C); // Shutdown register
  SPI_SendData(hspi1, 0x01); // Normal operation (not shutdown)
  
}

void MAX7219_Display(SPI_HandleTypeDef hspi1, unsigned char digit, unsigned char value) {
  // Send the digit and value to the MAX7219 display driver
  SPI_SendData(hspi1, digit); // Digit register (1-8)
  SPI_SendData(hspi1, value); // Value to display (0-15)
}

void MAX7219_Clear(SPI_HandleTypeDef hspi1) {
  // Clear all digits on the MAX7219 display
  for (unsigned char digit = 1; digit <= 8; digit++) {
    SPI_SendData(hspi1, digit); // Digit register (1-8)
    SPI_SendData(hspi1, 0x00); // Clear the digit
  }
}

