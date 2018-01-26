/*
	File:				TextAdventure.cpp
	Created By:			Justin LeCheminant
	Created On:			1-26-2018
	Last Modified:		1-26-2018
	Last Modified By:	Justin LeCheminant

	Notes:				A class for running a diagnostic command

*/

#pragma once

#include "stdafx.h"

#include "CommandInterface.h"
#include "Player.h"
#include "Parser.h"

class DiagnosticCommand :
	public CommandInterface
{
public:
	DiagnosticCommand();
	DiagnosticCommand(string);
	DiagnosticCommand(string,Player*);
	DiagnosticCommand(string,Player*,Parser*);
	~DiagnosticCommand();

	void process() override;

};