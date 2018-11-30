/********************************************************************* 
** Author: Kevin Harvell
** Date: 3/11/18
** Description: A Customer object represents a customer with a name
** and account ID. Customers must be members of the Store to make
** a purchase. Premium members get free shipping.
*********************************************************************/

#include <iostream>
#include "Customer.hpp"
using std::string;
using std::vector;
using std::cout;
using std::endl;

// Constructor takes as parameters three values with which to initialize
// the Customer's name, account ID, and whether the customer
// is a premium member
Customer::Customer(string nameIn, string accountIDIn, bool premiumMemberIn)
{
	name = nameIn;
	accountID = accountIDIn;
	premiumMember = premiumMemberIn;
}

string Customer::getAccountID()
{
	return accountID;
}

vector<string> Customer::getCart()
{
	return cart;
}

bool Customer::isPremiumMember()
{
	return premiumMember;
}

/*********************************************************************
 * 			Customer::addProductToCart
 * addProductToCart adds the product ID code to the Customer's cart
*********************************************************************/
void Customer::addProductToCart(string id)
{
	cart.push_back(id);
}

/*********************************************************************
 * 			Customer::emptyCart
 * emptyCart empties the Customer's cart
*********************************************************************/
void Customer::emptyCart()
{
	cart.clear();
}

/*testing
int main()
{
	Customer person("Kevin", "1234", true);
	cout << person.getAccountID() << endl;
	cout << person.getCart().empty() << endl;
	cout << "Adding Bacon to cart:" << endl;
	person.addProductToCart("Bacon");
	cout << person.getCart().at(0) << endl;
	cout << person.isPremiumMember() << endl;
	cout << "Emptying cart:" << endl;
	person.emptyCart();
	cout << person.getCart().empty() << endl;

	return 0;
}*/
