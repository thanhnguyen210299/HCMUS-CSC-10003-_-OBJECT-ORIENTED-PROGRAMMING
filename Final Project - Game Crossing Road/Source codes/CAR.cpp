#include "CAR.h"

void CCAR::Draw()
{
	TextColor(112);
	//draw car
	int k = CVEHICLE::mX;
	TextColor(127);
	gotoxy(k, 11);
	printf(" %c%c ", 176, 219);

	TextColor(113);
	gotoxy(k, 12);
	printf("%c%c%c%c", 219, 219, 219, 219);
}

void CCAR::DrawSpace()
{
	int k = CVEHICLE::mX;
	gotoxy(k, 11);
	printf("    ");
	gotoxy(k, 12);
	printf("    ");
}