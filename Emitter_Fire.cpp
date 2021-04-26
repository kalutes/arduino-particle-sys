/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * Emitter_Fire.cpp - emit particles to simulate fire
 */

#include "Emitter_Fire.h"

uint8_t Emitter_Fire::baseHue = 128; //blues
uint8_t Emitter_Fire::maxTtl = 128;

Emitter_Fire::Emitter_Fire()
{
    counter = 0;
    cycleHue = false;
}

void Emitter_Fire::update(ParticleSysConfig *g)
{
}

void Emitter_Fire::emit(Particle_Abstract *particle, ParticleSysConfig *g)
{
    counter++;
    if (cycleHue) baseHue = (counter>>2)%240;

    if ((counter & 0x01) == 0) {
        particle->hue = baseHue+16;
    } else {
        particle->hue = baseHue;
    }
 
    particle->x = random(0, g->max_x);
    particle->ttl = random(1, 100);

    particle->y = g->max_y-1;

    particle->vx = 0;
    particle->vy = 0;


    particle->isAlive = true;
}
