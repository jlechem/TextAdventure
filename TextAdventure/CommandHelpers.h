#pragma once

#include "stdafx.h"

#include "Command.h"

bool IsValidCommand(vector<string> commands, string command)
{
	return false;
}

void EnterCommand(Command& command)
{
	string commandLine;

	cout << "?> ";
	
	getline(cin, commandLine);
	
	command.setCommand(commandLine);

}

void ProcessCommand(Command command)
{
	// TODO: process the command
}

void PrintInvalidCommand(Command command)
{

}