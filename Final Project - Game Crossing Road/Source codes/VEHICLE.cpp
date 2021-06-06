#include "VEHICLE.h"

void CVEHICLE::Move(int x, int y)
{
	mX = x;
	mY = y;
}

void CVEHICLE::MoveLeft()
{
	mX--;
	if (mX == 1)
		mX = MAX_LENGTH - 4;
}

void CVEHICLE::MoveRight()
{
	mX++;
	if (mX > MAX_LENGTH - 4)
		mX = 1;
}

bool CVEHICLE::CheckPos(int x, int y)
{
	if ((mX <= x) && (x <= mX + 3) && (y == mY + 1))
		return true;
	return false;
}

void CVEHICLE::print(ofstream &f)
{
	f.write(reinterpret_cast<char*>(&mX), sizeof(mX)); 
	f.write(reinterpret_cast<char*>(&mY), sizeof(mY));
}
