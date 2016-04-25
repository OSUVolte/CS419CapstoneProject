/******************************************************************************
 * Filename:			unittest1.c
 * Author:			David Hite
 * Date Created:		4/20/2016
 * Last Date Modified:		4/23/2016
 *
 * Description:
 * Tests that the kingdomCards() function in dominion.c returns an array with
 * the same values passed into it.
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

int RunTest(int* testArray, int failCount);

int main()
{
	int failCount = 0;
	int testArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	printf("Normal test case, valid values:\n");
	failCount = RunTest(testArray, failCount);
	
	printf("\nFaulty test case, invalid values:\n");
	int testArray2[10] = { 1, 1, 3, 4, 5, 6, 7, 8, 9, 10 };
	failCount = RunTest(testArray2, failCount);
	
	printf("\nFaulty test case, invalid values:\n");
	int testArray3[10] = { curse - 1, 1, 3, 4, 5, 6, 7, 8, 9, treasure_map + 1 };
	failCount = RunTest(testArray3, failCount);
	
	printf("\n%d tests failed\n", failCount);
	printf("\nTesting complete!\n");
	
	return 0;
}

int RunTest(int* testArray, int failCount)
{
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
	int passed = 1;
	// check that values have not changed
	for (i = 0; i < 10; i++)
	{
		if (testArray[i] != returnArray[i])
		{
			passed = 0;
		}
	}
	
	if (passed == 0)
		failCount = failCount + 1;
	
	// check if cards are valid
	int validCards = 1;
	int j;
	for (i = 0; i < 10; i++)
	{
		if (returnArray[i] < curse || returnArray[i] > treasure_map)
		{
			validCards = 0;
		}
		for (j = 0; j < 10; j++)
		{
			if (j != i && returnArray[j] == returnArray[i])
			{
			  validCards = 0;
			}
		}
	}
	
	if (validCards == 0)
	{
		printf("Error: kingdomCards() did not catch invalid values\n");
		failCount = failCount + 1;
	}
	
	free(returnArray);
	
	return failCount;
}