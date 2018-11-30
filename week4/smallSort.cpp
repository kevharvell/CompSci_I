/********************************************************************* 
** Author: Kevin Harvell
** Date: 1/27/2018
** Description: smallSort takes three int parameters by reference and
** sorts their values into ascending order, so that the first parameter
** now has the lowest value, the second parameter the middle value,
** and the third parameter has the highest value.
*********************************************************************/

#include <iostream>
using namespace std;

// Function prototype
void smallSort(int &a, int &b, int &c);

/*int main()
{
	int a, b, c;
	cout << "Enter 3 integers. ";
	cin >> a >> b >> c;
	smallSort(a, b, c);
	cout << a << ", " << b << ", " << c << endl;
	return 0;
}*/

/***********************************************************************
** 			smallSort				      **
** 								      **
** smallSort takes three int parameters by reference and	      **
** sorts their values into ascending order, so that the first parameter*
** now has the lowest value, the second parameter the middle value,   **
** and the third parameter has the highest value.		      **
***********************************************************************/

void smallSort(int &a, int &b, int &c)
{
	int low,		// temporary variables used for sorting
	    mid,
	    high;
	
	// Check to see if a is the lowest
	if(a <= b && a <= c)
	{
		low = a;
		// If a is the lowest, then how do b and c compare?
		if(b <= c)
		{
			mid = b;
			high = c;
		}
		else
		{
			mid = c;
			high = b;
		}
	}
	// Check to see if a is the highest
	else if(a >= b && a >= c)
	{
		high = a;
		// If a is the highest, then how do b and c compare?
		if(b <= c)
		{
			low = b;
			mid = c;
		}
		else
		{
			low = c;
			mid = b;
		}
	}
	// If not lowest or highest, a must be the middle number.
	else 
	{
		mid = a;
		// If a is the middle number, then how do b and c compare?
		if(b <= c)
		{
			low = b;
			high = c;
		}
		else
		{
			low = c;
			high = b;
		}
	}

	// Assign a, b, and c the sorted integers low, mid, and high
	a = low;
	b = mid;
	c = high;
}
