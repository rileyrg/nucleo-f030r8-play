#ifdef RGR_ARDUINO

#include <Arduino.h>

void setup()
{
  // put your setup code here, to run once:
  // Initialize LED pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // Set the LED HIGH
  digitalWrite(LED_BUILTIN, HIGH);

  // Wait for a second
  delay(50);

  // Set the LED LOW
  digitalWrite(LED_BUILTIN, LOW);

  // Wait for a second
  delay(50);
}

#else

#include "main.h"


void LED_Init();

void HAL_Delay2(uint32_t milliseconds) {

   /* Initially clear flag */

   (void) SysTick->CTRL;

   while (milliseconds != 0) {

      /* COUNTFLAG returns 1 if timer counted to 0 since the last flag read */

      milliseconds -= (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) >> SysTick_CTRL_COUNTFLAG_Pos;

   }

}

int main(void)
{

  HAL_Init();
  LED_Init();

  while (1)
  {
       HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
       HAL_Delay(1000);
  }
}

void LED_Init()
{
  LED_GPIO_CLK_ENABLE();
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = LED_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);
}

void SysTick_Handler(void)
{
  HAL_IncTick();
}

#endif
