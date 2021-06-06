#include "PEOPLE.h"

void CPEOPLE::Up(int x)
{
	mY += x;
}

void CPEOPLE::Left(int y)
{
	mX -= y;
}

void CPEOPLE::Right(int y)
{
	mX += y;
}

void CPEOPLE::Down(int x)
{
	mY -= x;
}

bool CPEOPLE::isImpact(CVEHICLE **v, int level)
{
	for (int i = 0; i < 2 * level; i++)
		if (v[i]->CheckPos(mX, mY))
		{
			mState = false;
			return true;
		}
	return false;
}

bool CPEOPLE::isImpact(CANIMAL **v, int level)
{
	for (int i = 0; i < 2 * level; i++)
		if (v[i]->CheckPos(mX, mY))
		{
			mState = false;
			return true;
		}
	return false;
}

bool CPEOPLE::isFinish()
{
	if (mY == 1)
		return true;
	return false;
}

bool CPEOPLE::isDead()
{
	if (mState == false)
		return true;
	return false;
}

void CPEOPLE::setPos(int x, int y)
{
	mX = x;
	mY = y;
}

CPEOPLE::CPEOPLE()
{
	mX = MAX_LENGTH / 2;
	mY = 17;
	mState = true;
}

void CPEOPLE::print(ofstream& f)
{
	f.write(reinterpret_cast<char*>(&mX), sizeof(int));
	f.write(reinterpret_cast<char*>(&mY), sizeof(int));
}

void CPEOPLE::Draw()
{
	gotoxy(mX, mY);
	if (mState)
		TextColor(112);
	else
		TextColor(124);
	printf("%c", 12);
}

void CPEOPLE::DrawDied()
{
	for (int i = 0; i < 3; i++)
	{
		gotoxy(mX, mY);
		TextColor(112);
		printf("%c", 12);
		Sleep(200);
		gotoxy(mX, mY);
		TextColor(124);
		printf("%c", 12);
		Sleep(200);
	}
}

CPEOPLE::~CPEOPLE()
{
}

int CPEOPLE::getX()
{
	return mX;
}

int CPEOPLE::getY()
{
	return mY;
}

void CPEOPLE::resetState()
{
	mState = true;
}