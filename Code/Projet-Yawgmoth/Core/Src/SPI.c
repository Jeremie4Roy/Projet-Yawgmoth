#include "SPI.h"
#include "main.h"

void SPI_SendData( SPI_HandleTypeDef hspi1,unsigned char data)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); // Set CS low to select the slave device
    HAL_SPI_Transmit(&hspi1, &data, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); // Set CS high to deselect the slave device
}