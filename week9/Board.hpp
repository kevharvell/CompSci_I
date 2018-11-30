/********************************************************************* 
** Author: Kevin Harvell
** Date: 3/1/2018
** Description: The Board class represents a tic-tac-toe board using
** a 3x3 array of chars ('x', 'o', or space)
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

enum status {X_WON, O_WON, DRAW, UNFINISHED};

class Board
{
	private:
		char boardArr[3][3];
		status gameStatus;
		int numMoves;
	public:
		Board();
		bool makeMove(int, int, char);
		status gameState();
		void print();	
};

#endif 
