//Jessica Siano
//CS362 Software Engineering 2
//Unit test for the updateCoins() function

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "rngs.h"

int main(){

	int i, j = 1000, players = 2, bonus, maxBonus = 10, hand, maxHand = 5;

	int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	struct gameState gS;
	
	//arrays of all one type of currency
	//int c[MAX_HAND];
	//int s[MAX_HAND];
	int g[MAX_HAND];

	for(i = 0; i < MAX_HAND; i++){
		//c[i] = copper;
		//s[i] = silver;
		g[i] = gold;
	}

	printf("\n\nTesting the updateCoins() function\n\n");
	for(i = 0; i < players; i++){
		for(hand = 1; hand <= maxHand; hand++){	
			for(bonus = 0; bonus < maxBonus; bonus++){
				memset(&gS, 23, sizeof(struct gameState));
				printf("Testing player #%d with %d treasure cards and %d bonus points.\n", i, hand, bonus); 
				intializeGame(players, cards, j, &gS);
				//set the number of cards the player has.
				gS.handCount[i] = hand;
				updateCoins(i, &gS, bonus);
				//check to see if the number of coins is correct
				if(gS.coins == hand*2+bonus)
					printf("Test 1 passed!  The number of coins is correct.\n");
				else
					printf("Test 1 failed!  The number of coins is incorrect.\n");
				
				//set all of the coin cards to gold coin cards
				memcpy(gS.hand[i], g, sizeof(int)*hand);
				updateCoins(i, &gS, bonus);
				//check to see if the number of coins is correct	
				 if(gS.coins == hand*3+bonus)
                                        printf("Test 2 passed!  The number of coins is correct.\n");
                                else
                                        printf("Test 2 failed!  The number of coins is incorrect.\n");
			}
		}
	}
	printf("\n\nTesting of the updateCoins() function is complete!\n\n");
	
	return 0;
}
