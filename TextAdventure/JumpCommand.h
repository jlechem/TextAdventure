#pragma once

#include "CommandInterface.h"

class JumpCommand :
	public CommandInterface
{
public:
	JumpCommand();
	JumpCommand(string, Player*);
	JumpCommand(string, Player*, Parser*);
	~JumpCommand();

	void process() override;

private:
	void calculateValidity() override;

};