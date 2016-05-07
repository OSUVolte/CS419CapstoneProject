#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

//Smithy card tests: 1) if 3 cards were added to player's hand, and 2) if it was then discarded. 
int main()
{
    int numPlayer = 2; 
	int seed = 1000;
    int player = 1; 
	int handCount = 5; 
	
	//Kingdom cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
			   
    struct gameState G; 
	
	//Creates hand
    int newHand[handCount];
	
	newHand[0] = copper;
    newHand[1] = silver;
	newHand[2] = village;
	newHand[3] = smithy;
	newHand[4] = mine;
    
    char cardName[20]; 
	int hasSmithy = 0; 

    printf ("\nTesting Smithy Card:\n");
	
	printf("Test that player %d with %d cards has a Smithy card.\n", player, handCount);

	initializeGame(numPlayer, k, seed, &G); 
	G.handCount[player] = handCount;             
	memcpy(G.hand[player], newHand, sizeof(int) * handCount); 
	
	int i;
	for(i = 0; i < G.handCount[player]; i++)
	{
		cardNumToName(G.hand[player][i], cardName);
		printf("%s%s", cardName, ", ");
		if(strcmp(cardName, "Smithy") == 0)
		{
			//Smithy card in hand
			hasSmithy = 1;
		}
	}
	
	if (hasSmithy == 1)
	{
		printf ("\nPass - Smithy card is in player's hand\n");
	}
	else
	{
		printf ("\nFail - Smithy card is not in player's hand\n");
	}
	
	hasSmithy = 0; 
	printf ("Using Smithy card...\n");
	playSmithyCard(&G, 3, player);
	

	if(G.handCount[player] == 8 || G.handCount[player] == 7)
	{
		printf ("Pass - Player %d has received 3 new cards.\n", player);
	}
	else
	{
		printf ("Fail - Player %d has not received 3 new cards.\n", player);
	}
	
	for(i = 0; i < G.handCount[player]; i++)
	{
		cardNumToName(G.hand[player][i], cardName); 
		printf("%s%s", cardName, ", ");
		if(strcmp(cardName, "Smithy") == 0)
		{
			//not in hand
			hasSmithy = 0; 
		}
	}

	if (hasSmithy == 0)
	{
		printf ("\nPass - Smithy card was discarded.\n");
	}
	else
	{
		printf ("\nFail - Smithy card wasn't discarded.\n");
	}
	
	return 0;
}