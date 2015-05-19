/*
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/* 
 * ParticleSys.h - generic particle system class
 */

#ifndef p_system_h
#define p_system_h

#include "PsGlobals.h"
#include "Particle_Abstract.h"
#include "Emitter_Abstract.h"


//#include "Arduino.h"

class ParticleSys {
public:
    static byte perCycle;
    static byte res;
    static ps_globals_t g;
    byte numParticles;
    Particle_Abstract *particles;
    Emitter_Abstract *emitter;

    ParticleSys(uint8_t width, uint8_t height, byte numParticles, Particle_Abstract particles[], Emitter_Abstract *emitter);
    void update();

private:
    byte cycleRemaining;
};

#endif /* p_system_h */
