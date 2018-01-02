/*
	Parser.h
	Created By:		Justin LeCheminant
	Created On:		12-28-2017
	Last Modified:	01-02-2018

	Notes: This is the parser class used to parse a players input into something manageable we can use to create
	commands, actions, etc.

*/

#pragma once

class Parser
{
public:
	Parser();
	~Parser();

	void parse(string);

	string getVerb();
	string getNoun();
	string getAdjective();

private:
	string _verb;
	string _noun;
	string _adjective;

};