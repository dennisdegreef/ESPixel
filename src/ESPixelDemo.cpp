//
// Created by Dennis de Greef on 19/12/15.
//

#include "ESPixelDemo.h"

ESPixelDemo::ESPixelDemo(NeoPixelBus& bus) {
    strip = &bus;
    i = 0;
}

void ESPixelDemo::loop() {
    int modulo = i % 4;
    RgbColor c;

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

    strip->SetPixelColor(i, c);
    strip->Show();

    if (i == 150) {
        Serial.println("Reset loop");
        i = 0;
    }

    i++;
    delay(100);

}