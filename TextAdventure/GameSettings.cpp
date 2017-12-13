#include "stdafx.h"
#include "GameSettings.h"

GameSettings::GameSettings()
{
}


GameSettings::~GameSettings()
{
}

string GameSettings::getIntroduction()
{
	return _introduction;
}

void GameSettings::setIntroduction(string value)
{
	_introduction = value;
}

bool GameSettings::getShowIntroduction()
{
	return _showIntroduction;
}

void GameSettings::setShowIntroduction(bool value)
{
	_showIntroduction = value;
}

string GameSettings::getTitle()
{
	return _title;
}

void GameSettings::setTitle(string value)
{
	_title = value;
}