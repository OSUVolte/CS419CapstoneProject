/*
	Bryan Serif
	CS 362
	04/24/2016

	This file tests the function getCost()
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
	int result;
	int i;
	
	printf("\n-----Testing Get Cost-----\n");
	for( i = 0; i < 27; i++)
	{
		result = getCost(i);
		
		switch (i)
		{
			case curse:
				printf("\nTesting Curse:\n");
				if (result == 0)
					printf("Expected Cost: 0. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 0. Actual Cost %d. Failure!\n", result);
				break;
			case estate:
				printf("\nTesting Estate:\n");
				if (result == 2)
					printf("Expected Cost: 2. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 2. Actual Cost %d. Failure!\n", result);
				break;
			case duchy:
				printf("\nTesting Duchy:\n");
				if (result == 5)
					printf("Expected Cost: 5. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 5. Actual Cost %d. Failure!\n", result);
				break;
			case province:
				printf("\nTesting Province:\n");
				if (result == 8)
					printf("Expected Cost: 8. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 8. Actual Cost %d. Failure!\n", result);
				break;
			case copper:
				printf("\nTesting Copper:\n");
				if (result == 0)
					printf("Expected Cost: 0. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 0. Actual Cost %d. Failure!\n", result);
				break;
			case silver:
				printf("\nTesting Silver:\n");
				if (result == 3)
					printf("Expected Cost: 3. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 3. Actual Cost %d. Failure!\n", result);
				break;
			case gold:
				printf("\nTesting Gold:\n");
				if (result == 6)
					printf("Expected Cost: 6. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 6. Actual Cost %d. Failure!\n", result);
				break;
			case adventurer:
				printf("\nTesting Adventurer:\n");
				if (result == 6)
					printf("Expected Cost: 6. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 6. Actual Cost %d. Failure!\n", result);
				break;
			case council_room:
				printf("\nTesting Concil Room:\n");
				if (result == 5)
					printf("Expected Cost: 5. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 5. Actual Cost %d. Failure!\n", result);
				break;
			case feast:
				printf("\nTesting Feast:\n");
				if (result == 4)
					printf("Expected Cost: 4. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 4. Actual Cost %d. Failure!\n", result);
				break;
			case gardens:
				printf("\nTesting Gardens:\n");
				if (result == 4)
					printf("Expected Cost: 4. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 4. Actual Cost %d. Failure!\n", result);
				break;
			case mine:
				printf("\nTesting Mine:\n");
				if (result == 5)
					printf("Expected Cost: 5. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 5. Actual Cost %d. Failure!\n", result);
				break;
			case remodel:
				printf("\nTesting Remodel:\n");
				if (result == 4)
					printf("Expected Cost: 4. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 4. Actual Cost %d. Failure!\n", result);
				break;
			case smithy:
				printf("\nTesting Smithy:\n");
				if (result == 4)
					printf("Expected Cost: 4. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 4. Actual Cost %d. Failure!\n", result);
				break;
			case village:
				printf("\nTesting Village:\n");
				if (result == 3)
					printf("Expected Cost: 3. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 3. Actual Cost %d. Failure!\n", result);
				break;
			case baron:
				printf("\nTesting Baron:\n");
				if (result == 4)
					printf("Expected Cost: 4. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 4. Actual Cost %d. Failure!\n", result);
				break;
			case great_hall:
				printf("\nTesting Great Hall:\n");
				if (result == 3)
					printf("Expected Cost: 3. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 3. Actual Cost %d. Failure!\n", result);
				break;
			case minion:
				printf("\nTesting Minion:\n");
				if (result == 5)
					printf("Expected Cost: 5. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 5. Actual Cost %d. Failure!\n", result);
				break;
			case steward:
				printf("\nTesting Steward:\n");
				if (result == 3)
					printf("Expected Cost: 3. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 3. Actual Cost %d. Failure!\n", result);
				break;
			case tribute:
				printf("\nTesting Tribute:\n");
				if (result == 5)
					printf("Expected Cost: 5. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 5. Actual Cost %d. Failure!\n", result);
				break;
			case ambassador:
				printf("\nTesting Ambassador:\n");
				if (result == 3)
					printf("Expected Cost: 3. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 3. Actual Cost %d. Failure!\n", result);
				break;
			case cutpurse:
				printf("\nTesting Cutpurse:\n");
				if (result == 4)
					printf("Expected Cost: 4. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 4. Actual Cost %d. Failure!\n", result);
				break;
			case embargo:
				printf("\nTesting Embargo:\n");
				if (result == 2)
					printf("Expected Cost: 2. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 2. Actual Cost %d. Failure!\n", result);
				break;
			case outpost:
				printf("\nTesting Outpost:\n");
				if (result == 5)
					printf("Expected Cost: 5. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 5. Actual Cost %d. Failure!\n", result);
				break;
			case salvager:
				printf("\nTesting Salvager:\n");
				if (result == 4)
					printf("Expected Cost: 4. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 4. Actual Cost %d. Failure!\n", result);
				break;
			case sea_hag:
				printf("\nTesting Sea Hag:\n");
				if (result == 4)
					printf("Expected Cost: 4. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 4. Actual Cost %d. Failure!\n", result);
				break;
			case treasure_map:
				printf("\nTesting Tresure Map:\n");
				if (result == 4)
					printf("Expected Cost: 4. Actual Cost %d. Success!\n", result);
				else
					printf("Expected Cost: 4. Actual Cost %d. Failure!\n", result);
				break;
		}
	}
	printf("\n-----Testing of Get Cost Complete-----\n");
	return 0;
}