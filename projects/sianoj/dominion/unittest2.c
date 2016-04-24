//Jessica Siano
//CS362 Software Development 2
//Testing the shuffle function

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int main(){
	struct gameState gS;
	int p, i, j, players = 2, deck;
	int c[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	SelectStream(2);
	PutSeed(3);
	printf("\n\nTesting the shuffle() function.\n\n");
	for(p = 0; p < players; p++){
		for(deck = 10; deck < 100; deck+= 2){
			for(i = 0; i < sizeof(struct gameState); i++)
				((char*)&gS)[i] = random()%256;
			for(j = 0; j < deck; j++){
				int card = random()%10;
				gS.deck[p][j] = c[card];
			}
			gS.numPlayers = players;
			gS.deckCount[p] = deck;
		
			struct gameState testGS;
			memcpy(&testGS, &gS, sizeof(struct gameState));
			int x = shuffle(p, &gS);
			if(x == 0)
				printf("Test 1 passed - shuffle call successfull\n");
			else
				printf("Test 1 failed - shuffle call unsuccessfull\n");
			
			int y = memcmp(&testGS.deck[p], &gS.deck[p], sizeof(int)*testGS.deckCount[p]);
			if(y != 0)
				printf("Test 2 passed - the deck is in the same order\n");
                        else
                                printf("Test 2 failed - the deck is in a different order\n");
 
		}
	}

	printf("\n\nTest of the shuffle() function complete.\n\n");

	return 0;

}
