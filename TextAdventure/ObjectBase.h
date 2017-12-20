#pragma once

#include "stdafx.h"

#include "ObjectType.h"

class ObjectBase
{
public:
	ObjectBase();
	ObjectBase(string, string, int, ObjectType);
	~ObjectBase();

	string getName();
	void setName(string);

	string getDescription();
	void setDescription(string);

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

private:

};

