/********************************************************************* 
** Author: Kevin Harvell
** Date: 1/20/2018
** Description: Asks user to input how many numbers they wish to enter in order to find the minimum and maximum of the numbers.
*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int num,
	    firstNum,
	    nextNum,
	    count,
	    min,
	    max;

	// prompt user how many integers they would like to enter
	cout << "How many integers would you like to enter?" << endl;

	// initialize num to the user-entered value
	cin >> num;

	// prompt user to enter firstNum integer
	cout << "Please enter " << num << " integers." << endl;
	cin >> firstNum;
	
	// assign user-entered firstNum to min and max
	min = max = firstNum;

	// initialize count to 1
	count = 1;

	// while count <= num
	while(count < num) 
	{ 	// user inputs number assigned to nextNum
		cin >> nextNum;

		// if nextNum > max
		if(nextNum > max)
			// set max to nextNum
			max = nextNum;
		// else	if nextNum < min
		else if(nextNum < min)
			// set min to nextNum
			min = nextNum;
		// increment count by 1
		count++;
	}
	
	// output min and max
	cout << "min: " << min << endl;
	cout << "max: " << max << endl;

	return 0;
}
