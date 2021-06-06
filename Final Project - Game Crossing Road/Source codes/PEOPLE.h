#ifndef _PEOPLE_H_
#define _PEOPLE_H_

#include "ANIMAL.h"
#include "VEHICLE.h"
#include <fstream>
#include <string>
#include "process.h"
using namespace std;

#define MAX_LENGTH 75

class CPEOPLE
{
private:
	string name;
	int mX, mY;
	bool mState; // Trang thai song chet
public:
	CPEOPLE();
	int getX();
	int getY();
	void print(ofstream&);
	void setPos(int, int);
	void resetState();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	void Draw();
	void DrawDied();
	bool isImpact(CVEHICLE **, int);
	bool isImpact(CANIMAL **, int);
	bool isFinish();
	bool isDead();
	~CPEOPLE();
};

#endif

