/********************************************************************* 
** Author: Kevin Harvell
** Date: 1/27/2018
** Description: hailstone takes the starting integer as a parameter 
** and returns how many steps it takes to reach 1. If the starting
** integer is even, then it divides it by two to get the next integer
** in the sequence. If the integer is odd, then it multiplies it by 3
** and adds 1 to get the next integer in the sequence. Then, the value
** just generated is used to find out the next value, according to the
** same rules.
*********************************************************************/

#include <iostream>
using namespace std;

int hailstone(int term1);

int main()
{
	int term1;
	cout << "Enter any integer to start a hailstone sequence: ";
	cin >> term1;
	cout << hailstone(term1) << endl;

	return 0;
}

/********************************************************************
 * 			    hailstone
** Description: hailstone takes the starting integer as a parameter 
** and returns how many steps it takes to reach 1. If the starting
** integer is even, then it divides it by two to get the next integer
** in the sequence. If the integer is odd, then it multiplies it by 3
** and adds 1 to get the next integer in the sequence. Then, the value
** just generated is used to find out the next value, according to the
** same rules.
*********************************************************************/

int hailstone(int term1)
{
	int counter = 0;		// counter variable counts iterations
				// to reach 1


	while(term1 != 1)
	{
		// If number is even, divide by 2
		if(term1 % 2 == 0)
		{
			term1 /= 2;
		}
		// If number is not even, it must be odd; times by 3 and
		// add 1
		else
		{
			term1 = term1 * 3 + 1;
		}
		
		counter++;	// increment counter for each iteration.
	}

	return counter;
}
