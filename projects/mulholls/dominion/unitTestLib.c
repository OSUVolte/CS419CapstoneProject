#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "limits.h"

#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestLib.h"
#include "rngs.h"

int checkDeck(struct gameState* state, struct gameState* cpy){

	int i, j;
	int sCards[treasure_map+1];
	memset(sCards, 0, (treasure_map+1)*sizeof(int));
	int dCards[treasure_map+1];
	memset(dCards, 0, (treasure_map+1)*sizeof(int));

	for(i = 0; i < cpy->numPlayers; i++){
		for(j = 0; j < MAX_DECK; j++){
			sCards[state->deck[i][j]]++;
			dCards[cpy->deck[i][j]]++;
		}
	}

	for(i = 0; i < treasure_map+1; i++){
		if(sCards[i] != dCards[i]) return -1;
	}
	return 0;
}

int checkDeckCount(struct gameState* state, struct gameState* cpy){
	int i;
	for(i = 0; i < MAX_DECK; i++){
		if(state->deckCount[i] != cpy->deckCount[i]) return -1;
	}
	return 0;
}


int checkDiscard(struct gameState* state, struct gameState* cpy){
	int i, j;
	for(i = 0; i < cpy->numPlayers; i++){
		for(j = 0; j < MAX_DECK; j++){
			if(state->discard[i][j] != cpy->discard[i][j]) return -1;
		}
	}
	return 0;
}

int checkDiscardCount(struct gameState* state, struct gameState* cpy){
	int i;
	for(i = 0; i < MAX_DECK; i++){
		if(state->discardCount[i] != cpy->discardCount[i]) return -1;
	}
	return 0;
}

int checkState(struct gameState* state, struct gameState* cpy){

	int i, j;

	if(state->numPlayers != cpy->numPlayers) return -1; //number of players
	for(i = 0; i < treasure_map+1; i++){
		if(state->supplyCount[i] != cpy->supplyCount[i]) return -2;
	}
	for(i = 0; i < treasure_map+1; i++){
		if(state->embargoTokens[i] != cpy->embargoTokens[i]) return -3;
	}

	if(state->outpostPlayed != cpy->outpostPlayed) return -4;
	if(state->outpostTurn != cpy->outpostTurn) return -5;
	if(state->whoseTurn != cpy->whoseTurn) return -6;
	if(state->phase != cpy->phase) return -7;
	if(state->numActions != cpy->numActions) return -8; /* Starts at 1 each turn */
	if(state->numBuys != cpy->numBuys) return -9; /* Starts at 1 each turn */
	if(state->coins != cpy->coins) return -10; /* Use as you see fit! */
	for(i = 0; i < cpy->numPlayers; i++){
		for(j = 0; j < MAX_HAND; j++){
			if(state->hand[i][j] != cpy->hand[i][j]) return -11;
		}
	}
	for(i = 0; i < cpy->numPlayers; i++){
		if(state->handCount[i] != cpy->handCount[i]) return -12;
	}
	for(i = 0; i < cpy->numPlayers; i++){
		for(j = 0; j < MAX_DECK; j++){
			if(state->discard[i][j] != cpy->discard[i][j]) return -13;
		}
	}
	for(i = 0; i < cpy->numPlayers; i++){
		if(state->discardCount[i] != cpy->discardCount[i]) return -14;
	}
	for(i = 0; i < MAX_DECK; i++){
		if(state->playedCards[i] != cpy->playedCards[i]) return -15;
	}

	if(state->playedCardCount != cpy->playedCardCount) return -16;

	for(i = 0; i < cpy->numPlayers; i++){
		if(state->deckCount[i] != cpy->deckCount[i]) return -17;
	}
	for(i = 0; i < cpy->numPlayers; i++){
		for(j = 0; j < MAX_DECK; j++){
			if(state->deck[i][j] != cpy->deck[i][j]) return -18;
		}
	}
	return 0;
}

