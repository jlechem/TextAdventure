/*
Map.cpp
Created By:			Justin LeCheminant
Created On:			12-20-2017
Last Modified:		12-26-2017
Last Modified By:	Justin LeCheminant

Notes: Implementation of the Player class.

*/

#include "stdafx.h"
#include "Player.h"

Player::Player(): ActorBase()
{
	_isGameOver = false;
}

Player::Player(Room* initialRoom): ActorBase(initialRoom)
{
	_isGameOver = false;
}

Player::~Player()
{
}

void Player::printInventory()
{
	vector<unique_ptr<Item>>::iterator it;

	cout << "You have the following items" << endl;

	for (it = _items.begin(); it != _items.end(); ++it)
	{
		cout << (*it)->getName() << endl;
	}
}

string Player::takeAllItems()
{
	string result = "";
	
	vector<unique_ptr<Item>>::iterator it;

	// get all the items from this room
	vector<unique_ptr<Item>>* items = _currentRoom->getAllItems();

	if (items->size() == 0)
	{
		result = "There's nothing here to take";
	}
	else
	{
		try
		{
			// loop through the items in the room and add them to our inventory
			// add them to the players inventory
			for (it = items->begin(); it != items->end(); ++it)
			{
				if ((*it)->getCanTake())
				{
					result += (*it)->getName() + ": Taken\n";
					_score += (*it)->getScore();
					_items.push_back(std::move((*it)));
				}
				else
				{
					result += (*it)->getName() + ": Nice try\n";
				}
			}

			items->clear();

			_currentRoom->setItemsString("");

			// clear any ', ' at the end
			if (result.size() > 2)
			{
				result.erase(result.end() - 1);
			}
		}
		catch (exception* e)
		{
			cout << e->what() << endl;
		}
	}
	
	return result;

}

string Player::dropAllItems()
{
	string result = "";

	vector<unique_ptr<Item>>::iterator it;

	if (_items.size() == 0)
	{
		result = "You don't have anything";
	}
	else
	{
		try
		{
			// loop through the items in the room and add them to our inventory
			for (it = _items.begin(); it != _items.end(); ++it)
			{
				result += (*it)->getName() + ": Dropped\n";
				_score -= (*it)->getScore();
				_currentRoom->addItem(std::move((*it)));
			}

			_items.clear();

			// clear any '\n' at the end
			if (result.size() > 1)
			{
				result.erase(result.end() - 1);
			}
		}
		catch (exception* e)
		{
			cout << e->what() << endl;
		}
	}

	return result;

}

bool Player::getIsGameOver()
{
	return _isGameOver;
}

void Player::setIsGameOver(bool gameOverFlag)
{
	_isGameOver = gameOverFlag;
}

string Player::toString()
{
	// TODO: should the player class return something descriptive??
	return "";
}

unsigned long Player::getTotalExperience()
{
	return _totalExperience;
}

void Player::setTotalExperience(unsigned long experience)
{
	_totalExperience = experience;
}

unsigned long Player::getExperienceToNextLevel()
{
	return _experienceToNextLevel;
}

void Player::setExperienceToNextLevel(unsigned long experience)
{
	_experienceToNextLevel = experience;
}

string Player::openItem(string name)
{
	string result = "";

	auto item = findItem(name);

	if (item)
	{
		if (item->getCanOpen())
		{
			if (item->getIsOpen())
			{
				item->setIsOpen(true);
			}
			else
			{
				result = name + ": Is already open";
			}
		}
		else
		{
			result = name + ": Nice try";
		}
	}
	
	_items.push_back(std::move(item));

	return result;

}

string Player::closeItem(string name)
{
	return "";
}
