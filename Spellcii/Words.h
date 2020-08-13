#ifndef WORDS_H
#define WORDS_H
#include<fstream>
#include<string>
#include<random>
#include<ctime>

class Words {
private:
protected:
	std::string word;
	int wordSize;
	std::fstream fileHandle;
	//std::mt19937 random;
	std::random_device rd;
	std::default_random_engine random;
public:
	int wordc(std::string s, int l);
	Words();
	Words(int w);
	virtual ~Words();
	std::string getWord() { return this->word; }
};

#endif