#include "TRUCK.h"

void CTRUCK::Draw()
{
	//draw truck
	int k = CVEHICLE::mX;
	TextColor(127);
	gotoxy(k, 15);
	printf("%c", 219);

	TextColor(126);
	gotoxy(k + 1, 14);
	printf("%c%c%c", 219, 219, 219);
	gotoxy(k + 1, 15);
	printf("%c%c%c", 219, 219, 219);

}

void CTRUCK::DrawSpace()
{
	int k = CVEHICLE::mX;
	gotoxy(k, 14);
	printf("    ");
	gotoxy(k, 15);
	printf("    ");
}