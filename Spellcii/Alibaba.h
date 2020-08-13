#ifndef ALIBABA_H
#define ALIBABA_H
#include<cstdio>
#include<time.h>
#include<Windows.h>
#include<ctype.h>
#include "Levels.h"
#include "Words.h"
#include "Player.h"
#include "conio.h"
#include "Functions.h"

class Alibaba {
private:
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	bool inGame;
	bool exitCon;
	bool tutorial;
	bool back;
	std::string s = "";
	bool levelFin;
	Levels l;
	Player p;
	char c;
	//private functions
	void start();
	void menu();
	void tutorialMenu();
	int update();
	void help();
	void startPlay();
public:
	Alibaba();
	virtual ~Alibaba();
};

#endif