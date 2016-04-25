#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"

#include "dominion.h"
#include "rngs.h"

int checkDeck(struct gameState* goalState, struct gameState* testState){

   int goalCount[treasure_map+1];
   memset(&goalCount, 0, (treasure_map+1) * sizeof(int));
   int testCount[treasure_map+1];
   memset(&testCount, 0, (treasure_map+1) * sizeof(int));

   int i, j;
   for(i = 0; i < testState->numPlayers; i++){
      for(j = 0; j < testState->deckCount[i]; j++){
	 testCount[testState->deck[i][j]]++;
	 goalCount[goalState->deck[i][j]]++;
      }
   }
   
   for(i = 0; i < treasure_map+1; i++){
      if(testCount[i] != goalCount[i]){return -1;}
   }
   return 0;
}

int* getDeckCount(int player, struct gameState* state){

   int* deckCount = (int*)(malloc((treasure_map+1) * sizeof(int)));
   memset(deckCount, 0, (treasure_map+1) * sizeof(int));

   int i;
   for(i = 0; i < state->deckCount[player]; i++){
      deckCount[state->deck[player][i]]++;
   }
   for(i = 0; i < state->handCount[player]; i++){
      deckCount[state->hand[player][i]]++;
   }
   for(i = 0; i < state->discardCount[player]; i++){
      deckCount[state->discard[player][i]]++;
   }

   return deckCount;
} 


int checkHand(struct gameState* goalState, struct gameState* testState){

   int goalCount[treasure_map+1];
   memset(&goalCount, 0, (treasure_map+1) * sizeof(int));
   int testCount[treasure_map+1];
   memset(&testCount, 0, (treasure_map+1) * sizeof(int));

   int i, j;
   for(i = 0; i < testState->numPlayers; i++){
      for(j = 0; j < testState->handCount[i]; j++){
	 testCount[testState->hand[i][j]]++;
	 goalCount[goalState->hand[i][j]]++;
      }
   }
   
   for(i = 0; i < treasure_map+1; i++){
      if(testCount[i] != goalCount[i]){return -1;}
   }
   return 0;
}

int checkDiscard(struct gameState* goalState, struct gameState* testState){

   int goalCount[treasure_map+1];
   memset(&goalCount, 0, (treasure_map+1) * sizeof(int));
   int testCount[treasure_map+1];
   memset(&testCount, 0, (treasure_map+1) * sizeof(int));

   int i, j;
   for(i = 0; i < testState->numPlayers; i++){
      for(j = 0; j < testState->discardCount[i]; j++){
	 testCount[testState->discard[i][j]]++;
	 goalCount[goalState->discard[i][j]]++;
      }
   }
   
   for(i = 0; i < treasure_map+1; i++){
      if(testCount[i] != goalCount[i]){return -1;}
   }
   return 0;
}

int checkDeckCount(struct gameState* goalState, struct gameState* testState){
   int i;
   for(i = 0; i < testState->numPlayers; i++){
      if(goalState->deckCount[i] != testState->deckCount[i]){
	 return -1;
      }
   }
   return 0;
}

int checkDiscardCount(struct gameState* goalState, struct gameState* testState){
   int i;
   for(i = 0; i < testState->numPlayers; i++){
      if(goalState->discardCount[i] != testState->discardCount[i]){
	 return -1;
      }
   }
   return 0;
}

