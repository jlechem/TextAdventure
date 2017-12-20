#include "stdafx.h"
#include "LookCommand.h"


LookCommand::LookCommand()
{
}

LookCommand::LookCommand(string command)
	:CommandInterface(command)
{
}


LookCommand::~LookCommand()
{
}

void LookCommand::process()
{
}

void LookCommand::calculateValidity()
{
	_isValid = false;
}