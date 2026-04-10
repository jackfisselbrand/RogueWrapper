#include "roguewrapper.h"
#include "rogueutil.h"

char screen_char[TERMINAL_HEIGHT][TERMINAL_WIDTH] = {0};
char screen_fgcolor[TERMINAL_HEIGHT][TERMINAL_WIDTH][10] = {0};
char screen_bgcolor[TERMINAL_HEIGHT][TERMINAL_WIDTH][10] = {0};

int terminal_x1 = 0;
int terminal_y1 = 0;
int print_offsetx = 0;
int print_offsety = 0;
int cursor_visibility = 1;



void setPrintOffsetX(int o) {
	print_offsetx = o;
}
int getPrintOffsetX(int o) {
	return print_offsetx;
}
void setPrintOffsetY(int o) {
	print_offsety = o;
}
int getPrintOffsetY(int o) {
	return print_offsety;
}

void setCursorVis(int v) {
	cursor_visibility = v;
	setCursorVisibility(v);
	return;
}
int getCursorvis(void) {
	return cursor_visibility;
}

int getTerminalRows(void) {
	return trows();
}
int getTerminalCols(void) {
	return tcols();
}



void setX1Pos(int x) {
	terminal_x1 = x;
	return;
}
int getX1Pos(void) {
	return terminal_x1;
}
void setY1Pos(int y) {
	terminal_y1 = y;
	return;
}
int getY1Pos(void) {
	return terminal_y1;
}



void setCharacter(char c) {
	screen_char[terminal_x1][terminal_y1] = c;
	return;
}
char getCharacter(void) {
	return screen_char[terminal_x1][terminal_y1];
}



void setFgColor(int c) {
	const char* fgColor = getANSIColor(c);
	for (int i=0; i<strlen(fgColor); i++) {
		screen_fgcolor[terminal_x1][terminal_y1][i] = fgColor[i];
	}

	return;
}
int getFgColor(void) {
	for (int i=0; i<16; i++) {
		if (strcmp(getANSIColor(i), screen_fgcolor[terminal_x1][terminal_y1]) == 0) {
			return i;
		}
	}
	return -1;
}

void setBgColor(int c) {
	const char* bgColor = getANSIBgColor(c);
	for (int i=0; i<strlen(bgColor); i++) {
		screen_bgcolor[terminal_x1][terminal_y1][i] = bgColor[i];
	}

	return;
}
int getBgColor(void) {
	for (int i=0; i<16;i++) {
		if (strcmp(getANSIBgColor(i), screen_bgcolor[terminal_x1][terminal_y1]) == 0) {
			return i;
		}
	}
	return -1;
}



char getKeyPress(void) {
	return nb_getch();
}



void print(void) {
	int x = terminal_x1 + print_offsetx;
	int y = terminal_y1 + print_offsety;

	gotoxy(x, y);
	printf("%s", screen_bgcolor[terminal_x1][terminal_y1]);

	gotoxy(x, y);
	printf("%s", screen_fgcolor[terminal_x1][terminal_y1]);

	gotoxy(x, y);
	printf("%c", screen_char[terminal_x1][terminal_y1]);
	
	terminal_x1++;
	return;
}
void stamp(void) {
	int x = terminal_x1 + print_offsetx;
	int y = terminal_y1 + print_offsety;

	gotoxy(x, y);
	printf("%s", screen_bgcolor[terminal_x1][terminal_y1]);

	gotoxy(x, y);
	printf("%s", screen_fgcolor[terminal_x1][terminal_y1]);

	gotoxy(x, y);
	printf("%c", screen_char[terminal_x1][terminal_y1]);
	gotoxy(x, y);

	return;
}



void clear(void) {
	cls();
	return;
}
void clearColor(void) {
	resetColor();
	return;
}
void resetCursorVis(void) {
	setCursorVis(1);
}