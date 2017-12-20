#pragma once

#include "CommandInterface.h"

class LookCommand :
	public CommandInterface
{
public:
	LookCommand();
	LookCommand(string);
	~LookCommand();

	void process();

private:
	void calculateValidity();
};