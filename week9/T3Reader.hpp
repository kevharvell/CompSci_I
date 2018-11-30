/********************************************************************* 
** Author: Kevin Harvell
** Date: 3/1/2018
** Description: T3Reader class uses the Board class to re-run a game
** of TicTacToe from moves that it reads from a text file.
*********************************************************************/

#ifndef T3READER_HPP
#define T3READER_HPP
#include "Board.hpp"

class T3Reader
{
	private:
		Board ticGame;
		char playerTurn;

	public:
		T3Reader(char);
		bool readGameFile(std::string);
};

#endif
