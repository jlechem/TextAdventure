/*
	File:				OpenCommand.h
	Created By:			Justin LeCheminant
	Created On:			12-27-2017
	Last Modified:		1-9-2018

	Notes:				A class used to open an Item

*/

#pragma once

#include "CommandInterface.h"

class OpenCommand :
	public CommandInterface
{
public:
	OpenCommand();
	OpenCommand(string);
	OpenCommand(string, Player*);
	OpenCommand(string, Player*, Parser*);
	~OpenCommand();

	void process() override;

};