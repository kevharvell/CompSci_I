/********************************************************************* 
** Author: Kevin Harvell
** Date: 2/8/2018
** Description: Team class has five data members of type Player: a 
   point guard, a shooting guard, a small forward, a power forward,
   and a center.
** Team class has a constructor that takes five Players and uses them
   to initialize each of those data members (in the given order)
** Team class has get and set methods for each data member.
** Team class has a method named totalPoints that returns the sum of
   the points for all players on the team. 
*********************************************************************/

#include "Team.hpp"

Team::Team(Player pointGuardIn, Player shootingGuardIn, Player smallForwardIn,
	   Player powerForwardIn, Player centerIn)
{
	setPointGuard(pointGuardIn);
	setShootingGuard(shootingGuardIn);
	setSmallForward(smallForwardIn);
	setPowerForward(powerForwardIn);
	setCenter(centerIn);
}

void Team::setPointGuard(Player pointGuardIn)
{
	pointGuard = pointGuardIn;
}

Player Team::getPointGuard()
{
	return pointGuard;
}

void Team::setShootingGuard(Player shootingGuardIn)
{
	shootingGuard = shootingGuardIn;
}

Player Team::getShootingGuard()
{
	return shootingGuard;
}

void Team::setSmallForward(Player smallForwardIn)
{
	smallForward = smallForwardIn;
}

Player Team::getSmallForward()
{
	return smallForward;
}

void Team::setPowerForward(Player powerForwardIn)
{
	powerForward = powerForwardIn;
}

Player Team::getPowerForward()
{
	return powerForward;
}

void Team::setCenter(Player centerIn)
{
	center = centerIn;
}

Player Team::getCenter()
{
	return center;
}

/*********************************************************************
**		    Team::totalPoints()
** totalPoints returns the sum of the points for all players 
** on the team. 
*********************************************************************/

int Team::totalPoints()
{
	int total;
	total = getPointGuard().getPoints() +
		getShootingGuard().getPoints() +
		getSmallForward().getPoints() +
		getPowerForward().getPoints() +
		getCenter().getPoints();
	return total;
}
