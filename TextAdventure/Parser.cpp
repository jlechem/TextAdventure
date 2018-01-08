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

	vector<string> words;

	// this is an entire sentence so we need to break it up and parse the words
	if (!sentence.empty())
	{
		// tokenize the command based on spaces
		char delim = ' ';
		stringstream ss(sentence);
		string item;

		words.clear();

		while (std::getline(ss, item, delim))
		{
			words.push_back(item);
		}
	}

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

string Parser::getArticleOne()
{
	return _articleOne;
}

string Parser::getArticleTwo()
{
	return _articleTwo;
}

bool Parser::getIsValid()
{
	return _isValid;
}