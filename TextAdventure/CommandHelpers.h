#pragma once

#include "stdafx.h"

#include "Command.h"

bool IsValidCommand(vector<string> commands, string command)
{
	return false;
}

void EnterCommand(unique_ptr<Command>& command)
{
	string commandLine;

	cout << "?> ";
	
	getline(cin, commandLine);
	
	command->setCommand(commandLine);

}

void PrintInvalidCommand(unique_ptr<Command>& command)
{
	cout << "I don't understand how to '" << command->getCommand() << "'" << endl;
}

void ProcessCommand(unique_ptr<Command>& command)
{
	// TODO: process the command
	if (command->IsValid())
	{

	}
	else
	{
		PrintInvalidCommand(command);
	}
}