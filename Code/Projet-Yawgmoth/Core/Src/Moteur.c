#include "Moteur.h"
#include "main.h"

void Moteur_SetState(bool bState) {
  if (bState) {
    HAL_GPIO_WritePin(MotorOut_GPIO_Port, MotorOut_Pin, GPIO_PIN_SET); // Turn on the motor
  } else {
    HAL_GPIO_WritePin(MotorOut_GPIO_Port, MotorOut_Pin, GPIO_PIN_RESET); // Turn off the motor
  }
}