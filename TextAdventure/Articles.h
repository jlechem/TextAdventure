/*
	File:									Articles.h
	Created By:					Justin LeCheminant
	Created On:					1-8-2018
	Last Modified On:			1-8-2018

	Notes: A class used for articles

*/

#pragma once

#include "WordBase.h"

class Articles :
	public WordBase
{
public:
	Articles(Articles const&) = delete;
	void operator=(Articles const&) = delete;
	~Articles();

	static Articles& getInstance();

private:
	Articles();

};