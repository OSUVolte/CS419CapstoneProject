/*************************************************************************************
   Program:      randomtestadventurer
   Date:         05/06/2016
   Author:       Jerry Hayes
   Description:  This program is used to as a Random Tester for the Adventurer card
                 used in the game of Domonion.  
**************************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "rngs.h"

#define  CARD_TYPES 27
#define  RANDOM_SAMPLES 1000

/*************************************************************************************
   Function:      classifyCards
   Input:         cards:  A pile of arbitary cards
                  size:   The number of cards in the pile
                  container: A combinational data structure used to represent card content
   Description:   This function is used to analyze a pile of cards and fill a 
                  combinational data structure representing the card content of the pile
**************************************************************************************/
void classifyCards(int *cards, int *size, int *container) {
    int i;
    int hand[CARD_TYPES] =  {0};
    for(i=0; i < *size; i++) {
        hand[*cards] += 1;
        cards++;
    }
    for(i=0; i<CARD_TYPES; i++) {
        *container = hand[i];
        container++;
    }
}

/*************************************************************************************
   Function:      countTreasureCards
   Input:         pile:  A combinational data structure representing card contenct
   Description:   This function is used to count the number of treasure cards in pile.
   Return:        The number of treasure cards in pile.
**************************************************************************************/
int countTreasureCards(int *pile) {
    int i, count=0;

    for(i=0; i <=CARD_TYPES; i++) {
        if ((i>=copper) && (i<=gold)) {
            count += *pile;
        }
        pile++;
    }
    return count;
}

/*************************************************************************************
   Function:      displayCards
   Input:         predeck        The contents of deck before calling Adventurer
                  prehand        The contents of hand before calling Adventurer
                  prediscard     The contents of discard before calling Adventurer
                  postdeck       The contents of deck after calling Adventurer
                  posthand       The contents of hand after calling Adventurer
                  postdiscard    The contents of discard after calling Adventurer
   Description:   This function is used to display the pre and post card piles
                  relevant to testing Adventurer.
**************************************************************************************/
void displayCards(int *predeck, int *prehand,  int *prediscard, int *postdeck, int *posthand,  int *postdiscard) {
    int i;

    for (i = 0; i < CARD_TYPES; i++) {
        printf("Type:%d  predeck:%d  prehand:%d  prediscard:%d  postdeck:%d  posthand:%d  postdiscard:%d\n", i,*predeck,*prehand,*prediscard,*postdeck,*posthand,*postdiscard);
        predeck++;
        prehand++;
        prediscard++;
        postdeck++;
        posthand++;
        postdiscard++;
    }
}
/*************************************************************************************
   Function:      nullPiles
   Input:         G:   A gameState structure used to represent the state of the game
   Description:   This function essentially nullifies out any parts of the game state
                  that was expected to change when calling Adventurer so that a 
                  memory comparison can be performed on the parts that were not 
                  expected to change..
**************************************************************************************/
void nullPiles(struct gameState *G) {
    int i, j;
    for(i=0; i<MAX_PLAYERS; i++) {
        for(j=0; j<MAX_HAND;j++) {
            G->deck[i][j] = -1;
            G->hand[i][j] = -1;
            G->discard[i][j] = -1;
        }
        G->deckCount[i] = 0;
        G->handCount[i] = 0;
        G->discardCount[i] = 0;
    }
    G->playedCardCount = 0;
}
/*************************************************************************************
   Function:      generateInput
   Input:         G:   A gameState structure used to represent the state of the game
                       It is passed as a randomly initialized structure
   Description:   This function is used to modify the parts of the gameState structure
                  that are relevant to testing the card Adventurer. Modification is
                  accomplished by "randomizing" these parts to ranges and values that
                  may be expected during the course of play.
**************************************************************************************/
void generateInput(struct gameState *G) {
    int i, mode;

    mode = floor(Random() * 10);
 

    int p = floor(Random() * MAX_PLAYERS);
    G->whoseTurn = p;
   
    if (mode == 9 ) {   // Use large pile of cards
        G->deckCount[p] = floor(Random() * MAX_HAND/2) + 10;
        for(i = 0; i < G->deckCount[p]; i++ ) {
            G->deck[p][i] = floor(Random() * CARD_TYPES);
        }
        G->discardCount[p] = floor(Random() * MAX_HAND/2) + 10;
        for(i = 0; i < G->discardCount[p]; i++ ) {
            G->discard[p][i] = floor(Random() * CARD_TYPES);
        }
        G->handCount[p] = floor(Random() * MAX_HAND/2) + 10;
        for(i = 0; i < G->handCount[p]; i++ ) {
            G->hand[p][i] =  floor(Random() * CARD_TYPES);
        }
    }
    else {  // Use normal size pile of cards
        G->deckCount[p] = floor(Random() * 11);
        for(i = 0; i < G->deckCount[p]; i++ ) {
            G->deck[p][i] = floor(Random() * CARD_TYPES);
        }
        G->discardCount[p] = floor(Random() * 11);
        for(i = 0; i < G->discardCount[p]; i++ ) {
            G->discard[p][i] = floor(Random() * CARD_TYPES);
        }
        G->handCount[p] = floor(Random() * 11);
        for(i = 0; i < G->handCount[p]; i++ ) {
            G->hand[p][i] =  floor(Random() * CARD_TYPES);
        }
    }
    G->playedCardCount = 0;
}

