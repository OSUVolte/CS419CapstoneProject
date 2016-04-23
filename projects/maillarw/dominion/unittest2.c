//unittest2
//Testing the isGameOver() function;
/*
From http://wiki.dominionstrategy.com/index.php/Gameplay, how does the game end:

Ending conditions

The game ends at the end of any player’s turn when any of these are true:
Any three Supply piles are empty (four Supply piles in a game of at least five players)
The Province Supply pile is empty
The Colony Supply pile is empty (if Colony was used)

*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main () {

  int r;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState *G = newGame();
 
  initializeGame(2, k, 1, G);

  int totalCoins = 0;

  printf ("\n--------Test 1: Newly Initialized Game---------\n\n");
  
  initializeGame(2, k, 1, G);
  if(isGameOver(G) == 0){
	  printf("Passed\n");
  }
  else{
	  printf("Failed\n");
  }
 
   printf ("\n--------Test 2: 3 Supply Stacks are Empty and 2 players---------\n\n");
  
  initializeGame(2, k, 1, G);
  G->supplyCount[0] = 0;
  G->supplyCount[1] = 0;
  G->supplyCount[2] = 0;
  
  if(isGameOver(G) == 0){
	  printf("Failed\n");
  }
  else{
	  printf("Passed\n");
  }
 
 printf ("\n--------Test 3: 3 Supply Stacks are Empty and 5 players---------\n\n");
  
  initializeGame(5, k, 1, G);
  G->supplyCount[0] = 0;
  G->supplyCount[1] = 0;
  G->supplyCount[2] = 0;
  
  if(isGameOver(G) == 0){
	  printf("Passed\n");
  }
  else{
	  printf("Failed\n");
  }
  
printf ("\n--------Test 4:  Stack of Province Cards is Empty---------\n\n");
  
  initializeGame(2, k, 1, G);
  G->supplyCount[province] = 0;
  
  if(isGameOver(G) != 0){
	  printf("Passed\n");
  }
  else{
	  printf("Failed\n");
  }
}
  
 
  
  
