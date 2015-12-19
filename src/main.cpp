#include <Arduino.h>
#include <NeoPixelBus.h>

#include "ESPixel.h"
#include "ESPixelDemo.h"

#define NEOPIXELS 150
#define NEOPIXELS_PIN 5

NeoPixelBus strip = NeoPixelBus(NEOPIXELS, NEOPIXELS_PIN);

const uint8_t ESPIXEL_MODE_DEMO = 1;
uint8_t mode = ESPIXEL_MODE_DEMO;

ESPixelDemo app = ESPixelDemo(strip);

void setup() {
    Serial.begin(115200);
    Serial.println();
    delay(2000);

    switch (mode) {
        case ESPIXEL_MODE_DEMO:
            //app = ESPixelDemo(strip);
            break;
        default:
            // Reiterate in demo mode
            mode = ESPIXEL_MODE_DEMO;
            return;
    }

    strip.Begin();
    strip.Show();
}

void loop() {
    app.loop();
}
