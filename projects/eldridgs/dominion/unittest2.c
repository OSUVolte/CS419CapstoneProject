/*
Susan Eldridge
Spring 2016
CS361
This method takes the card from the hand and either lets it get trashed or adds it to the
played card stack.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int handP = 3;//hand position
    int player = 1;
    struct gameState game, testgame;
    int playerNumber = 2;
    int kCards[10] = {adventurer, council_room, feast, gardens, mine, smithy, village, baron, great_hall, minion};
    int rSeed = 50;
    int cardtoDiscard, testcardtoDiscard;

    printf("----------TESTING discardCard()----------\n\n");

    initializeGame(playerNumber, kCards, rSeed, &game);

    //make sure enough cards in hand to do all tests
    game.handCount[player] = 10;

    memcpy(&testgame,&game,sizeof(struct gameState));//save state into test

    //if trash flag is set to 1 then the card is not added to discard pile
    discardCard(handP, player, &game, 1);

    //if trash flag is set to 1 then the card is not added to discard pile

    printf("----------TESTING Trash Flag and Discard Pile----------\n");
    //by doing nothing with the testgame.played card count, it makes sure that playedCards was not changed
    if(testgame.playedCards[testgame.playedCardCount] == game.playedCards[game.playedCardCount])
    {
        printf("Test 1 (trashflag set) passed.\n");
    }
    else
    {
        printf("Test 1 (trashflag set) failed.\n");
    }

    memcpy(&testgame,&game,sizeof(struct gameState));//save state into test

    //if trash flag is set to 0 then the card is added to discard pile
    discardCard(handP, player, &game, 0);

    //increase number of cards in discard pile
    testgame.playedCardCount++;

    if(testgame.playedCardCount == game.playedCardCount)
    {
        printf("Test 2 (trashcard = 0: correct number of cards being added to discard pile) passed.\n");
    }
    else
    {
        printf("Test 2 (trashcard = 0: correct number of cards being added to discard pile) failed.\n");
    }

    memcpy(&testgame,&game,sizeof(struct gameState));//save state into test
    //make sure correct card is being discarded
    cardtoDiscard = game.hand[player][handP];
    testcardtoDiscard = testgame.hand[player][handP];

    discardCard(handP, player, &game, 0);

    //move testcardtoDiscard from hand to discard pile
    testgame.playedCards[testgame.playedCardCount] = testcardtoDiscard;
    testgame.playedCardCount++;

    if(testgame.playedCards[testgame.playedCardCount - 1] == game.playedCards[game.playedCardCount - 1] && game.playedCards[game.playedCardCount - 1] == cardtoDiscard && cardtoDiscard == testcardtoDiscard)
    {
        printf("Test 3 (trashcard = 0: correct card being added to discard pile) passed.\n");
    }
    else
    {
        printf("Test 3 (trashcard = 0: correct card being added to discard pile) failed.\n");
    }

    printf("\n----------TESTING Removing Card From Hand----------\n");

    memcpy(&testgame,&game,sizeof(struct gameState));//save state into test
    //test for removing card when there is more than one card in hand (seven cards left)
    discardCard(handP, player, &game, 0);

    //move last card in hand array to hand position
    testgame.hand[player][handP] = testgame.hand[player][testgame.handCount[player] - 1];
    //reduce hand array by 1
    testgame.handCount[player]--;

    //if handcounts are equal and the card at handposition is equal
    if(testgame.handCount[player] == game.handCount[player] && testgame.hand[player][handP] == game.hand[player][handP])
    {
        printf("Test 4 (removing correct card from hand with more than one card) passed.\n");
    }
    else
    {
        printf("Test 4 (removing correct card from hand with more than one card) failed.\n");
    }

    //test discarding a card with only one card in hand
    game.handCount[player] = 1;
    memcpy(&testgame,&game,sizeof(struct gameState));//save state into test

    discardCard(handP, player, &game, 0);

    //just reduce hand size by 1
    testgame.handCount[player]--;

    if(testgame.handCount[player] == game.handCount[player])
    {
        printf("Test 5 (removing last card from hand) passed.\n");
    }
    else
    {
        printf("Test 5 (removing last card from hand) failed.\n");
    }

    return 0;
}
