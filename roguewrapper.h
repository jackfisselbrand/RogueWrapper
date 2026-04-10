#ifndef ROGUEWRAPPER_H
#define ROGUEWRAPPER_H

#include <stdio.h>
#include <string.h>

#define TERMINAL_WIDTH 80
#define TERMINAL_HEIGHT 24

void setPrintOffsetX(int o);
int getPrintOffsetX(int o);
void setPrintOffsetY(int o);
int getPrintOffsetY(int o);

void setCursorVis(int v);
int getCursorvis(void);

int getTerminalRows(void);
int getTerminalCols(void);

void setX1Pos(int x);
int getX1Pos(void);
void setY1Pos(int y);
int getY1Pos(void);

void setCharacter(char c);
char getCharacter(void);

void setFgColor(int c);
int getFgColor(void);

void setBgColor(int c);
int getBgColor(void);

char getKeyPress(void);

void print(void);
void stamp(void);

void clear(void);
void clearColor(void);
void resetCursorVis(void);

#endif