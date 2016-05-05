/*
	Andriy Solovyov
	CS-362
	Assignment 3
        unittest1.c
        using testUpdateCoins.c
*/

int main() {
    int i;
    int player=1;
    int score;
    int seed = 1000;
    struct gameState originalG, testingG;
    int maxHandCount = 5;
    int successFlag = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

   
    initializeGame(player, k, seed, &originalG);

    memcpy(&testingG, &originalG, sizeof(struct gameState));

    // here we combining negative and positive numbers to get a score
    testingG.hand[player][0] = adventurer; 
    testingG.hand[player][1] = estate;
    testingG.hand[player][2] = estate; 
    testingG.hand[player][3] = curse; 
    testingG.hand[player][4] = estate; 

    testingG.deck[player][0] = adventurer;
    testingG.deck[player][1] = adventurer;
    testingG.deck[player][2] = estate; 
    testingG.deck[player][3] = estate; 
    testingG.deck[player][4] = curse; 

    testingG.discard[player][0] = province;
    testingG.discard[player][1] = curse; 
    testingG.discard[player][2] = curse; 
    testingG.discard[player][3] = province; 
    testingG.discard[player][4] = estate;

   

    testingG.handCount[player] = maxHandCount;
    testingG.discardCount[player] = maxHandCount;
    testingG.deckCount[player] = maxHandCount;
    score = scoreFor(player, &testingG);

    printf("End score: %d. Expected value: 12. \n", score);
    if (score == 10) {
      printf ("Passed.\n");
      successFlag += 1;
    } 
    else {
      printf ("Failed.\n");
    }

   
  return 0;

}

