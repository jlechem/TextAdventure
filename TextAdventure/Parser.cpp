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
	_isValid = false;

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
	if (words.empty() )
	{
		cout << "Do what?";
		_isValid = false;
	}
	else
	{
		// look at the first word, this should be a VERB
		_verb = words[0];
		
		// validate the verb is a valid, if not our entire command is invalid
		if (!Verbs::getInstance().containsWord(_verb))
		{
			_isValid = false;
		}
		else
		{
			// based on the size of the sentence we handle things differenty
			switch (words.size())
			{
				// LOOK, N, NE, ETC
				case 1:
					// we already know this is valid or we wouldn't have gotten here past the first valid check
					// so we do nothing here but break out
					_isValid = true;
					break;

				// LOOK ITEM
				// TAKE ITEM
				// DROP ALL
				// two word command
				case 2:
						// this is easy, we just assume the second word is the noun
					_noun = words[1];
					_isValid = true;
					break;

				// LOOK AT ITEM
				// TAKE THE ITEM
				// DROP THE ITEM
				// three word commands
				case 3:
					_articleOne = words[1];
					_noun = words[2];

					_isValid = Articles::getInstance().containsWord(_articleOne);

					break;

				// LOOK AT THE ITEM
				// 4 word commands
				case 4:
					_articleOne = words[1];
					_articleTwo = words[2];
					_noun = words[3];
	
					_isValid =	Articles::getInstance().containsWord(_articleOne) &&
								Articles2::getInstance().containsWord(_articleTwo)  &&
								( _articleOne != _articleTwo );
					break;

				// LOOK AT THE ROUND BLUE ITEM (ADJECTIVES are just examples, could be a lot of them)
				default:
					_articleOne = words[1];
					_articleTwo = words[2];
					
					_isValid = Articles::getInstance().containsWord(_articleOne) &&
						Articles2::getInstance().containsWord(_articleTwo) &&
						(_articleOne != _articleTwo);

					// the noun is the rest of the words
					if (_isValid)
					{
						for (auto i = 3; i < words.size(); i++)
						{
							_noun += words[i] + " ";
						}

						// erase the last space
						_noun.erase(_noun.end() - 1);

					}
					
					break;

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