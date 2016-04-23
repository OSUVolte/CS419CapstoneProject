#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>



int main () {

  int r;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};


  struct gameState G;

  int totalCoins = 0;

  
  
  printf ("\n--------Test 1: Zero Treasure Cards in Player's Hand---------\n\n");
  
  initializeGame(4, k, 1, &G);
  totalCoins = 0;
  updateCoins(1, &G, 0);
  
  if(G.coins == totalCoins){
	  printf("Passed\n");
  }
  else printf("Failed\n");

    
  printf ("\n--------Test 2: Full Hand of All Copper Cards---------\n\n");
  
  initializeGame(4, k, 1, &G);
  totalCoins = 0;
  
  for(int i = 0; i < 5; i++){
	  gainCard(copper, &G, 2, 1); 
	  totalCoins += 1;
  }
  
  updateCoins(1, &G, 0);
  
  if(G.coins == totalCoins){
	  printf("Passed\n");
  }
  else printf("Failed\n");
  
  printf ("\n--------Test 3: Full Hand of All Silver Cards---------\n\n");
  
  initializeGame(4, k, 1, &G);
  totalCoins = 0;
  
  for(int i = 0; i < 5; i++){
	  gainCard(silver, &G, 2, 1); 
	  totalCoins += 2;
  }
  
  updateCoins(1, &G, 0);
  
  if(G.coins == totalCoins){
	  printf("Passed\n");
  }
  else printf("Failed\n");
 
  printf ("\n--------Test 4: Full Hand of All Gold Cards---------\n\n");
  
  initializeGame(4, k, 1, &G);
  totalCoins = 0;
  
  for(int i = 0; i < 5; i++){
	  gainCard(gold, &G, 2, 1);
	  totalCoins += 3;
  }
  
  updateCoins(1, &G, 0);
  
  if(G.coins == totalCoins){
	  printf("Passed\n");
  }
  else printf("Failed\n");
  
 printf ("\n--------Test 5: Large Hand with 5 Copper, 5 Silver, and 5 Gold---------\n\n");
  
  initializeGame(4, k, 1, &G);
  totalCoins = 0;
  
  for(int i = 0; i < 5; i++){
	  gainCard(copper, &G, 2, 1);
	  totalCoins += 1;
  }
  
  for(int i = 0; i < 5; i++){
	  gainCard(silver, &G, 2, 1); 
	  totalCoins += 2;
  }
  for(int i = 0; i < 5; i++){
	  gainCard(gold, &G, 2, 1); 
	  totalCoins += 3;
  }
  
  updateCoins(1, &G, 0);
  
  if(G.coins == totalCoins){
	  printf("Passed\n");
  }
  else printf("Failed\n");
  
  printf ("\n--------Test 6: One Gold Card and a bonus of 1---------\n\n");
  
  initializeGame(4, k, 1, &G);
  totalCoins = 0;
  

	gainCard(gold, &G, 2, 1); 
	totalCoins += 3;

  
  updateCoins(1, &G, 1);
  totalCoins++;
  
  if(G.coins == totalCoins){
	  printf("Passed\n");
  }
  else printf("Failed\n");
  
  return 0;
}