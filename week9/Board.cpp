/********************************************************************* 
** Author: Kevin Harvell
** Date: 3/1/2018
** Description: The Board class represents a tic-tac-toe board using
** a 3x3 array of chars ('x', 'o', or space)
*********************************************************************/

#include <iostream>
#include "Board.hpp"

Board::Board()
{
	gameStatus = UNFINISHED;
	numMoves = 0;
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			boardArr[row][col] = ' ';					
		}
	}
}

/*********************************************************************
 *			Board::makeMove
 * makeMove takes two ints and a char('x' or 'o') as parameters, 
 * representing row and col of the move and which player's turn it is.
 * If the location is unoccupied, it records the move and returns
 * true. If occupied, it returns false.
 *********************************************************************/

bool Board::makeMove(int rowIn, int colIn, char playerTurnIn)
{
	// if the space is not empty, this returns false
	bool success = false;
	// if the space is empty, record move & return true
	if(boardArr[rowIn][colIn] == ' ' && gameState() == UNFINISHED)
	{
		boardArr[rowIn][colIn] = playerTurnIn;
		success = true;
		numMoves++;
	}
	return success;
}

/*********************************************************************
 *			Board::gameState
 * gameState returns one of four enum values: X_WON, O_WON, DRAW, or
 * UNFINISHED.
 ********************************************************************/
status Board::gameState()
{
	
	gameStatus = UNFINISHED;

	// check for winning combination in rows and columns of grid
	for(int i = 0; i < 3; i++)
	{
		if((boardArr[i][0] == boardArr[i][1] && 
		    boardArr[i][1] == boardArr[i][2]) ||
		   (boardArr[0][i] == boardArr[1][i] &&
		    boardArr[1][i] == boardArr[2][i]))
		{
			if(boardArr[i][i] == 'x')
			{
				gameStatus = X_WON;
			}
			else if(boardArr[i][i] == 'o')
			{
				gameStatus = O_WON;
			}
		}
	}
	// check for winning combination in diagonals
	if ((boardArr[0][0] == boardArr[1][1] && 
	     	  boardArr[1][1] == boardArr[2][2]) ||
	    	 (boardArr[0][2] == boardArr[1][1] &&
	     	  boardArr[1][1] == boardArr[2][0]))
	{
		if(boardArr[1][1] == 'x')
		{
			gameStatus = X_WON;
		}
		else if(boardArr[1][1] == 'o')
		{
			gameStatus = O_WON;
		}
	} 
	// check to see if draw if moves are greater than 9
	else if(numMoves > 8 && gameStatus == UNFINISHED)
	{
		gameStatus = DRAW;
	}

	return gameStatus;
}

// print board for debugging
void Board::print()
{
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			std::cout << boardArr[row][col]; 
			if(col < 2)
				std::cout << " | ";
		}
		if(row < 2)
			std::cout << std::endl << "----------" << std::endl;
	}
	std::cout << std::endl << std::endl;
}

/*int main()
{
	Board game;
	std::cout << "gameState()" << game.gameState() << std::endl;
	game.makeMove(0,0,'x');
	game.print();
	return 0;
}*/



