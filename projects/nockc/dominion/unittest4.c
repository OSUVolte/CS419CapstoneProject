/* Unit Test 4 for updateCoins 
   Tests for:
    - correctly sums up the coin values for treasure cards and bonus (1 for copper, 2 for silver, 3 for gold), 
    - correctly returns a 0 for a hand with no coins and no bonus, 
	- correctly returns bonus for a hand with no coins and a bonus,
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define NOISY_TEST 1

int gamestatecheck(struct gameState *previous, struct gameState *post, int p);

int main()
{
   
    int seed = 1000;
    int kingdomCards[10] = { tribute, adventurer, council_room, baron, mine, remodel, feast, smithy, village, sea_hag };
	struct gameState previous; 
    struct gameState post; 
    int i, j, r, h, p, b, x, z;
	int finalfail = 0;
    int finalpass = 0;
	int ran;
	int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
	int cards[MAX_HAND];
    for ( i = 0; i < MAX_HAND; i++ ) 
	{
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
	}
	/* Test every possible combination of players (1 to 2), treasure cards (1 - 10), and bonus values up to 10 */
	for ( p = 0; p < 2; p++ ) 
	{
        for ( h = 1; h <= 10; h++ )  
		{
            for ( b = 0; b <= 10; b++) 
			{
#if (NOISY_TEST == 1)				
				printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, h, b );
#endif				
                /* Reset game state and start a new game for current combination */
				memset(&post, 23, sizeof(struct gameState));
                initializeGame( 2, kingdomCards, seed, &post ); 
				/* First test for a hand of coppers */
				post.handCount[p] = h;                
                memcpy( post.hand[p], coppers, sizeof(int) * h ); 
                updateCoins( p, &post, b );
				if ( post.coins != (h + b) )
				{
#if (NOISY_TEST == 1)
					printf("Test Result: Fail. actual coin count: %d, expected coin count: %d\r\n", post.coins, (h + b) );
#endif	
					finalfail++;
				}
				else 
				{
#if (NOISY_TEST == 1)
					printf("Test Result: Pass. actual coin count: %d, expected coin count: %d\r\n", post.coins, (h + b) );
#endif
					finalpass++;
				}
				/* Next test for a hand of silvers */
                memcpy( post.hand[p], silvers, sizeof(int) * h ); 
                updateCoins( p, &post, b );
				if ( post.coins != ( ( 2 * h ) + b) )
				{
#if (NOISY_TEST == 1)
					printf("Test Result: Fail. actual coin count: %d, expected coin count: %d\r\n", post.coins, ( ( 2 * h ) + b) );
#endif	
					finalfail++;
				}
				else 
				{
#if (NOISY_TEST == 1)
					printf("Test Result: Pass. actual coin count: %d, expected coin count: %d\r\n", post.coins, ( ( 2 * h ) + b) );
#endif
					finalpass++;
				}
				/* Next test for a hand of golds */
                memcpy( post.hand[p], golds, sizeof(int) * h ); 
                updateCoins( p, &post, b );
				if ( post.coins != ( ( 3 * h ) + b) )
				{
#if (NOISY_TEST == 1)
					printf("Test Result: Fail. actual coin count: %d, expected coin count: %d\r\n", post.coins, ( ( 3 * h ) + b) );
#endif	
					finalfail++;
				}
				else 
				{
#if (NOISY_TEST == 1)
					printf("Test Result: Pass. actual coin count: %d, expected coin count: %d\r\n", post.coins, ( ( 3 * h ) + b) );
#endif
					finalpass++;
				}
			}
        }
    }
#if (NOISY_TEST == 1)	
	/* returns a 0 for a hand with no coins and no bonus */
	printf("Testing for a hand with no treasure cards and no bonus\n");
#endif
	b = 0;
	previous.hand[0][0] = kingdomCards[1];
	previous.hand[0][1] = kingdomCards[2];
	previous.hand[0][2] = kingdomCards[3];
	previous.hand[0][3] = kingdomCards[4];
	previous.hand[0][4] = kingdomCards[5];
	previous.hand[0][5] = kingdomCards[6];
	post.hand[0][0] = kingdomCards[1];
	post.hand[0][1] = kingdomCards[2];
	post.hand[0][2] = kingdomCards[3];
	post.hand[0][3] = kingdomCards[4];
	post.hand[0][4] = kingdomCards[5];
	post.hand[0][5] = kingdomCards[6];
	updateCoins( 0, &post, b ); 
	if ( post.coins != 0 )
	{
#if (NOISY_TEST == 1)
		printf("Test Result: Fail. actual coin count: %d, expected coin count: 0\r\n", post.coins );
#endif	
		finalfail++;
	}
	else 
	{
#if (NOISY_TEST == 1)
		printf("Test Result: Pass. actual coin count: %d, expected coin count: 0\r\n", post.coins );
#endif
		finalpass++;
	}	
	#if (NOISY_TEST == 1)	
	/* returns a 0 for a hand with no coins and no bonus */
	printf("Testing for a hand with no treasure cards and a bonus\n");
#endif
	b = 10;
	updateCoins( 0, &post, b ); 
	if ( post.coins != 10 )
	{
#if (NOISY_TEST == 1)
		printf("Test Result: Fail. actual coin count: %d, expected coin count: 10\r\n", post.coins );
#endif	
		finalfail++;
	}
	else 
	{
#if (NOISY_TEST == 1)
		printf("Test Result: Pass. actual coin count: %d, expected coin count: 10\r\n", post.coins );
#endif
		finalpass++;
	}
	printf("Final tally for Unit Test 4 (Update Coins):\nPass: %d\nFailures: %d\r\n", finalpass, finalfail );
    return 0;
}




