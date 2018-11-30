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

#ifndef TEAM_HPP
#define TEAM_HPP
#include "Player.hpp"

class Team
{
	private:
		Player pointGuard;
		Player shootingGuard;
		Player smallForward;
		Player powerForward;
		Player center;
	public:
		Team(Player, Player, Player, Player, Player);
		void setPointGuard(Player);
		Player getPointGuard();
		void setShootingGuard(Player);
		Player getShootingGuard();
		void setSmallForward(Player);
		Player getSmallForward();
		void setPowerForward(Player);
		Player getPowerForward();
		void setCenter(Player);
		Player getCenter();
		int totalPoints();
};

#endif
