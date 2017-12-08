#pragma once

#include "stdafx.h"

class ItemBase
{
public:
	ItemBase();
	~ItemBase();

	int getId();
	void setId(int);

	string getName();
	void setName(string);

	int getScore();
	void setScore(int);

	string getDescription();
	void setDescription(string);

private:

protected:
	int _id;
	string _name;
	string _description;
	int _scoreValue;

};

