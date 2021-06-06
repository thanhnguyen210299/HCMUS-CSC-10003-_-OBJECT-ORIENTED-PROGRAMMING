#include "DINAUSOR.h"

void CDINAUSOR::Draw()
{
	//draw dinausor
	int k = CANIMAL::mX;
	TextColor(114);
	gotoxy(k, 7);
	printf("  %c", 219);
	gotoxy(k, 8);
	printf(" %c%c", 219, 219);
	gotoxy(k, 9);
	printf("%c%c", 219, 219);
}

void CDINAUSOR::DrawSpace()
{
	TextColor(112);
	int k = CANIMAL::mX;
	gotoxy(k, 7);
	printf("   ");
	gotoxy(k, 8);
	printf("   ");
	gotoxy(k, 9);
	printf("   ");
}