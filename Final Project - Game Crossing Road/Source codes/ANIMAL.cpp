#include "ANIMAL.h"

void CANIMAL::Move(int x, int y)
{
	mX = x;
	mY = y;
}

void CANIMAL::MoveLeft()
{
	mX--;
	if (mX == 1)
		mX = MAX_LENGTH - 3;
}

void CANIMAL::MoveRight()
{
	mX++;
	if (mX > MAX_LENGTH - 3)
		mX = 1;
}

void CANIMAL::print(ofstream &f)
{
	f.write(reinterpret_cast<char*>(&mX), sizeof(mX));
	f.write(reinterpret_cast<char*>(&mY), sizeof(mY));
}

bool CANIMAL::CheckPos(int x, int y)
{
	if ((mX <= x) && (x <= mX + 2) && (y == mY + 2))
		return true;
	return false;
}