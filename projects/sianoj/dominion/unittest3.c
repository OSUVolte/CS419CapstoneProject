//Jessica Siano
//CS362 Software Development 2
//Testing the discarCard() function

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int main(){
	int i, p, handPos, players = 2, f, maxHand = 5, playedCards = 0, hand;

	struct gameState gS;

	SelectStream(2);
	PutSeed(2);

	printf("\n\nTesting the discardCard() function()\n\n");

	for(p = 0; p < players; p++){
		for(hand = 1; hand <= maxHand; hand++){
			for(handPos = 0; handPos < hand; handPos++){
				for(i = 0; i < sizeof(struct gameState); i++)
					((char*)&gS)[i] = random() % 256;
				
				gS.numPlayers = players;
				gS.playedCardCount = playedCards;
				gS.handCount[p] = hand;
				f = random() % 2;
				
				struct gameState testGS;
	
				memcpy(&testGS, &gS, sizeof(struct gameState));

				int x = discardCard(handPos, p, &gS, f);
				
				if(f == 0)
					testGS.playedCardCount++;

				testGS.handCount[p]--;

				if(x == 0)
					printf("Test 1 passed - function call was successfull\n");
				else
					printf("Test 1 failed - function call was not successfull\n");
	
				if(testGS.playedCardCount == gS.playedCardCount)
					printf("Test 2 passed - number of cards matches\n");
                                else
                                        printf("Test 2 failed - number of cards doesn't match\n");

				
				if(testGS.handCount[p] == gS.handCount[p])
					printf("Test 3 passed - number of cards matches\n");
                                else
                                        printf("Test 3 failed - number of cards doesn't match\n");

			}
		}
	}

	printf("\n\nTesting for discardCard() function complete.\n\n");
	
	return 0;
}
