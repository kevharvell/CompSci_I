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

#ifndef TAXICAB_HPP
#define TAXICAB_HPP

class Taxicab
{
	private:
		int xPos,
		    yPos,
 		    totalDistance;
	public:
		Taxicab();
		Taxicab(int, int);
		int getXCoord();
		int getYCoord();
		int getDistanceTraveled();
		void moveX(int);
		void moveY(int);
};


#endif