/*************************************************************************************
   Function:      addCARDS
   Input:         pile1:  Combinational data structure describing card contenxt of pile1
                  pile2:  Combinational data structure describing card contenxt of pile2
   Output:        sum:    A combinational data structure describing the sum of pile1 and
                          pile2.
**************************************************************************************/
void addCARDS(int *pile1, int *pile2, int *sum) {
    int i;
    for(i = 0; i < CARD_TYPES; i++) {
        *sum = *pile1+*pile2;
        sum++;
        pile1++;
        pile2++;
    }
}

/*************************************************************************************
   Function:      countCARDS
   Input:         pile:  Combinational data structure describing card contenxt of pile
   Description:   The function is used to determine the actual number of cards in a pile
   Return:        Number of cards in pile
**************************************************************************************/
int countCARDS(int *pile) {
    int count = 0;
    int i;
    for(i = 0; i < CARD_TYPES; i++) {
        count += *pile;
        pile++;
    }
    return count;
}

/*************************************************************************************
   Function:      diffCARDS
   Input:         pile1:  Combinational data structure describing card contenxt of pile1
                  pile2:  Combinational data structure describing card contenxt of pile2
   Output:        diff:   A combinational data structure describing the difference in 
                          card content between pile1 and pile2
**************************************************************************************/
void diffCARDS(int *pile1,  int *pile2,  int *diff) {
    int i;
    for(i = 0; i < CARD_TYPES; i++) {
        *diff = abs(*pile1-*pile2);
        diff++;
        pile1++;
        pile2++;
    }
}

