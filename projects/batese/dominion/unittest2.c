/*
File: unittest2.c
Author: Elliot Bates
Description: Unit test for get winners function from dominion
*/

/*
int getWinners(int players[MAX_PLAYERS], struct gameState *state) {
  int i;	
  int j;
  int highScore;
  int currentPlayer;

  //get score for each player
  for (i = 0; i < MAX_PLAYERS; i++)
    {
      //set unused player scores to -9999
      if (i >= state->numPlayers)
	{
	  players[i] = -9999;
	}
      else
	{
	  players[i] = scoreFor (i, state);
	}
    }

  //find highest score
  j = 0;
  for (i = 0; i < MAX_PLAYERS; i++)
    {
      if (players[i] > players[j])
	{
	  j = i;
	}
    }
  highScore = players[j];

  //add 1 to players who had less turns
  currentPlayer = whoseTurn(state);
  for (i = 0; i < MAX_PLAYERS; i++)
    {
      if ( players[i] == highScore && i > currentPlayer )
	{
	  players[i]++;
	}
    }

  //find new highest score
  j = 0;
  for (i = 0; i < MAX_PLAYERS; i++)
    {
      if ( players[i] > players[j] )
	{
	  j = i;
	}
    }
  highScore = players[j];

  //set winners in array to 1 and rest to 0
  for (i = 0; i < MAX_PLAYERS; i++)
    {
      if ( players[i] == highScore )
	{
	  players[i] = 1;
	}
      else
	{
	  players[i] = 0;
	}
    }

  return 0;
}
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"



int main() {
	int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	int x, y; // p1 and p2 scores respectively
	int players[MAX_PLAYERS];

	printf ("TESTING getWinners():\n");	

	//Player 1 higher score
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	G.whoseTurn = 0; // Set to player 1's turn
	// add province to player 1's deck
	G.hand[0][G.handCount[0]] = 4; //4 is code for province
	G.handCount[0]++;
	getWinners(players, &G);
	// Player 1 is winner
	if (players[0] == 1 && players[1] == 0)
		printf("PASSED: Player1 score = %d, expected = 1  Player2 score = %d, expected = 0.\n", players[0], players[1]);
	else
		printf("FAILED: Player1 score = %d, expected = 1  Player2 score = %d, expected = 0.\n", players[0], players[1]);


	//Player 2 higher score
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	G.whoseTurn = 0; // Set to player 1's turn
	// add province to player 2's deck
	G.hand[1][G.handCount[1]] = 4; //4 is code for province
	G.handCount[1]++;
	getWinners(players, &G);
	if (players[0] == 0 && players[1] == 1)
		printf("PASSED: Player1 score = %d, expected = 0  Player2 score = %d, expected = 1.\n", players[0], players[1]);
	else
		printf("FAILED: Player1 score = %d, expected = 0  Player2 score = %d, expected = 1.\n", players[0], players[1]);

	
	//Same score player 1's turn
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	G.whoseTurn = 0; // Set to player 1's turn
	getWinners(players, &G);
	if (players[0] == 0 && players[1] == 1)
		printf("PASSED: Player1 score = %d, expected = 0  Player2 score = %d, expected = 1.\n", players[0], players[1]);
	else
		printf("FAILED: Player1 score = %d, expected = 0  Player2 score = %d, expected = 1.\n", players[0], players[1]);	
	
	//Same score player 2's turn
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	G.whoseTurn = 1; // Set to player 1's turn
	getWinners(players, &G);
	if (players[0] == 1 && players[1] == 1)
		printf("PASSED: Player1 score = %d, expected = 1  Player2 score = %d, expected = 1.\n", players[0], players[1]);
	else
		printf("FAILED: Player1 score = %d, expected = 1  Player2 score = %d, expected = 1.\n", players[0], players[1]);
	
	return 0;
}



















