/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * Particle_Attractor.cpp - particle with an attractor
 */

#include "Particle_Attractor.h"

uint16_t Particle_Attractor::atx = 0;
uint16_t Particle_Attractor::aty = 0;
int16_t Particle_Attractor::atf = 4;

Particle_Attractor::Particle_Attractor(void)
{
    isAlive = 0;
}

void Particle_Attractor::update(ps_globals_t *g)
{
    int16_t dx, dy, tempX, tempY, tempVx, tempVy;
    int16_t acx, acy;
    float mult;
    //age
    //ttl--;
    if (ttl == 0) {
        isAlive = false;
    }

    dx = (int16_t)atx - x;
    dy = (int16_t)aty - y;
    mult = (float)atf/sqrt(dx*dx+dy*dy);
    acx = (int16_t)(mult*dx);
    acy = (int16_t)(mult*dy);

    //apply acceleration
    tempVx = vx+acx;
    tempVy = vy+acy;

    tempX = x + tempVx;
    tempY = y + tempVy;

    if (tempX < 0 || tempX > g->max_x){
        tempVx = 0;//-tempVx;
    }
    if (tempY < 0 || tempY > g->max_y){
        tempVy = 0;//-tempVy;
    }

    if (tempVx > 50 || tempVx < -50) vx = random(10)-5;
    else vx = tempVx;

    if (tempVy > 50 || tempVy < -50) vy = random(10)-5;
    else vy = tempVy;

    if (tempX > g->max_x) x = g->max_x;
    else if (tempX < 0) x = 0;
    else x = tempX;

    if (tempY > g->max_y) y = g->max_y;
    else if (tempY < 0) y = 0;
    else y = tempY;
}

