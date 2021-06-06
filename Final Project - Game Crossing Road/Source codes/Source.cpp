#include "GAME.h"
#include <stdio.h>
#include <thread>
#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#include <Mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")


using namespace std;

int CGAME::level = 1;
bool CGAME::pause = true;
int CGAME::speed = 250;
int CBIRD::direction = 0;
int CDINAUSOR::direction = 1;
bool CCAR::TrafficLight = false;
bool CTRUCK::TrafficLight = true;

char MOVING;
CGAME cg;
bool IS_RUNNING = true;
bool play = true;
bool sound = true;


void exitGame(thread* t)
{
	system("cls");
	IS_RUNNING = false;
	t->join();
}

void SubThread()
{
	while (IS_RUNNING)
	{
		if (CGAME::pause)
		{
			if (!cg.getPeople().isDead())
				cg.updatePosPeople(MOVING);
			MOVING = ' ';
			cg.getPeople().Draw();

			cg.resetScreen();
			if (sound)
				PlaySound(L"bird.wav", NULL, SND_ASYNC);
			cg.updatePosVehicle();
			cg.updatePosAnimal();
			cg.drawVehicleaAnimal();
			Sleep(CGAME::speed);

			if (cg.getPeople().isFinish())
			{
				cg.levelUp();
				cg.drawGame();
			}

			if (cg.getPeople().isImpact(cg.getAnimal(), CGAME::level) || cg.getPeople().isImpact(cg.getVehicle(), CGAME::level))
			{
				PlaySound(NULL, 0, 0);
				cg.getPeople().Draw(); if (sound)
					PlaySound(L"crack.wav", NULL, SND_ASYNC);
				cg.getPeople().DrawDied();
				gotoxy(15, 20);
				TextColor(124);
				cout << "Dead, Press Y to continue or anykey to exit";
				CGAME::pause = false;
			}
		}
	}
}

void MenuLoading()
{
	TextColor(112);
	gotoxy(35, 20);
	cout << "Loading .....";
	for (int i = 0; i < 5; i++)
	{
		Sleep(100);
		gotoxy(43 + i, 20);
		printf("%c", 219);
	}
}

string MenuFile()
{
	clrscr();
	system("color 74");
	point upleft, downright;
	//Ve vien ngoai
	upleft.x = 20;
	upleft.y = 9;
	downright.x = 60;
	downright.y = 15;
	DrawRectangle(upleft, downright);
	//////////////////////////////////////////////////////////
	gotoxy(35, 9);
	printf("LINK GAME");

	string file = "";
	TextColor(112);
	while (file == "")
	{
		gotoxy(22, 12);
		cout << "Input link: ";
		getline(cin, file);
	}
	Sleep(1000);
	return file;
}

int MenuSound()
{
	clrscr();
	system("color 74");
	str thaotac[2] = {
		" On",
		" Off",
	};
	point upleft, downright;
	system("color 74");
	//Ve vien ngoai
	upleft.x = 28;
	upleft.y = 9;
	downright.x = 45;
	downright.y = 15;
	DrawRectangle(upleft, downright);
	//////////////////////////////////////////////////////////
	gotoxy(35, 9);
	printf("SOUND");

	////////////////////////////////////////////////////
	int option = -1;
	do option = control(thaotac, 2);
	while (option != 0 && option != 1);
	if (option == 1)
		sound = false;
	if (option == 0)
		sound = true;
	return option;
}

int MenuSetting()
{
	clrscr();
	system("color 74");
	str thaotac[3] = {
		"1. Sound",
		"2. Level",
		"3. Back"
	};
	point upleft, downright;
	system("color 74");
	//Ve vien ngoai
	upleft.x = 30;
	upleft.y = 9;
	downright.x = 47;
	downright.y = 18;
	DrawRectangle(upleft, downright);
	//////////////////////////////////////////////////////////
	gotoxy(36, 9);
	printf("SETTING");

	////////////////////////////////////////////////////
	int option = -1;
	do option = control(thaotac, 3);
	while (option != 0 && option != 1 && option != 2);
	if (option == 0)
	{
		MenuSound();
		MenuSetting();
	}

	if (option == 1)
	{
		do
		{
			TextColor(112);
			gotoxy(30, 20);
			cout << "Level (1 - " << NUMBER_MAX << "): ...";
			gotoxy(45, 20);
			cin >> CGAME::level;
			if (1 > CGAME::level || CGAME::level > NUMBER_MAX)
			{
				gotoxy(30, 25);
				TextColor(124);
				cout << "The level is wrong!";
			}
			else
			{
				gotoxy(30, 25);
				TextColor(113);
				cout << "    Sucessfull!    ";
			}
		} while (1 > CGAME::level || CGAME::level > NUMBER_MAX);
		cg.setGame();
	}
	if (option == 2)
		return option;
	return option;
}

