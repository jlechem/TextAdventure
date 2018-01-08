/*
	File:									WordBase.h
	Created By:					Justin LeCheminant
	Created On:					1-8-2018
	Last Modified On:			1-8-2018

	Notes: A class used for all word collcetions, mainly to load the vector

*/

#pragma once

#include "stdafx.h"

class WordBase
{
public:
	WordBase();
	~WordBase();

	void Load(string);

	vector<string>& getWords();
	void addWord(string);
	void removeWord(string);

protected:
	vector<string> _words;

};