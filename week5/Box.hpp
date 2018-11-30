/********************************************************************* 
** Author: Kevin Harvell
** Date: 2/1/2018
** Description: 
** Box.hpp is the class declaration for the Box class.
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

#ifndef BOX_H
#define BOX_H

// Box class declaration
class Box
{
	private:
		double height,
		       width,
		       length; 	
	public:
		Box();
		Box(double, double, double);
		void setHeight(double);
		void setWidth(double);
		void setLength(double);
		double calcVolume();
		double calcSurfaceArea();

};
#endif
