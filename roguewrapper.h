/*
	A wrapper library around rogueutil to make it behave more uniformly between operating systems and terminals.
	Written by Jack R. Fisselbrand
	April 2026
	Language: C
	Compiler: gcc
	============================================================================================================================
	This library aims to create a virtual terminal with character matrices as the character buffer, and color buffers.
	Wrapping of x and y values is implemented, so that if you enter an invalid x or y position, it won't break the program.
	============================================================================================================================
	Future plans:
		I would like to add dynamic virtual terminal sizing at runtime. Currently, the terminal is always 80x24 exactly, but I 
		would like to have the terminal's size be decided when the program runs by dynamically allocating memory for each matrix.
*/

#ifndef ROGUEWRAPPER_H
#define ROGUEWRAPPER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Pre defined terminal width and height. I plan on adding dynamic terminal sizing at runtime later on
#define TERMINAL_WIDTH 80
#define TERMINAL_HEIGHT 24

// Modify or access the print offset of the virtual terminal on the x and y axis
void setPrintOffsetX(int o);
int getPrintOffsetX(void);
void setPrintOffsetY(int o);
int getPrintOffsetY(void);

// Modify or access the cursor visibility. For setting the cursor visibility, 0 = invisible, anything else is visible
void setCursorVis(int v);
int getCursorVis(void);

// Access the amount of rows and columns the terminal currently has
int getTerminalRows(void);
int getTerminalCols(void);

// Modify or access the current selected x1 or y1 positions. I have them as x1 and y1 because I plan on adding x2 and y2 later for drawing lines.
void setX1Pos(int x);
int getX1Pos(void);
void setY1Pos(int y);
int getY1Pos(void);

// Modify or access the character at the current x1 and y1 position on the virtual terminal.
void setCharacter(char c);
char getCharacter(void);

// Modify or access the foreground color at the current x1 and y1 position on the virtual terminal.
void setFgColor(int c);
int getFgColor(void);

// Modify or access the background color at the current x1 and y1 position on the virtual terminal.
void setBgColor(int c);
int getBgColor(void);

// Get the key that is currently being pressed.
char getKeyPress(void);

// Print the foreground color, backround color, and character at the current x1 and y1. Print advances the cursor after printing, stamp does not advance the cursor.
void print(void);
void stamp(void);

// Clear the screen.
void clear(void);

// Clear all colors on the screen.
void clearColor(void);

// Set the cursor visibility back to visible (0)
void resetCursorVis(void);

#endif