#include "SPI.h"

void SPI_SendData(unsigned char data) {
  // Set the Slave Select (SS) pin low to select the slave device
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

  // Send the data byte by byte
  for (int i = 0; i < 8; i++) {
    // Set the MOSI pin according to the current bit of the data
    if (data & (1 << (7 - i))) {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); // MOSI high
    } else {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); // MOSI low
    }

    // Toggle the SCK pin to indicate that the bit is ready to be read
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); // SCK high
    HAL_Delay(1); // Short delay to ensure the slave can read the bit
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); // SCK low
    HAL_Delay(1); // Short delay before sending the next bit
  }

  // Set the Slave Select (SS) pin high to deselect the slave device
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

void SPI_Init(void) {
  // Initialize the GPIO pins for SPI communication
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  // Enable the clock for the GPIO port
  __HAL_RCC_GPIOA_CLK_ENABLE();

  // Configure SCK, MOSI, and SS pins as output
  GPIO_InitStruct.Pin = GPIO_PIN_3 | GPIO_PIN_5 | GPIO_PIN_4; // SCK, MOSI, SS
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  // Set the SS pin high to deselect the slave device initially
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

unsigned char SPI_ReceiveData() {
  unsigned char receivedData = 0;

  // Set the Slave Select (SS) pin low to select the slave device
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

  // Read the data byte by byte
  for (int i = 0; i < 8; i++) {
    // Toggle the SCK pin to indicate that the master is ready to read the bit
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); // SCK high
    HAL_Delay(1); // Short delay to ensure the slave can set the bit

    // Read the bit from the MISO pin
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == GPIO_PIN_SET) { // MISO pin
      receivedData |= (1 << (7 - i)); // Set the corresponding bit in receivedData
    }

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); // SCK low
    HAL_Delay(1); // Short delay before reading the next bit
  }

  // Set the Slave Select (SS) pin high to deselect the slave device
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

  return receivedData;
}

