#pragma once

#include "stdafx.h"

#include "ActionType.h"
#include "Player.h"

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
	string getCommandResult();
	ActionType getActionType();
	void setPlayer(shared_ptr<Player>);
	unique_ptr<vector<string>>& getVerbs();
	void Process();
	void PrintResult();
	bool IsValid();

private:
	string _commandResult;	// result of the command
	string _action;			// look, north, take, etc
	string _noun;			// thing actions acts on, Item, Treasure, etc
	string _modifier;		// temp words, ie ACTION at NOUN
	string _command;		// entire command, ACTION MODIFIER NOUN
	bool _isValid;			// is this commands valid

	shared_ptr<Player> _player;

	unique_ptr<vector<string>> _verbs;
	unique_ptr<vector<string>> _nouns;
	unique_ptr<vector<string>> _modifiers;

	ActionType _actionType;

	void parseCommand();
	void calculateIsValid(vector<string>);
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