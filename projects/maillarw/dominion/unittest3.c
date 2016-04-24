//unittest3

//Unit tests of the scoreFor() functions.
//Upon new game there is a deck count of 10!!!!
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>


int main () {

  printf ("\n************************    Unit Test 3: Testing scoreFor()     **********************\n\n");

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
  int allCards[27] = {curse,  estate, duchy, province, copper, silver, gold, adventurer, council_room, 
                      feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, 
                      steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
  int numCards =  27;

  struct gameState *G = newGame();
 
  initializeGame(2, k, 1, G);

  
  printf ("\n--------Test 1: Empty Deck, Hand, and Discard---------\n\n");
  
  initializeGame(2, k, 1, G);
  G->deckCount[1] = 0;
  G->deckCount[1] = 0;
  for(int i = 0; i < 10; i++){
    G->deck[1][i] = -9999; //set every card in deck to meaningless value
  }  
  
  if(scoreFor(1, G) == 0){
	  printf("Passed\n");
  }
  else{
	  printf("Failed\n");
    printf("Count is %d but should be 0\n", scoreFor(1, G));
  }
  
   printf ("\n--------Test 2: Hand that has one of every card, empty deck ---------\n\n");
  
  initializeGame(2, k, 1, G);
  G->deckCount[1] = 0;
  for(int i = 0; i < 10; i++){
    G->deck[1][i] = -9999; //set every card in deck to meaningless value
  }  
  
  G->handCount[1] = numCards;
  for(int i = 0; i < numCards; i++){
	  G->hand[1][i] = allCards[i];
  }
   
  if(scoreFor(1, G) == 11){
	  printf("Passed\n");
  }
  else{
	  printf("Failed\n");
    printf("Count is %d but should be 11\n", scoreFor(1, G));
  }
  
  printf ("\n--------Test 3: Discard that has one of every card, empty deck ---------\n\n");
  
  initializeGame(2, k, 1, G);
  G->deckCount[1] = 0;
  for(int i = 0; i < 10; i++){
    G->deck[1][i] = -9999; //set every card in deck to meaningless value
  }
  
  
  G->discardCount[1] = numCards;
  for(int i = 0; i < numCards; i++){
	  G->discard[1][i] = allCards[i];
  }
   
  if(scoreFor(1, G) == 11){
	  printf("Passed\n");
  }
  else{
	  printf("Failed\n");
    printf("Count is %d but should be 11\n", scoreFor(1, G));
  }
  
  
  
printf ("\n--------Test 4: Deck that has one of every card ---------\n\n");
  
  initializeGame(2, k, 1, G);
  
  G->deckCount[1] = numCards;
  for(int i = 0; i < numCards; i++){
	  G->deck[1][i] = allCards[i];
  }
   
  if(scoreFor(1, G) == 11){
	  printf("Passed\n");
  }
  else{
	  printf("Failed\n");
    printf("Count is %d but should be 11\n\n", scoreFor(1, G));
  }
  }
 
  
 
  
  
