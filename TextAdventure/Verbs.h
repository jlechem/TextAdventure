/*
	FIle:									Verbs.h
	Created By:					Justin LeCheminant
	Created On:					1-8-2018
	Last Modified On:			1-8-2018

	Notes: Class for loading and holding global valid Verbs

*/

#pragma once

#include "stdafx.h"

#include "WordBase.h"

class Verbs :
	public WordBase
{
public:
	Verbs(Verbs const&) = delete;
	void operator=(Verbs const&) = delete;
	~Verbs();

	static Verbs& getInstance();

private:
	Verbs();

};