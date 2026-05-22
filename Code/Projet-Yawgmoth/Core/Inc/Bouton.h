#ifndef BOUTON_H
#define BOUTON_H
#ifdef __cplusplus
extern "C" {
#include "main.h"
#include "stm32f1xx_it.h"
#include "stm32f1xx_hal_conf.h"

    class Bouton 
    {
        private:
        GPIO_TypeDef* GPIOx;
        uint16_t GPIO_Pin;
        public:
        Bouton(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
        bool isPressed();

    };
}
#endif
#endif
