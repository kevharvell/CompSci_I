/********************************************************************* 
** Author: Kevin Harvell
** Date: 2/27/18 
** Description: transformArray is a void function that takes two
** parameters - a reference to a pointer to a dynamically allocated
** array of ints, and the size of that array. transformArray replaces
** the array with one that is twice as long, with the values from the
** original array followed by each of those values plus one.
*********************************************************************/

void transformArray(int *&arr, int size)
{	
	// Size of the new expanded array
	int newSize = size * 2;
	// Create new expanded array
	int *newArr = new int[newSize];
	// Input values into new expanded array
	for(int i = 0; i < newSize; i++)
	{
		// Copy original values to 1st half of array
		if(i < size)
			newArr[i] = arr[i];
		// Copy original values + 1 to 2nd half of array 
		else
			newArr[i] = newArr[i - size] + 1;
	}
	delete []arr;
	arr = newArr;
}

/*int main()
{
	int* myArray = new int[5];
	myArray[0] = 4;
	myArray[1] = 2;
	myArray[2] = 5;
	myArray[3] = 22;
	myArray[4] = 15;

	transformArray(myArray,5);

	for (int i = 0; i < 10; i++)
		std::cout << myArray[i] << std::endl;
	
	delete []myArray;
	
	return 0;
}*/
