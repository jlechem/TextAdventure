/*
	Parser.h
	Created By:		Justin LeCheminant
	Created On:		12-28-2017
	Last Modified:	01-02-2018

	Notes: This is the parser class used to parse a players input into something manageable we can use to create
	commands, actions, etc.

*/

#pragma once

#include "stdafx.h"

#include "Articles.h"
#include "Articles2.h"
#include "Verbs.h"

class Parser
{
public:
	Parser();
	~Parser();

	void parse(string);

	string getVerb();
	string getNoun();
	string getArticleOne();
	string getArticleTwo();
	bool getIsValid();

private:
	string _sentence;
	string _verb;
	string _noun;
	string _articleOne;
	string _articleTwo;
	string _connector;

	bool _isValid;

};