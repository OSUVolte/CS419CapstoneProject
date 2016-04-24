/***********************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  unittest1.c
** Date:  4/23/16
** Due Date: 4/24/16
**
** Description: unittest1 will test the initializeGame function which 
** takes in a number of players, an array of kingdomCards[10], as well
** as a randomSeed and pointer to a gamestate.  The unittest must test
** these following properties (pulled from dominion.c):
**		0.  Invalid player number will produce an error
**		1.  Valid number of players are added to gameState
**		2.  Verify that supply is initialized appropriately
**			a. curse cards
**			b. estate, duchy, and province
**			c. copper, silver, gold
**		3.  Verify that the first player's turn has been initialized
**			correctly.
**			a. whoseTurn
**			b. numActions
**			c. numBuys
**			d. playedCardCount
**		4.  Verify that only the first player has drawn cards (5) and that 
**			all other players have not (0).
**		5.  Verify that initializeGame will throw error when kingdomCards
**			array has multiple of the same card.
**
** Makefile: gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{
	//Declare Variables Used to test initializeGame()
	struct gameState state;
	int kCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int pNum;
	int rSeed = 100;
	int retVal;
	int i = 0;
	
		printf("************************************\n");
		printf("* Running Unit Test 1...           *\n");
		printf("************************************\n");
	
		printf("*****TEST: initializeGame() - BEGIN*****\n\n");
			
			//Subtest 0 - Verify that initializeGame will throw error if too many/too little players
			printf("SubTest 0:\n");
				
				retVal = initializeGame(1, kCards, rSeed, &state);
				
					if(retVal == -1)
					{
						printf("ST0 - Caught not enough players error: PASS\n");
					}
					else
					{
						printf("ST0 - Caught not enough players error: FAIL\n");
					}
					
				retVal = initializeGame(5, kCards, rSeed, &state);
				
					if(retVal == -1)
					{
						printf("ST0 - Caught too many players error: PASS\n");
					}
					else
					{
						printf("ST0 - Caught not enough players error: FAIL\n");
					}
			
			printf("\n");
		
			//for every player setup [2..4] run Subtests 1 through 4 from above
			for (pNum = 2; pNum <= MAX_PLAYERS; pNum++)
			{
				printf ("Running initializeGame() for %d Players: \n", pNum);
				
					retVal = initializeGame(pNum, kCards, rSeed, &state);
					
					
						//Check for error in return value, should return 1 for each test [1-4]
						if (retVal == 0)
						{
							printf("Function returned with 0: PASS\n");
						}
						else
						{
							printf("Function returned with -1: FAIL\n");
						}
					
						//Subtest 1 - Verify numPlayers is initialized correctly
						printf("SubTest 1:\n");
						
						if (state.numPlayers == pNum)
						{
							printf("ST1 - Number of Players: PASS\n");
						}
						else
						{
							printf("ST1 - Number of Player: FAIL\n");
						}
						
						
						
						//Subtest 2 - Verify that supply is initialized appropriately
						printf("SubTest 2:\n");
						
							//check curse cards
							if (state.supplyCount[curse] == 10 * (pNum - 1))
							{
								printf("ST2 - # Curse Cards: PASS\n");
							}
							else
							{
								printf("ST2 - # Estate Cards: FAIL\n");
							}
							
							//check estate, duchy, and province cards
							if (pNum == 2)
							{
								//check estate cards for 2 players
								if(state.supplyCount[estate] == 8)
								{
									printf("ST2 - # Estate Cards: PASS\n");
								}
								else
								{
									printf("ST2 - # Estate Cards: FAIL\n");
								}
							
								//check duchy cards for 2 players
								if(state.supplyCount[duchy] == 8)
								{
									printf("ST2 - # Duchy Cards: PASS\n");
								}
								else
								{
									printf("ST2 - # Duchy Cards: FAIL\n");
								}
							
								//check province cards for 2 players
								if(state.supplyCount[province] == 8)
								{
									printf("ST2 - # Province Cards: PASS\n");
								}
								else
								{
									printf("ST2 - # Province Cards: FAIL\n");
								}
							}
							else if (pNum > 2)
							{
								//check estate cards for 3-4 players
								if(state.supplyCount[estate] == 12)
								{
									printf("ST2 - # Estate Cards: PASS\n");
								}
								else
								{
									printf("ST2 - # Estate Cards: FAIL\n");
								}
							
								//check duchy cards for 3-4 players
								if(state.supplyCount[duchy] == 12)
								{
									printf("ST2 - # Duchy Cards: PASS\n");
								}
								else
								{
									printf("ST2 - # Duchy Cards: FAIL\n");
								}
							
								//check province cards for 3-4 players
								if(state.supplyCount[province] == 12)
								{
									printf("ST2 - # Province Cards: PASS\n");
								}
								else
								{
									printf("ST2 - # Province Cards: FAIL\n");
								}
							}
						
							//test copper, silver, and gold cards
							if (state.supplyCount[copper] == 60 - (pNum * 7))
							{
								printf("ST2 - # Copper Cards: PASS\n");
							}
							else
							{
								printf("ST2 - # Copper Cards: FAIL\n");
							}
						
							if (state.supplyCount[silver] == 40)
							{
								printf("ST2 - # Silver Cards: PASS\n");
							}
							else
							{
								printf("ST2 - # Silver Cards: FAIL\n");
							}
						
							if (state.supplyCount[gold] ==  30)
							{
								printf("ST2 - # Gold Cards: PASS\n");
							}
							else
							{
								printf("ST2 - # Gold Cards: FAIL\n");
							}
						
						
						//Subtest 3 - Verify 1st players turn initialized appropriately
						printf("SubTest 3:\n");
						
							//check whose turn
							if (state.whoseTurn == 0)
							{
								printf("ST3 - First Players Turn: PASS\n");
							}
							else
							{
								printf("ST3 - First Players Turn: FAIL\n");
							}
						
							//check numActions
							if (state.numActions == 1)
							{
								printf("ST3 - First Players numActions = 1: PASS\n");
							}
							else
							{
								printf("ST3 - First Players numActions = 1: FAIL\n");
							}
						
							//check numBuys
							if (state.numBuys == 1)
							{
								printf("ST3 - First Players numBuys = 1: PASS\n");
							}
							else
							{
								printf("ST3 - First Players numBuys = 1: FAIL\n");
							}
						
							//check played card count
							if (state.playedCardCount == 0)
							{
								printf("ST3 - First Players playedCardCount = 0: PASS\n");
							}
							else
							{
								printf("ST3 - First Players playedCardCount = 0: FAIL\n");
							}
						
						
						//Subtest 4 - Verify that only the first player has drawn cards
						printf("SubTest 4:\n");
						
							if (state.handCount[state.whoseTurn] == 5)
							{
								printf("ST4 - First Player has Drawn 5 Cards: PASS\n");
							}
							else
							{
								printf("ST4 - First Player has Drawn 5 Cards: FAIL\n");
							}
							
							//for all remaining players...check that handCount == 0;
							for (i = state.whoseTurn + 1; i < pNum; i++)
							{
								if (state.handCount[i] == 0)
								{
									printf("ST4 - Other Player has Drawn 0 Cards: PASS\n");
								}
								else
								{
									printf("ST4 - Other Player has Drawn 0 Cards: FAIL\n");
								}
							}	
							
				printf("\n");
			}
			
			//Subtest 5 - Verify that initializeGame will throw error if multiple same kingdom cards are passed
			printf("SubTest 5:\n");
			
				//change k[9] to be the same as a previously used card;
				kCards[9] = adventurer;
				
				retVal = initializeGame(2, kCards, rSeed, &state);
				
					if(retVal == -1)
					{
						printf("ST5 - Function Caught Same kCard Error: PASS\n");
					}
					else
					{
						printf("ST5 - Function Caught Same kCard Error: FAIL\n");
					}
			
			printf("\n");
		
		printf("*****TEST: initializeGame() - END ******\n\n");
		
	return 0;
}