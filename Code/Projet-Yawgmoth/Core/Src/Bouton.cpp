
#include "Bouton.h"
//Constructor
Bouton::Bouton(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    this->GPIOx = GPIOx;
    this->GPIO_Pin = GPIO_Pin;
    ucAntiBounceDelay = 10;
    ucRepetitionDelay = 10;
    eCurrentState = NOT_PRESSED;
}

//Method to get the state of the button with anti-bounce and repetition delay
eBoutonState Bouton::GetState()
{
    if(HAL_GPIO_ReadPin(this->GPIOx, this->GPIO_Pin) == GPIO_PIN_SET)
    {
        if(ucAntiBounceDelay == 0)
        {
            if(eCurrentState == NOT_PRESSED)
            {
                eCurrentState = JUST_PRESSED;
            }else
            {
                eCurrentState = PRESSED;
            }
            if(ucRepetitionDelay == 0)
            {
                ucRepetitionDelay = 10;
                eCurrentState = REPETITION;
            }else
            {
                ucRepetitionDelay--;
            }
        }else
        {
            ucAntiBounceDelay--;
        }
    }else
    {
        if(ucAntiBounceDelay > 10)
       {
            ucRepetitionDelay = 10;
            if(eCurrentState == REPETITION || eCurrentState == PRESSED)
            {
            eCurrentState = JUST_PRESSED;
            } else
            {
            eCurrentState = NOT_PRESSED;
            }
       }else
       {
        ucAntiBounceDelay++;
       }
      
    }
    return eCurrentState;
} 

unsigned char Bouton::ucReadAnitBounceDelay()
{
    return ucAntiBounceDelay;
}

unsigned char Bouton::ucReadRepetitionDelay()
{
    return ucRepetitionDelay;
}

