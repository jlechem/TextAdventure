/*
	FIle:									Articles2.cpp
	Created By:					Justin LeCheminant
	Created On:					1-8-2018
	Last Modified On:			1-8-2018

	Notes: Implementation of the Articles2 class

*/

#include "stdafx.h"

#include "Articles2.h"

Articles2::Articles2()
{
}

Articles2::~Articles2()
{
}

Articles2 & Articles2::getInstance()
{
	static Articles2 instance;
	return instance;
}