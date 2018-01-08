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
		_verb = words[0];
		
		// validate the verb is a valid verb, if not our entire command is invalid
		if (!Verbs::getInstance().containsWord(_verb))
		{
			_isValid = false;
		}
		else
		{
			// next if we have anything should be an article or noun
			if (words.size() > 1)
			{
				// if no article we assume its all noun the rest of the way
				if (!Articles::getInstance().containsWord(words[1]))
				{
					for (auto i = 1; i < words.size(); i++)
					{
						_noun += words[i] + " ";
					}

					// trim the end of the noun
					if (_noun.size() > 1)
					{
						_noun.erase(_noun.end() - 1);
					}
				}
			}




		}
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

bool Parser::getIsValid()
{
	return _isValid;
}