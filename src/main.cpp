#ifdef ARDUINO_ARCH_STM32

#include <Arduino.h>


void setup() {
  // put your setup code here, to run once:
   // Initialize LED pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    // Set the LED HIGH
  digitalWrite(LED_BUILTIN, HIGH);

  // Wait for a second
  delay(200);

  // Set the LED LOW
  digitalWrite(LED_BUILTIN, LOW);

   // Wait for a second
  delay(150);
}

#else

#include "main.h"

void LED_Init();

int main(void) {
  HAL_Init();
  LED_Init();
  while (1)
  {
    HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
    HAL_Delay(100);
    static long c =0;
    c++;
  }
}

void LED_Init() {
  LED_GPIO_CLK_ENABLE();
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = LED_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);
}

void SysTick_Handler(void) {
  HAL_IncTick();
}

#endif
