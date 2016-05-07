/* Random Test for Village
   Previous game state: playing 2-4 player Dominion game, Village card is played
   Tests will cover:
   - if hand count was unaltered
   - if deck count is decreased by 1
   - if number actions increased by 2
   - if village card is discarded
   - if next card is moved to the hand
   - if village remains in hand after playing
      - other player has no game state change 
		- same deck count
		- same hand count
		- same discard count	
		- same cards in hand
		- same cards in deck
		- same cards in discard
	- no game state change	
		- same players
		- same supply count for each card
		- same embargo token count for each card
		- same outposed played 
		- same outpost turn
		- same whose turn
		- same phase
		- same number of actions
		- same number buys
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define NOISY_TEST 0

int cardExists(int turn, struct gameState *state, int target);

int main()
{
    int startgame, turn, i, j, r, p, x, pos, card, diff;
    int players = 2;
    int seed = rand();
    int kingdomCards[10] = { gardens, adventurer, council_room, baron, mine, remodel, feast, smithy, village, great_hall };
	struct gameState previous;
	struct gameState post; 
    int testruns = 1000; 
    int finalfail = 0;
	srand(time(NULL));
	/* Looping through amount of test runs */
    for (i = 0; i < testruns; i++){
        printf("Test %d\n", i);
	    seed = rand();
		players = ( rand() % 3 ) + 2;
		/* Start with a new game */
		memset(&previous, 23, sizeof(struct gameState));   
        startgame = initializeGame(players, kingdomCards, seed, &previous); 
		/* Total number of cards in deck and discard should be less than MAXDECK and hand should be less than MAXHAND from better card draw.c */
		for (turn = 0; turn < players; turn++){
			previous.deckCount[turn] = floor(Random() * MAX_DECK);
            previous.discardCount[turn] = floor(Random() * MAX_DECK);
            previous.handCount[turn] = floor(Random() * MAX_HAND);
			/* Select random cards for deck, discard and hand */
            for ( j = 0; j < previous.deckCount[turn]; j++ ){
                previous.deck[turn][j] = floor( Random() *treasure_map );
            }
            for ( j = 0; j < previous.discardCount[turn]; j++ ){
                previous.discard[turn][j] = floor( Random() *treasure_map );
            }
            for ( j = 0; j < previous.handCount[turn]; j++ ){
                previous.hand[turn][j] = floor( Random() *treasure_map );
            }
			/* Make sure village is in the player hand */
            int villagerexist = -1;
            for ( j = 0; j < previous.handCount[turn]; j++ ){
                card = previous.hand[turn][j];
                if ( card == village ){
                    villagerexist = j;
					break;
                }
            }
			/* If its not in the hand put it in the hand in a random position */
            if ( villagerexist == -1 ){
                pos = floor( Random() * previous.handCount[turn] );
                previous.hand[turn][pos] = village;
            }
		}
		/* Selct random player, make a copy of GS to run test on, player adventure card */
		turn = rand() % players; 
		int tmp2 = previous.deckCount[turn];
		int tmp4 = previous.handCount[turn];
		int expNumAct = 0;
		int newcard = 0;
        memcpy( &post, &previous, sizeof(struct gameState)); 
        playVillage(turn, &post, 0);
#if (NOISY_TEST == 1)			
		printf("\nTesting if hand count was unaltered\n");
#endif
		/* When village is played, it adds a card to the players hand but also discards the village */               
		if ( tmp4 != post.handCount[turn])
		{
			finalfail++;
		}
#if (NOISY_TEST == 1)
		if ( tmp4 != post.handCount[turn])
		{
			printf("Test Result: Fail. actual handCount: %d, expected handCount: %d\r\n", tmp4, post.handCount[turn] );	
		}
		printf("\nTesting if deck count is decreased by 1\n");			
#endif   
		/* When village is played, it adds a card to the players hand which is taken off the deck */
		if( ( tmp2 - 1 ) != post.deckCount[turn] )
		{
			finalfail++;  
		}
#if (NOISY_TEST == 1)
		if ( ( tmp2 - 1 ) != post.deckCount[turn] )
		{
			printf("Test Result: Fail. actual deckCount: %d, expected deckCount: %d\r\n", post.deckCount[turn], ( tmp2 - 1 ) );

		}
		printf("\nTesting if number actions increased by 2\n");			
#endif   
        /* When playing village, num of actions should increase by 2 for a pass */
		expNumAct = previous.numActions + 2;
		if ( expNumAct != post.numActions )
		{
			finalfail++;
		}
#if (NOISY_TEST == 1)
        if ( expNumAct != post.numActions )
		{
			printf("Number actions test failed\n");
			printf("Test Result: actual number actions: %d, expected number actions: %d\r\n", post.numActions, expNumAct );   
		}
		printf("\nTesting if village card is discarded\n");	
#endif
        /* Village card should be discarded after playing so it should be at the top of the discard pile */ 
        if( post.playedCards[post.playedCardCount - 1] != village )
		{
			finalfail++;  
		}
#if (NOISY_TEST == 1)
        if ( post.playedCards[post.playedCardCount - 1] != village )
		{
			printf("Village discard test failed\n");
		}
		printf("\nTesting if village remains in hand after playing\n");
#endif           
		/* When village is played, it should leave hand  */ 
        r = cardExists(turn, &post, village);
		/* If village is not in hand then it pass */
        if ( r != -1 ) 
        {
            finalfail++;
        }
#if (NOISY_TEST == 1)
        if (r != -1) 
        {
            printf("Test Result: Fail. Village still in hand after playing\r\n");
        }
		printf("\nTesting other player hasn't had his hand count alterned\n");			
#endif 
/* Current player's adventurer should not affect other play's game state */
		for ( p = 0; p < players; p++ )
		{
			if ( p != turn )
			{
				if( previous.handCount[p] != post.handCount[p] )
				{
					finalfail++;  
				}
#if (NOISY_TEST == 1)
				if ( previous.handCount[p] != post.handCount[p]  )
				{
					printf("Test Result: Fail. Current player's playing Village changed other player's hand count\n");
					printf("Test Result: actual handCount: %d, expected handCount: %d\r\n", post.handCount[p],  previous.handCount[p]  );
				}
				printf("\nTesting other player hasn't had his deck count alterned\n");
#endif
				if( previous.deckCount[p] != post.deckCount[p] )
				{
					finalfail++;  
				}
#if (NOISY_TEST == 1)
				if ( previous.deckCount[p] != post.deckCount[p] )
				{
					printf("Test Result: Fail. Current player's playing Village changed other player's deck count\n");
					printf("Test Result: actual deckCount: %d, expected deckCount: %d\r\n", post.deckCount[p], previous.deckCount[p] );
				}
				printf("\nTesting other player hasn't had his discard count alterned\n");
#endif
				if ( post.discardCount[p] != previous.discardCount[p] )            
				{
					finalfail++;  
				}
#if (NOISY_TEST == 1)
				if ( post.discardCount[p] != previous.discardCount[p] )
				{
					printf("Test Result: Fail. Current player's playing Village changed other player's discard count\n");
					printf("Test Result: actual discardCount: %d, expected discardCount: %d\r\n", post.discardCount[p], previous.discardCount[p] );
				}
#endif
			}
		}
		/* Check game state hasn't changed */
#if (NOISY_TEST == 1)			
		printf("\nTesting general game state changes\n");
#endif
		if ( post.numPlayers != previous.numPlayers )            
		{
            finalfail++;  
		}
#if (NOISY_TEST == 1)
		if ( post.numPlayers != previous.numPlayers )
		{
			printf("Test Result: Fail. Number of players changed\n");
		}
#endif	
		if ( post.outpostPlayed != previous.outpostPlayed )            
		{
            finalfail++; 
		}				
#if (NOISY_TEST == 1)
		if ( post.outpostPlayed != previous.outpostPlayed )
		{
			printf("Test Result: Fail. Outpost played changed\n");
		}
#endif
		if ( post.outpostTurn != previous.outpostTurn )            
		{
            finalfail++; 
		}				
#if (NOISY_TEST == 1)
		if ( post.outpostTurn != previous.outpostTurn )
		{
			printf("Test Result: Fail. Outpost turn changed\n");
		}
#endif
		if ( post.whoseTurn != previous.whoseTurn )            
		{
            finalfail++;  
		}
#if (NOISY_TEST == 1)
		if ( post.whoseTurn != previous.whoseTurn )
		{
			printf("Test Result: Fail. Whose turn changed\n");
		}
#endif
		if ( post.phase != previous.phase )            
		{
            finalfail++;  
		}
#if (NOISY_TEST == 1)
		if ( post.phase != previous.phase )
		{
			printf("Test Result: Fail. Phase changed\n");
		}
#endif
		if ( post.numBuys != previous.numBuys )            
		{
            finalfail++;  
		}
#if (NOISY_TEST == 1)
		if ( post.numBuys != previous.numBuys )
		{
			printf("Test Result: Fail. Num buys changed\n");
		}
#endif
		if (post.playedCardCount != previous.playedCardCount + 1)
        {
            diff = post.playedCardCount - previous.playedCardCount;
#if (NOISY_TEST == 1)
            printf("Test Result: Fail. playedCardCount did not increase by 1 instead by %d.\n", diff);
#endif
			finalfail++; 
        }
#if (NOISY_TEST == 1)
		if ( post.numBuys != previous.numBuys )
		{
			printf("Test Result: Fail. Num buys changed\n");
		}
#endif
		for ( x = 0; x < treasure_map + 1; x++ )    
		{
			if ( post.supplyCount[x] != previous.supplyCount[x] )
			{
				finalfail++; 
#if (NOISY_TEST == 1)
				printf("Test Result: Fail. Supply count changed for a card\n");
#endif
			}
			if ( post.embargoTokens[x] != previous.embargoTokens[x] )
			{
				finalfail++; 
#if (NOISY_TEST == 1)
				printf("Test Result: Fail. Embargo token changed for a card\n");
#endif
			}
		}
	}
    printf("Final tally for Random Test ( Village ):\nFail: %d\r\n", finalfail );
    return 0;
}


int cardExists(int turn, struct gameState *state, int target){
    int cardexists = -1;
    int loopsize = state->handCount[turn];
	int i;
    for (i = 0; i < loopsize; i++)
    {
        if (state->hand[turn][i] == target)
        {
                 cardexists = i;
        }
    }
    return cardexists;
}
