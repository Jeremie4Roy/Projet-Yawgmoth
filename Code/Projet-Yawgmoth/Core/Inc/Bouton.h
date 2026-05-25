#ifndef BOUTON_H
#define BOUTON_H
#ifdef __cplusplus
extern "C" {
#include "main.h"
#include "stm32f1xx_it.h"
#include "stm32f1xx_hal_conf.h"
enum eBoutonState {NOT_PRESSED, JUST_PRESSED, PRESSED, REPETITION, RELEASED};

    class Bouton 
    {
        private:
        GPIO_TypeDef* GPIOx;
        uint16_t GPIO_Pin;
        unsigned char ucAntiBounceDelay;
        unsigned char ucRepetitionDelay;
        eBoutonState eCurrentState;
        public:
        Bouton(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
        eBoutonState GetState();
        unsigned char ucReadAnitBounceDelay();
        unsigned char ucReadRepetitionDelay();
    };
}
#endif
#endif
