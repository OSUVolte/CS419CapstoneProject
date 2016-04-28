/* -----------------------------------------------------------------------
*Name: Suyana Lozada 
*Unit Test # 4 
*fullDeckCount() 
*Reference:testUpdateCoins.c  
*Test description:
*Determine if correct deck count for an specific card on player deck,hand and discard 
*-----------------------------------------------------------------------
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 5;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    int adventurerc[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        adventurerc[i] = adventurer;
    }

	handCount=5;
    printf ("Unit Test #4\n");
    printf ("TESTING fullDeckCount():\n");
    for (p = 0; p < numPlayer; p++)
    {
            for (handCount = 0; handCount <= maxHandCount; handCount++)
            {
                printf("Test player %d with %d adventurer card(s) in hand\n", p, handCount);
                // clear the game state
				memset(&G, 23, sizeof(struct gameState));  
				// initialize a new game 
                r = initializeGame(numPlayer, k, seed, &G); 
                G.handCount[p] = handCount;               
				memcpy(G.hand[p],adventurerc, sizeof(int) * handCount); 
                
				fullDeckCount(p,adventurer,&G);
				if(fullDeckCount(p,adventurer,&G)== handCount)
				{
					printf("PASS:test = %d, expected = %d\n", fullDeckCount(p,adventurer,&G),handCount);
				}
				else
				{
					printf("FAIL:test = %d, expected = %d\n", fullDeckCount(p,adventurer,&G),handCount);

				}
                printf("Test player %d with %d adventurer card(s) in hand and in deck\n", p, handCount);
                G.deckCount[p] = handCount;               
				memcpy(G.deck[p],adventurerc, sizeof(int) * handCount); 
                
				fullDeckCount(p,adventurer,&G);
				if(fullDeckCount(p,adventurer,&G)== 2*handCount)
				{
					printf("PASS:test = %d, expected = %d\n", fullDeckCount(p,adventurer,&G),2*handCount);
				}
				else
				{
					printf("FAIL:test = %d, expected = %d\n", fullDeckCount(p,adventurer,&G),2*handCount);

				}

                printf("Test player %d with %d adventurer card(s) in hand, in deck, and in discard \n", p, handCount);
                G.discardCount[p] = handCount;               
				memcpy(G.discard[p],adventurerc, sizeof(int) * handCount); 
                
				fullDeckCount(p,adventurer,&G);
				if(fullDeckCount(p,adventurer,&G)== 3*handCount)
				{
					printf("PASS:test = %d, expected = %d\n", fullDeckCount(p,adventurer,&G),3*handCount);
				}
				else
				{
					printf("FAIL:test = %d, expected = %d\n", fullDeckCount(p,adventurer,&G),3*handCount);

				}


            }
    }

    printf("End Unit Test #4\n");

    return 0;
}
