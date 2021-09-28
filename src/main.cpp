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
  delay(50);
}
