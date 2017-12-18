/*
	Command.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-18-2017
	Notes: A class that represents a command entered by the user
*/

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
	
	void loadActions();
	
	bool isFunCommand(string);
	bool isMoveCommand(string);
	bool isTakeCommand(string);
	bool isLookCommand(string);
	bool isDropCommand(string);
	bool isItemCommand(string);
	bool isInventoryCommand(string);
	bool isSaveCommand(string);
	bool isExitCommand(string);
	bool isMissingAction(string);
	bool isKillCommand(string);
	bool isValid(string);
	bool isActionCommand(string);
	bool isClearCommand(string);

	void setRoomDescription();
	void setInvalidMove(string);

};