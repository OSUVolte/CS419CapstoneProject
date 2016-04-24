/* Unit Test 1 for isGameOver 
   Tests for:
    - returns 1 if the supply of province becomes empty, 
    - returns 1 if the supply of three other cards becomes empty for all cards, 
    - gamestate remaining unchanged throughout all tests 
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int gamestatecheck(struct gameState *previous, struct gameState *post);

int main()
{
    int turn;
    int players = 2;
    int seed = 1000;
    int kingdomCards[10] = { tribute, adventurer, council_room, baron, mine, remodel, feast, smithy, village, sea_hag };
	struct gameState previous; 
    struct gameState post; 
    int i;
	int r;
	int gameover1 = 0;
	int gameover2 = 0;
    int testruns = 1; 
    int finalfail = 0;
    int finalpass = 0;
	int supplycnt = 0;
	initializeGame(players, kingdomCards, seed, &post); 
	for( i = 0; i < treasure_map + 1; i++ )
	{
        post.supplyCount[i] = -1;
    }
	/* As long as the provinces supply is > 0 game will not be overt */	
	post.supplyCount[province] = 0;
	memcpy(&previous, &post, sizeof(struct gameState));
	if( isGameOver(&post) != 1 )
	{
        finalfail++;
		printf("\nTest Result: Game failed to end when it should have - province empty\n");
    }
       else
     {
         finalpass++;
                printf("\nTest Result: Game passed to end when it should have - province empty\n");
     }  
	if ( gamestatecheck( &previous, &post ) == 0 )
    {
        finalfail++;
		printf("\nTest Result: Gamestate changed while testing for 0 province supply\n");
    }
    else
    {
        finalpass++;
        printf("\nTest Result: Gamestate passed while testing for 0 province supply\n");
    }
	/* Game also can be over if three piles of supplies are empty */
    post.supplyCount[province] = 1;
    post.supplyCount[0] = 0;
    post.supplyCount[1] = 0;
    post.supplyCount[2] = 0;
    memcpy(&previous, &post, sizeof(struct gameState));
    if( isGameOver(&post) != 1 )
	{
        printf("\nTest Result: Game failed to end when it should have - 3 supply piles empty\n");
        finalfail++;
    }
    else
     {
         finalpass++;
         printf("\nTest Result: Game passed to end when it should have - 3 supply piles empty\n");
     }
      if ( gamestatecheck( &previous, &post ) == 0 )
    {
        finalfail++;
                printf("\nTest Result: Gamestate changed while testing for three 0 supply piles\n");
    }
    else
    {
        finalpass++;
        printf("\nTest Result: Gamestate passed while testing for three 0 supply piles\n");
    }

	/* Repeat above test on the other cards */
        post.supplyCount[2] = -1; //reset duchy chard to non empty
	 //then start from the province card
        for( r=province; r < treasure_map + 1; r++ )
	{
		post.supplyCount[r] = 0;
		memcpy(&previous, &post, sizeof(struct gameState));
	        if( isGameOver(&post) != 1 )
		{
                        finalfail++;
			printf("\nTest Result: Game failed to end when it should have - 3 supply piles including %d empty\n", r);
		}
                else
                {
                        finalpass++;
                        printf("\nTest Result: Game passed to end when it should have - 3 supply piles second test\n");
                }

                if ( gamestatecheck( &previous, &post ) == 0 )
                 {
			finalfail++;
			printf("\nTest Result: Gamestate changed while testing for three 0 supply piles\n");
		}
                else
                {
                        finalpass++;
                        printf("\nTest Result: Gamestate passed while testing for three 0 province supply\n");
                }

        post.supplyCount[r] = -1;
    }
   	printf("Final tally for Unit Test 1 (Game over):\nPass: %d\nFailures: %d\r\n", finalpass, finalfail );
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