/*************************************************************************************
   Function:      compareCARDS
   Input:         pile1:  Combinational data structure describing card contenxt of pile1
                  pile1:  Combinational data structure describing card contenxt of pile2
   Description:   This function compares 2 27-element arrays to determine if the they
                  contain the same card content. 
   Return:        0 if piles are the same, 1 otherwise.
**************************************************************************************/
int compareCARDS(int *pile1,  int *pile2) {
    int i;
    for(i = 0; i < CARD_TYPES; i++) {
        if (*pile1 != *pile2)  { return 1; }
        pile1++;
        pile2++;
    }
    return 0;
}
/*************************************************************************************
   Function:      displayFailure
   Input:         pre:  Game state before calling Adventurer
                  post: Game state after  calling Adventurer will modify.
   Description:   This function is used to display pre and post game states when 
                  a failure has been detected.
**************************************************************************************/
void displayFailure(struct gameState *pre, struct gameState *post) {

    int i;

    int pile1[CARD_TYPES];
    int pile2[CARD_TYPES];

    classifyCards(pre->deck[pre->whoseTurn], &pre->deckCount[pre->whoseTurn], pile1);
    classifyCards(post->deck[post->whoseTurn], &post->deckCount[post->whoseTurn], pile2);
    printf("DECK\n");
    for(i=0; i<CARD_TYPES; i++) {
    	printf("%d  pre:%d   post%d\n", i, pile1[i], pile2[i]);
    }

    classifyCards(pre->hand[pre->whoseTurn], &pre->handCount[pre->whoseTurn], pile1);
    classifyCards(post->hand[post->whoseTurn], &post->handCount[post->whoseTurn], pile2);
    printf("HAND\n");
    for(i=0; i<CARD_TYPES; i++) {
    	printf("%d  pre:%d   post%d\n", i, pile1[i], pile2[i]);
    }

    classifyCards(pre->discard[pre->whoseTurn],   &pre->discardCount[pre->whoseTurn], pile1);
    classifyCards(post->discard[post->whoseTurn], &post->discardCount[post->whoseTurn], pile2);
    printf("DISCARD\n");
    for(i=0; i<CARD_TYPES; i++) {
    	printf("%d  pre:%d   post%d\n", i, pile1[i], pile2[i]);
    };
}
/*************************************************************************************
   Function:      oracle
   Input:         pre:  Game state before calling Adventurer
         :        post: Game state that Adventurer will modify. The pre and post 
                        post states are identical when passed to this function
   Description:   This function is used to call playAdventurer that will modify
                  the post state gameStructure according the how Adventurer is 
                  coded in dominion.c   The pre state and post state structures
                  are then used to construct test "asserts" to determine if 
                  the results of playAdventurer is expected.
   Return:        0 if all checks pass, otherwise a positive integer indicating
                  the failed check.
**************************************************************************************/
int oracle(struct gameState *pre, struct gameState *post) {

    int compare;
    int pre_deck[CARD_TYPES]       = { 0 };
    int pre_discard[CARD_TYPES]    = { 0 };
    int pre_hand[CARD_TYPES]       = { 0 };
    int post_deck[CARD_TYPES]      = { 0 };
    int post_discard[CARD_TYPES]   = { 0 };
    int post_hand[CARD_TYPES]      = { 0 };
    int added_to_hand[CARD_TYPES]  = { 0 };
    int sum1[CARD_TYPES]           = { 0 };
    int sum2[CARD_TYPES]           = { 0 };
    int sum3[CARD_TYPES]           = { 0 };

    playAdventurer(post);     // play Adventurer Card

    int p = post->whoseTurn;

    //Create combinational structures for all piles that will be used do determine pile card content
    classifyCards(pre->deck[p], &pre->deckCount[p], pre_deck);
    classifyCards(pre->discard[p], &pre->discardCount[p], pre_discard);
    classifyCards(pre->hand[p], &pre->handCount[p], pre_hand);
    classifyCards(post->deck[p], &post->deckCount[p], post_deck);
    classifyCards(post->discard[p], &post->discardCount[p], post_discard);
    classifyCards(post->hand[p], &post->handCount[p], post_hand);

    int drawedTC = countTreasureCards(pre_deck) + countTreasureCards(pre_discard);
    if (drawedTC > 2) { drawedTC = 2; }

    //Ensure that the cards added to the hand were indeed treasure cards.
    if (countTreasureCards(post_hand) !=  countTreasureCards(pre_hand) + drawedTC) { return 1; }

    //Ensure that post-handCount = pre-handCount + the number of cards drawn
    if (pre->handCount[p] + drawedTC  != post->handCount[p]) { return 2; }

    //Ensure that the number of cards in the post-deck pile = the post-deckCount
    if (countCARDS(post_deck) != post->deckCount[p]) { return 3; }

    //Ensure that the number of cards in the post-discard pile = the post-discardCount
    if (countCARDS(post_discard) != post->discardCount[p]) { return 4; }

    //Ensure that the number of cards in the post-hand pile = the post-handCount
    if (countCARDS(post_hand) != post->handCount[p]) { return 5; }

    //Ensure that the pre deck+discard count = the post deck+discount count + the number of cards drawn
    if (pre->deckCount[p]+pre->discardCount[p] != post->deckCount[p]+post->discardCount[p]+drawedTC) { return 6; }

    //Ensure that the cards added to the hand, together with the post-deck and post-discard piles
    //have the same card content as the pre-deck and pre-discard piles.
    diffCARDS(post_hand, pre_hand, added_to_hand);
    addCARDS(post_deck, post_discard, sum1);
    addCARDS(sum1, added_to_hand, sum2);
    addCARDS(pre_deck, pre_discard, sum3);
    compare = compareCARDS(sum2, sum3);
    if (compare) { return 7; }

    //Ensure that nothing other that what was supposed to change ... changed
    nullPiles(pre);
    nullPiles(post);
    if (memcmp(pre, post, sizeof(struct gameState)) != 0) { return 8; }

    return 0;
}

/************************************************************************************

**************************************************************************************/
int main() {
    int n, i, r=0;
    int pass = 0;
    int fail = 0;
    int deck[CARD_TYPES]    = { 0 };
    int discard[CARD_TYPES] = { 0 };
    struct gameState post, pre;

    SelectStream(2);
    PutSeed(3);

    for (n = 0; n < RANDOM_SAMPLES; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
	    ((char*)&post)[i] = floor(Random() * 256);
	}
        do {
            generateInput(&post);    // generate random input to be tested
            classifyCards(post.deck[post.whoseTurn], &post.deckCount[post.whoseTurn], deck);
            classifyCards(post.discard[post.whoseTurn], &post.discardCount[post.whoseTurn], discard);
        } while (countTreasureCards(deck) + countTreasureCards(discard) < 2);  // ensure at least 2 or more treasure cards available

        memcpy(&pre, &post, sizeof(struct gameState));   // initialize pre structure to be exact copy of post before test
        r = oracle(&pre, &post);    // Perform test
        if (r) {                    // If check failed, print failure
            printf("Failed:%d\n", r);
            displayFailure(&pre, &post);
            fail++;
        }
        else   { pass++;  }
    }
    printf("randomtestadventurer => Passed:%d  Failed:%d\n", pass, fail);

    return 0;
}
