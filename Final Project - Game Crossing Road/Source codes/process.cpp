#include "process.h"

void gotoxy(int column, int line)
{
	COORD coordinate;
	coordinate.X = column;
	coordinate.Y = line;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

//Draw Rectangle
void listof(point upleft, point downright, int y1, int n, int a[]) {

	//////////////////////////////////////////////////////////
	//Ve 4 goc
	gotoxy(upleft.x, upleft.y);
	printf("%c", UPLEFT);
	gotoxy(downright.x, upleft.y);
	printf("%c", UPRIGHT);
	gotoxy(downright.x, downright.y);
	printf("%c", DOWNRIGHT);
	gotoxy(upleft.x, downright.y);
	printf("%c", DOWNLEFT);
	// Ve 3 duong ngang
	for (int i = upleft.x + 1; i < downright.x; i++) {
		gotoxy(i, upleft.y);
		printf("%c", HORIZONTAL);
		gotoxy(i, downright.y);
		printf("%c", HORIZONTAL);
		gotoxy(i, y1);
		printf("%c", HORIZONTAL);
	}
	//Ve n duong doc
	for (int i = upleft.y + 1; i < downright.y; i++) {
		if (i != y1) {
			for (int j = 0; j < n; j++) {
				gotoxy(a[j], i);
				printf("%c", 179);
			}
		}
		else {
			gotoxy(upleft.x, i);
			printf("%c", 195);
			gotoxy(downright.x, i);
			printf("%c", 180);
			for (int j = 1; j < n - 1; j++) {
				gotoxy(a[j], i);
				printf("%c", 197);
			}
		}
	}
	for (int i = 1; i < n - 1; i++) {
		gotoxy(a[i], upleft.y);
		printf("%c", 194);
		gotoxy(a[i], downright.y);
		printf("%c", 193);
	}
	gotoXY(1, 1);
}

void DrawRectangle(point upleft, point downright)
{
	gotoxy(upleft.x, upleft.y);
	printf("%c", UPLEFT);
	gotoxy(downright.x, upleft.y);
	printf("%c", UPRIGHT);
	gotoxy(downright.x, downright.y);
	printf("%c", DOWNRIGHT);
	gotoxy(upleft.x, downright.y);
	printf("%c", DOWNLEFT);
	for (int i = upleft.x + 1; i < downright.x; i++)
	{
		gotoxy(i, upleft.y);
		printf("%c", HORIZONTAL);
		gotoxy(i, downright.y);
		printf("%c", HORIZONTAL);
	}
	for (int i = upleft.y + 1; i < downright.y; i++)
	{
		gotoxy(upleft.x, i);
		printf("%c", VERTICAL);
		gotoxy(downright.x, i);
		printf("%c", VERTICAL);
	}
}