void setupRandomTestState(int numPlayers, struct gameState* state){
	int i, j;
	state->numPlayers = numPlayers; //number of players
	for(i = 0; i < treasure_map+1; i++){
		state->supplyCount[i] = rand() % MAX_DECK;  //this is the amount of a specific type of card given a specific number.
		state->embargoTokens[i] = rand() % MAX_DECK;
	}
	state->outpostPlayed = rand() % 2;
	state->outpostTurn = rand() % 2;
	state->whoseTurn = rand() % numPlayers;
	state->phase = rand() % 2;
	state->numActions = rand()% 5 + 1;
	state->coins = rand() % 5;
	state->numBuys = rand() % 5; // Starts at 1 each turn 
	for(i = 0; i < numPlayers; i++){
		state->handCount[i] = rand() % MAX_HAND;
		state->deckCount[i] = rand() % MAX_DECK;
		state->discardCount[i] = rand() % MAX_DECK;
		for(j = 0; j < state->handCount[i]; j++){
			state->hand[i][j] = rand() % (treasure_map+1);
		}
		for(j = 0; j < state->deckCount[i]; j++){
			state->deck[i][j] = rand() % (treasure_map+1);
		}
		for(j = 0; j < state->discardCount[i]; j++){
			state->discard[i][j] = rand() % (treasure_map+1);
		}
	}
	state->playedCardCount = rand() % MAX_DECK;
	for(i = 0; i < state->playedCardCount; i++){
		state->playedCards[i] = rand() % (treasure_map+1);
	}
	return;
}

int* getDeckCount(int player, struct gameState* state){
	int* dC = (int*)(malloc((treasure_map+1)*sizeof(int)));
	memset(dC, 0, (treasure_map+1)*sizeof(int));

	int i;
	for(i = 0; i < state->handCount[player]; i++){
		dC[state->hand[player][i]]++;
	}
	for(i = 0; i < state->deckCount[player]; i++){
		dC[state->deck[player][i]]++;
	}

	for(i = 0; i < state->discardCount[player]; i++){
		dC[state->discard[player][i]]++;
	}

	return dC;
}

