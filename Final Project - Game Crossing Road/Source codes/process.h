#ifndef _PROCESS_H_
#define _PROCESS_H_

#pragma warning(disable: 4996)
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "console.h"
#include <stdlib.h>

#define UPLEFT 218
#define UPRIGHT 191
#define VERTICAL 179
#define HORIZONTAL 196
#define DOWNLEFT 192
#define DOWNRIGHT 217
#define MIDDLEUP 194
#define MIDDLEDOWN 193

#define MAX 50

struct point
{
	int x;
	int y;
};

void DrawRectangle(point upleft, point downright);
void gotoxy(int column, int line);

#endif