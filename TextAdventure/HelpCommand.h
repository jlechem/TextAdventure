#pragma once

#include "CommandInterface.h"

class HelpCommand :
	public CommandInterface
{
public:
	HelpCommand();
	HelpCommand(string);
	HelpCommand(string, Player*);
	~HelpCommand();

	void process() override;

protected:
	void calculateValidity() override;

};