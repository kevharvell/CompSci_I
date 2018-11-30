/********************************************************************* 
** Author: Kevin Harvell
** Date: 1/26/2018
** Description: fallDistance takes the falling time as an argument 
** and returns the distance in meters that the object has fallen 
** in that time. 
*********************************************************************/

#include <iostream>
using namespace std;


double fallDistance(double time);

/*int main()
{
	double time; 

	cout << "Please enter the time in seconds the object has been falling: ";
	cin >> time;
	cout << fallDistance(time) << endl;

	return 0;
}*/

/*************************************************************************
 * 			fallDistance					 *
 *  fallDistance takes the falling time as an argument and returns the 	 *
 *  distance in meters that the target has fallen in that time.		 *
*************************************************************************/

double fallDistance(double time)
{
	const double GRAVITY = 9.8;	// Gravity constant
	double distance;		// Distance in meters that the object has fallen in time

	distance = (1.0 / 2.0) * GRAVITY * time * time;

	return distance;
}
