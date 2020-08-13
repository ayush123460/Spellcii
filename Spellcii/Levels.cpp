#include "Levels.h"

Levels::Levels()
:level(100),
x(0),
y(0),
wordsPlaced(0) {
	random.seed(std::random_device()());
}

Levels::~Levels() {}

void Levels::loadLevelBase() {
	this->fileHandle.open("levels/base.txt", std::ios::in);
	std::string line;
	SetConsoleTextAttribute(this->handle, 15);
	while (std::getline(this->fileHandle, line)) {
		std::cout << line << std::endl;
	}
	this->fileHandle.close();
}

void Levels::loadImmovableObject(int x, int y) {
	SetConsoleTextAttribute(handle, 10);
	gotoxy(x, y);
	std::cout << "#";
}

void Levels::loadLevelTutorial() {
	//left side objects
	for (int i = 4; i < 35; i++) {
		loadImmovableObject(i, 3);
	}
	for (int i = 4; i < 35; i++) {
		loadImmovableObject(i, 4);
	}
	for (int i = 4; i < 35; i++) {
		loadImmovableObject(i, 5);
	}
	for (int i = 4; i < 35; i++) {
		loadImmovableObject(i, 6);
	}
	for (int i = 4; i < 25; i++) {
		loadImmovableObject(i, 7);
	}
	for (int i = 4; i < 25; i++) {
		loadImmovableObject(i, 8);
	}
	for (int i = 4; i < 25; i++) {
		loadImmovableObject(i, 9);
	}
	for (int i = 4; i < 25; i++) {
		loadImmovableObject(i, 17);
	}
	for (int i = 4; i < 25; i++) {
		loadImmovableObject(i, 18);
	}
	for (int i = 4; i < 25; i++) {
		loadImmovableObject(i, 19);
	}
	for (int i = 4; i < 35; i++) {
		loadImmovableObject(i, 20);
	}
	for (int i = 4; i < 35; i++) {
		loadImmovableObject(i, 21);
	}
	for (int i = 4; i < 35; i++) {
		loadImmovableObject(i, 22);
	}
	//right side objects
	for (int i = 39; i < 75; i++) {
		loadImmovableObject(i, 3);
	}
	for (int i = 39; i < 75; i++) {
		loadImmovableObject(i, 4);
	}
	for (int i = 39; i < 75; i++) {
		loadImmovableObject(i, 5);
	}
	for (int i = 39; i < 75; i++) {
		loadImmovableObject(i, 6);
	}
	for (int i = 41; i < 55; i++) {
		loadImmovableObject(i, 7);
	}
	for (int i = 41; i < 55; i++) {
		loadImmovableObject(i, 8);
	}
	for (int i = 41; i < 55; i++) {
		loadImmovableObject(i, 9);
	}
	for (int i = 41; i < 55; i++) {
		loadImmovableObject(i, 10);
	}
	for (int i = 41; i < 55; i++) {
		loadImmovableObject(i, 11);
	}
	for (int i = 41; i < 55; i++) {
		loadImmovableObject(i, 12);
	}
	for (int i = 41; i < 55; i++) {
		loadImmovableObject(i, 13);
	}
	for (int i = 41; i < 55; i++) {
		loadImmovableObject(i, 14);
	}
	for (int i = 39; i < 75; i++) {
		loadImmovableObject(i, 18);
	}
	for (int i = 39; i < 75; i++) {
		loadImmovableObject(i, 19);
	}
	for (int i = 39; i < 75; i++) {
		loadImmovableObject(i, 20);
	}
	for (int i = 39; i < 75; i++) {
		loadImmovableObject(i, 21);
	}
	for (int i = 39; i < 75; i++) {
		loadImmovableObject(i, 22);
	}
	gotoxy(1, 1);
	SetConsoleTextAttribute(handle, 11);
	std::cout << "@";
	gotoxy(69, 1);
	SetConsoleTextAttribute(handle, 13);
	std::cout << "A";
	gotoxy(1, 24);
	std::cout << "K";
	gotoxy(77, 12);
	std::cout << "R";
	this->wordsPlaced = 3;
}
void Levels::randomWordPlace(std::string stt) {
	std::uniform_int_distribution<std::mt19937::result_type> xRand(2, 78);
	std::uniform_int_distribution<std::mt19937::result_type> yRand(2, 23);
	SetConsoleTextAttribute(handle, 13);
	int xR, yR, i = 0;
	char sc, scu, scd, scl, scr;
	while (i < stt.size()) {
	r:
		xR = xRand(this->random);
		yR = yRand(this->random);
		sc = readChar(xR, yR);
		scu = readChar(xR, yR - 1);
		scd = readChar(xR, yR + 1);
		scl = readChar(xR - 1, yR);
		scr = readChar(xR + 1, yR);
		if (sc != '#' && scu != '#' && scd != '#' && scl != '#' && scr != '#') {
			if (!isalpha(sc) && !isalpha(scu) && !isalpha(scd) && !isalpha(scl) && !isalpha(scr)) {
				gotoxy(xR, yR);
				std::cout << stt[i];
				++this->wordsPlaced;
			}
			else
				goto r;
		}
		else
			goto r;
		i++;
	}
}
void Levels::loadLevel() {
	std::string s;
	system("cls");
	this->loadLevelBase();
	if (this->level == 0) {
		this->loadLevelTutorial();
	}
	else {
		//left side objects
		for (int i = 4; i < 35; i++) {
			loadImmovableObject(i, 3);
		}
		for (int i = 4; i < 35; i++) {
			loadImmovableObject(i, 4);
		}
		for (int i = 4; i < 35; i++) {
			loadImmovableObject(i, 5);
		}
		for (int i = 4; i < 35; i++) {
			loadImmovableObject(i, 6);
		}
		for (int i = 4; i < 25; i++) {
			loadImmovableObject(i, 7);
		}
		for (int i = 4; i < 25; i++) {
			loadImmovableObject(i, 8);
		}
		for (int i = 4; i < 25; i++) {
			loadImmovableObject(i, 9);
		}
		for (int i = 4; i < 25; i++) {
			loadImmovableObject(i, 17);
		}
		for (int i = 4; i < 25; i++) {
			loadImmovableObject(i, 18);
		}
		for (int i = 4; i < 25; i++) {
			loadImmovableObject(i, 19);
		}
		for (int i = 4; i < 35; i++) {
			loadImmovableObject(i, 20);
		}
		for (int i = 4; i < 35; i++) {
			loadImmovableObject(i, 21);
		}
		for (int i = 4; i < 35; i++) {
			loadImmovableObject(i, 22);
		}
		//right side objects
		for (int i = 39; i < 75; i++) {
			loadImmovableObject(i, 3);
		}
		for (int i = 39; i < 75; i++) {
			loadImmovableObject(i, 4);
		}
		for (int i = 39; i < 75; i++) {
			loadImmovableObject(i, 5);
		}
		for (int i = 39; i < 75; i++) {
			loadImmovableObject(i, 6);
		}
		for (int i = 41; i < 55; i++) {
			loadImmovableObject(i, 7);
		}
		for (int i = 41; i < 55; i++) {
			loadImmovableObject(i, 8);
		}
		for (int i = 41; i < 55; i++) {
			loadImmovableObject(i, 9);
		}
		for (int i = 41; i < 55; i++) {
			loadImmovableObject(i, 10);
		}
		for (int i = 41; i < 55; i++) {
			loadImmovableObject(i, 11);
		}
		for (int i = 41; i < 55; i++) {
			loadImmovableObject(i, 12);
		}
		for (int i = 41; i < 55; i++) {
			loadImmovableObject(i, 13);
		}
		for (int i = 41; i < 55; i++) {
			loadImmovableObject(i, 14);
		}
		for (int i = 39; i < 75; i++) {
			loadImmovableObject(i, 18);
		}
		for (int i = 39; i < 75; i++) {
			loadImmovableObject(i, 19);
		}
		for (int i = 39; i < 75; i++) {
			loadImmovableObject(i, 20);
		}
		for (int i = 39; i < 75; i++) {
			loadImmovableObject(i, 21);
		}
		for (int i = 39; i < 75; i++) {
			loadImmovableObject(i, 22);
		}
		gotoxy(1, 1);
		SetConsoleTextAttribute(handle, 11);
		std::cout << "@";
		SetConsoleTextAttribute(handle, 13);
		switch (this->level) {
		case 1: {
			Words w(3);
			s = w.getWord();
			this->randomWordPlace(s);
			word = s;
			this->wordsPlaced = 3;
			break;
		}
		case 2: {
			Words w(3);
			s = w.getWord();
			this->randomWordPlace(s);
			word = s;
			break;
		}
		case 3: {
			Words w(3);
			s = w.getWord();
			this->randomWordPlace(s);
			word = s;
			this->wordsPlaced = 3;
			break;
		}
		case 4: {
			Words w(4);
			s = w.getWord();
			this->randomWordPlace(s);
			word = s;
			this->wordsPlaced = 4;
			break;
		}
		case 5: {
			Words w(4);
			s = w.getWord();
			this->randomWordPlace(s);
			word = s;
			this->wordsPlaced = 4;
			break;
		}
		case 6: {
			Words w(5);
			s = w.getWord();
			this->randomWordPlace(s);
			word = s;
			this->wordsPlaced = 5;
			break;
		}
		case 7: {
			Words w(5);
			s = w.getWord();
			this->randomWordPlace(s);
			word = s;
			this->wordsPlaced = 5;
			break;
		}
		case 8: {
			Words w(6);
			s = w.getWord();
			this->randomWordPlace(s);
			word = s;
			this->wordsPlaced = 6;
			break;
		}
		case 9: {
			Words w(6);
			s = w.getWord();
			this->randomWordPlace(s);
			word = s;
			this->wordsPlaced = 6;
			break;
		}
		case 10: {
			Words w(7);
			s = w.getWord();
			this->randomWordPlace(s);
			word = s;
			this->wordsPlaced = 7;
			break;
		}
		}
	}
}
void Levels::levelMap() {
	int x(0), y(0), c(6);
	system("cls");
	while (true) {
		gotoxy(25, 8);
		SetConsoleTextAttribute(handle, 14);
		std::cout << "--------LEVEL SELECTOR--------";
		SetConsoleTextAttribute(handle, 15);
		gotoxy(20, 14);
		std::cout << "1";
		gotoxy(30, 14);
		std::cout << "2";
		gotoxy(40, 14);
		std::cout << "3";
		gotoxy(50, 14);
		std::cout << "4";
		gotoxy(60, 14);
		std::cout << "5";
		gotoxy(20, 20);
		std::cout << "6";
		gotoxy(30, 20);
		std::cout << "7";
		gotoxy(40, 20);
		std::cout << "8";
		gotoxy(50, 20);
		std::cout << "9";
		gotoxy(60, 20);
		std::cout << "10";
		while (c != 5) {
			SetConsoleTextAttribute(handle, 10);
			gotoxy(16 + x, 14 + y);
			std::cout << "->";
			gotoxy(0, 0);
			c = getKey();
			gotoxy(16 + x, 14 + y);
			std::cout << "  ";
			if (c == 1) {
				if (x == 0)
					x = 0;
				else
					x -= 10;
			}
			if (c == 2) {
				if (x == 40)
					x = 40;
				else
					x += 10;
			}
			if (c == 3) {
				if (y == 0)
					y = 0;
				else
					y -= 6;
			}
			if (c == 4) {
				if (y == 6)
					y = 6;
				else
					y += 6;
			}
		}
		if (y == 0) {
			if (x == 0) {
				this->level = 1;
			}
			else if (x == 10) {
				this->level = 2;
			}
			else if (x == 20) {
				this->level = 3;
			}
			else if (x == 30) {
				this->level = 4;
			}
			else if (x == 40) {
				this->level = 5;
			}
		}
		else if (y == 6) {
			if (x == 0) {
				this->level = 6;
			}
			else if (x == 10) {
				this->level = 7;
			}
			else if (x == 20) {
				this->level = 8;
			}
			else if (x == 30) {
				this->level = 9;
			}
			else if (x == 40) {
				this->level = 10;
			}
		}
		break;
	}
}