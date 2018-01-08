/*
	FIle:									WordBase.cpp
	Created By:					Justin LeCheminant
	Created On:					1-8-2018
	Last Modified On:			1-8-2018

	Notes: Implementation of the WordBase class.

*/

#include "stdafx.h"

#include "WordBase.h"

WordBase::WordBase()
{
}

WordBase::~WordBase()
{
}

void WordBase::Load(string filename)
{
	ifstream inputFile(filename);

	if (inputFile.is_open())
	{
		string line;

		while (!inputFile.eof())
		{
			getline(inputFile, line);
			_words.push_back(line);
		}
	}
}

vector<string>& WordBase::getWords()
{
	return _words;
}

void WordBase::addWord(string word)
{
	_words.push_back(word);
}

void WordBase::removeWord(string word)
{
	auto found = find(_words.begin(), _words.end(), word);

	if (found != _words.end())
	{
		_words.erase(found);
	}
}