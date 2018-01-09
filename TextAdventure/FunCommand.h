/*
	File:			FunCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-9-2018

	Notes:			A class that represents a Fun command. Like jump, sing, dance, etc

*/

#pragma once

#include "stdafx.h"

#include "CommandInterface.h"

class FunCommand :
	public CommandInterface
{
public:
	FunCommand();
	FunCommand(string);
	FunCommand(string, Player*);
	FunCommand(string, Player*,map<string,string>);
	~FunCommand();

	void process() override;
	
private:
	map<string, string> _map;

};