#ifndef LEVELS_H
#define LEVELS_H
#include<fstream>
#include<iostream>
#include<math.h>
#include "Functions.h"
#include "Words.h"
#include<sstream>
#include<string>
#include<random>

class Levels {
private:
	//private vars
	int level;
	double x, y;
	using intdis = std::uniform_int_distribution<int>;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	std::fstream fileHandle;
	std::string str;
	std::string word;
	std::mt19937 random;
	//private functions
	void loadImmovableObject(int x, int y);
	void loadLevelTutorial();
	void randomWordPlace(std::string stt);
public:
	Levels();
	~Levels();
	const int getLevels() const { return this->level; }
	const void setLevel(int level) { this->level = level; }
	std::string getWord() { return this->word; }
	void loadLevelBase();
	void loadLevel();
	void levelMap();
	int wordsPlaced;

};

#endif
