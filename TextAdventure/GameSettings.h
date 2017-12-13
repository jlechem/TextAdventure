#pragma once

#include "stdafx.h"

class GameSettings
{
public:
	GameSettings();
	~GameSettings();

	string getIntroduction();
	void setIntroduction(string);

	bool getShowIntroduction();
	void setShowIntroduction(bool);

	string getTitle();
	void setTitle(string);

private:
	string _introduction;

	bool _showIntroduction;

	string _title;

};

