#include "BIRD.h"

void CBIRD::Draw()
{
	// draw bird
	int k = CANIMAL::mX;
	TextColor(118);
	gotoxy(k, 3);
	printf("%c %c", 219, 219);
	
	TextColor(121);
	gotoxy(k, 4);
	printf(" %c", 219);
}

void CBIRD::DrawSpace()
{
	gotoxy(CANIMAL::mX, 3);
	printf("   ");
	gotoxy(CANIMAL::mX, 4);
	printf("   ");
}