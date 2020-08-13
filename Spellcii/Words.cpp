#include "Words.h"

int Words::wordc(std::string s, int l) {
	switch (l) {
	case 3:
		this->fileHandle.open("dict/3.txt");
		break;
	case 4:
		this->fileHandle.open("dict/4.txt");
		break;
	case 5:
		this->fileHandle.open("dict/5.txt");
		break;
	case 6:
		this->fileHandle.open("dict/6.txt");
		break;
	case 7:
		this->fileHandle.open("dict/7.txt");
		break;
	}
	while (std::getline(this->fileHandle, this->word)) {
		if (s == word) {
			return 0;
		}
	}
	return 1;
}

Words::Words() {}

Words::Words(int w)
:wordSize(w){
	int i = 0, words = 0;
	random.seed(rd());
	switch (this->wordSize) {
	case 3:
	{
		this->fileHandle.open("dict/3.txt");
		std::uniform_int_distribution<int> id(1, 2129);
		int ran = id(this->random);
		while (std::getline(this->fileHandle, this->word)) {
			i++;
			if (i == ran) {
				break;
			}
		}
		break;
	}
	case 4:
	{
		this->fileHandle.open("dict/4.txt");
		std::uniform_int_distribution<int> id(1, 7183);
		int ran = id(this->random);
		while (std::getline(this->fileHandle, this->word)) {
			i++;
			if (i == ran) {
				break;
			}
		}
		break;
	}
	case 5:
	{
		this->fileHandle.open("dict/5.txt");
		std::uniform_int_distribution<int> id(1, 15917);
		int ran = id(this->random);
		while (std::getline(this->fileHandle, this->word)) {
			i++;
			if (i == ran) {
				break;
			}
		}
		break;
	}
	case 6:
	{
		this->fileHandle.open("dict/6.txt");
		std::uniform_int_distribution<int> id(1, 29873);
		int ran = id(this->random);
		while (std::getline(this->fileHandle, this->word)) {
			i++;
			if (i == ran) {
				break;
			}
		}
		break;
	}
	case 7:
	{
		this->fileHandle.open("dict/7.txt");
		std::uniform_int_distribution<int> id(1, 41996);
		int ran = id(this->random);
		while (std::getline(this->fileHandle, this->word)) {
			i++;
			if (i == ran) {
				break;
			}
		}
		break;
	}
	}
	fileHandle.close();
}
Words::~Words() {}