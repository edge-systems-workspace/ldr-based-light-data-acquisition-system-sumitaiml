#include <Arduino.h>
/**
 * @file main.cpp
 * @brief Embedded Light Intensity Monitoring using LDR
 * @author Sumit
 * @date 2026-02-28
 *
 * @details
 * Reads analog brightness data from an LDR sensor and outputs structured
 * information to the Serial Monitor.
 */

/**
 * @brief Analog pin connected to the LDR voltage divider output.
 */
const uint8_t LDR_PIN = A0;

/**
 * @brief ADC threshold used to decide Bright vs Dark.
 *
 * Values greater than or equal to this threshold are considered "Bright".
 */
const int BRIGHT_THRESHOLD = 600;

/**
 * @brief Stores the most recent raw ADC reading from the LDR.
 */
int ldrValue = 0;

/**
 * @brief Arduino setup function.
 *
 * Initializes serial communication at 9600 baud and prints an initialization
 * message together with configuration values.
 */
void setup() {
    Serial.begin(9600);
    while (!Serial) { }
    Serial.println(F("LDR Light Data Acquisition System Initialized"));
    Serial.print(F("Configured LDR pin: "));
    Serial.println(LDR_PIN);
    Serial.print(F("Bright threshold (ADC): "));
    Serial.println(BRIGHT_THRESHOLD);
}

/**
 * @brief Arduino main loop.
 *
 * Reads the analog value from the LDR, prints the raw ADC reading and a
 * human-readable brightness status (Bright/Dark). Runs every 500 ms.
 */
void loop() {
    ldrValue = analogRead(LDR_PIN);

    Serial.print(F("LDR ADC: "));
    Serial.println(ldrValue);

    if (ldrValue >= BRIGHT_THRESHOLD) {
        Serial.println(F("Brightness: Bright"));
    } else {
        Serial.println(F("Brightness: Dark"));
    }

    Serial.println();
    delay(500);
}
