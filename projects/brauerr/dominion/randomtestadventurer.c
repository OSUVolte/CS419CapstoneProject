//randomtestadventurer.c
//for CS362
//random tester for the adventurer card 

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//returns true if card exists in kingdomCards array already
int cardIsChosen(int kingdomCards[10], int card) {
  int i = 0;
  for (i = 0; i < 10; i++) {
    if (kingdomCards[i] == card) return 1;
  }
  return 0;
}

int addCardToDeck(struct gameState *state, int player, int card, int numCopies) {
  int i;
  for (i = 0; i < numCopies; i++) {
    state->deck[player][state->deckCount[player]] = card;
    state->deckCount[player]++;
  }
}

int initializeRandomGame(struct gameState *state) {
  int numPlayers = 2;
  int kingdomCards[10];
  int i;
  int j;
  int it;	
  
  //set number of players
  state->numPlayers = numPlayers;
  
  //randomly select 8 kingdom cards (in addition to adventurer and smithy)
  
  kingdomCards[0] = smithy;
  kingdomCards[1] = adventurer;
  for (i = 2; i < 10; i++) {
    kingdomCards[i] = -1;
  }
  int card = 0;
  for (i = 2; i < 10; i++) {
    do {
      card = (rand() % 20) + 7;
    } while(cardIsChosen(kingdomCards, card));
    kingdomCards[i] = card;
  }
  
  //initialize supply
  ///////////////////////////////

  //set number of Curse cards
  if (numPlayers == 2)
    {
      state->supplyCount[curse] = 10;
    }
  else if (numPlayers == 3)
    {
      state->supplyCount[curse] = 20;
    }
  else
    {
      state->supplyCount[curse] = 30;
    }

  //set number of Victory cards
  if (numPlayers == 2)
    {
      state->supplyCount[estate] = 8;
      state->supplyCount[duchy] = 8;
      state->supplyCount[province] = 8;
    }
  else
    {
      state->supplyCount[estate] = 12;
      state->supplyCount[duchy] = 12;
      state->supplyCount[province] = 12;
    }

  //set number of Treasure cards
  state->supplyCount[copper] = 60 - (7 * numPlayers);
  state->supplyCount[silver] = 40;
  state->supplyCount[gold] = 30;

  //set number of Kingdom cards
  for (i = adventurer; i <= treasure_map; i++)       	//loop all cards
    {
      for (j = 0; j < 10; j++)           		//loop chosen cards
	{
	  if (kingdomCards[j] == i)
	    {
	      //check if card is a 'Victory' Kingdom card
	      if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
		{
		  if (numPlayers == 2){ 
		    state->supplyCount[i] = 8; 
		  }
		  else{ state->supplyCount[i] = 12; }
		}
	      else
		{
		  state->supplyCount[i] = 10;
		}
	      break;
	    }
	  else    //card is not in the set choosen for the game
	    {
	      state->supplyCount[i] = -1;
	    }
	}

    }

  ////////////////////////
  //supply intilization complete
  
  //set player decks
  //each player has 25 cards
  //each includes 7 coppers, 2 gold, 2 silver, 3 estates, and 9 random cards
  //plus adventurer which is in hand
  for (i = 0; i < 2; i++) {
    int randomCard = 0;
    state->deckCount[i] = 0;
    addCardToDeck(state, i, estate, 3);
    addCardToDeck(state, i, copper, 7);
    addCardToDeck(state, i, silver, 2);
    addCardToDeck(state, i, gold, 2);
    for (j = 0; j < 9; j++) {
      randomCard = rand() % 10;
      state->deck[i][state->deckCount[i]] = kingdomCards[randomCard];
      state->deckCount[i]++;
    }
  }
  //shuffle decks
  for (i = 0; i < numPlayers; i++)
    {
      if ( shuffle(i, state) < 0 )
	{
	  return -1;
	}
  }
  for (i = 0; i < numPlayers; i++)
    {
      if ( shuffle(i, state) < 0 )
	{
	  return -1;
	}
  }
  /*
  for (i = 0; i < state->deckCount[0]; i++) {
    printf("card is: %d\n", state->deck[0][i]);
  }*/
  
  //initialize hands
  for (i = 0; i < numPlayers; i++) {
    state->handCount[i] = 0;
    state->discardCount[i] = 0;
  }
  //set embargo tokens to 0 for all supply piles
  for (i = 0; i <= treasure_map; i++)
    {
      state->embargoTokens[i] = 0;
    }

  //initialize first player's turn
  state->outpostPlayed = 0;
  state->phase = 0;
  state->numBuys = 1;
  state->playedCardCount = 0;
  state->whoseTurn = 0;
  state->handCount[state->whoseTurn] = 0;
  
  //randomly assign numActions to 1 or 2
  state->numActions = (rand() % 2) + 1;
  
  //add smithy as top card of deck for player 1
  
  state->deck[0][state->deckCount[0]] = adventurer;
  state->deckCount[0]++;
  //draw cards for player 1
  
  for (it = 0; it < 5; it++) {
    drawCard(state->whoseTurn, state);
    //printf("card in hand is: %d\n", state->hand[state->whoseTurn][it]);
  }
  
  updateCoins(state->whoseTurn, state, 0);
}

