/* Card Test for Smithy
   Previous game state: playing 2 player Dominion game, Smithy card is drawn
   Tests will cover:
	- if hand count was increased by 2
	- if deck count was decreased by 3
	- if played card count was increased by 1
	- if Smithy is in played cards
	- if Smithy is still in hand
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

int cardExists(int turn, struct gameState *state, int target, int place);

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
            inithand[0] = smithy;
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
            playSmithy(turn, &post, 0);
#if (NOISY_TEST == 1)			
			printf("\nTesting if hand count was increased by 2\n");
#endif			
			/* When Smith is played, it adds three cards to the players hand. So post should be 2 more than previous hand count, takiung into account
			Smithy being discarded */               
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
			printf("\nTesting if deck count was decreased by 3\n");
#endif
            r = post.deckCount[turn]; 
			/* If deck count of post state is 3 less than previous state, this test is passed */
            if (r == previous.deckCount[turn] - 3) 
            {
                finalpass++;
            }
            else
            {
               finalfail++;
            }
#if (NOISY_TEST == 1)
            printf("Test Result: actual deckCount: %d, expected deckCount: %d\r\n", r, previous.deckCount[turn] - 3);   
			printf("\nTesting if played card count was increased by 1\n");
#endif
            /* When Smith is played, it should increment the played card count */ 
            r = post.playedCardCount;
			/* If played card count of post state is 1 more than previous state, this test is passed */
            if (r == previous.playedCardCount + 1) 
            {
                finalpass++;
            }
            else
            {
                finalfail++;
            }
#if (NOISY_TEST == 1)
            printf("Test Result: actual playedCardCount = %d, expected playedCardCount = %d\r\n", r, previous.playedCardCount + 1);
			printf("\nTesting if Smithy is in played cards\n");
#endif           
			/* When Smith is played, it should be added to the played card  */ 
            r = cardExists(turn, &post, smithy, 0);
			/* If smithy is found in the played cards then it pass */
            if (r == -1) 
            {
               finalfail++;
            }
            else
            {
                finalpass++;
            }
#if (NOISY_TEST == 1)
            if (r == -1) 
            {
               printf("Test Result: Fail. Smithy not in the played cards\r\n");
            }
            else
            {
                printf("Test Result: Pass. Smithy in the played cards\r\n", r);
            }
			printf("\nTesting if Smithy is still in hand\n");
#endif
             /* When Smith is played, it should not still be in player's post state hand  */
            r = cardExists(turn, &post, smithy, 1);
			/* If smithy is not found in the played cards then it pass */
            if (r == -1) 
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
                printf("Test Result: Pass. Smithy not in the player's post state hand\r\n");
            }
            else
            {
                printf("Test Result: Fail. Smithy still in the player's post state hand\r\n", r);
            }
			printf("Testing other player hasn't had his hand count alterned\n");			
#endif   
			/* Current player's smithy should not affect other play's game state */
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
				printf("Test Result: Fail. Current player's playing smithy changed other player's hand count\n");
				printf("Test Result: actual handCount: %d, expected handCount: %d\r\n", post.handCount[1 - turn],  previous.handCount[1 - turn]  );
			}
			else
			{
				printf("Test Result: Pass. Current player's playing smithy did not affect other player's hand count\n");
				printf("Test Result: actual handCount: %d, expected handCount: %d\r\n", post.handCount[1 - turn],  previous.handCount[1 - turn] );
			}
			printf("Testing other player hasn't had his deck count alterned\n");
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
				printf("Test Result: Fail. Current player's playing smithy changed other player's deck count\n");
				printf("Test Result: actual deckCount: %d, expected deckCount: %d\r\n", post.deckCount[1 - turn], previous.deckCount[1 - turn] );
			}
			else
			{
				printf("Test Result: Pass. Current player's playing smithy did not affect other player's deck count\n");
				printf("Test Result: actual deckCount: %d, expected deckCount: %d\r\n", post.deckCount[1 - turn], previous.deckCount[1 - turn] );
			}
#endif
        }
     }
     printf("Final tally for Card Test 1 ( Smithy ):\nPass: %d\nFail: %d\r\n",finalpass, finalfail );
    return 0;
}


int cardExists(int turn, struct gameState *state, int target, int place)
{
    /* Initalize flag to doesn't exist */
	int cardexists = -1;
    /* Retrieve size of played cards, hand or deck for checking loop */
	int loopsize = 0;
	/* Find size of loop for played cards, ahnd or deck */
    if (place == 0) 
		{ loopsize = state->playedCardCount; };
    if (place == 1) 
		{ loopsize = state->handCount[turn]; };
    int i;
    for (i = 0; i < loopsize; i++)
    {
        /* If checking played cards for a certain card, use this loop */
		if (place == 0)
        {
            /* If target is found in played cards, then it exists */
			if (state->playedCards[i] == target)
            {
                cardexists = i;
            }
        }
		/* If checking player's hand for a certain card, use this loop */
        else if (place == 1)
        {
            if (state->hand[turn][i] == target)
            {
                 cardexists = i;
            }
        }
    }
    return cardexists;
} 