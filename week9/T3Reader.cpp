/********************************************************************* 
** Author: Kevin Harvell
** Date: 3/1/2018
** Description: T3Reader class uses the Board class to re-run a game
** of TicTacToe from moves that it reads from a text file.
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "T3Reader.hpp"


// constructor with the player turn as a parameter
T3Reader::T3Reader(char playerTurnIn)
{
	playerTurn = playerTurnIn;
}

/*********************************************************************
 *			T3Reader::readGameFile
 * readGameFile takes a string parameter that gives the name of the
 * game file. It keeps looping, reading a move from the file, and 
 * sending it to the board with makeMove. 
 ********************************************************************/

bool T3Reader::readGameFile(std::string gameFile)
{
	std::ifstream inputFile;
	inputFile.open(gameFile.c_str());
	// if input file exists
	if(inputFile)
	{
		// temporary variables for row & column from .txt file
		int row, col;
		while(inputFile >> row && inputFile >> col)
		{
			// Check to see if the game is over but there are still moves left
			if(ticGame.gameState() != UNFINISHED)
			{
				inputFile.close();
				return false;
			}
			// Check to see if making a move in an empty spot
			if(ticGame.makeMove(row, col, playerTurn))
			{
				// change player turn
				if(playerTurn == 'x')
					playerTurn = 'o';
				else
					playerTurn = 'x';
			}
			// if spot is not empty, return false
			else
			{
				inputFile.close();
				return false;
			}
		}
	}
	// file was not found and/or could not open
	else
	{
		std::cout << gameFile << " not opened." << std::endl;
	}

	inputFile.close();
	return true;
}


//testing
/*int main()
{
	T3Reader game('x');
	std::cout << "readGameFile output:" << game.readGameFile("game.txt") << std::endl;
	game.ticGame.print();
	return 0;
}*/
