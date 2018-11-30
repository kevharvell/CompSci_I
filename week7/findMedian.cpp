/********************************************************************* 
** Author: Kevin Harvell
** Date: 2/17/2018
** Description: findMedian is a function that takes two parameters -
** an array of int and the size of the array. It returns the median
** of the array which requires sorting the array. 
*********************************************************************/

#include <algorithm>

double findMedian(int[], int);

/*int main()
{
	int length = 6;
	int arr1[] = {23, 21, 1, 4, 199, 5};
	for(int i = 0; i < length; i++)
	{
		std::cout << arr1[i] << "    ";
	}
	std::cout << std::endl << findMedian(arr1, length) << std::endl;

	
	int length2 = 7;
	int arr2[] = {17, 23, 21, 1, 4, 199, 5};
	for(int i = 0; i < length2; i++)
	{
		std::cout << arr2[i] << "    ";
	}
	std::cout << std::endl << findMedian(arr2, length2) << std::endl;
}*/

/*********************************************************************
* 			findMedian				     *
* Description: findMedian is a function that takes two parameters -  *
* an array of int and the size of the array. It returns the median   *
* of the array which requires sorting the array.                     *
*********************************************************************/

double findMedian(int arr[], int size)
{
	// Variable to store where the half Index is
	int halfIndex = size / 2;	
	// Median variable that will be returned
	double median;

	// Sort the array from least to greatest
	std::sort(arr, arr + size);	
	
	// Check to see if array length is even
	if(size % 2 == 0)
	{
		median = (arr[halfIndex - 1] + arr[halfIndex]) / 2.0;
	}
	// If not even, then array length is odd
	else
	{
		median = arr[halfIndex];
	}

	return median;
}
