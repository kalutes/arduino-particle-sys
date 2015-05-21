
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

void FastLEDPartMatrix::render(Particle_Abstract particles[], byte numParticles, CRGB *_leds, ParticleSysGlobals *g)
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

        dx = g->res - (particles[i].x % g->res);
        dy = g->res - (particles[i].y % g->res);

        //bottom left
        col = particles[i].x / g->res;
        row = particles[i].y / g->res;
        tempVal = ((unsigned long)dx*dy*particles[i].ttl)/g->res2;
        if(tempVal > 255) {tempVal = 255;}
        addColor(col, row, &baseRGB, tempVal, _leds);

        //bottom right;
        col++;
        if (col < g->width) {
            tempVal = ((unsigned long)(g->res-dx)*dy*particles[i].ttl)/g->res2;
            if(tempVal > 255) {tempVal = 255;}
            addColor(col, row, &baseRGB, tempVal, _leds);
        }

        //top right
        row++;
        if (col < g->width && row < g->height) {
            tempVal = ((unsigned long)(g->res-dx)*(g->res-dy)*particles[i].ttl)/g->res2;
            if(tempVal > 255) {tempVal = 255;}
            addColor(col, row, &baseRGB, tempVal, _leds);
        }

        //top left
        col--;
        if (row < g->height) {
            tempVal = ((unsigned long)dx*(g->res-dy)*particles[i].ttl)/g->res2;
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

void FastLEDPartMatrix::reset(CRGB *_leds, ParticleSysGlobals *g)
{
    //init all pixels to black
    //memset8(_leds,0,sizeof(CRGB)*PS_PIXELS_X*PS_PIXELS_Y);
    for(byte y=0; y<g->height; y++) {
        for(byte x=0; x<g->width; x++) {
            _leds[XY(x,y)] = CRGB(0,0,0);
        }
    }
}

void FastLEDPartMatrix::fade(CRGB *_leds, ParticleSysGlobals *g)
{
    //fade all pixels
    for (byte y=0; y<g->height; y++) {
        for(byte x=0; x<g->width; x++) {
            _leds[XY(x,y)].fadeToBlackBy(128);
        }
    }
}

void FastLEDPartMatrix::fadeBy(byte amount, CRGB *_leds, ParticleSysGlobals *g)
{
    //fade all pixels
    for (byte y=0; y<g->height; y++) {
        for(byte x=0; x<g->width; x++) {
            _leds[XY(x,y)].fadeToBlackBy(amount);
        }
    }
}
