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

struct ps_globals_t {
    uint8_t  width;
    uint8_t  height;
    uint8_t  res;
    uint16_t res2;
    uint16_t max_x;
    uint16_t max_y;
};

#endif

/*
//some constants
//matrix pixels
#ifndef PS_PIXELS_X
#define PS_PIXELS_X 64
#endif

#ifndef PS_PIXELS_Y
#define PS_PIXELS_Y 8
#endif

//particle dimensions
#ifndef PS_P_RADIUS
#define PS_P_RADIUS 32
#endif

#ifndef PS_P_SURFACE
#define PS_P_SURFACE (PS_P_RADIUS*PS_P_RADIUS)
#endif

//box dimensions
#ifndef PS_MAX_X
#define PS_MAX_X (PS_PIXELS_X*PS_P_RADIUS-1)
#endif

#ifndef PS_MAX_Y
#define PS_MAX_Y (PS_PIXELS_Y*PS_P_RADIUS-1)
#endif
*/