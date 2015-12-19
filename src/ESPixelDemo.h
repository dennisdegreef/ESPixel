//
// Created by Dennis de Greef on 19/12/15.
//

#ifndef ESPIXEL_ESPIXELDEMO_H
#define ESPIXEL_ESPIXELDEMO_H

#include <NeoPixelBus.h>
#include "ESPixel.h"

class ESPixelDemo/*: public ESPixel */{

public:
    ESPixelDemo(NeoPixelBus& bus);
    void loop();


private:
    NeoPixelBus *strip;
    int i;

};

#endif //ESPIXEL_ESPIXELDEMO_H
