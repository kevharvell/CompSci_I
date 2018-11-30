/********************************************************************* 
** Author: Kevin Harvell
** Date: 3/11/2018 
** Description: A Product object represents a product with an ID code,
** title, description, price and quantity available.
*********************************************************************/

#include <iostream>
#include "Product.hpp"
using std::string;
using std::cout;
using std::endl;

// Constructor takes as parameters five values with which to initialize
// the Product's iddCode, title, description, price, and quantity available
Product::Product(string idIn, string titleIn, string descriptionIn, 
		 double priceIn, int quantityIn)
{
	idCode = idIn;
	title = titleIn;
	description = descriptionIn;
	price = priceIn;
	quantityAvailable = quantityIn;
}

string Product::getIdCode()
{
	return idCode;
}

string Product::getTitle()
{
	return title;
}

string Product::getDescription()
{
	return description;
}

double Product::getPrice()
{
	return price;
}

int Product::getQuantityAvailable()
{
	return quantityAvailable;
}

/*********************************************************************
 * 			Product::decreaseQuantity()
 * decreaseQuantity decreases the quantity available by one
*********************************************************************/
void Product::decreaseQuantity()
{
	quantityAvailable--;
}


/*testing
int main()
{
	Product sample("1234", "Coffee", "The world's worst coffee", 
			12.99, 10);
	cout << sample.getIdCode() << endl;
	cout << sample.getTitle() << endl;
	cout << sample.getDescription() << endl;
	cout << sample.getPrice() << endl;
	cout << sample.getQuantityAvailable() << endl;
	cout << "Subtracting 1 from QA:" << endl;
	sample.decreaseQuantity();
	cout << sample.getQuantityAvailable() << endl;
	return 0;
}*/