int main() {
  srand(time(NULL));
  
  int numberRandomRuns = 250;
  int i, j;
  int cardsToDiscardPass = 0;
  int treasureToHandPass = 0;
  int adventurerToPlayedPass = 0;
  int otherPlayerStatePass = 0;
  int decrementActionsPass = 0;
  //run 
  for (i = 0; i < numberRandomRuns; i++) {
    struct gameState *G;
    G = newGame();
    initializeRandomGame(G);
    
    int p2HandCount = G->handCount[1];
    int p2DeckCount = G->deckCount[1];
    int p2DiscardCount = G->discardCount[1];
    int p1HandCount = G->handCount[0];
    int p1DeckCount = G->deckCount[0];
    int p1DiscardCount = G->discardCount[0];
    int p1ActionCount = G->numActions;
    int p1Coins = G->coins;
    
    playCard(0, 0, 0, 0, G);
    
    //test that other cards are added to discard
    if (G->discardCount[0] > p1DiscardCount) {
      cardsToDiscardPass++;
    } 
    
    //test that treasure cards are added to hand
    updateCoins(G->whoseTurn, G, 0);
    if (G->coins >= p1Coins + 2) {
      treasureToHandPass++;
    } 
    
    //test that adventurer removed from hand and added to played pile
    if (G->hand[0][G->handCount[0] - 1] == adventurer) {
      //do nothing no pass
    } else if (G->playedCards[G->playedCardCount - 1] == adventurer) {
      adventurerToPlayedPass++;
    } 

    //check state of other player to ensure no changes
    if (G->handCount[1] == p2HandCount && G->deckCount[1] == p2DeckCount && G->discardCount[1] == p2DiscardCount) {
      otherPlayerStatePass++;
    } 
    //check that actions have been decremented
    if (G->numActions == p1ActionCount - 1) {
      decrementActionsPass++;
    } 
    
    //if actions remain - play another random card
    if (G->numActions > 0) {
      for (j = 0; j < G->handCount[0]; j++) {
        if (G->hand[0][j] > 6) {
          playCard(j, 0, 0, 0, G);
          break;
        }
      }
    }
    
    //buy a random card
    int buyPosition = 0;
    int cardBought = 0;
    while (!cardBought) {
      buyPosition = rand() % 26;
      if (buyCard(buyPosition, G) != -1) {
        cardBought = 1;
      }
    }
    
    //end turn
    endTurn(G);
  }
  
  printf("Testing Adventurer %d times...\n", numberRandomRuns);
  printf("Cards to Discard Passed %d times\n", cardsToDiscardPass);
  printf("Treasure to Hand Passed %d times\n", treasureToHandPass);
  printf("Adventurer to Played Passed %d times\n", adventurerToPlayedPass);
  printf("Other Player State Passed %d times\n", otherPlayerStatePass);
  printf("Decrement Actions Passed %d times\n", decrementActionsPass);

  
  return 0;
}