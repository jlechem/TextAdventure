#pragma once

#include "stdafx.h"

#include "ItemBase.h"

class Item: public ItemBase
{
public:
	Item();
	~Item();

private:
	bool _isContainer;

	vector<Item> _subItems;

};