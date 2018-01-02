/*
	ObjectBase.h
	Created By:		Justin LeCheminant
	Created On:		12-19-2017
	Last Modified:	01-02-2018

	Notes: Base class for all items in the system.

*/

#pragma once

#include "stdafx.h"

#include "ObjectType.h"

class ObjectBase
{
public:
	ObjectBase();
	ObjectBase(int);
	ObjectBase(string, string, int, int, ObjectType);
	~ObjectBase();

	string getName();
	void setName(string);

	string getDescription();
	void setDescription(string);

	int getId();
	void setId(int);

	int getScore();
	void setScore(int);
	void addToScore(int);

	ObjectType getType();
	void setType(ObjectType);

protected:
	string _name;
	string _description;
	int _score;
	ObjectType _type;
	int _id;

private:

};