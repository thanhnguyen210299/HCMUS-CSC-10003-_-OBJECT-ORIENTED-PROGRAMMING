#include "GAME.h"

CGAME::CGAME() //Chuan bi du lieu cho tat ca cac doi tuong
{
	level = 1;
	setGame();
}

void CGAME::drawLine()
{
	system("cls");

	int StarLine[7] = { 0, 2, 6, 10, 13, 16, 18 };

	system("color 74");
	TextColor(113);

	// Ve cac line
	for (int i = 0; i <= MAX_LENGTH; i++)
	{
		gotoxy(i, StarLine[0]);
		printf("%c", 4);
	}
	for (int i = 0; i <= 18; i++)
	{
		gotoxy(0, i);
		printf("%c", 4);
	}
	for (int i = 0; i <= 18; i++)
	{
		gotoxy(MAX_LENGTH, i);
		printf("%c", 4);
	}
	for (int i = 0; i <= MAX_LENGTH; i++)
	{
		gotoxy(i, StarLine[6]);
		printf("%c", 4);
	}

	TextColor(116);
	for (int k = 1; k < 6; k++)
	{
		for (int i = 1; i < MAX_LENGTH; i++)
		{
			gotoxy(i, StarLine[k]);
			cout << "*";
		}
	}

	//Ve ki hieu
	TextColor(112);
	int t = MAX_LENGTH / 4 * 3;
	gotoxy(t, 25);
	printf("| A  : Move Left  |");
	gotoxy(t, 26);
	printf("| D  : Move Right |");
	gotoxy(t, 27);
	printf("| W  : Move Up    |");
	gotoxy(t, 28);
	printf("| S  : Move Down  |");
	gotoxy(t, 29);
	printf("| L  : Save Game  |");
	gotoxy(t, 30);
	printf("| T  : Load Game  |");
	gotoxy(t, 31);
	printf("| P  : Pause Game |");
	gotoxy(t, 32);
	printf("| ESC: Exit       |");

	gotoxy(t, 24);
	for (int i = 0; i < 19; i++)
		printf("%c", 61);
	gotoxy(t, 33);
	for (int i = 0; i < 19; i++)
		printf("%c", 61);
}

void CGAME::drawVehicleaAnimal()
{
	for (int k = 0; k < level; k++)
	{
		ac[k].Draw();
		axh[k].Draw();
		akl[k].Draw();
		axt[k].Draw();
	}
}

void CGAME::drawTrafficLight()
{
	if (CCAR::TrafficLight)
		TextColor(122);
	else
		TextColor(124);
	gotoxy(74, 10);
	printf("%c", 219);

	if (CTRUCK::TrafficLight)
		TextColor(122);
	else
		TextColor(124);
	gotoxy(1, 13);
	printf("%c", 219);
}

void CGAME::drawGame() //Thuc hien ve tro choi ra man hinh sau kkhi co du lieu
{
	drawLine();

	CBIRD::direction = 1;
	CDINAUSOR::direction = 0;

	drawVehicleaAnimal();

	cn.Draw();

	drawTrafficLight();

	TextColor(112);
	gotoxy(25, 30);
	cout << "Level: " << level << endl;

	//Ve vien ngoai
	point upleft, downright;
	TextColor(112);
	upleft.x = 23;
	upleft.y = 28;
	downright.x = 34;
	downright.y = 32;
	DrawRectangle(upleft, downright);
}

CPEOPLE& CGAME::getPeople() //Lay thong tin nguoi
{
	return cn;
}

CVEHICLE ** CGAME::getVehicle() //Lay danh sach cac xe
{
	CVEHICLE **p = new CVEHICLE *[2 * level];
	for (int i = 0; i < level; i++)
	{
		p[i] = &axh[i];
	}
	for (int i = 0; i < level; i++)
		p[i + level] = &axt[i];
	return p;
}

CANIMAL** CGAME::getAnimal() //Lay danh sach cac thu
{
	CANIMAL **p = new CANIMAL*[2 * level];
	for (int i = 0; i < level; i++)
	{
		p[i] = &ac[i];
	}
	for (int i = 0; i < level; i++)
		p[i + level] = &akl[i];
	return p;
}

void CGAME::resetGame() //Thuc hien thiet lap lai toan bo du lieu nhu luc dau
{
	clear();

	// Cap nhat du lieu
	level = 1;
	cn.setPos(MAX_LENGTH/ 2, 17);
	cn.resetState();
	setGame();
}

void CGAME::exitGame(HANDLE t) //Thuc hien thoat Thread
{
	system("cls");
	TerminateThread(t, 0);
}

void CGAME::startGame() //Thuc hien bat dau tro choi
{
	drawGame();
}

void CGAME::levelUp()
{

	level++; // Tang level

	TextColor(124);

	if (level > NUMBER_MAX) // Neu so thu dat muc quy dinh thi reset lai game
	{
		gotoxy(MAX_LENGTH / 2 - 5, 20);
		cout << "Congratulation!!!";
		Sleep(500);

		TextColor(112);
		gotoxy(12, 22);
		cout << "This is max level. Let's reset game with level 1";
		Sleep(1000);

		TextColor(124);
		gotoxy(MAX_LENGTH / 2 - 5, 20);
		printf("   RESET GAME!    ");
		Sleep(200);
		resetGame();
		return;
	}

	gotoxy(MAX_LENGTH / 2 - 5, 20);
	printf("LEVEL UP!");
	Sleep(200);

	cn.setPos(MAX_LENGTH / 2, 17);
	setGame();
}

