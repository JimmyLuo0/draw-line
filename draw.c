#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c){
  int dy, dx, leftx, lefty, rightx, righty;
  if(x0 <= x1){
    dx = x1 - x0;
    dy = y1 - y0;
    leftx = x0;
    lefty = y0;
    rightx = x1;
    righty = y1;
  }
  else{
    draw_line(x1,y1,x0,y0,s,c);
  }
  if (dy <= dx && dy >= 0){
    draw_oct1(leftx, lefty, rightx, righty, s, c, dx, dy);
  }
  if(dy > dx  && dy >= 0){
    draw_oct2(leftx, lefty, rightx, righty, s, c, dx, dy);
  }
  if(dx >= -dy  && dy < 0){
    draw_oct8(leftx, lefty, rightx, righty, s, c, dx, dy);
  }
  if(dx < -dy && dy < 0 ){
    draw_oct7(leftx, lefty, rightx, righty, s, c, dx, dy);
  }
}

void drawh(int x0, int y0, int x1, screen s, color c){
  int x = x0;
  while(x <= x1){
    plot(s,c,x,y0);
    x++;
  }
}

void drawv(int x0, int y0, int y1, screen s, color c){
  int y = y0;
  while(y <= y1){
    plot(s,c,x0,y);
    y++;
  }
}

void draw_oct1(int x0, int y0, int x1, int y1, screen s, color c, int dx, int dy){
  if(dy == 0){
    drawh(x0,y0,x1,s,c);
  }
  else{
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
}

void draw_oct2(int x0, int y0, int x1, int y1, screen s, color c, int dx, int dy){
  if(dx == 0){
    drawv(x0,y0, y1, s, c);
  }
  else{
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
}

void draw_oct7(int x0, int y0, int x1, int y1, screen s, color c, int dx, int dy){
  int x = x0;
  int y = y0;
  int d = dy + 2 * dx;
  while (y >= y1){
    plot(s,c,x,y);
    if(d>0){
      x++;
      d += 2*dy;
    }
    y--;
    d += 2*dx;
  }
}

void draw_oct8(int x0, int y0, int x1, int y1, screen s, color c, int dx, int dy){
  int x = x0;
  int y = y0;
  int d = 2 * dy + dx;
  while (x <= x1){
    plot(s,c,x,y);
    if(d<0){
      y--;
      d += 2*dx;
    }
    x++;
    d += 2*dy;
  }
}
