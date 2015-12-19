#include <Arduino.h>
#include <NeoPixelBus.h>

#define NEOPIXELS 150
#define NEOPIXELS_PIN 5

NeoPixelBus strip = NeoPixelBus(NEOPIXELS, NEOPIXELS_PIN);

uint8_t i;
int modulo;
RgbColor c;

void setup() {
    Serial.begin(115200);
    Serial.println();
    delay(2000);

    strip.Begin();
    strip.Show();
}

void loop() {

    modulo = i % 4;

    switch(modulo) {
        case 0:
            c = RgbColor(0xff, 0x00, 0x00);
            break;
        case 1:
            c = RgbColor(0x00, 0xff, 0x00);
            break;
        case 2:
            c = RgbColor(0x00, 0x00, 0xff);
            break;
        case 3:
            c = RgbColor(0x00, 0x00, 0x00);
            break;
        default:
            Serial.println("Invalid modulo value in switch statement, did you change the modulo?");
            delay(100);
            panic();
    }

    strip.SetPixelColor(i, c);
    strip.Show();

    if (i == 150) {
        Serial.println("Reset loop");
        i = 0;
    }

    i++;
    delay(100);

}