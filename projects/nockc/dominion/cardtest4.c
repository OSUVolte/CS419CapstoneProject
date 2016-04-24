/* Card Test for Council Room
   Previous game state: playing 2 player Dominion game, Council Room card is played
   Tests will cover:
   - if hand count was increased by 3
   - if council_room remains in hand after playing
   - if number of buys increased by 1
   - if Council Room card is discarded
   - if deck count is decreased by 4
   - other player has drawn a card hand increase by 1
   - other player has drawn a card deck decrease by 1
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
            inithand[0] = council_room;
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
            playCouncil_Room(turn, &post, 0);
			tmp2 = previous.deckCount[turn];
			tmp3 = previous.discardCount[turn];
			tmp4 = previous.handCount[turn];
			int expNumAct = 0;
			int newcard = 0;
#if (NOISY_TEST == 1)			
			printf("\nTesting if hand count was increased by 3\n");
#endif			
			/* When council_room is played, it adds 4 cards to the players hand but also discards the council room */               
			if ( (tmp4 + 3) != post.handCount[turn] )
			{
				finalfail++;
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
			if ( (tmp4 + 3) != post.handCount[turn] )
			{
				printf("Handcount test failed\n");
				printf("Test Result: actual handCount: %d, expected handCount: %d\r\n", post.handCount[turn], (tmp4 + 3) );
			}
			else
			{
				printf("Test Result: actual handCount: %d, expected handCount: %d\r\n", post.handCount[turn], (tmp4 + 3) );
			}
			printf("\nTesting if council_room remains in hand after playing\n");
#endif           
			/* When council_room is played, it should leave hand  */ 
            r = cardExists(turn, &post, council_room);
			/* If council_room is not in hand then it pass */
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
               printf("Test Result: Pass. Council Room not in the hand after playing\r\n");
            }
            else
            {
                printf("Test Result: Fail. Council Room still in hand after playing\r\n");
            }
			printf("\nTesting if number of buys increased by 1\n");
#endif           
            
			/* When playing Council Room, num of buys should increase by 1 for a pass */
			expNumAct = previous.numBuys + 1;
			if ( expNumAct != post.numBuys )
			{
				finalfail++;
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
            if ( expNumAct != post.numBuys )
			{
				printf("Number buys test failed\n");
				printf("Test Result: actual number buys: %d, expected number buys: %d\r\n", post.numBuys, expNumAct );   
			}
			else
			{
				printf("Test Result: actual number buys: %d, expected number buys: %d\r\n", post.numBuys, expNumAct );   
			}
			printf("\nTesting if Council Room card is discarded\n");	
#endif
            /* Council Room card should be discarded after playing so it should be at the top of the discard pile */ 
            if(post.playedCards[post.playedCardCount - 1] != council_room )
			{
				finalfail++;  
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
            if ( post.playedCards[post.playedCardCount - 1] != council_room )
			{
				printf("Council Room discard test failed\n");
			}
			else
			{
				printf("Test Result: Pass. Council Room card has been discarded\n");   
			}
			printf("\nTesting deck count is decreased by 4\n");			
#endif   
			/* When Council Room is played, it takes four cards off the players deck (4 cards + 1 buy card - 1 council room) */
			expNumAct = tmp2 - 4;
			if( expNumAct != post.deckCount[turn] )
			{
				finalfail++;  
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
			if ( expNumAct != post.deckCount[turn] )
			{
				printf("Deckcount test failed\n");
				printf("Test Result: actual deckCount: %d, expected deckCount: %d\r\n", post.deckCount[turn], expNumAct );
			}
			else
			{
				printf("Test Result: actual deckCount: %d, expected deckCount: %d\r\n", post.deckCount[turn], expNumAct );
			}
			printf("\nTesting other player has drawn a card hand increase by 1\n");			
#endif   
			/* When Council Room is played, other player draw a card from deck /hand increase by 1*/
			if( (previous.handCount[1 - turn] + 1) != post.handCount[1 - turn] )
			{
				finalfail++;  
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
			if ( (previous.handCount[1 - turn] + 1) != post.handCount[1 - turn] )
			{
				printf("Test Result: Fail. Other player hand did not increase by 1\n");
				printf("Test Result: actual handCount: %d, expected handCount: %d\r\n", post.handCount[1 - turn],  (previous.handCount[1 - turn] + 1) );
			}
			else
			{
				printf("Test Result: Pass. Other player hand increased by 1\n");
				printf("Test Result: actual handCount: %d, expected handCount: %d\r\n", post.handCount[1 - turn],  (previous.handCount[1 - turn] + 1) );
			}
			printf("\nTesting other player has drawn a card deck decrease by 1\n");
#endif
/* When Council Room is played, other player draw a card from hand */
			if( (previous.deckCount[1 - turn] - 1) != post.deckCount[1 - turn] )
			{
				finalfail++;  
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
			if ( (previous.deckCount[1 - turn] - 1) != post.deckCount[1 - turn] )
			{
				printf("Test Result: Fail. Other player deck did not decreased by 1\n");
				printf("Test Result: actual deckCount: %d, expected deckCount: %d\r\n", post.deckCount[1 - turn], (previous.deckCount[1 - turn] - 1) );
			}
			else
			{
				printf("Test Result: Pass. Other player deck decreased by 1\n");
				printf("Test Result: actual deckCount: %d, expected deckCount: %d\r\n", post.deckCount[1 - turn], (previous.deckCount[1 - turn] - 1) );
			}
#endif			
          }
     }
    printf("Final tally for Card Test 4 ( Council Room ):\nPass: %d\nFail: %d\r\n",finalpass, finalfail );
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