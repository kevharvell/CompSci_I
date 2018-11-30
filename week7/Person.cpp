/********************************************************************* 
** Author: Kevin Harvell
** Date: 2/17/18
** Description: Person is a class that has 2 data members: a string
** variable called name and a double variable called age. It has a 
** constructor that takes 2 values and uses them to initialize the
** data members. It has get methods for both data members.
*********************************************************************/

#include "Person.hpp"
#include <string>
using std::string;

// Constructor with parameters name and age
Person::Person(string nameIn, double ageIn)
{
	name = nameIn;
	age = ageIn;
}

string Person::getName()
{
	return name;
}

double Person::getAge()
{
	return age;
}

