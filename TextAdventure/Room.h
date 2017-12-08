#pragma once

#include "stdafx.h"

class Room
{
public:
	Room();
	~Room();

	string getName();
	void setName(string);

	string getDescription();
	void setDescription(string);

	unique_ptr<map<Directions, shared_ptr<Room>>> getExits();
	void setExits(unique_ptr<map<Directions, shared_ptr<Room>>>);
	void addExit(Directions, shared_ptr<Room>);

private:
	string _name;
	string _description;
	unique_ptr<map<Directions,shared_ptr<Room>>> _exits;

};