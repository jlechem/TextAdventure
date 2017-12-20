#pragma once

#include "CommandBase.h"

class LookCommand :
	public CommandBase
{
public:
	LookCommand();
	~LookCommand();

	void process();

};