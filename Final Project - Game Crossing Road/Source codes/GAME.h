#ifndef _GAME_H_
#define _GAME_H_

#define NUMBER_MAX 6

#include "TRUCK.h"
#include "CAR.h"
#include "DINAUSOR.h"
#include "BIRD.h"
#include "PEOPLE.h"
#include "interface.h"
#include <fstream>
#include <string>
#include "interface.h"

using namespace std;

class CGAME
{
	CTRUCK* axt;
	CCAR* axh;
	CDINAUSOR* akl;
	CBIRD* ac;
	CPEOPLE cn;
private:
	void clear();
public:
	static int level;
	static bool pause;
	static int speed;

	CGAME(); //Chuan bi du lieu cho tat ca cac doi tuong
	void levelUp();
	void drawLine();
	void drawVehicleaAnimal();
	void drawTrafficLight();
	void resetScreen();
	void setGame();
	void drawGame(); //Thuc hien ve tro choi ra man hinh sau kkhi co du lieu
	CPEOPLE& getPeople(); //Lay thong tin nguoi
	CVEHICLE** getVehicle(); //Lay danh sach cac xe
	CANIMAL** getAnimal(); //Lay danh sach cac thu
	void resetGame(); //Thuc hien thiet lap lai toan bo du lieu nhu luc dau
	void exitGame(HANDLE); //Thuc hien thoat Thread
	void startGame(); //Thuc hien bat dau tro choi
	void loadGame(string); //Thuc hien tai lai tro choi
	void saveGame(string); //Thuc hien luu lai du lieu tro choi
	void pauseGame(HANDLE); //Tam dung Thread
	void resumeGame(HANDLE); //Quay lai Thread
	void updatePosPeople(char); //Thuc hien dieu khien di chuyen cua CPEOPLE
	void updatePosVehicle(); //Thuc hien cho CTRUCK & CCAR di chuyen
	void updatePosAnimal(); //Thuc hien cho CDINAUSOR & CBIRD di chuyen
	~CGAME(); //Huy tai nguyen da cap phat
};

#endif