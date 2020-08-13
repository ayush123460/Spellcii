#include "Alibaba.h"

Alibaba::Alibaba()
:inGame(false),
exitCon(false),
tutorial(false),
back(false),
levelFin(false)
{
	//Define console resolution in a Rectangle structure
	SMALL_RECT rect;
	rect.Left = 0;
	rect.Top = 0;
	rect.Bottom = 30;
	rect.Right = 80;

	//Set the console resolution
	SetConsoleWindowInfo(handle, TRUE, &rect);

	//Splash screen
	this->start();

	//Not sure why but this is required
	std::cin.ignore(1);

	while (!inGame && !exitCon) {
		this->menu();
	}
}
void Alibaba::startPlay() {
	//load the level
	l.loadLevel();
	p.x = 1;
	p.y = 1;
	int x;
	gotoxy(p.x, p.y);
	SetConsoleTextAttribute(handle, 11);
	std::cout << "@";
	while (inGame) {
		x = this->update();
		gotoxy(0, 0);
	}
	if (l.getLevels() == 0) {
		if (x == 0) {
			system("cls");
			SetConsoleTextAttribute(handle, 15);
			std::cout << "You have completed the tutorial level.\nPress enter key to continue...";
			std::cout << "You entered: " << this->s << std::endl;
		}
		else {
			system("cls");
			SetConsoleTextAttribute(handle, 15);
			std::cout << "You collected the words in the wrong order, try again!";
			std::cout << "You entered: " << this->s << std::endl;
		}
	}
	else {
		if (x == 0) {
			system("cls");
			SetConsoleTextAttribute(handle, 15);
			std::cout << "You have finished the level.\nPress enter key to continue...";
			std::cout << "You entered: " << this->s << std::endl;
		}
		else {
			system("cls");
			SetConsoleTextAttribute(handle, 15);
			std::cout << "You collected the words in the wrong order, try again!\n";
			std::cout << "You entered: " << this->s << std::endl;
			std::cout << "The correct word is: " << l.getWord();
		}
	}
	int c(6);
	while (c != 5)
		c = getKey();
	Alibaba();
}

Alibaba::~Alibaba() {}

