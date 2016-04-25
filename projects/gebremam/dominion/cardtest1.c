/* -----------------------------------------------------------------------
 * Martha Gebremariam
 * CS362_SP2016
 * Assignment 3
 * Description: Unit test for adventurere card in dominion.c
 * 
 * The following lines were also included makefile:
 *
 * unittest4: cardtest1.c dominion.o rngs.o
 * gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
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
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, mine, remodel, smithy, village, salvager, sea_hag, treasure_map};
    struct gameState G;
    int maxHandCount = 5;
   
    memset(&G, 0, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    for (i=0; i<2; i++){
        G.deckCount[i] = 25;
        G.discardCount[i]=25;
        G.handCount[i]=5;
    }
 
    
    int testDeck1[25]={curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, mine, remodel, smithy, village, salvager, sea_hag, treasure_map, copper, silver, gold, copper, silver, estate, feast, copper};
    memcpy(G.deck[0], testDeck1, sizeof(int)*25);

    int testDiscard1[25]= {feast, mine, remodel, smithy, village, salvager, sea_hag, treasure_map, copper, silver, gold, copper, silver, estate, feast, copper, curse, estate, duchy, province, copper, silver, gold, adventurer, council_room};
    memcpy(G.discard[0], testDiscard1, sizeof(int)*25);

    int testHand1[5]= {copper, silver, estate, feast, adventurer};
    memcpy(G.hand[0], testHand1, sizeof(int)*5);



    int testDeck2[25] = {province, copper, silver, gold, estate, smithy, village, remodel, copper, curse, treasure_map, smithy, silver, gold, estate, gold, estate, copper, copper, silver, estate, smithy, remodel, copper, gold};
    memcpy(G.deck[1], testDeck2, sizeof(int)*25);

    int testDiscard2[25] = {estate, gold, estate, copper, copper, silver, estate, smithy, remodel, copper, gold, adventurer, mine, treasure_map, copper, gold, duchy, remodel, silver, copper, estate, council_room, salvager, feast, mine};
    memcpy(G.discard[1], testDiscard2, sizeof(int)*25);

    int testHand2[5] = {copper, council_room, gold, gold, adventurer};
    memcpy(G.hand[1], testHand2, sizeof(int)*5);

    int *temphand [MAX_HAND];
    printf("testing adventurer card for player1\n");
    //r =adventurerRefactored(0, &G, 0, 0, temphand);
    cardEffect(adventurer, 0, 0, 0, &G, 0, 0);

    printf("\noriginal hand: ");
    for (i=0; i<5; i++){
	//int curHand=G.hand[0][i];
        printf("%d", testHand1[i]);
        printf(" ");
    }
 
    printf("\nhand: ");
    for (i=0; i<G.handCount[0]; i++){
	int curHand=G.hand[0][i];
        printf("%d", curHand);
        printf(" ");
    }
    
    printf("\n\noriginal deck: ");
    for (i=0; i<25; i++){
        printf("%d", testDeck1[i]);
        printf(" ");
    }

    printf("\ndeck: ");
    for (i=0; i<G.deckCount[0]; i++){
        printf("%d", G.deck[0][i]);
        printf(" ");
    }
    printf("\n\noriginal discard: ");
    for (i=0; i<25; i++){
        printf("%d", testDiscard1[i]);
        printf(" ");
    }
   
    printf("\ndiscard: ");
    for (i=0; i<G.discardCount[0]; i++){
        printf("%d", G.discard[0][i]);
        printf(" ");
    }
    printf("\n");
    return 0;
        
  }
