#include "interface.h"
#include <iostream>

using namespace std;

STATUS key(int z)
{
	if (z == 224)
	{
		char c;
		c = _getch();
		if (c == 72)
			return UP;
		if (c == 80)
			return DOWN;
		if (c == 77)
			return RIGHT;
		if (c == 75)
			return LEFT;
	}
	else if (z == 13)
		return ENTER;
	else if (z == ESC)
		return esc;
}

void draw(int x, int y, int color) {
	point upleft, downright;

	upleft.x = x;
	upleft.y = 13;
	downright.x = y;
	downright.y = 16;

	TextColor(color);
	DrawRectangle(upleft, downright);
}

int control(str thaotac[], int n) {
	int tt = 0;
	int *mau = new int[n];
	for (int i = 0; i < n; i++)
		mau[i] = MAUCHU;
	mau[0] = MAUNEN2;

	gotoxy(10, 1);
	printf("   #HH||                  #|             ##HH|            H| ");
	gotoxy(10, 2);
	printf("  ##    ## H|#H|  #HH|#HH|   ##H|  #HH|  ##  ||#H| ##|    H| ");
	gotoxy(10, 3);
	printf("  ##    ##H|## H|##H|##H| #| ## H|## H|  ##HH|## H|  H| #HH|");
	gotoxy(10, 4);
	printf("  ##    ##  ## H|   H|  H|#| ## H| #HH|  ## H|## H|##H|## H| ");
	gotoxy(10, 5);
	printf("   #HH||##   #H| ##H|##H| #H|## H|   H|  ##  ||#H| ##HH|#HH| ");
	gotoxy(10, 6);
	printf("                                   ##H|                       ");

	while (1)
	{
		for (int i = 0; i < n; i++) {
			TextColor(mau[i]);
			gotoxy(35, 12 + i);
			printf("%s\n", thaotac[i]);
		}

		int z = _getch();
		STATUS status = key(z);
		switch (status) {
		case UP: {
			if (tt == 0)
				tt = n - 1;
			else
				tt--;
			break;
		}
		case DOWN: {
			if (tt == n - 1)
				tt = 0;
			else
				tt++;
			break;
		}
		case esc:
		{
			clrscr();
			return 0;
		}
		case ENTER:
		{
			return tt;
		}
		}
		//Reset lai mau sau khi da chon lai thao tac de in ra
		for (int i = 0; i <= n; i++)
			mau[i] = MAUCHU;
		mau[tt] = MAUNEN2;
	}
}

void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX)& ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}