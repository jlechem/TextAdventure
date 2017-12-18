#pragma once

#include "stdafx.h"

#include "ActionType.h"



class Command
{
public:
	Command();
	Command(string);

	~Command();

	void setCommand(string);
	string getCommand();

	string getAction();
	string getNoun();
	string getModifier();
	string getActionResult();

	ActionType getActionType();

	unique_ptr<vector<string>>& getVerbs();

	bool IsValid();

private:
	string _actionResult;	// you jump up and down, you sleep, you rest, etc
	string _action;			// look, north, take, etc
	string _noun;			// thing actions acts on, Item, Treasure, etc
	string _modifier;		// temp words, ie ACTION at NOUN
	string _command;		// entire command, ACTION MODIFIER NOUN
	bool _isValid;			// is this commands valid

	void parseCommand();
	void calculateIsValid(vector<string>);

	unique_ptr<vector<string>> _verbs;
	unique_ptr<vector<string>> _nouns;
	unique_ptr<vector<string>> _modifiers;

	ActionType _actionType;

	bool isActionCommand(string verb);
	bool isMoveCommand(string verb);
	bool isTakeCommand(string verb);
	bool isLookCommand(string verb);
	bool isDropCommand(string verb);
	bool isItemCommand(string verb);
	bool isInventoryCommand(string verb);
	bool isSaveCommand(string verb);
	bool isExitCommand(string verb);
	void calculateActionType(string verb);
	void calculateActionResult(string verb);

};