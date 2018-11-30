/********************************************************************* 
** Author: Kevin Harvell
** Date: 2/26/2018
** Description: smallSort2 is a function that takes as parameters the
** addresses of three int variables and sorts the ints at those 
** addresses into ascending order.
*********************************************************************/

void smallSort2(int *low, int *mid, int *high)
{
	int temp;
	
	// If the first value is greater than the middle,
	// swap the 2 values
	if(*low > *mid)
	{
		temp = *low;
		*low = *mid;
		*mid = temp;
	}
	
	// If the second value is greater than the third value,
	// swap the 2 values
	if(*mid > *high)
	{
		temp = *mid;
		*mid = *high;
		*high = temp;
	}

	// If the first value is greater than the middle,
	// swap the 2 values
	if(*low > *mid)
	{
		temp = *low;
		*low = *mid;
		*mid = temp;
	}
}

