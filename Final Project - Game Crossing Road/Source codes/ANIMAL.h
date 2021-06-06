#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include "process.h"

using namespace std;

#define MAX_LENGTH 75

class CANIMAL
{
protected:
	int mX, mY;
public:
	void Move(int, int);
	void MoveLeft();
	void MoveRight();
	bool CheckPos(int, int);
	void print(ofstream&);
	virtual void Draw() = 0;
	virtual void DrawSpace() = 0;
};

