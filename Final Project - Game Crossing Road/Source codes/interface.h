#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include "process.h"

#define MAUNEN 74
#define MAUCHU 1415
#define MAUNEN2 74
#define ESC 27

typedef char str[50];

enum STATUS { UP, DOWN, LEFT, RIGHT, ENTER, esc };
STATUS key(int z);

void draw(int x, int y, int color);

int control(str thaotac[], int n);

void FixConsoleWindow();

#endif