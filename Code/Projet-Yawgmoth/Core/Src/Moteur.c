#include "Moteur.h"


void Moteur_SetState(bool bState) {
  if (bState) {
    // Set the motor control pin high to start the motor
    HAL_GPIO_WritePin(GPIOC, MotorControl_Pin, GPIO_PIN_SET);
  } else {
    // Set the motor control pin low to stop the motor
    HAL_GPIO_WritePin(GPIOC, MotorControl_Pin, GPIO_PIN_RESET);
  }
}