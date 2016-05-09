/*
 * Carolyn Cheung
 * Testing: Adventurer
 *      Action: Reveal cards from deck until 2 treasure cards, put
 *              those treasure cards into your and and discard the
 *              rest of the revealed cards
 *              Only get 1 treasure card if only 1 is in the deck
 *      cost: 6 coins
 * +0-2 treasure cards
 * +? to discard
 * no change to other player hands
 */

#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTCARD "adventurer"

int MAX_TESTS = 2000;

int randomTestAdventurer (int p, struct gameState *post) {
    struct gameState Gtest;
    memcpy(&Gtest, post, sizeof(struct gameState));
    int r, i, a, b;
    int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, handPos = 0;
    int numPlayers = post->numPlayers;
    int treasures = 0, treasures_post = 0, card;
    int hand1 = 0, hand2 = 0;
    int pass = 1;

// count current number of treasures on Gtest
    for(i = 0; i < Gtest.deckCount[p]; i++) {
        card = Gtest.deck[p][i];
        if (card == copper || card == silver || card == gold) {
            treasures++;
            if (i == 0) {
                hand1++;
            }
            if (i == 1) {
                hand2++;
            }
        }
    }

    r = cardEffect(adventurer, choice1, choice2, choice3, post, bonus, &handPos);

// count number of treasures again after calling function, expected 2 removed
    for(i = 0; i < post->deckCount[p]; i++) {
        card = post->deck[p][i];
        if (card == copper || card == silver || card == gold) {
            treasures_post++;
        }
    }

// if there was only 1 treasure, then only take 1
    if (treasures == 1) {
        treasures--;
    } else  if (treasures > 0) {
        treasures -= 2;
    }

// check if the correct amount of treasures was removed from the deck
    if (treasures != treasures_post) {
            printf("FAILED: CURRENT PLAYER DID NOT REMOVE TREASURES FROM DECK\n");
            printf("    EXPECTED = %d, REAL = %d\n", treasures_post, treasures);
            pass--;
    }

// check hand count to see if it was not added
    if (Gtest.handCount[p] == post->handCount[p] && treasures > 0){
        printf("FAILED: CURRENT PLAYER DID NOT INCREASE HANDCOUNT\n");
        pass--;
    }

// check other players to see if their hands have changed
    for (i = 0; i < numPlayers; i++) {
        if (i != p) {
            a = Gtest.handCount[i];
            b = post->handCount[i];
            if (a != b) {
                printf("FAILED PLAYER %d HANDCOUNT: EXPECTED = %d, REAL = %d\n", i, a, b);
                pass--;
            }
            a = Gtest.deckCount[i];
            b = post->deckCount[i];
            if (a != b) {
                printf("FAILED PLAYER %d DECKCOUNT: EXPECTED = %d, REAL = %d\n", i, a, b);
                pass--;
            }
        }
    }

// check to see if the discard pile has changed.
// accounts for instances where hand1 and hand2 were treasure cards,
// eliminating the need to discard anything
    if (Gtest.discardCount[p] == post->discardCount[p] && hand1 == 1 && hand2 == 1){
        printf("FAILED: CURRENT PLAYER DID NOT DISCARD ANY CARDS\n");
        printf("    PRE = %d, POST = %d, TREASURES GAINED = %d\n", Gtest.discardCount[p], post->discardCount[p], treasures);
        printf("    DECK[0] WAS TREASURE = %d, DECK[1] WAS TREASURE = %d", hand1, hand2);
        pass--;
    }

    return pass;
//  assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);
}


int main()
{
    srand(time(NULL));
    int seed;

    int i, n, r, p, decCount, discardCount, handCount, numPlayers;
    int a, b, handPos = 0, pass = 0;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};
    struct gameState G;
    struct gameState Gtest;

    printf("==== TESTING: %s ====\n", TESTCARD);
    printf(" RANDOM TESTS: %d\n\n", MAX_TESTS);
    printf("    - correct amount of treasures was removed from the deck\n");
    printf("    - correct amount of treasures was added to the hand\n");
    printf("    - check other players to see if their hands have changed\n");
    printf("    - check discard piles have changed\n\n");

    for (n = 0; n < MAX_TESTS; n++) {
        seed = rand() % 100 + 1;
        numPlayers = rand() %(MAX_PLAYERS - 1) + 2;
        initializeGame(numPlayers, k, seed, &G);

        p = floor(Random() * numPlayers);

        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        G.whoseTurn = p;

        pass += randomTestAdventurer(p, &G);
    }
    printf("===========================\n");
    if (pass == MAX_TESTS)
        printf(" RANDOM TESTS PASSED\n");
    else
        printf(" RANDOM TESTS HAS FAILED\n");
    printf("===========================\n");

    return 0;
}
