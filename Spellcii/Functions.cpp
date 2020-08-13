#include "Functions.h"

int getKey() {
	char key = _getch();
	if ((key == static_cast<char>(0xe0)) || (key == static_cast<char>(0x00)))
		key = _getch();

	switch (key) {
	case 'K': //left arrow
		return 1;
		break;
	case 'M': //right arrow 
		return 2;
		break;
	case 'H': //up arrow 
		return 3;
		break;
	case 'P': //down arrow
		return 4;
		break;
	case char(13):
		return 5;
		break;
	default:
		return 0;
		break;
	};
}

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
char getCursorChar() {
	char c = '\0';
	CONSOLE_SCREEN_BUFFER_INFO con;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (handle != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo(handle, &con)) {

		DWORD read = 0;

		if (!ReadConsoleOutputCharacter(handle, &c, 1, con.dwCursorPosition, &read) || read != 1) {
			c = '\0';
		}
	}
	return c;
}
char readChar(int x, int y) {
	gotoxy(x, y);
	char cccc = getCursorChar();
	return cccc;
}