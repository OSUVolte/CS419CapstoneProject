//unittest4

//Unit test for fullDeckCount()


#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main () {

  int r;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState *G = newGame();
 
  initializeGame(2, k, 1, G);
  
  int allCards[27] = {curse,  estate, duchy, province, copper, silver, gold, adventurer, council_room, 
                      feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, 
                      steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
  int numCards = 27;

  
  
  printf ("\n--------Test 1: Newly Initialized Game, Check for Every Card---------\n\n");
  
  initializeGame(2, k, 1, G);
  int count = 0;
  
  for(int i = 0; i < numCards; i++){
      count += fullDeckCount(1, allCards[i], G);
  }
  
  if(count != 10){                              //Game is initialized with 10 cards in the player's deck
     printf("Failed\n");
  }
  else printf("Passed\n");
 
   printf ("\n--------Test 2: One of the desired card in the Deck, the Hand, and the Discard ---------\n\n");
  
  initializeGame(2, k, 1, G);
  
  G->deckCount[1] = 1;
  G->deck[1][0] = gold;
  G->handCount[1] = 1;
  G->hand[1][0] = gold;
  G->discardCount[1] = 1;
  G->discard[1][0] = gold;
  
  if(fullDeckCount(1, gold, G) == 3){
	  printf("Passed\n");
  }
  else{
	  printf("Failed\n");
  }
  
  
  printf ("\n--------Test 3: One of the desired cards in the hand but not the others ---------\n\n");
  
  initializeGame(2, k, 1, G);
  
  G->deckCount[1] = 1;
  G->deck[1][0] = silver;
  G->handCount[1] = 1;
  G->hand[1][0] = gold;
  G->discardCount[1] = 1;
  G->discard[1][0] = silver;
  
  if(fullDeckCount(1, gold, G) == 1){
	  printf("Passed\n");
  }
  else{
	  printf("Failed\n");
  }
 
  printf ("\n--------Test 4: One of the desired cards in the discard but not the others ---------\n\n");
  
  initializeGame(2, k, 1, G);
  
  G->deckCount[1] = 1;
  G->deck[1][0] = silver;
  G->handCount[1] = 1;
  G->hand[1][0] = silver;
  G->discardCount[1] = 1;
  G->discard[1][0] = gold;
  
  if(fullDeckCount(1, gold, G) == 1){
	  printf("Passed\n");
  }
  else{
	  printf("Failed\n");
  }
  
    printf ("\n--------Test 4: One of the desired cards in the deck but not the others ---------\n\n");
  
  initializeGame(2, k, 1, G);
  
  G->deckCount[1] = 1;
  G->deck[1][0] = gold;
  G->handCount[1] = 1;
  G->hand[1][0] = silver;
  G->discardCount[1] = 1;
  G->discard[1][0] = silver;
  
  if(fullDeckCount(1, gold, G) == 1){
	  printf("Passed\n");
  }
  else{
	  printf("Failed\n");
  }
}
 
  
  
