/* Card Test for fullDeckCount
   Previous game state: playing 2 player Dominion game, Council Room card is played
   Tests will cover:
   - count of cards in a player's hand
   - count of cards in a player's discard pile
   - count of cards in a player's deck
   - if sum of above accounts are correctly calculated
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define NOISY_TEST 0

int main()
{
    int startgame;
    int turn;
    int players = 2;
    int seed = 1000;
    int kingdomCards[10] = { gardens, adventurer, council_room, baron, mine, remodel, feast, smithy, village, great_hall };
	const char* domCards[] =  {"curse", "estate", "duchy", "province", "copper", "silver", "gold", "adventurer", "council_room", "feast",
        "gardens", "mine", "remodel", "smithy", "village", "baron", "great_hall", "minion", "steward", "tribute",
        "ambassador", "cutpurse", "embargo", "outpost", "salvager", "sea_hag", "treasure_map"};
	struct gameState previous; 
    struct gameState post;
	int i, j, r, h, d, t, td, th, p, b, x, z;
	int finalfail = 0;
    int finalpass = 0;
	int totalCount;
    int deck;
    int hand;
    int discard;
    int maxCards = 10; 
    int result;
    int testruns = 0; 
  	int tmp2 = 0;
	int tmp3 = 0;
	int tmp4 = 0;
	/* Testing fullDeckCount for 2 player with all possible combos of card number (card in deck, card in hand, and card in discard */
	for ( p = 0; p < 2; p++ )
    {
        /* Tests cover all dominion cards */
		for ( r = 0; r <= 26; r++ ) 
		{
            /* Tests cover discard piles of up to 10 cards */
			for ( i = 0; i <= 10; i++ )
            {
                /* Tests cover hands of up to 10 cards */
				for ( h = 0; h <= 10; h++ )
                {
                    /* Tests cover deck piles of up to 10 cards */
					for ( d = 0; d <= 10; d++ )
                    {
                        /* Get the total number of cards in discard pile, hand pile and deck pile */
						t = i + h + d;
						/* Make a deck pile for testing consisting of d cards */
                        int td[d];
                        for (j = 0; j < d; j++)
                        {
                            td[j] = r;
                        }
						/* Make a hand for testing consisting of h cards */
                        int th[h];
                        for (j = 0; j < h; j++)
                        {
                            th[j] = r;
                        }
						/* Make a discard pile for testing consisting of h cards */
                        int z[i];
                        for (j = 0; j < i; j++)
                        {
                            z[j] = r;
                        }
                        /* Play dominion with current h, d, i values */
						memset( &post, 23, sizeof(struct gameState) );  
                        initializeGame( 2, kingdomCards, seed, &post ); 
                        post.handCount[p] = h;        
                        post.deckCount[p] = d;        
                        post.discardCount[p] = i;  
                        memcpy( post.hand[p], th, sizeof(int) * h );
                        memcpy( post.deck[p], td, sizeof(int) * d );
                        memcpy( post.discard[p], z, sizeof(int) * i);
                        result = fullDeckCount( p, r, &post );
                        testruns++;
						/* test if the total number of cards is equal to what the full Deck Count returned for current game state */
                        if ( t == result )
                        {
                            finalpass++;
#if (NOISY_TEST == 1)
                              printf("\nTest Result: Pass. Total number of cards is equal to what the full Deck Count returned for %d cards ( %d in the deck, %d in the hand, and %d in the discard pile\r\n", p, t, d, h, i, domCards[r]);                           
#endif
                        }
                        else
                        {
                            finalfail++;
#if (NOISY_TEST == 1)
							printf("\nTest Result: Fail. Expected number of cards: % d Actual number of cards: %d\r\n", t, result);
#endif                        
						}
                    }
                }
            }
        }
	}
    printf("Final tally for Unit Test 3 ( Full Deck Count ):\nPass: %d\nFail: %d\r\n",finalpass, finalfail );
    return 0;
} 