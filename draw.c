#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c){
  //int A = y1-y0; dy
  //int B = x0 - x1; -dx
  int minx = min(x0,x1);
  int miny = min(y0,y1);
  int maxx = max(x0,x1);
  int maxy = max(y0,y1);
  int dx = maxx - minx;
  int dy = maxy - miny;
  if (dy <= dx){
    draw_oct1(minx, miny, maxx, maxy, s, c, dx, dy);
  }
  if(dy > dx){
    draw_oct2(minx, miny, maxx, maxy, s, c, dx, dy);
  }
}

void draw_oct1(int x0, int y0, int x1, int y1, screen s, color c, int dx, int dy){
  int x = x0;
  int y = y0;
  int d = 2 * dy - dx;
  while (x <= x1){
    plot(s,c,x,y);
    if(d>0){
      y++;
      d += -2*dx;
    }
    x++;
    d += 2*dy;
  }
}

void draw_oct2(int x0, int y0, int x1, int y1, screen s, color c, int dx, int dy){
  int x = x0;
  int y = y0;
  int d = dy + 2 * (-dx);
  while (y <= y1){
    plot(s,c,x,y);
    if(d<0){
      x++;
      d += 2*dy;
    }
    y++;
    d += -2*dx;
  }
}

int max(int first, int second){
  if(first>second){
    return first;
  }
  return second;
}

int min(int first, int second){
  if(first<second){
    return first;
  }
  return second;
}
