/**
 * File: LcdBarGraphX.h
 * Description:
 * LcdBarGraphX is an Arduino library for displaying analog values in LCD display, 
 *   which is previously initialized. This library uses LCD library (https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home) for displaying.
 *
 * Author: Balazs Kelemen
 * Contact: prampec+arduino@gmail.com
 * Copyright: 2010 Balazs Kelemen
 * Credits: Hans van Neck
 * Copying permission statement:
    This file is part of LcdBarGraphX.

    LcdBarGraphX is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef LCDBARGRAPH_H
#define LCDBARGRAPH_H

#include <LiquidCrystal_I2C.h>

#include "Arduino.h"

#define USE_BUILDIN_FILLED_CHAR  0xFF // -- Char 0xFF is usualy a filled character. Uncomment if you want the library to create the filled char at the expense of 26 bytes.

class LcdBarGraphX
{
public:
    /**
     * Create an instance of the class. The bar will be drawn in the startY row 
	 * of the LCD, from the startX column positon (inclusive) to to the startX+numCols column position
	 * (inclusive).
	 * lcd - A LiquidCristal instance should be passed.
	 * numCols - Width of the bar.
	 * startX - Horzontal starting position (column) of the bar. Zero based value.
	 * startY - Vertical starting position (row) of the bar. Zero based value.
     */
    LcdBarGraphX(LiquidCrystal_I2C lcd, byte numCols, byte startX = 0, byte startY = 0);
    /**
     * Draw a bargraph with a value between 0 and maxValue.
     */
    void drawValue(int value, int maxvalue);
   /**
    * Initializes the display.
    */
   void begin();
	
private:
    LiquidCrystal_I2C _lcd;
    byte _numCols;
    byte _startX;
    byte _startY;
    int _prevValue;
    byte _lastFullChars;
	boolean _initialized = false;

#ifndef USE_BUILDIN_FILLED_CHAR
    static byte _level0[8];
#endif
    static byte _level1[8];
    static byte _level2[8];
    static byte _level3[8];
    static byte _level4[8];
};

#endif
