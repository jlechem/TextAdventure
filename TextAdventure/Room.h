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

	vector<Directions> getExits();
	void setExits(vector<Directions>);
	void addExit(Directions);
	void removeExit(Directions);

private:
	string _name;
	string _description;
	vector<Directions> _exits;

};
