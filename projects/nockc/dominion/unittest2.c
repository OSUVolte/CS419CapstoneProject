/* Unit Test 2 for buy Card
   Tests for:
    - not allowing user to buy a card when they have no buys, 
    - not allowing user to buy a card with 0 supply , 
	- allowing user to buy a available card when they have buys,
	- gamestate remaining unchanged throughout all tests 
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define NOISY_TEST 1

int gamestatecheck(struct gameState *previous, struct gameState *post);

int main()
{
   
    int seed = 1000;
    int kingdomCards[10] = { tribute, adventurer, council_room, baron, mine, remodel, feast, smithy, village, sea_hag };
	struct gameState previous; 
    struct gameState post; 
    int i, j, r, h, p, b, x, z;
	int finalfail = 0;
    int finalpass = 0;
	initializeGame( 2, kingdomCards, seed, &post );
	memcpy( &previous, &post, sizeof(struct gameState) );
#if (NOISY_TEST)
			printf("\nPlayer with 0 buys should not be able to buy cards\n");
#endif
	/* If player has no buys, he should not be able to buy anything */
    for ( r = 0; r < 9; r++ )
    {
        post.numBuys = 0;
        if (buyCard( kingdomCards[r], &post ) != -1 )
		{
			finalfail++;
#if (NOISY_TEST)
			printf("\nTest Result: Fail. Function did not return -1 in case of player having 0 buys\n");
#endif
		}
		else
		{
			finalpass++;
#if (NOISY_TEST)
			printf("\nTest Result: Pass. Function returned -1 in case of player having 0 buys\n");
#endif
		}
        /* Revert to previous state and make suer states are unchanged */
        post.numBuys = previous.numBuys;
        if ( gamestatecheck( &previous, &post ) == 0 )
		{
			finalfail++;
#if (NOISY_TEST)		
			printf("\nTest Result: Gamestate changed while testing for player with no buys\n");
#endif
		}
		else
		{
			finalpass++;
#if (NOISY_TEST)
			printf("\nTest Result: Gamestate passed while testing for player with no buys\n");
#endif
		}
    }
#if (NOISY_TEST)
			printf("\nPlayer should only be able to buy cards with a supply greater than 0\n");
#endif
	/* As long as a card is available (not empty upply) player should be able to buy it */
    for ( r = 0; r < 9; r++ )
    {
        post.supplyCount[kingdomCards[r]] = 0;
        if ( buyCard( kingdomCards[r], &post ) != -1 )
        {
			finalfail++;
#if (NOISY_TEST)
			printf("\nTest Result: Fail. Player shouldn't be allowed to buy unavailable card\n");
#endif
        }
        else
        {
			finalpass++;
#if (NOISY_TEST)
			printf("\nTest Result: Pass. Player isn't be allowed to buy unavailable card\n");
#endif
        }
        /* Revert to previous state and make suer states are unchanged */
        post.supplyCount[kingdomCards[r]] = previous.supplyCount[kingdomCards[r]];
        if ( gamestatecheck( &previous, &post ) == 0 )
		{
			finalfail++;
#if (NOISY_TEST)		
			printf("\nTest Result: Gamestate changed while testing for buying card with no supply\n");
#endif
		}
		else
		{
			finalpass++;
#if (NOISY_TEST)
			printf("\nTest Result: Gamestate passed while testing for buying card with no supply\n");
#endif
		}
    }
	for ( x = 0; x < 9; x++ )
    {
        //Ensure that player can buy card
        post.coins = 10;
        post.supplyCount[kingdomCards[x]] = 5;
        post.numBuys = 1;
                    
        //Save state of game before call to drawCard for comparison
        memcpy( &previous, &post, sizeof(struct gameState) );
                    
        //Test for general error in call to function
        if ( buyCard(kingdomCards[x], &post) == -1 )
        {
			finalfail++;
#if (NOISY_TEST)
			printf("\nTest Result: Fail. Player was not able to buy an available card\n");
#endif
        }
        else
        {
			finalpass++;
#if (NOISY_TEST)
			printf("\nTest Result: Pass. Player was able to buy an available card\n");
#endif
        } 
    } 
	printf("Final tally for Unit Test 2 ( Buy Card ):\nPass: %d\nFailures: %d\r\n", finalpass, finalfail );
    return 0;
}

/* To check if a gamestate has changed, all elements must have the same values in previous and post state. Values tested are:
 - treasure map
 - embargo tokens
 - supply count
 - number player
 - number actioons
 - phase
 - coins
 - hand cards
 - hand count
 - deck cards
 - deck count
 - discard cards
 = discard count */ 
int gamestatecheck(struct gameState *previous, struct gameState *post)
{
    int r = -1;
    int i, j;
    for ( i = 0; i < treasure_map; i++ )
    {
        if ( previous->supplyCount[i] != post->supplyCount[i] )
        {
            r = 0;
            printf("\nTest Result: Gamestate changed - supply count\n");
        }
    }
	for ( i = 0; i < treasure_map; i++ )
    {
        if ( previous->embargoTokens[i] != post->embargoTokens[i] )
        {
            r = 0;
            printf("\nTest Result: Gamestate changed - embargo\n");
        }
    }
    if ( previous->numPlayers != post->numPlayers )
    {
        r = 0;
        printf("\nTest Result: Gamestate changed - player number\n");
    }
    if ( previous->numActions != post->numActions )
    {
        r = 0;
        printf("\nTest Result: Gamestate changed - action number\n");
    }
    if ( previous->outpostPlayed != post->outpostPlayed )
    {
        r = 0;
        printf("\nTest Result: Gamestate changed - outpost number\n");
    }
    if ( previous->phase != post->phase )
    {
        r = 0;
        printf("\nTest Result: Gamestate changed - phase\n"); 
    }
    if ( previous->coins != post->coins )
    {
        r = 0;
        printf("\nTest Result: Gamestate changed - coin number\n"); 
    }
    for ( j = 0; j < MAX_HAND; j++ )
    {
            if ( previous->hand[0][j] != post->hand[0][j] )
            {
                r = 0;
                printf("\nTest Result: Gamestate changed - hand cards\n"); 
            }
    }
    if ( previous->handCount[i] != post->handCount[i] )
    {
        r = 0;
        printf("\nTest Result: Gamestate changed - hand count\n");
      
    }
    for ( j = 0; j < MAX_DECK; j++ )
    {
        if ( previous->deck[0][j] != post->deck[0][j] )
        {
            r = 0;
            printf("\nTest Result: Gamestate changed - deck cards\n");
        }
    }
    if ( previous->deckCount[i] != post->deckCount[i] )
    {
        r = 0;
        printf("\nTest Result: Gamestate changed - deck count\n");
    }
    for ( j = 0; j < MAX_DECK; j++ )
    {
        if ( previous->discard[0][j] != post->discard[0][j] )
        {
            r = 0;
            printf("\nTest Result: Gamestate changed - discard pile\n");
        }
    }
    if ( previous->discardCount[i] != post->discardCount[i] )
    {
        r = 0;
          printf("\nTest Result: Gamestate changed - discard count\n");
    }   
    return r;
}
