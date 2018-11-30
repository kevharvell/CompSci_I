/********************************************************************* 
** Author: Kevin Harvell
** Date: 2/7/2018
** Description: The Player class has four data members: a string for
   the player's name, and an int for each of these stats: points, 
   rebounds and assists.
** Player class has a default constructor that initializes the name to
   the empty string and initializes each of the stats to -1
** Player class has a constructor that takes four parameters and uses
   them to initialize the data members.
** Player class has get and set methods for each data member.
** Player class has a bool method called hasMorePointsThan that takes
   a Player parameter and returns true if the Player that is executing
   the function has more points than the Player that was passed as a
   parameter.
*********************************************************************/

#include "Player.hpp"
#include <string>
using std::string;

// Default constructor
Player::Player()
{
	playerName = "";
	setPoints(-1);
	setRebounds(-1);
	setAssists(-1);
}

// Constructor with parameters
Player::Player(string playerNameIn, int pointsIn, int reboundsIn, int assistsIn)
{
	playerName = playerNameIn;
	setPoints(pointsIn);
	setRebounds(reboundsIn);
	setAssists(assistsIn);
}

string Player::getName()
{
	return playerName;
}

void Player::setPoints(int pointsIn)
{
	points = pointsIn;
}

int Player::getPoints()
{
	return points;
}

void Player::setRebounds(int reboundsIn)
{
	rebounds = reboundsIn;
}

int Player::getRebounds()
{
	return rebounds;
}

void Player::setAssists(int assistsIn)
{
	assists = assistsIn;
}

int Player::getAssists()
{
	return assists;
}

/********************************************************************
		Player::hasMorePointsThan()
** a bool method that takes a Player parameter and returns true if 
** the Player that is executing the function has more points than 
** the Player that was passed as a parameter.
********************************************************************/
bool Player::hasMorePointsThan(Player player2)
{
	if(points > player2.getPoints())
		return true;
	else
		return false;	
}

