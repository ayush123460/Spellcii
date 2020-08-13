#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include<conio.h>
#include "Functions.h"

class Player {
private:
	int movingDirection;
	std::string s;
public:
	int x;
	int y;
	Player();
	void changeDir(int m);
};

#endif
