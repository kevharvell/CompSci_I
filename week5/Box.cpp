/*********************************************************************
** Author: Kevin Harvell
** Date: 2/1/2018
** Description:
** Box.cpp is the function implementation for the Box class.
** The Box class has 3 double fields called height, width and length.
** The Box class contains set methods for each field.
** The Box constructor takes 3 doubles and passes them to the set
   methods to initialize the fields of box.
** The default constructor uses set methods to initialize each field
   to 1.
** The Box class has a method that calculates and returns the volume
   of the Box and a method that caluclates and returns the surface
   area of the Box.
*********************************************************************/

#include "Box.hpp"

// Default Box constructor sets height, width & length to one.
Box::Box()
{
	setHeight(1);
	setWidth(1);
	setLength(1);
}

// Constructor takes 3 doubles and passes them 
// to set height, width & length
Box::Box(double heightIn, double widthIn, double lengthIn)
{
	setHeight(heightIn);
	setWidth(widthIn);
	setLength(lengthIn);
}

void Box::setHeight(double h)
{
	height = h;	
}

void Box::setWidth(double w)
{
	width = w;
}

void Box::setLength(double len)
{
	length = len;
}

/***********************************************************************
 * 			Box::calcVolume
 * calcVolume calculates the volume of the Box by multiplying height,
 * width, and length.
 * ********************************************************************/
double Box::calcVolume()
{
	return height * width * length;
}

/***********************************************************************
 * 			Box::calcSurfaceArea
 * calcSurfaceArea calculates the surface area of the Box by the following
 * formula: SA = 2LW + 2LH + 2WH where H, W, and L stand for height, width
 * and length respectively.
 * ********************************************************************/
double Box::calcSurfaceArea()
{
	return (2 * (length * width) +
	        2 * (length * height) +
	        2 * (width * height)); 
}
