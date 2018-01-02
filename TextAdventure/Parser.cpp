/*
	Parser.cpp
	Created By:		Justin LeCheminant
	Created On:		12-28-2017
	Last Modified:	01-02-2018

	Notes: Implementation of the parser class.

*/

#include "stdafx.h"

#include "Parser.h"

#include "Utils.h"


Parser::Parser()
{
}

Parser::~Parser()
{
}

void Parser::parse(string sentence)
{
	Utilities::toLower(sentence);

	// split the words into a vector
	vector<string> words;

	// validate the length
	if (words.size() == 0)
	{
		cout << "Do what?";
	}
	else
	{
		// look at the first word, this should be a valid VERB (LOOK,MOVE,etc)


	}


}

string Parser::getVerb()
{
	return _verb;
}

string Parser::getNoun()
{
	return _noun;
}

string Parser::getAdjective()
{
	return _adjective;
}