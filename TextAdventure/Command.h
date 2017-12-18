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
	string getCommandResult();
	void setPlayer(shared_ptr<Player>);
	void process();
	void printResult();
	vector<string>& getVerbs();

private:
	string _commandResult;				// result of the command
	vector<string> _commands;			// string command seperated using white space
	string _command;					// entire command

	vector<string> _validActions;		// a list of valid base actions, look, jump, etc

	map<string, string> _funCommands;	// single commands with no real use, like jump, hum, dance, etc

	shared_ptr<Player> _player;			// the player, we need this for item management, etc

	void parseCommand();
	bool isActionCommand(string verb);
	bool isMoveCommand(string verb);
	bool isTakeCommand(string verb);
	bool isLookCommand(string verb);
	bool isDropCommand(string verb);
	bool isItemCommand(string verb);
	bool isInventoryCommand(string verb);
	bool isSaveCommand(string verb);
	bool isExitCommand(string verb);
	void calculateActionResult(string verb);
	void loadActions();
	bool isValid(string);
};