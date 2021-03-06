/*
	File:			SaveCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-26-2018

	Notes:			A class that represents a save command, ie when the user saves their game.

*/

#pragma once

#include "stdafx.h"

#include "CommandInterface.h"
#include "Rooms.h"

class SaveCommand :
	public CommandInterface
{
public:
	SaveCommand();
	SaveCommand(string);
	SaveCommand(string, Player*);
	SaveCommand(string, Player*, Parser*);
	~SaveCommand(); 
		
	void process() override;

private:
	void saveItems(vector<unique_ptr<Item>>&, ofstream& );
	void saveRooms(ofstream&);
};