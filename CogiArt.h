// =======================================================================
// CogiArt.h
// Part of the ESP8266 Subscriber Counter Project
// Created by: Mateo Cogeanu
// Date: January 2025
// Description:
// This header file defines a custom font used for displaying text and 
// symbols on the MAX7219 LED matrix in the Subscriber Counter project. 
// The font includes standard alphanumeric characters, punctuation marks, 
// and custom symbols such as smileys, arrows, and shapes.
//
// YouTube Channel: https://www.youtube.com/@CogiArt
//
// How to Use:
// 1. Include this file in your main project.
// 2. Use the `fontSubs` array as the font for the MD_Parola library by 
//    calling `P.setFont(fontSubs);` in your setup() function.
// 3. Modify or extend the font definitions as needed for your project.
//
// Note: This file uses the `MD_MAX72XX::fontType_t` type from the MD_MAX72XX 
//       library. Each character or symbol is defined as an array of bytes 
//       representing the pattern to be displayed.
// =======================================================================

#pragma once // Ensures the file is included only once in a compilation unit

// Custom font definition for MD_MAX72XX
MD_MAX72XX::fontType_t fontSubs[] PROGMEM = 
{
  // Font header (format, width, height, etc.)
  'F', 2, 0, 0, 0, 126, 8,

  // Symbols and Characters (each entry has a comment describing the glyph)
  0,         // 0 - 'Empty Cell'
  5, 32, 22, 16, 22, 32,        // 1 - 'Sad Smiley'
  5, 16, 38, 32, 38, 16,        // 2 - 'Happy Smiley'
  5, 28, 62, 124, 62, 28,       // 3 - 'Heart'
  5, 24, 36, 66, 36, 24,        // 4 - 'Diamond'
  5, 28, 87, 125, 87, 28,       // 5 - 'Clubs'
  5, 28, 82, 113, 82, 28,       // 6 - 'Spades'
  4, 0, 24, 60, 24,             // 7 - 'Bullet Point'
  5, 255, 231, 195, 231, 255,   // 8 - 'Rev Bullet Point'
  4, 0, 24, 36, 24,             // 9 - 'Hollow Bullet Point'
  5, 255, 231, 219, 231, 255,   // 10 - 'Rev Hollow BP'
  5, 48, 72, 58, 6, 14,         // 11 - 'Male'
  5, 38, 41, 121, 41, 38,       // 12 - 'Female'
  5, 64, 127, 5, 5, 7,          // 13 - 'Music Note 1'
  5, 64, 127, 5, 37, 63,        // 14 - 'Music Note 2'
  5, 90, 60, 231, 60, 90,       // 15 - 'Snowflake'
  5, 127, 62, 28, 28, 8,        // 16 - 'Right Pointer'
  5, 8, 28, 28, 62, 127,        // 17 - 'Left Pointer'
  5, 20, 34, 127, 34, 20,       // 18 - 'UpDown Arrows'
  5, 255, 255, 255, 255, 255,   // 19 - 'Full Block'
  5, 240, 240, 240, 240, 240,   // 20 - 'Half Block Bottom'
  3, 255, 255, 255,             // 21 - 'Half Block LHS'
  5, 0, 0, 0, 255, 255,         // 22 - 'Half Block RHS'
  5, 15, 15, 15, 15, 15,        // 23 - 'Half Block Top'
  5, 8, 4, 126, 4, 8,           // 24 - 'Up Arrow'
  5, 16, 32, 126, 32, 16,       // 25 - 'Down Arrow'
  5, 8, 8, 42, 28, 8,           // 26 - 'Right Arrow'
  5, 8, 28, 42, 8, 8,           // 27 - 'Left Arrow'
  5, 170, 0, 85, 0, 170,        // 28 - '30% shading'
  5, 170, 85, 170, 85, 170,     // 29 - '50% shading'
  1, 0,                         // 30 - 'Up Pointer'
  5, 12, 28, 60, 28, 12,        // 31 - 'Down Pointer'

  // Add remaining characters (e.g., A-Z, 0-9, symbols, etc.)
  2, 0, 0,                      // 32 - 'Space'
  1, 46,                        // 33 - '!'
  3, 6, 0, 6,                   // 34 - '"'
  5, 20, 62, 20, 62, 20,        // 35 - '#'
  3, 44, 126, 52,               // 36 - '$'
  3, 18, 8, 36,                 // 37 - '%'
  8, 0, 126, 66, 90, 90, 70, 126, 0, // 38 - '&'
  1, 6,                         // 39 - '''
  2, 28, 34,                    // 40 - '('
  2, 34, 28,                    // 41 - ')'

  // Continue defining more characters...
};