void Alibaba::start() {
	system("cls");
	SetConsoleTextAttribute(handle, 11);
	gotoxy(33, 14);
	std::cout << "SPELLCII";
	for (;;) {
		gotoxy(26, 16);
		SetConsoleTextAttribute(handle, 7);
		std::cout << "Press enter to start";
		Sleep(500);
		if (_kbhit()) {
			break;
		}
		gotoxy(26, 16);
		SetConsoleTextAttribute(handle, 0);
		std::cout << "Press enter to start";
		Sleep(500);
		if (_kbhit()) {
			break;
		}
	}
	SetConsoleTextAttribute(handle, 15);
}
void Alibaba::menu() {
	system("cls");
	while (true) {
		int selected(2), c(6);
		gotoxy(28, 8);
		SetConsoleTextAttribute(handle, 14);
		std::cout << "--------MENU--------";
		SetConsoleTextAttribute(handle, 15);
		gotoxy(34, 13);
		std::cout << "TUTORIAL";
		gotoxy(36, 15);
		std::cout << "PLAY";
		gotoxy(36, 17);
		std::cout << "QUIT";
		while (c != 5) {
			SetConsoleTextAttribute(handle, 10);
			gotoxy(31, 13 + selected);
			std::cout << "->";
			gotoxy(43, 13 + selected);
			std::cout << "<-";
			gotoxy(0, 0);
			c = getKey();
			gotoxy(31, 13 + selected);
			std::cout << "  ";
			gotoxy(43, 13 + selected);
			std::cout << "  ";
			if (c == 4) {
				if (selected < 4)
					selected += 2;
			}
			else if (c == 3) {
				if (selected > 0)
					selected -= 2;
			}
		}
		if (selected == 0) {
			this->tutorial = true;
			this->tutorialMenu();
		}
		else if (selected == 2) {
			this->l.levelMap();
			this->inGame = true;
			this->startPlay();
		}
		else if (selected == 4) {
			exit(0);
		}
	}
}
void Alibaba::tutorialMenu() {
	system("cls");
	int c = 0;
	int selected = 2;
	SetConsoleTextAttribute(handle, 14);
	gotoxy(26, 8);
	std::cout << "--------TUTORIAL--------";
	SetConsoleTextAttribute(handle, 15);
	gotoxy(36, 13);
	std::cout << "Play";
	gotoxy(36, 15);
	std::cout << "Help";
	gotoxy(36, 17);
	std::cout << "Back";
	while (c != 5) {
		SetConsoleTextAttribute(handle, 10);
		gotoxy(31, 13 + selected);
		std::cout << "->";
		gotoxy(43, 13 + selected);
		std::cout << "<-";
		gotoxy(0, 0);
		c = getKey();
		gotoxy(31, 13 + selected);
		std::cout << "  ";
		gotoxy(43, 13 + selected);
		std::cout << "  ";
		if (c == 4) {
			if (selected < 4)
				selected += 2;
		}
		else if (c == 3) {
			if (selected > 0)
				selected -= 2;
		}
	}
	if (selected == 0) {
		this->help();
		system("cls");
		this->inGame = true;
		this->l.setLevel(0);
		this->startPlay();
	}
	else if (selected == 2) {
		this->help();
	}
	else if (selected == 4) {
		this->tutorial = false;
	}
}
int Alibaba::update() {
	int x;
	char c;
	if (_kbhit()) {
		x = getKey();
		if (l.wordsPlaced == 0) {
			inGame = false;
		}
		if (x == 1) {
			c = readChar(p.x - 1, p.y);
			if (c != '#') {
				if (isalpha(c)) {
					s += c;
					l.wordsPlaced -= 1;
				}
				gotoxy(p.x, p.y);
				std::cout << " ";
				p.x -= 1;
				gotoxy(p.x, p.y);
				SetConsoleTextAttribute(handle, 11);
				std::cout << "@";
			}
		}
		if (x == 2) {
			c = readChar(p.x + 1, p.y);
			if (c != '#') {
				if (isalpha(c)) {
					s += c;
					l.wordsPlaced -= 1;
				}
				gotoxy(p.x, p.y);
				std::cout << " ";
				p.x += 1;
				gotoxy(p.x, p.y);
				SetConsoleTextAttribute(handle, 11);
				std::cout << "@";
			}
		}
		if (x == 3) {
			c = readChar(p.x, p.y - 1);
			if (c != '#') {
				if (isalpha(c)) {
					s += c;
					l.wordsPlaced -= 1;
				}
				gotoxy(p.x, p.y);
				std::cout << " ";
				p.y -= 1;
				gotoxy(p.x, p.y);
				SetConsoleTextAttribute(handle, 11);
				std::cout << "@";
			}
		}
		if (x == 4) {
			c = readChar(p.x, p.y + 1);
			if (c != '#') {
				if (isalpha(c)) {
					s += c;
					l.wordsPlaced -= 1;
				}
				gotoxy(p.x, p.y);
				std::cout << " ";
				p.y += 1;
				gotoxy(p.x, p.y);
				SetConsoleTextAttribute(handle, 11);
				std::cout << "@";
			}
		}
		if (l.wordsPlaced == 0) {
			if (l.getLevels() == 0) {
				if (s == "ARK")
					return 0;
				else
					return 1;
			}
			else {
				if (s == l.getWord())
					return 0;
				else {
					Words wc;
					int qwerty = wc.wordc(s, s.size());
					if (qwerty == 0) {
						return 0;
					}
					else {
						return 1;
					}
				}
			}
			inGame = false;
		}
	}
}

void Alibaba::help() {
	help:
	system("cls");
	gotoxy(25, 11);
	SetConsoleTextAttribute(handle, 15);
	std::cout << "Want to know how to play?(Y/N)";
	gotoxy(39,12);
	//std::cin.ignore(1);
	char c = getchar();
	if (islower(c)) {
		toupper(c);
	}
	switch (c){
	case 'Y':
		system("cls");
		gotoxy(30, 8);
		SetConsoleTextAttribute(handle, 14);
		std::cout << "--SPELLCII HELP--";
		gotoxy(24, 11);
		SetConsoleTextAttribute(handle, 15);
		std::cout << "Use arrow keys to move around.";
		gotoxy(25, 13);
		SetConsoleTextAttribute(handle, 11);
		std::cout << "@";
		SetConsoleTextAttribute(handle, 12);
		std::cout << " <-";
		SetConsoleTextAttribute(handle, 15);
		std::cout << " This is your character.";
		gotoxy(25, 15);
		SetConsoleTextAttribute(handle, 10);
		std::cout << "#";
		SetConsoleTextAttribute(handle, 12);
		std::cout << " <-";
		SetConsoleTextAttribute(handle, 15);
		std::cout << " This is an immovable object.";
		gotoxy(5, 17);
		std::cout << "Eat the letters from the maze in the correct order to finish the level.";
		std::cin.ignore(2);
		_getch();
		system("cls");
		break;
	case 'N':
		break;
	default:
		gotoxy(35, 13);
		std::cout << "That's not an option...";
		_getch();
		goto help;
	}
}