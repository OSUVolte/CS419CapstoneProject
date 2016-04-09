#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};


  printf ("Starting game.\n");
  
  initializeGame(2, k, atoi(argv[1]), &G);
  
  int money = 0;
  int smithyPos = -1;
  int adventurerPos = -1;
  //new cards
  int cutpursePos = -1;
  int sea_hagPos = -1;
  int tributePos = -1;

  int i=0;

  int numSmithies = 0;
  int numAdventurers = 0;
  //new cards
  int numCutpurses = 0;
  int numSea_hags = 0;
  int numTributes = 0;

  while (!isGameOver(&G)) {
    money = 0;
    smithyPos = -1;
    adventurerPos = -1;
	//new cards
	cutpursePos = -1;
	sea_hagPos = -1;
	tributePos = -1;

    for (i = 0; i < numHandCards(&G); i++) {
      if (handCard(i, &G) == copper)
		money++;
      else if (handCard(i, &G) == silver)
		money += 2;
      else if (handCard(i, &G) == gold)
		money += 3;
      else if (handCard(i, &G) == smithy)
		smithyPos = i;
      else if (handCard(i, &G) == adventurer)
			adventurerPos = i;
	  else if (handCard(i, &G) == cutpurse)
		  cutpursePos = i;
	  else if (handCard(i, &G) == sea_hag)
		  sea_hagPos = i;
	  else if (handCard(i, &G) == tribute)
		  tributePos = i;
    }

    if (whoseTurn(&G) == 0) {
		//replace smithy with other card to try

      if (smithyPos != -1) {
        printf("0: smithy played from position %d\n", smithyPos); 
	playCard(smithyPos, -1, -1, -1, &G); 
	printf("smithy played.\n");
		/*if (cutpursePos != -1) {
			printf("0: cutpurse played from position %d\n", cutpursePos);
			playCard(cutpursePos, -1, -1, -1, &G);
			printf("cutpurse played.\n"); */
		/*if (sea_hagPos != -1) {
			printf("0: sea_hag played from position %d\n", sea_hagPos);
			playCard(sea_hagPos, -1, -1, -1, &G);
			printf("sea_hag played.\n");*/
		/*if (tributePos != -1) {
			printf("0: tribute played from position %d\n", tributePos);
			playCard(tributePos, -1, -1, -1, &G);
			printf("tribute played.\n");*/
			
	money = 0;
	i=0;
	while(i<numHandCards(&G)){
	  if (handCard(i, &G) == copper){
	    playCard(i, -1, -1, -1, &G);
	    money++;
	  }
	  else if (handCard(i, &G) == silver){
	    playCard(i, -1, -1, -1, &G);
	    money += 2;
	  }
	  else if (handCard(i, &G) == gold){
	    playCard(i, -1, -1, -1, &G);
	    money += 3;
	  }
	  i++;
	}
      }

      if (money >= 8) {
        printf("0: bought province\n"); 
        buyCard(province, &G);
      }
      else if (money >= 6) {
        printf("0: bought gold\n"); 
        buyCard(gold, &G);
      }

	  //replace smithy with other card to try

      else if ((money >= 4) && (numSmithies < 2)) {
        printf("0: bought smithy\n"); 
        buyCard(smithy, &G);
        numSmithies++;
      }
	  
	  /*else if (money >= 4) {
		  printf("0: bought cutpurse\n");
		  buyCard(cutpurse, &G);
		  numCutpurses++;
	  }
	  */
	  
	  /*else if (money >= 4) {
	  printf("0: bought sea_hag\n");
	  buyCard(sea_hag, &G);
	  numSea_hags++;
	  }*/

	  /*else if (money >= 5) {
	  printf("0: bought tribute\n");
	  buyCard(tribute, &G);
	  numTributes++;
	  }*/

	  

      else if (money >= 3) {
        printf("0: bought silver\n"); 
        buyCard(silver, &G);
      }

      printf("0: end turn\n");
      endTurn(&G);
    }
    else {
      if (adventurerPos != -1) {
        printf("1: adventurer played from position %d\n", adventurerPos);
	playCard(adventurerPos, -1, -1, -1, &G); 
	money = 0;
	i=0;
	while(i<numHandCards(&G)){
	  if (handCard(i, &G) == copper){
	    playCard(i, -1, -1, -1, &G);
	    money++;         
	  }
	  else if (handCard(i, &G) == silver){
	    playCard(i, -1, -1, -1, &G);
	    money += 2;
	  }
	  else if (handCard(i, &G) == gold){
	    playCard(i, -1, -1, -1, &G);
	    money += 3;
	  }
	  i++;
	}
      }

      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, &G);
      }
      else if ((money >= 6) && (numAdventurers < 2)) {
        printf("1: bought adventurer\n");
	buyCard(adventurer, &G);
	numAdventurers++;
      }else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, &G);
        }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, &G);
      }
      printf("1: endTurn\n");
      
      endTurn(&G);      
    }
  } // end of While

  printf ("Finished game.\n");
  printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, &G), scoreFor(1, &G));

  return 0;
}
