//
// Created by Michael Loo on 4/23/16.
//
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

/*
case adventurer:
while(drawntreasure<2){
if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
shuffle(currentPlayer, state);
}
drawCard(currentPlayer, state);
cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
drawntreasure++;
else{
temphand[z]=cardDrawn;
state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
z++;
}
}
while(z-1>=0){
state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
z=z-1;
}
return 0;

*/

//first generate a random game

int main() {
    int player;
    int testCount = 0;
    struct gameState Game;

    //game parameters

    int i, initialHand, finalHand, initialDeck;

    int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy };

    srand(time(NULL));
    
    int failed = 0;

    int random = rand() % 10;
    int numPlayers = rand() % (MAX_PLAYERS - 1) + 2;

    //initialize new game


    while (testCount < 10){

        //printf("1.\n");
        //set it to a random person's turn
        initializeGame(numPlayers, k, random, &Game);
        Game.whoseTurn =0;
        //give them the adventurer card
        Game.hand[Game.whoseTurn][0] = adventurer;
        //printf("2.\n");

        //check hand before
        player = Game.whoseTurn;
        initialDeck = Game.deckCount[player];
        initialHand = Game.handCount[player];

        //create hand and deck that have no treasure cards;
        for (i = 0; i < initialHand; i++)
        {
            int randomCard = rand() % 10;
            //printf("%d.\n", randomCard);
            while (randomCard == gold || randomCard == silver || randomCard == copper){
                randomCard = rand() % 10;
            }
            
            Game.hand[player][i] = randomCard;
            //printf("added\n");
            
        }

        int initialVal = 0;

        for (i = 0; i < initialHand; i++)
        {
            int handCard = Game.hand[player][i];
            //printf("card is: %d\n", handCard);
            if (handCard == gold)
                initialVal += 3;
            else if (handCard == silver)
                initialVal += 2;
            else if (handCard == copper)
                initialVal++;
            else{
                continue;
            }
        }

        //printf("Initial val is: %d\n", initialVal);

        for (i = 0; i < initialDeck; i++)
        {
            int randomCard = rand() % 10;
            //printf("4.\n");
            while (randomCard == gold || randomCard == silver || randomCard == copper){
                randomCard = rand() % 10;
            }
            
            Game.deck[player][i] = randomCard;
           
        }

        //now pick two random treasure cards to add to the deck
        //printf("5.\n");
        int randomTreasure1, randomTreasure2, randomValue, slot1, slot2;

        randomValue = 0;
        randomTreasure1 = rand() % 7 + 4;
        randomTreasure2 = rand() % 7 + 4;
        //printf("6.\n");
        if (randomTreasure1 == gold)
            randomValue += 3;
        else if (randomTreasure1 == silver)
            randomValue += 2;
        else
            randomValue++;

        if (randomTreasure2 == gold)
            randomValue += 3;
        else if (randomTreasure2 == silver)
            randomValue += 2;
        else
            randomValue++;
        //printf("Random Value: %d\n", randomValue);
        Game.handCount[player] = rand() % MAX_HAND + 3;

        slot1 = rand() % Game.deckCount[player];
        //printf("7.\n");
        slot2 = slot1;

        while (slot2 == slot1)
            slot2 = rand() % Game.deckCount[player];

        Game.deck[player][slot1] = randomTreasure1;
        Game.deck[player][slot2] = randomTreasure2;
        

        //now we just play the adventurer card and make sure that it adds the correct value;

        cardEffect(adventurer, 0, 0, 0, &Game, 0, 0);

        int finalVal = 0;
        finalHand = Game.handCount[player];

        for (i = 0; i < finalHand; i++)
        {
            int handCard = Game.hand[player][i];

            if (handCard == gold)
                finalVal += 3;
            else if (handCard == silver)
                finalVal += 2;
            else if (handCard == copper)
                finalVal++;
            else{
                continue;
            }
        }
        //printf("Final Value: %d\n", finalVal);
        if (finalVal != randomValue){
            //printf("failed.\n");
            failed++;
        }
            

        testCount++;
    }

    printf("Num failed: %d\n", failed);

    return 0;
}