int MenuStart()
{
	clrscr();
	system("color 74");
	str thaotac[4] = {
		"1. New game",
		"2. Load game",
		"3. Settings",
		"4. Exit"
	};
	point upleft, downright;
	system("color 74");
	//Ve vien ngoai
	upleft.x = 30;
	upleft.y = 9;
	downright.x = 50;
	downright.y = 18;
	DrawRectangle(upleft, downright);
	//////////////////////////////////////////////////////////
	gotoxy(39, 9);
	printf("MENU");

	////////////////////////////////////////////////////
	int option = -1;
	do option = control(thaotac, 4);
	while (option != 0 && option != 1 && option !=2 && option != 3);
	if (option == 1)
	{
		string file = MenuFile();
		cg.loadGame(file);
		MenuLoading();
	}

	if (option == 2)
	{
		MenuSetting();
		MenuStart();
	}
	if (option == 0)
	{
		MenuLoading();
	}
	return option;
}

int MenuPause()
{
	clrscr();
	system("color 74");
	str thaotac[5] = {
		"1. Continue",
		"2. New game",
		"3. Load game",
		"4. Save game",
		"5. Sound"
	};
	point upleft, downright;
	system("color 74");
	//Ve vien ngoai
	upleft.x = 30;
	upleft.y = 9;
	downright.x = 50;
	downright.y = 18;
	DrawRectangle(upleft, downright);
	//////////////////////////////////////////////////////////
	gotoxy(39, 9);
	printf("MENU");
	////////////////////////////////////////////////////////////
	int option = -1;
	do option = control(thaotac, 5);
	while (option != 0 && option != 1 && option != 2 && option != 3 && option != 4);

	if (option == 2)
	{
		string file = MenuFile();
		cg.loadGame(file);
		MenuLoading();
		cg.drawGame();
	}

	if (option == 3)
	{
		string file = MenuFile();
		cg.saveGame(file);
		cg.drawGame();
	}

	if (option == 1)
	{
		cg.resetGame();
		MenuLoading();
		cg.drawGame();
	}

	if (option == 0)
	{
		clrscr();
		cg.drawGame();
	}

	if (option == 4)
	{
		MenuSound();
		cg.drawGame();
	}

	return option;
}

void main()
{
	resizeConsole(750, 700);
	FixConsoleWindow();
	HideConsole();
	if (MenuStart() == 3)
		return;
	system("color 74");
	TextColor(112);

	int count = 0;
	int temp;
	cg.drawGame();
	thread t1(SubThread);
	while (play)
	{
		temp = toupper(getch());
		count++;
		if (count % 5 == 0)
		{
			if (CCAR::TrafficLight)
			{
				CCAR::TrafficLight = false;
				TextColor(124);
			}
			else
			{
				CCAR::TrafficLight = true;
				TextColor(122);
			}
			gotoxy(74, 10);
			printf("%c", 219);
		}

		if (count % 6 == 0)
		{
			if (CTRUCK::TrafficLight)
			{
				CTRUCK::TrafficLight = false;
				TextColor(124);
			}
			else
			{
				CTRUCK::TrafficLight = true;
				TextColor(122);
			}
			gotoxy(1, 13);
			printf("%c", 219);
		}

		if (!cg.getPeople().isDead())
		{
			if (temp == 27)
			{
				exitGame(&t1);
				cg.exitGame(t1.native_handle());
				break;
			}
			else
			{
				if (temp == 'P')
				{
					PlaySound(NULL, 0, 0);
					cg.pauseGame(t1.native_handle());
					MenuPause();
					cg.resumeGame((HANDLE)t1.native_handle());
				}
				else
				{
					cg.resumeGame((HANDLE)t1.native_handle());
					MOVING = temp;
				}
			}
		}
		else
		{
			if (temp == 'Y')
			{
				cg.resetGame();
				cg.drawGame();
				CGAME::pause = true;
			}
			else
			{
				exitGame(&t1);
				cg.exitGame(t1.native_handle());
				break;
			}
		}

		if (temp == 'T')
		{
			PlaySound(NULL, 0, 0);
			cg.pauseGame(t1.native_handle());
			string file = MenuFile();
			cg.loadGame(file);
			MenuLoading();
			cg.drawGame();
			cg.resumeGame((HANDLE)t1.native_handle());
		}
		if (temp == 'L')
		{
			PlaySound(NULL, 0, 0);
			cg.pauseGame(t1.native_handle());
			string file = MenuFile();
			cg.saveGame(file);
			cg.drawGame();
			cg.resumeGame((HANDLE)t1.native_handle());
		}
	}
}