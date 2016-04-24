#include "dominion.h" 
#include "dominion_helpers.h"  
#include <stdio.h> 
#include <stdlib.h>

//testing of getCost function

int main(){
    
    struct gameState T;
    int bad_k1[10] = {adventurer, bad, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    int bad_k2[10] = {adventurer, smithy, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    int good_k[10] = {gardens, adventurer, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    
    //Test against bad kingdom cards
    if(initializeGame(2, bad_k1, 5, *T) != -1)
        {printf("FAIL Did not catch bad kingdom card\n");}
 
    //Test against repeat kingdomCards
    if(initializeGame(2, bad_k2, 5, *T) != -1)
        {printf("FAIL Did not catch repeat kingdom card\n");}
    
    //Test against bad number of players
    if(initializeGame(-1, good_k, 5, *T) != -1)
        {printf("FAIL Did not catch invalid number of players\n");}
    
    //Initialize good game
    if(initializeGame(2, good_k, 5, *T) == -1)
        {printf("FAIL Returned -1 on correct input\n");}
 
 //check numplayers
 if(state->numPlayers != 2){
     printf("FAIL number of players does not equal 2\n");
 }

//check number of curse cards
 if(state->supplyCount[curse] != 10){
     printf("FAIL number of curse cards is incorrect\n");
 }

 //check number of Victory cards
  
  if(state->supplyCount[estate] != 8 ||
      state->supplyCount[duchy] != 8 ||
      state->supplyCount[province] != 8)
      {
          printf("FAIL number of Victory cards is incorrect\n");
      }
    
  //check number of Treasure cards
  if(state->supplyCount[copper] != 46 ||
  state->supplyCount[silver] != 40 ||
  state->supplyCount[gold] != 30){
      printf("FAIL number of Treasure cards is incorrect\n");
  }

  //set number of Kingdom cards
  if(state->supplyCount[gardens] != 8){
      printf("FAIL incorrect Victory card settings\n");
  }
  if(state->supplyCount[great_hall] != -1){
      printf("FAIL did not set unused card to -1\n");
  }
  if(state->supplyCount[adventurer] != 10 ||
  state->supplyCount[sea_hag] != 10){
      printf("FAIL did not correctly set supply counts\n");
  }

  //check each player has correct number of cards in deck
  if(state->deckCount[0] != 10 || state->deckCount[1] != 10){
      printf("FAIL incorrect number of cards in deck\n");
  }
}