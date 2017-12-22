/*
	CommandInterface.h
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-21-2017
	Last Modified By:	Justin LeCheminant

	Notes: This is an interface class that will get used for dependency injection. When a command is typed in the correct concrete
	implementation will be injected into the appropriate object that holds the command. This is most likely in the actual game loop.

	Subclasses HAVE TO IMPLEMENT:
	public:
		void process();
		CONSTRUCTOR(string);

	protected:
		void calculateValidity();

*/

#pragma once

#include "stdafx.h"

#include "ActorBase.h"
#include "Player.h"

class CommandInterface
{
public:
	CommandInterface();
	CommandInterface(string);
	CommandInterface(string, shared_ptr<Player>);
	virtual ~CommandInterface();

	virtual void process() = 0;
	
	string getCommad();
	void setCommand(string);

	void addWord(string);
	vector<string>& getWords();

	string getResult();

	shared_ptr<Player> getPlayer();
	void setPlayer(shared_ptr<Player>);

	shared_ptr<Player> getPlayerToActOn();
	void setPlayerToActOn(shared_ptr<Player>);

	unique_ptr<ObjectBase>& getObjectToActOn();
	void setObjectToActOn(unique_ptr<ObjectBase>);

protected:
	bool _isValid;

	string _command;
	string _commandResult;

	vector<string> _commandWords;

	virtual void calculateValidity() = 0;

	shared_ptr<Player> _player;
	shared_ptr<Player> _playerToActOn;
	unique_ptr<ObjectBase> _objectToActOne;
	
	void parseCommand();

};