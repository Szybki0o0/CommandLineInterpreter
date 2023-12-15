#include "Parser.h"
#include <iostream>
#include <string>

using namespace std;

string commands[] = { "cd", "dir", "mkdir", "copy", "help", "rmdir"};

Parser::Parser(const string& command) : fcommand(command) {}

void Parser::setCommand(string command) { fcommand = command; }

string Parser::getCommand() const { return fcommand; }

string Parser::getKeyWord(string command)
{
	string temp;
	for (auto i : command)
	{
		if (i == ' ') return temp;
		temp += i;
	}
	return temp;
}

string Parser::getFirstContent(string command)
{
	string temp;
	int breakPoint = 0;
	for (auto i : command)
	{
		if (breakPoint == 1) temp += i;		
		if (i == ' ') breakPoint = 1;
	}
	return temp;
}

string Parser::getSecondContent(string command)
{
	string temp;
	int breakPoint = 0;
	for (auto i : command)
	{
		if (breakPoint == 1) temp += i;
		if (i == ' ') breakPoint = 1;
	}
	return temp;
}

bool Parser::isACommand(string keyWord) {
	//string keyWord = getKeyWord(command);
	for (auto i : commands)
	{
		if (keyWord == i) return true;
	}
	return false;
}
