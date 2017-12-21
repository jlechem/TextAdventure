/*
	ExamineCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017
	Notes: Implemenation of the ExamineCommand class.
*/

#include "stdafx.h"
#include "ExamineCommand.h"


ExamineCommand::ExamineCommand(): CommandInterface()
{
}

ExamineCommand::ExamineCommand(string command) : CommandInterface(command)
{
}


ExamineCommand::~ExamineCommand()
{
}

void ExamineCommand::process()
{
}

void ExamineCommand::calculateValidity()
{
}