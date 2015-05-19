
/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * PartMatrix.cpp renders a particle system to an RGB matrix
 */

#include "FastLEDPartMatrix.h"

FastLEDPartMatrix::FastLEDPartMatrix()
{
}

void FastLEDPartMatrix::render(Particle_Abstract particles[], byte numParticles, CRGB *_leds)
{
    byte row, col;
    uint16_t dx, dy;
    unsigned long tempVal;
    CRGB baseRGB;

    //go over particles and update matrix cells on the way
    for(int i = 0; i<numParticles; i++) {
        if (! particles[i].isAlive) {
            continue;
        }
        //generate RGB values for particle
        baseRGB = CHSV(particles[i].hue, 255,255);

        dx = PS_P_RADIUS - (particles[i].x % PS_P_RADIUS);
        dy = PS_P_RADIUS - (particles[i].y % PS_P_RADIUS);

        //bottom left
        col = particles[i].x / PS_P_RADIUS;
        row = particles[i].y / PS_P_RADIUS;
        tempVal = ((unsigned long)dx*dy*particles[i].ttl)/PS_P_SURFACE;
        if(tempVal > 255) {tempVal = 255;}
        addColor(col, row, &baseRGB, tempVal, _leds);

        //bottom right;
        col++;
        if (col < PS_PIXELS_X) {
            tempVal = ((unsigned long)(PS_P_RADIUS-dx)*dy*particles[i].ttl)/PS_P_SURFACE;
            if(tempVal > 255) {tempVal = 255;}
            addColor(col, row, &baseRGB, tempVal, _leds);
        }

        //top right
        row++;
        if (col < PS_PIXELS_X && row < PS_PIXELS_Y) {
            tempVal = ((unsigned long)(PS_P_RADIUS-dx)*(PS_P_RADIUS-dy)*particles[i].ttl)/PS_P_SURFACE;
            if(tempVal > 255) {tempVal = 255;}
            addColor(col, row, &baseRGB, tempVal, _leds);
        }

        //top left
        col--;
        if (row < PS_PIXELS_Y) {
            tempVal = ((unsigned long)dx*(PS_P_RADIUS-dy)*particles[i].ttl)/PS_P_SURFACE;
            if(tempVal > 255) {tempVal = 255;}
            addColor(col, row, &baseRGB, tempVal, _leds);
        }
    }
}


void FastLEDPartMatrix::addColor(byte col, byte row, CRGB *colorRGB, byte value, CRGB *_leds)
{
    // add colorRGB with intensity of value at position (col, row) to the existing RGB value
    CRGB newColor = colorRGB[0];
    newColor.fadeToBlackBy(255-value);
    _leds[XY(col,row)] += newColor;
}

void FastLEDPartMatrix::reset(CRGB *_leds)
{
    //init all pixels to black
    //memset8(_leds,0,sizeof(CRGB)*PS_PIXELS_X*PS_PIXELS_Y);
    for(byte y=0; y<PS_PIXELS_Y; y++) {
        for(byte x=0; x<PS_PIXELS_X; x++) {
            _leds[XY(x,y)] = CRGB(0,0,0);
        }
    }
}

void FastLEDPartMatrix::fade(CRGB *_leds)
{
    //fade all pixels
    for (byte y=0; y<PS_PIXELS_Y; y++) {
        for(byte x=0; x<PS_PIXELS_X; x++) {
            _leds[XY(x,y)].fadeToBlackBy(128);
        }
    }
}

void FastLEDPartMatrix::fadeBy(byte amount, CRGB *_leds)
{
    //fade all pixels
    for (byte y=0; y<PS_PIXELS_Y; y++) {
        for(byte x=0; x<PS_PIXELS_X; x++) {
            _leds[XY(x,y)].fadeToBlackBy(amount);
        }
    }
}
