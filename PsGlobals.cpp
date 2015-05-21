/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

#include "PsGlobals.h"

ParticleSysGlobals::ParticleSysGlobals(uint8_t width, uint8_t height) {
    this->width = width;
    this->height = height;
    this->res = 32;        // default resolution
    calcValues();
}
ParticleSysGlobals::ParticleSysGlobals(uint8_t width, uint8_t height, uint8_t res) {
    this->width = width;
    this->height = height;
    this->res = res;
    calcValues();
}

void ParticleSysGlobals::calcValues(void) {
    this->res2 = this->res*this->res;
    this->max_x = (this->width * this->res - 1);
    this->max_y = (this->height * this->res - 1);
}
