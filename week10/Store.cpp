/********************************************************************* 
** Author: Kevin Harvell
** Date: 3/12/18
** Description: A Store object represents a store, which has some
** number of products in its inventory and some number of customers
** as members.
*********************************************************************/

#include <iostream>
#include <algorithm>
#include "Store.hpp"
using std::vector;
using std::string;
using std::cout;
using std::endl;

/*********************************************************************
 * 			Store::addProduct
 * addProduct adds a product to the inventory
**********************************************************************/
void Store::addProduct(Product* productPtr)
{	
	if(productPtr != NULL)
		inventory.push_back(productPtr);
}

/*********************************************************************
 * 			Store::addMember
 * addMember adds a customer to the members
**********************************************************************/
void Store::addMember(Customer* customerPtr)
{
	if(customerPtr != NULL)
		members.push_back(customerPtr);
}

/*********************************************************************
 * 			Store::getProductFromID
 * getProductFromID returns pointer to product with matching ID. Returns 
 * NULL if no matching ID is found.
**********************************************************************/
Product* Store::getProductFromID(string idMatch)
{
	// loop through inventory vector searching for ID match
	for(int i = 0; i < inventory.size(); i++)
	{
		// if the product ID's match, immediately return pointer
		// to the product
		if(inventory.at(i)->getIdCode() == idMatch)
		{
			return inventory.at(i);
		}
	}
	// After looping through entire inventory vector, there is no match
	// Therefore, return NULL
	return NULL;
}

/*********************************************************************
 * 			Store::getMemberFromID
 * getMemberFromID returns pointer to customer with matching ID.
 * Returns NULL if no matching ID is found.
**********************************************************************/
Customer* Store::getMemberFromID(string cidMatch)
{
	// loop through members vector searching for ID match
	for(int	i = 0; i < members.size(); i++)
	{
		// if the member ID's match, immediately reutnr point
		// to the customer
		if(members.at(i)->getAccountID() == cidMatch)
		{
			return members.at(i);
		}
	}
	// After looping through entire members vector, there is no match
	// Therefore, return NULL
	return NULL;
}

/*********************************************************************
 * 			Store::productSearch
 * productSearch returns a sorted vector of ID codes for every product 
 * whose title or description contains the search string.
**********************************************************************/
vector<string> Store::productSearch(string term)
{
	// found indices used to denote any occurrences of search term
	// in title or description
	size_t foundTitle, foundDescription;
	// title & description variables make code more readable
	string title;
	string description;
	// vector to be returned at the end of function
	vector<string> sortedMatches;
	// Loop through inventory vector
	for(int i = 0; i < inventory.size(); i++)
	{
		// Set title & description variables for readability
		title = inventory.at(i)->getTitle();
		description = inventory.at(i)->getDescription();
		// Check uppercase search term first
		term[0] = toupper(term[0]);
		foundTitle = title.find(term);
		foundDescription = description.find(term);

		if(foundTitle != string::npos || 
		   foundDescription != string::npos)
		{
			sortedMatches.push_back(inventory.at(i)->getIdCode());
		}
		// Uppercase search term not found; try lowercase instead.
		else
		{
			term[0] = tolower(term[0]);
			foundTitle = title.find(term);
			foundDescription = description.find(term);
			if(foundTitle != string::npos || 
			   foundDescription != string::npos)
			{
				sortedMatches.push_back(inventory.at(i)->getIdCode());
			}
		}	
	}
	// Sort the search results
	std::sort(sortedMatches.begin(), sortedMatches.end());
	
	return sortedMatches;
}

/*********************************************************************
 * 			Store::addProductToMemberCart
 * If both product ID and member ID are found, and the product is still
 * available, addProductToCart adds the product to the Customer cart.
**********************************************************************/
string Store::addProductToMemberCart(string pID, string mID)
{	
	// Placeholder variables for readability
	Product* productFound = getProductFromID(pID);
	Customer* memberFound = getMemberFromID(mID);

	// Return product ID not found
	if(!productFound)
		return "product ID not found";
	// Return member ID not found
	else if(!memberFound)
		return "member ID not found";
	// If product and member are found and quantity available is
	// greater than 1, add the product to the cart.
	else if(productFound && memberFound && 
		productFound->getQuantityAvailable() >= 1)
	{	
		memberFound->addProductToCart(pID);
		return "product added to cart";
	}
	// If the quantity available is less than 1, return
	// product out of stock
	else if(productFound->getQuantityAvailable() < 1)
	{
		return "product out of stock";
	}
}