void CGAME::setGame()
{
	// Khoi tao xe va thu
	axt = new CTRUCK[level];
	axh = new CCAR[level];
	ac = new CBIRD[level];
	akl = new CDINAUSOR[level];

	// Tinh khoang cach giua thu va xe tren cung 1 dong
	int insAni = (MAX_LENGTH - 3 * level) / (level + 1);
	int insVeh = (MAX_LENGTH - 4 * level) / (level + 1);

	for (int i = 0; i < level; i++)
	{
		//Khoi tao vi tri cho bird
		ac[i].Move(insAni * (i + 1) + 3 * i, 3);

		//Khoi tao vi tri cho dinausor
		akl[i].Move((insAni - 1) * (i + 1) + 3 * i, 7);

		//Khoi tao  vi tri cho car
		axh[i].Move(insVeh * (i + 1) + 4 * i, 11);

		//Khoi tao vi tri cho truck
		axt[i].Move(insVeh * (i + 1) + 4 * i, 14);
	}
}

void CGAME::loadGame(string fileName) //Thuc hien tai lai tro choi
{
	ifstream f(fileName.c_str(), ios::in | ios::binary);

	if (!f)
	{
		TextColor(124);
		gotoxy(20, 25);
		cout << "Can't open file! Let's play with old level";
		Sleep(1000);
		return;
	}

	clear();

	int x = 0, y = 0;
	// Doc vi tri nguoi, level, diem
	f.read(reinterpret_cast<char*>(&x), sizeof(int));
	f.read(reinterpret_cast<char*>(&y), sizeof(int));
	f.read(reinterpret_cast<char*>(&level), sizeof(level));
	
	cn.setPos(x, y);

	// Khoi tao xe va thu
	axt = new CTRUCK[level];
	axh = new CCAR[level];
	ac = new CBIRD[level];
	akl = new CDINAUSOR[level];

	for (int i = 0; i < level; i++) // Bird
	{
		f.read(reinterpret_cast<char*>(&x), sizeof(int));
		f.read(reinterpret_cast<char*>(&y), sizeof(int));
		ac[i].Move(x, y);
	}

	for (int i = 0; i < level; i++) // Dinausor
	{
		f.read(reinterpret_cast<char*>(&x), sizeof(x));
		f.read(reinterpret_cast<char*>(&y), sizeof(y));
		akl[i].Move(x, y);
	}

	for (int i = 0; i < level; i++) // Car
	{
		f.read(reinterpret_cast<char*>(&x), sizeof(x));
		f.read(reinterpret_cast<char*>(&y), sizeof(y));
		axh[i].Move(x, y);
	}

	for (int i = 0; i < level; i++) // Truck
	{
		f.read(reinterpret_cast<char*>(&x), sizeof(x));
		f.read(reinterpret_cast<char*>(&y), sizeof(y));
		axt[i].Move(x, y);
	}

	f.close();
}

void CGAME::saveGame(string fileName) //Thuc hien luu lai du lieu tro choi
{
	ofstream f(fileName.c_str(), ios::out | ios::binary);

	cn.print(f); //In vi tri cua nguoi
	f.write(reinterpret_cast<char*>(&level), sizeof(&level)); // In level

	// Thu tu in: bird, dinausor, car, truck

	for (int i = 0; i < level; i++) // Bird
		ac[i].print(f);

	for (int i = 0; i < level; i++) // Dinausor
		akl[i].print(f);

	for (int i = 0; i < level; i++) // Car
		axh[i].print(f);

	for (int i = 0; i < level; i++) // Truck
		axt[i].print(f);

	f.close();
}

void CGAME::pauseGame(HANDLE t) //Tam dung Thread
{
	SuspendThread(t);
}

void CGAME::resumeGame(HANDLE t) //Quay lai Thread
{
	ResumeThread(t);
}

void CGAME::updatePosPeople(char c) //Thuc hien dieu khien di chuyen cua CPEOPLE
{
	gotoxy(cn.getX(), cn.getY());
	printf(" ");
	int StarLine[7] = { 0, 2, 6, 10, 13, 16, 18 };
	int Line;
	for (int i = 1; i < 7; i++)
		if (cn.getY() == StarLine[i] - 1)
		{
			Line = i;
			break;
		}
	switch (c)
	{
	case 'W':
	{
		cn.setPos(cn.getX(), StarLine[Line - 1] - 1);
		cn.Draw();
		break;
	}
	case 'S':
	{
		if (Line != 6)
			cn.setPos(cn.getX(), StarLine[Line + 1] - 1);
		cn.Draw();
		break;
	}
	case 'A':
	{
		if (cn.getX() != 1)
			cn.Left(1);
		cn.Draw();
		break;
	}
	case 'D':
	{
		if (cn.getX() != MAX_LENGTH)
			cn.Right(1);
		cn.Draw();
		break;
	}
	}
}

void CGAME::updatePosVehicle() //Thuc hien cho CTRUCK & CCAR di chuyen
{
	if (CCAR::TrafficLight)
		for (int i = 0; i < level; i++)
			axh[i].MoveRight();
	if (CTRUCK::TrafficLight)
		for (int i = 0; i < level; i++)
			axt[i].MoveLeft();
}

void CGAME::resetScreen()
{
	for (int i = 0; i < level; i++)
	{
		ac[i].DrawSpace();
		axt[i].DrawSpace();
		axh[i].DrawSpace();
		akl[i].DrawSpace();
	}
}

void CGAME::updatePosAnimal() //Thuc hien cho CDINAUSOR & CBIRD di chuyen
{
	for (int i = 0; i < level; i++)
	{
		ac[i].MoveRight();
		akl[i].MoveLeft();
	}
}

void CGAME::clear() //Xoa du lieu
{
		delete[] ac;
		delete[] axt;
		delete[] axh;
		delete[] akl;
}

CGAME::~CGAME() //Huy tai nguyen da cap phat
{
	clear();
}
