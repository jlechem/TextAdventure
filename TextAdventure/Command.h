#pragma once

#include "stdafx.h"

class Command
{
public:
	Command();
	Command(string);

	~Command();

	void setCommand(string);
	string getCommand();

	unique_ptr<vector<string>>& getVerbs();

	bool IsValid();

private:
	string _action;		// look, north, take, etc
	string _noun;		// thing actions acts on, Item, Treasure, etc
	string _modifier;	// temp words, ie ACTION at NOUN
	string _command;	// entire command, ACTION MODIFIER NOUN
	bool _isValid;		// is this commands valid

	void parseCommand();
	void calculateIsValid(vector<string>);
	
	unique_ptr<vector<string>> _verbs;

};