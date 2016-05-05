#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

//Adventurer unit tests - 1) Deck was properly shuffled according to rules, and 2)Two treasure cards were added, and 3) Adventurer was then discarded
int main()
{
    int numPlayer = 2; 
	int seed = 1000;
    int player = 1; 
	int handCount = 5;
	
	//Kingdom cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
			   
    struct gameState G;
	
	//Custom hand
    int newHand[handCount];
	
	newHand[0] = smithy;
    newHand[1] = village;
	newHand[2] = gardens;
	newHand[3] = adventurer;
	newHand[4] = mine;
    
    char name[20]; 
	int hasAdvCard = 0; 
	int drawnTreasure = 0; 

    printf("\nTesting adventurer card:\n");
	
	printf("Test player %d with %d card(s) with 1 card being an Adventurer card.\n", player, handCount);

	initializeGame(numPlayer, k, seed, &G); 
	G.handCount[player] = handCount;          
	memcpy(G.hand[player], newHand, sizeof(int) * handCount);
	//sets to 0, so shuffling necessary
	G.deckCount[player] = 0; 
	
	int i;
	for(i = 0; i < G.handCount[player]; i++)
	{
		cardNumToName(G.hand[player][i], name); 
		printf("%s%s", name, ", ");
		if(strcmp(name, "Adventurer") == 0)
		{
			hasAdvCard = 1; 
		}
	}
	
	if (hasAdvCard == 1)
	{
		printf ("\nPass - Adventurer card in hand!\n");
	}
	else
	{
		printf ("\nFail - Adventurer card not in player's hand!\n");
	}
	
	hasAdvCard = 0;
	
	printf("Player's deck count is %d and must be shuffled\n", G.deckCount[player]);
	printf ("Using Adventurer card...\n");
	playAdvCard(&G, player);
	
	if(G.deckCount[player] == 0)
	{
		printf ("Fail - deckCount still %d, it was not shuffled\n", G.deckCount[player]);
	}
	else
	{
		printf ("Pass - deckCount now %d, deck was shuffled\n", G.deckCount[player]);
	}
	

	if(G.handCount[player] == 6 || G.handCount[player] == 7)
	{
		printf ("Pass - Player %d has received 2 cards.\n", player);
	}
	else
	{
		printf ("Fail - Player %d has not received the proper amount of cards.\n", player);
	}
	
	
	for(i = 0; i < G.handCount[player]; i++)
	{
		cardNumToName(G.hand[player][i], name); 
		printf("%s%s", name, ", ");
		if(strcmp(name, "Adventurer") == 0)
		{
			//Properly discarded
			hasAdvCard = 0; 
		}
		if(strcmp(name, "Copper") == 0 || strcmp(name, "Silver") == 0 || strcmp(name, "Gold") == 0)
		{
			drawnTreasure++;
		}
	}

	if (hasAdvCard == 0)
	{
		printf ("Pass - Adventurer card was discarded from hand.\n");
	}
	else
	{
		printf ("Fail - Adventurer card was NOT discarded from hand.\n");
	}
	
	if (drawnTreasure == 2)
	{
		printf ("Pass - Only two treasure cards were added to hand.\n");
	}
	else
	{
		printf ("Fail - Two treasure cards were NOT added to hand.\n");
	}
	
	return 0;
}