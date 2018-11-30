/********************************************************************* 
** Author: Kevin Harvell
** Date: 2/3/2018 
** Description: 
** Taxicab class has three int data members to store
   its current x- and y-coordinates and the total distance it has
   driven so far(actual distance).
** Taxicab has a constructor that takes two parameters and uses them 
   to initialize the coordinates, and also initializes the distance
   traveld to zero.
** Constructors will directly assign values to the data members instead
   of calling set methods.
** Taxicab has a get method for each data member.
** Taxicab has a method moveX that takes an int parameter and tells
   how far the Taxicab should shift left of right. moveY takes an int
   parameter and tells how far the Taxicab should shift up or down.
*********************************************************************/

#include "Taxicab.hpp"
#include <cmath>
using std::abs;

// Default Taxicab constructor sets xPos, yPos, and totalDistance to zero
Taxicab::Taxicab()
{
	xPos = 0;
	yPos = 0;
	totalDistance = 0;
}

// Constructor takes in 2 ints and passes them to xPos & yPos.
// Also initializes totalDistance to 0
Taxicab::Taxicab(int xPosIn, int yPosIn)
{
	xPos = xPosIn;
	yPos = yPosIn;
	totalDistance = 0;
}

int Taxicab::getXCoord()
{
	return xPos;
}

int Taxicab::getYCoord()
{
	return yPos;
}

int Taxicab::getDistanceTraveled()
{
	return totalDistance;
}

void Taxicab::moveX(int deltaX)
{
	xPos += deltaX;
	totalDistance += abs(deltaX);
}

void Taxicab::moveY(int deltaY)
{
	yPos += deltaY;
	totalDistance += abs(deltaY);
}
