/*
Map.cpp
Created By:			Justin LeCheminant
Created On:			12-20-2017
Last Modified:		12-20-2017
Last Modified By:	Justin LeCheminant

Notes: Implementation of the Player class.

*/

#include "stdafx.h"
#include "Player.h"

Player::Player(): ActorBase()
{
}

Player::Player(shared_ptr<Room> initialRoom): ActorBase(initialRoom)
{

}

Player::~Player()
{
}

void Player::takeAllItems()
{
	// TODO: implement take all
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