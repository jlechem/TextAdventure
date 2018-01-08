/*
	File:									Articles.cpp
	Created By:					Justin LeCheminant
	Created On:					1-8-2018
	Last Modified On:			1-8-2018

	Notes: Implementation of the Articles class

*/

#include "stdafx.h"

#include "Articles.h"

Articles::Articles()
{
}

Articles::~Articles()
{
}

Articles & Articles::getInstance()
{
	static Articles instance;
	return instance;
}