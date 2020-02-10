#include "ml6.h"

#ifndef DRAW_H
#define DRAW_H

void draw_line(int x0, int y0, int x1, int y1, screen s, color c);
void draw_oct1(int x0, int y0, int x1, int y1, screen s, color c, int dx, int dy);
void draw_oct2(int x0, int y0, int x1, int y1, screen s, color c, int dx, int dy);
void draw_oct7(int, int, int, int, screen, color, int, int);
void draw_oct8(int, int, int, int, screen, color, int, int);
void drawh(int x0, int y0, int x1, screen s, color c);
void drawv(int x0, int y0, int y1, screen s, color c);



#endif
