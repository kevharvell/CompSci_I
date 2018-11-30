/********************************************************************* 
** Author: Kevin Harvell
** Date: 2/17/18
** Description: Person is a class that has 2 data members: a string
** variable called name and a double variable called age. It has a 
** constructor that takes 2 values and uses them to initialize the
** data members. It has get methods for both data members.
*********************************************************************/
#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>

class Person {
	private:
		std::string name;
		double age;
	public:
		Person(std::string, double);
		std::string getName();
		double getAge();
};

#endif
