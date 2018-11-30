/********************************************************************* 
** Author: Kevin Harvell
** Date: 2/17/18
** Description: stdDev is a function that takes two parameters: an 
** array of Person objects and the size of the array. Then, it 
** returns the standard deviation of all ages.
*********************************************************************/
#include <cmath>
#include "Person.hpp"

double stdDev(Person[], int);

/*int main()
{
	Person personArr[] = { Person("Kev", 30),
			       Person("Sarita", 32),
			       Person("Connor", 16),
			       Person("Katie", 34)};
	int length = 4;
	std::cout << stdDev(personArr, length) << std::endl;
	return 0;
}*/

/*********************************************************************
*			stdDev					     *
* stdDev is a function that takes two parameters: an                 *
* array of Person objects and the size of the array. Then, it 	     *
* returns the standard deviation of all ages.			     *
*********************************************************************/
double stdDev(Person personArr[], int arrSize)
{
	// Variable to hold standard deviation of Person ages
	// which is returned at end of function
	double stdDevOut = 0;
	// Find the mean for the array of Person ages
	double mean = 0;
	for(int i = 0; i < arrSize; i++)
	{
		mean += personArr[i].getAge();
	}
	mean /= arrSize;

	// Find the standard deviation for the array of Person ages
	for(int i = 0; i < arrSize; i++)
	{
		stdDevOut += pow(personArr[i].getAge() - mean, 2.0); 
	}
	stdDevOut = sqrt(stdDevOut / arrSize);

	return stdDevOut;
}
