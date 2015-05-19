/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/* Adaptation for FastLED by Gottfried Mayer github.com/fuse314 */

/**
 * FastLEDPartMatrix.h renders a particle system to a FastLED RGB matrix
 */

#ifndef fastled_part_matrix_h
#define fastled_part_matrix_h

#include "PsConstants.h"
#include "Particle_Abstract.h"
#include <FastLED.h>

//#include "Arduino.h"

class FastLEDPartMatrix {
public:

    FastLEDPartMatrix();
    void render(Particle_Abstract particles[], byte numParticles, CRGB *_leds);
    void reset(CRGB *_leds);    //set each pixel to 0
    void fade(CRGB *_leds);     //divide each pixel by half
    void fadeBy(byte amount, CRGB *_leds); //substract amount from each pixel

private:
    void addColor(byte col, byte row, CRGB *rgb, byte value, CRGB *_leds);
};

extern uint16_t XY(uint8_t x, uint8_t y);

#endif /* fastled_part_matrix_h */