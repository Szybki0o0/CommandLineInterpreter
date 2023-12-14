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

	string getContent(string command);

	bool isACommand(string command);
};