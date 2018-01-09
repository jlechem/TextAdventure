/*
	File:				CommandInterface.h
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		1-9-2018
	Last Modified By:	Justin LeCheminant

	Notes: This is an interface class that will get used for dependency injection. When a command is typed in the correct concrete
	implementation will be injected into the appropriate object that holds the command. This is most likely in the actual game loop.

	Subclasses HAVE TO IMPLEMENT:
	public:
		void process();
		CONSTRUCTOR(string);
		CONSTRUCTOR(string);
		CONSTRUCTOR(string, Player*);
		CONSTRUCTOR(string, Player*, Parser*);

*/

#pragma once

#include "stdafx.h"

#include "ActorBase.h"
#include "Player.h"
#include "Parser.h"

class CommandInterface
{
public:
	CommandInterface();
	CommandInterface(string);
	CommandInterface(string, Player*);
	CommandInterface(string, Player*, Parser*  );

	virtual ~CommandInterface();

	virtual void process() = 0;

	string getCommad();
	void setCommand(string);

	string getResult();

	Player* getPlayer();
	void setPlayer(Player*);

	Player* getPlayerToActOn();
	void setPlayerToActOn(Player*);

protected:
	string _command;
	string _commandResult;

	Player* _player;
	Player* _playerToActOn;

	Parser* _parser;

};