/*********************************************************************
 * 			Store::checkOutMember
 * checkOutMember returns the charge for the member's cart. This will
 * be the total cost of all the items in the cart, not including any
 * items that are not in the inventory or are out of stock, plus the
 * shipping cost.
**********************************************************************/
double Store::checkOutMember(string mID)
{
	// Placeholder customer and checkout cart variables for readability
	Customer* memberFound = getMemberFromID(mID);
	vector<string> checkoutCart = memberFound->getCart();
	// Product pointer variable to be changed when looping through cart
	Product* tempProduct = NULL;
	// accumulator
	double total = 0.0;
	
	// If member not found return -1
	if(!memberFound)
	{
		return -1;
	}
	// Member is found; proceed
	else
	{
		// Loop through cart to get prices
		for(int i = 0; i < checkoutCart.size(); i++)
		{
			// set tempProduct
			tempProduct = getProductFromID(checkoutCart.at(i));
			if(tempProduct != NULL)
			{
				// check to make sure quantity available is >= 1
				if(tempProduct->getQuantityAvailable() >= 1)
				{
					// add price to toal and decrease quantity by 1
					total += tempProduct->getPrice();
					tempProduct->decreaseQuantity();
				}
			}
		}
		// If customer is not a member, there is a 7% shipping charge
		if(!memberFound->isPremiumMember())
		{
			total += (total * .07);
		}	
	// total is complete, empty the customer's cart	
	memberFound->emptyCart();
	}

	return total;
}


int main()
{
	// testing product list
	Store Kevs;
	Product toothpaste("123", "Kev's Toothpaste", "Shiny white teeth for life Tooth.",
			   14.99, 2);
	Product toothbrush("124", "Kev's Toothbrush", "Chh chh chh chh chhh tooth", 2.99, 2);
	cout << "Product toothpaste created" << endl;
	cout << "toothpaste address: " << &toothpaste << endl;
	Kevs.addProduct(&toothpaste);
	cout << "toothpaste added to store inventory" << endl;
	cout << "If there is a match for getProductFromID, we should see the toothepaste address again: " << endl;
	cout << Kevs.getProductFromID("123") << endl;
	cout << "We should see null on the next getProductFromID" << endl;
	cout << Kevs.getProductFromID("2123") << endl;
	cout << "Adding toothbrush to inventory" << endl;
	Kevs.addProduct(&toothbrush);
	cout << "If there is a match for '124', we should see same address: " << endl;
	cout << Kevs.getProductFromID("124") << endl;

	// testing member list
	cout << "Creating a new customer" << endl;
	Customer person("Sarah", "1111", false);
	cout << "new customer addresss: " << &person << endl;
	Kevs.addMember(&person);
	cout << "person added to store members" << endl;
	cout << "If there is a match for getMemberFromID, we should see the person address again: " << endl;
	cout << Kevs.getMemberFromID("1111") << endl;
	cout << "We should see null on the next getMemberFromID" << endl;
	cout << Kevs.getMemberFromID("1234") << endl;

	// testing productSearch()
	Product floss("1", "Kev's Floss tooth", "Nothing works like Kev's Floss", 7, 10);
	Kevs.addProduct(&floss);
	for(int i = 0; i < Kevs.productSearch("tooth").size(); i++)
	{
		cout << Kevs.productSearch("toot").at(i) << endl;
	}
	cout << Kevs.addProductToMemberCart("123", "1111") << endl;
	cout << Kevs.addProductToMemberCart("124", "1111") << endl;
	cout << Kevs.addProductToMemberCart("1", "1111") << endl;
	cout << Kevs.addProductToMemberCart("123", "1111") << endl;

	// testing checkOut
	cout << Kevs.checkOutMember("1111") << endl;

	Product myProduct("aaa", "pet rock", "low maintenance pet, fully house-trained", 50, 2);
	Customer myCustomer("Jenny", "8675309", true);
	myCustomer.addProductToCart("12345");
	myCustomer.getCart();

	Store myStore;
	myStore.addProduct(&myProduct);
	myStore.addMember(&myCustomer);
	myStore.productSearch("Pet");
	cout << myStore.addProductToMemberCart("aaa", "8675309") << endl;
	cout << myStore.checkOutMember(myCustomer.getAccountID()) << endl;


	return 0;
}