void setupRandomTestState2(struct gameState* state){

   memset(state, 0, sizeof(struct gameState));

   int i, j;

   //At least 2 player, but <= MAX_PLAYERS
   state->numPlayers = (int)((MAX_PLAYERS-1) * Random())+2;

   //Picks supply types in random game
   int supplyTypes[treasure_map+1];
   memset(supplyTypes, 0, (treasure_map+1)*sizeof(int));
   int numSupplyTypes = 0;

   //Select 10 supply types
   while(numSupplyTypes < 10){
      int card = (int)((treasure_map+1) * Random());
      if(supplyTypes[card] == 0 
		   && card != curse
		   && card != estate
		   && card != duchy
		   && card != province
		   && card != copper
		   && card != silver
		   && card != gold){
	 supplyTypes[card] = 1;
	 numSupplyTypes++;
      }
   }
   
   //Between 0 and (numPlayers-1)*10 curse cards
   state->supplyCount[curse] = (int)(((state->numPlayers-1)*10) * Random());
 
   //If 3/4 players 12 victory cards each 
   if(state->numPlayers > 2){ 
      //Between 0 and 12 estate
      state->supplyCount[estate] = (int)((12) * Random());
      //Between 0 and 12 duchy
      state->supplyCount[duchy] = (int)((12) * Random());
      //Between 0 and 12 province
      state->supplyCount[province] = (int)((12) * Random());
   //If 2 players 8 victory cards each
   } else {
      //Between 0 and 8 estate
      state->supplyCount[estate] = (int)((8) * Random());
      //Between 0 and 8 duchy
      state->supplyCount[duchy] = (int)((8) * Random());
      //Between 0 and 8 province
      state->supplyCount[province] = (int)((8) * Random());
   }

   //Between 0 and 60 copper
   state->supplyCount[copper] = (int)((60) * Random());
   //Between 0 and 40 silver
   state->supplyCount[silver] = (int)((40) * Random());
   //Between 0 and 30 gold
   state->supplyCount[gold] = (int)((30) * Random());

   //Set each supply type selected to a count of 10
   for(i = gold+1; i < treasure_map+1; i++){
      if(supplyTypes[i]){
	  state->supplyCount[i] = 10;  //this is the amount of a specific type of card given a specific number.
      }
      state->embargoTokens[i] = rand() % MAX_DECK;
   }

   //Setting doesn't really matter
   state->outpostPlayed = (int)(2 * Random());
   state->outpostTurn = (int)(2 * Random());
   state->whoseTurn = (int)(state->numPlayers * Random());
   state->phase = (int)(2 * Random());
   state->numActions = (int)(INT_MAX * Random());
   state->coins = (int)(INT_MAX * Random());
   state->numBuys = (int)(INT_MAX * Random()) + 1;

   for(i = 0; i < state->numPlayers; i++){

      //Initializes Hand, discard, and deck to all -1
      for(j = 0; j < MAX_HAND; j++){
	 state->hand[i][j] = -1;
      }
      for(j = 0; j < MAX_DECK; j++){
	 state->discard[i][j] = -1;
	 state->deck[i][j] = -1;
      }

 
      //Ensure total card count for player i is less than the MAX_DECK/numPlayers
      state->deckCount[i] = (int)(MAX_DECK/state->numPlayers * Random()); //Between 0 and MAX_DECK/numPlayers cards in deck
      state->discardCount[i] = (int)((MAX_DECK/state->numPlayers - state->deckCount[i]) * Random()); //Between 0 and MAX_DECK/numPlayers - deckCount cards in discard
      state->handCount[i] = (int)((MAX_HAND/state->numPlayers - state->discardCount[i]) * Random()); //Between 0 and MAX_HAND/numPlayers - discardCount - deckCount cards in hand

      int cardCount = state->deckCount[i] + state->discardCount[i] + state->handCount[i];
      int copperSpot = 0;
      int numCoppers = 1;

      for(j = 0; j < state->handCount[i]; j++){
	    if(++copperSpot == numCoppers * cardCount / 7){
	       state->hand[i][j] = copper;
	       numCoppers++;
	    } else {
	       state->hand[i][j] = (int)((treasure_map+1)*Random());
	    }
      }
      for(j = 0; j < state->deckCount[i]; j++){
	    if(++copperSpot == numCoppers * cardCount / 7){
	       state->deck[i][j] = copper;
	       numCoppers++;
	    } else {
	       state->deck[i][j] = (int)((treasure_map+1)*Random());
	    }
      }
      for(j = 0; j < state->discardCount[i]; j++){
	    if(++copperSpot == numCoppers * cardCount / 7){
	       state->discard[i][j] = copper;
	       numCoppers++;
	    } else {
	       state->discard[i][j] = (int)((treasure_map+1)*Random());
	    }
      }
   }
   state->playedCardCount = (int)(MAX_DECK * Random());
   for(i = 0; i < state->playedCardCount; i++){
	  state->playedCards[i] = (int)((treasure_map+1)*Random());
   }

   return;
}

int checkGameOver(struct gameState* state){

	if(!state->supplyCount[province]){
		return 1;
	}
	int i, count = 0;
	for(i = 0; i < treasure_map+1; i++){
		if(state->supplyCount[i] == 0) count++;
		if(count >= 3) return 1;
	}

	return 0;
}

