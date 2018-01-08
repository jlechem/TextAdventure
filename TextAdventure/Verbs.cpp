/*
	FIle:									Verbs.cpp
	Created By:					Justin LeCheminant
	Created On:					1-8-2018
	Last Modified On:			1-8-2018

	Notes: Implementation of the Verbs class

*/

#include "stdafx.h"

#include "Verbs.h"

Verbs::Verbs()
{
}

Verbs::~Verbs()
{
}

Verbs & Verbs::getInstance()
{
	static Verbs instance;
	return instance;
}