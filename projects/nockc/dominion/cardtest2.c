/* Card Test for Adventurer
   Previous game state: playing 2 player Dominion game, Adventurer card is played
   Tests will cover:
   - if hand count was increased by 2
   - if adventurer remains in hand after playing
   - if 2 treasure cards were added
   - if Adventurer card is discarded
   - if deck count is decreased by at least 2
   - other player hasn't had his hand count alterned
   - other player hasn't had his deck count alterned
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define NOISY_TEST 1

int cardExists(int turn, struct gameState *state, int target);

int main()
{
    int startgame;
    int turn;
    int players = 2;
    int seed = 1000;
    int kingdomCards[10] = { gardens, adventurer, council_room, baron, mine, remodel, feast, smithy, village, great_hall };
	struct gameState previous; 
    struct gameState post; 
    int i;
	int r;
    int testruns = 1; 
    int finalfail = 0;
    int finalpass = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int tmp4 = 0;
#if (NOISY_TEST == 1)
    const char* domCards[] =  {"curse", "estate", "duchy", "province", "copper", "silver", "gold", "adventurer", "council_room", "feast",
        "gardens", "mine", "remodel", "smithy", "village", "baron", "great_hall", "minion", "steward", "tribute",
        "ambassador", "cutpurse", "embargo", "outpost", "salvager", "sea_hag", "treasure_map"};
#endif
	/* Looping through amount of test runs */
    for (i = 0; i < testruns; i++)
    {
        /* Start with a new game */
		memset(&previous, 23, sizeof(struct gameState));   
        startgame = initializeGame(players, kingdomCards, seed, &previous); 
		for (turn = 0; turn < players; turn++)
        {
			/* For current player, initialize the hand and deck */
            previous.handCount[turn] = 1;       
            int inithand[1];
            inithand[0] = adventurer;
            memcpy(previous.hand[turn], inithand, sizeof(int));
            previous.deckCount[turn] = 5;       
            int initdeck[5];
            initdeck[0] = copper;
            initdeck[1] = silver;
            initdeck[2] = gold;
            initdeck[3] = gardens;
            initdeck[4] = tribute;
            memcpy(previous.deck[turn], initdeck, sizeof(int) * 5);
			/* The post game state will be a copy of the previous game state with tests ran on it */
            memcpy(&post, &previous, sizeof(struct gameState)); 
            playAdventurer( &post, turn);
			tmp2 = previous.deckCount[turn];
			tmp3 = previous.discardCount[turn];
			tmp4 = previous.handCount[turn];
			int expNumAct = 0;
			int newcard = 0;
#if (NOISY_TEST == 1)			
			printf("\nTesting if hand count was increased by 2\n");
#endif
			/* When Adventurer is played, it adds two cards to the players hand. */               
			r = post.handCount[turn]; 
			/* If hand count of post state is 2 more than previous state, this test is passed */
            if (r == previous.handCount[turn] + 2) 
            {
                finalpass++;
            }
            else
            {
               finalfail++;
            }
#if (NOISY_TEST == 1)
            printf("Test Result: actual handCount: %d, expected handCount: %d\r\n", r, previous.handCount[turn] + 2);
			printf("\nTesting if adventurer remains in hand after playing\n");
#endif           
			/* When adventurer is played, it should leave hand  */ 
            r = cardExists(turn, &post, adventurer);
			/* If adventurer is not in hand then it pass */
            if ( r == -1 ) 
            {
               finalpass++;
            }
            else
            {
                finalfail++;
            }
#if (NOISY_TEST == 1)
            if (r == -1) 
            {
               printf("Test Result: Pass. Adventurer not in the hand after playing\r\n");
            }
            else
            {
                printf("Test Result: Fail. Adventurer still in hand after playing\r\n");
            }
			printf("\nTesting if 2 treasure cards were added\n");	
#endif           
            
			/* When playing Adventurer, 2 treasure cards should be added last */
			if( (( post.hand[turn][post.handCount[turn] - 2] != copper ) && ( post.hand[turn][post.handCount[turn] - 2] != silver ) && 
			(post.hand[turn][post.handCount[turn] - 2] != gold )) && (( post.hand[turn][post.handCount[turn] - 1] != copper ) && ( post.hand[turn][post.handCount[turn] - 1] != silver ) && 
			(post.hand[turn][post.handCount[turn] - 1] != gold )))
			{
				finalfail++;
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
            if( (( post.hand[turn][post.handCount[turn] - 2] != copper ) && ( post.hand[turn][post.handCount[turn] - 2] != silver ) && 
			(post.hand[turn][post.handCount[turn] - 2] != gold )) && (( post.hand[turn][post.handCount[turn] - 1] != copper ) && ( post.hand[turn][post.handCount[turn] - 1] != silver ) && 
			(post.hand[turn][post.handCount[turn] - 1] != gold )))
			{
				printf("Added non treasure card instead of treasure cards failed\n"); 
			}
			else
			{
				printf("Added treasure cards correctly\n");   
			}
			printf("\nTesting if Adventurer card is discarcded\n");	
#endif
            /* Council Room card should be discarded after playing so it should be at the top of the discard pile */ 
            if(post.playedCards[post.playedCardCount - 1] != adventurer )
			{
				finalfail++;  
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
            if ( post.playedCards[post.playedCardCount - 1] != adventurer )
			{
				printf("Adventurer discard test failed\n");
			}
			else
			{
				printf("Test Result: Pass. Adventurer card has been discarded\n");   
			}
			printf("\nTesting deck count is decreased by at least 2\n");			
#endif   
			/* If post state deck count didn't decreasse by 2 its fail */
			r = post.deckCount[turn];
            if ( (tmp2 - 2) < r  ) 
            {
               finalfail++;
            }
            else
            {
                finalpass++;
            }
#if (NOISY_TEST == 1)
          	if( (tmp2 - 2) < r  )
			{
				printf("Test Result: Fail. Deck count not decreased by at least 2\r\n");
				printf("Test Result: actual deckCount: %d, expected deckCount: %d\r\n", r, (tmp2 - 2));
				
			}
			else
			{
				printf("Test Result: Pass. Deck count decreased by at least 2\r\n");
				printf("Test Result: actual deckCount: %d, expected deckCount: %d\r\n", r, (tmp2 - 2));
			}
			printf("\nTesting other player hasn't had his hand count alterned\n");			
#endif   
			/* Current player's adventurer should not affect other play's game state */
			if( previous.handCount[1 - turn] != post.handCount[1 - turn] )
			{
				finalfail++;  
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
			if (previous.handCount[1 - turn] != post.handCount[1 - turn]  )
			{
				printf("Test Result: Fail. Current player's playing adventurer changed other player's hand count\n");
				printf("Test Result: actual handCount: %d, expected handCount: %d\r\n", post.handCount[1 - turn],  previous.handCount[1 - turn]  );
			}
			else
			{
				printf("Test Result: Pass. Current player's playing adventurer did not affect other player's hand count\n");
				printf("Test Result: actual handCount: %d, expected handCount: %d\r\n", post.handCount[1 - turn],  previous.handCount[1 - turn] );
			}
			printf("\nTesting other player hasn't had his deck count alterned\n");
#endif
			
			if( previous.deckCount[1 - turn] != post.deckCount[1 - turn] )
			{
				finalfail++;  
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
			if ( previous.deckCount[1 - turn] != post.deckCount[1 - turn] )
			{
				printf("Test Result: Fail. Current player's playing adventurer changed other player's deck count\n");
				printf("Test Result: actual deckCount: %d, expected deckCount: %d\r\n", post.deckCount[1 - turn], previous.deckCount[1 - turn] );
			}
			else
			{
				printf("Test Result: Pass. Current player's playing adventurer did not affect other player's deck count\n");
				printf("Test Result: actual deckCount: %d, expected deckCount: %d\r\n", post.deckCount[1 - turn], previous.deckCount[1 - turn] );
			}
			
#endif			
          }
     }
    printf("Final tally for Card Test 2 ( Adventurer ):\nPass: %d\nFail: %d\r\n",finalpass, finalfail );
    return 0;
}


int cardExists(int turn, struct gameState *state, int target)
{
    /* Initalize flag to doesn't exist */
	int cardexists = -1;
    /* Retrieve size of played cards, hand or deck for checking loop */
	int loopsize = state->handCount[turn];;
	/* Find size of loop for played cards, ahnd or deck */
    int i;
    for (i = 0; i < loopsize; i++)
    {
        /* If checking player's hand for a certain card, use this loop */
        if (state->hand[turn][i] == target)
        {
                 cardexists = i;
        }
    }
    return cardexists;
} 