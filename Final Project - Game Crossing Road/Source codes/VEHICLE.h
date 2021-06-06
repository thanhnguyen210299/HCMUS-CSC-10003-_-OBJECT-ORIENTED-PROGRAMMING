#pragma once
#include <fstream>
#include "process.h"
#define MAX_LENGTH 75

using namespace std;

class CVEHICLE
{
protected:
	int mX, mY;
public:
	void Move(int, int);
	void MoveLeft();
	void MoveRight();
	bool CheckPos(int, int);
	void print(ofstream &f);
	virtual void Draw() = 0;
	virtual void DrawSpace() = 0;
};