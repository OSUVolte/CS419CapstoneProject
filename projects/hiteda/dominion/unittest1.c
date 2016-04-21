/******************************************************************************
 * Filename:			unittest1.c
 * Author:			David Hite
 * Date Created:		4/20/2016
 * Last Date Modified:		4/20/2016
 *
 * Description:
 * Tests the kingdomCards() function in dominion.c.
 *****************************************************************************/
#include <assert.h>
#include "dominion.h"

int main()
{
	int testArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	int* returnArray = kingdomCards(testArray[0],
									testArray[1],
									testArray[2],
									testArray[3],
									testArray[4],
									testArray[5],
									testArray[6],
									testArray[7],
									testArray[8],
									testArray[9]);
	int i;							
	for (i = 0; i < 10; i++)
	{
		assert(testArray[i] == returnArray[i]);
	}
	return 0;
}