#pragma once

#include "CommandInterface.h"

class JumpCommand :
	public CommandInterface
{
public:
	JumpCommand();
	JumpCommand(string, Player*);
	~JumpCommand();

	void process();

private:
	void calculateValidity();

};