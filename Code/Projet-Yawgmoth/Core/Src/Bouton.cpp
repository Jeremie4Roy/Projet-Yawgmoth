
#include "Bouton.h"

Bouton::Bouton(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    this->GPIOx = GPIOx;
    this->GPIO_Pin = GPIO_Pin;
}