void printGameState(int p, struct gameState* before, struct gameState* after){

   int i, j;

   printf("\t\tcol 1 = before, col2 = after\n");
   printf("numPlayers: \t\t%i, %i\n", before->numPlayers, after->numPlayers);
   for(j = 0; j < treasure_map+1; j++){
      printf("supplyCount[%i]: \t\t%i, %i\n", j, before->supplyCount[j], after->supplyCount[j]);
   }

   printf("outpostPlayed: \t\t%i, %i\n", before->outpostPlayed, after->outpostPlayed);
   printf("outpostTurn: \t\t%i, %i\n", before->outpostTurn, after->outpostTurn);
   printf("whoseTurn: \t\t%i, %i\n", before->whoseTurn, after->whoseTurn);
   printf("phase: \t\t\t%i, %i\n", before->phase, after->phase);
   printf("numActions: \t\t%i, %i\n", before->numActions, after->numActions);
   printf("coins: \t\t\t%i, %i\n", before->coins, after->coins);
   printf("numBuys: \t\t%i, %i\n", before->numBuys, after->numBuys);
   printf("handCount[%i]: \t\t%i, %i\n",p, before->handCount[p], after->handCount[p]);
   printf("deckCount[%i]: \t\t%i, %i\n",p, before->deckCount[p], after->deckCount[p]);
   printf("discardCount[%i]: \t%i, %i\n",p, before->discardCount[p], after->discardCount[p]);
   for(j = 0; j < before->handCount[p]; j++){
      printf("hand[%i][%i]: \t\t%i, %i\n",p, j, before->hand[p][j], after->hand[p][j]);
   }
   for(j = 0; j < before->deckCount[p]; j++){
      printf("deck[%i][%i]: \t\t%i, %i\n",p, j, before->deck[p][j], after->deck[p][j]);
   }
   for(j = 0; j < before->discardCount[p]; j++){
      printf("discard[%i][%i]: \t\t%i, %i\n",p, j, before->discard[p][j], after->discard[p][j]);
   }
   printf("playedCardCount: \t\t%i, %i\n", before->playedCardCount, after->playedCardCount);
   
   for(i = 0; i < before->playedCardCount; i++){
      printf("playedCards[%i]: \t%i, %i\n", i, before->playedCards[i], after->playedCards[i]);
   }
   return;
}


void printGameStateDifferences(int p, struct gameState* before, struct gameState* after){

   int i, j;

   printf("\t\tcol 1 = before, col2 = after\n");
   if(before->numPlayers != after->numPlayers)
      printf("numPlayers: \t\t%i, %i\n", before->numPlayers, after->numPlayers);
   if(before->outpostPlayed != after->outpostPlayed)
      printf("outpostPlayed: \t\t%i, %i\n", before->outpostPlayed, after->outpostPlayed);
   if(before->outpostTurn != after->outpostTurn)
      printf("outpostTurn: \t\t%i, %i\n", before->outpostTurn, after->outpostTurn);
   if(before->whoseTurn != after->whoseTurn)
      printf("whoseTurn: \t\t%i, %i\n", before->whoseTurn, after->whoseTurn);
   if(before->phase != after->phase)
      printf("phase: \t\t\t%i, %i\n", before->phase, after->phase);
   if(before->numActions != after->numActions)
      printf("numActions: \t\t%i, %i\n", before->numActions, after->numActions);
   if(before->coins != after->coins)
      printf("coins: \t\t\t%i, %i\n", before->coins, after->coins);
   if(before->numBuys != after->numBuys)
      printf("numBuys: \t\t%i, %i\n", before->numBuys, after->numBuys);
   if(before->handCount[p] != after->handCount[p])
      printf("handCount[%i]: \t\t%i, %i\n",p, before->handCount[p], after->handCount[p]);
   if(before->deckCount[p] != after->deckCount[p])
      printf("deckCount[%i]: \t\t%i, %i\n",p, before->deckCount[p], after->deckCount[p]);
   if(before->discardCount[p] != after->discardCount[p])
      printf("discardCount[%i]: \t%i, %i\n",p, before->discardCount[p], after->discardCount[p]);
   for(j = 0; j < before->handCount[p]; j++){
      if(before->hand[p][j] != after->hand[p][j])
      printf("hand[%i][%i]: \t\t%i, %i\n",p, j, before->hand[p][j], after->hand[p][j]);
   }
   for(j = 0; j < before->deckCount[p]; j++){
      if(before->deck[p][j] != after->deck[p][j])
      printf("deck[%i][%i]: \t\t%i, %i\n",p, j, before->deck[p][j], after->deck[p][j]);
   }
   for(j = 0; j < before->discardCount[p]; j++){
      if(before->discard[p][j] != after->discard[p][j])
      printf("discard[%i][%i]: \t\t%i, %i\n",p, j, before->discard[p][j], after->discard[p][j]);
   }
   if(before->playedCardCount != after->playedCardCount)
      printf("playedCardCount: \t\t%i, %i\n", before->playedCardCount, after->playedCardCount);
   
   for(i = 0; i < before->playedCardCount; i++){
      if(before->playedCards[i] != after->playedCards[i])
         printf("playedCards[%i]: \t%i, %i\n", i, before->playedCards[i], after->playedCards[i]);
   }
   return;
}