int checkState(struct gameState* goalState, struct gameState* testState){   

   int i, j;

   if(goalState->numPlayers != testState->numPlayers)		  {return -1;}	 //numPlayers
   for(i = 0; i < treasure_map+1; i++){
   if(goalState->supplyCount[i] != testState->supplyCount[i])	  {return -2;}	 //supplyCount
   }
   for(i = 0; i < treasure_map+1; i++){
   if(goalState->embargoTokens[i] != testState->embargoTokens[i]) {return -3;}	 //embargoTokens
   }
   if(goalState->outpostPlayed != testState->outpostPlayed)	  {return -4;}	 //outpostPlayed
   if(goalState->outpostTurn != testState->outpostTurn)		  {return -5;}	 //outpostTurn
   if(goalState->whoseTurn != testState->whoseTurn)		  {return -6;}	 //whoseTurn
   if(goalState->phase != testState->phase)			  {return -7;}	 //phase
   if(goalState->numActions != testState->numActions)		  {return -8;}	 //numActions
      
   if(goalState->coins != testState->coins)			  {return -9;}	 //coins
   if(goalState->numBuys != testState->numBuys)			  {return -10;}	 //numBuys
   for(i = 0; i < MAX_PLAYERS; i++){
      for(j = 0; j < MAX_HAND; j++){ 
      if(goalState->hand[i][j] != testState->hand[i][j])	  {return -11;}	 //hand
      }
   }
   for(i = 0; i < MAX_PLAYERS; i++){
   if(goalState->handCount[i] != testState->handCount[i])	  {return -12;}	 //handCount
   }
   for(i = 0; i < MAX_PLAYERS; i++){
      for(j = 0; j < MAX_DECK; j++){ 
      if(goalState->discard[i][j] != testState->discard[i][j])	  {return -13;}	 //discard
      }
   }
   for(i = 0; i < MAX_PLAYERS; i++){
   if(goalState->discardCount[i] != testState->discardCount[i])	  {return -14;}	 //discardCount
   }
   for(i = 0; i < MAX_DECK; i++){
   if(goalState->playedCards[i] != testState->playedCards[i])	  {return -15;}	 //playedCards
   }
   if(goalState->playedCardCount != testState->playedCardCount)	  {return -16;}	 //playedCardCount
   for(i = 0; i < MAX_PLAYERS; i++){
   if(goalState->deckCount[i] != testState->deckCount[i])	  {return -17;}	 //deckCount
   }

   for(i = 0; i < MAX_PLAYERS; i++){
      for(j = 0; j < MAX_DECK; j++){ 
      if(goalState->deck[i][j] != testState->deck[i][j])	  {return -18;}	 //deck
      }
   }
  
   return 0;
}

int checkGameOver(struct gameState* state){
   if(state->supplyCount[province] == 0){
      return 1;
   }

   int i, count=0;
   for(i = 0; i < treasure_map+1; i++){
      if(!state->supplyCount[i]){
	 count++;
      }
      if(count > 2){
	 return 1;
      }
   } 
   return 0;
}

void setupRandomTestState(int numPlayers, struct gameState* state){
   int i, j;

   state->numPlayers = numPlayers;
   for(i = 0; i < treasure_map+1; i++){
      state->supplyCount[i] = rand() % MAX_DECK;
   }
   for(i = 0; i < treasure_map+1; i++){
      state->embargoTokens[i] = rand() % MAX_DECK;
   }
   state->outpostPlayed = rand() % 2;
   state->outpostTurn = rand() % 2;
   state->whoseTurn = rand() % numPlayers;
   state->phase = rand() % 2;
   state->numActions = rand();
   state->coins = rand();
   state->numBuys = rand();
   for(i = 0; i < numPlayers; i++){
      int randHandSize = rand() % MAX_HAND;
      state->handCount[i] = randHandSize;
      for(j = 0; j < randHandSize; j++){
	 state->hand[i][j] = rand() % (treasure_map+1);
      }
      int randDeckSize = (rand() % (MAX_DECK - 1)) + 1;
      state->deckCount[i] = randDeckSize;
      for(j = 0; j < randDeckSize; j++){
	 state->deck[i][j] = rand() % (treasure_map+1);
      }
      int randDiscSize = rand() % MAX_DECK;
      state->discardCount[i] = randDiscSize;
      for(j = 0; j < randDiscSize; j++){
	 state->discard[i][j] = rand() % (treasure_map+1);
      }
      int randPlayedSize = rand() % MAX_DECK;
      state->playedCardCount = randPlayedSize;
      for(j = 0; j < randPlayedSize; j++){
	 state->playedCards[j] = rand() % (treasure_map+1);
      }

   }
   
}

