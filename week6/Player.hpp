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
   the function has more points than the Player that was passed as s
   parameter.
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

class Player
{
	private:
		std::string playerName;
		int points,
		    rebounds,
		    assists;
	public:
		Player();
		Player(std::string, int, int, int);
		std::string getName();
		void setPoints(int);
		int getPoints();
		void setRebounds(int);
		int getRebounds();
		void setAssists(int);
		int getAssists();
		bool hasMorePointsThan(Player);
};

#endif
