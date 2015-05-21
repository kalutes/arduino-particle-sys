/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

#ifndef PS_GLOBALS_T
#define PS_GLOBALS_T
#include <stdint.h>

class ParticleSysGlobals {
public:
    uint8_t width;
    uint8_t height;
    uint8_t res;
    uint16_t res2;
    uint16_t max_x;
    uint16_t max_y;
    ParticleSysGlobals(uint8_t width, uint8_t height);
    ParticleSysGlobals(uint8_t width, uint8_t height, uint8_t res);
private:
    void calcValues(void);
};

/*
struct ps_globals_t {
    uint8_t  width;
    uint8_t  height;
    uint8_t  res;
    uint16_t res2;
    uint16_t max_x;
    uint16_t max_y;
};
*/

#endif
