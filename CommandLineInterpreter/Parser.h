#pragma once

#include <string>
#include <vector>

using namespace std;

class Parser {
private:
	string fcommand;
public:
	Parser(const string& command);

	void setCommand(string command);

	string getCommand() const;

	string getKeyWord(string command);

	string getFirstContent(string command);

	string getSecondContent(string command);

	bool isACommand(string command);
};