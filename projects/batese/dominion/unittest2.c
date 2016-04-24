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
	
	for (x = 0; x <= 40; x += 10) {
		for (y = 0; y <= 40; y += 10) {
			printf("Testing with player1 score of %d and player2 score of %d on player 1's turn.\n", x, y);
			players[0] = x;
			players[1] = y; //Store scores in players array
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
			G.whoseTurn = 0; // Set to player 1's turn
			getWinners(players, &G);
			if (x > y) { // Player 1 is winner
				if (players[0] == 1 && players[1] == 0)
					printf("PASSED: Player1 score = %d, expected = 1  Player2 score = %d, expected = 0.\n", players[0], players[1]);
				else
					printf("FAILED: Player1 score = %d, expected = 1  Player2 score = %d, expected = 0.\n", players[0], players[1]);
			} else { // Player 2 is the winner even if scores are equal since they have had one less turn
				if (players[0] == 0 && players[1] == 1)
					printf("PASSED: Player1 score = %d, expected = 0  Player2 score = %d, expected = 1.\n", players[0], players[1]);
				else
					printf("FAILED: Player1 score = %d, expected = 0  Player2 score = %d, expected = 1.\n", players[0], players[1]);				
			}
			printf("Testing with player1 score of %d and player2 score of %d on player 2's turn.\n", x, y);
			players[0] = x;
			players[1] = y; //Store scores in players array
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
			G.whoseTurn = 1; // Set to player 2's turn
			getWinners(players, &G);
			if (x > y) { // Player 1 is winner
				if (players[0] == 1 && players[1] == 0)
					printf("PASSED: Player1 score = %d, expected = 1  Player2 score = %d, expected = 0.\n", players[0], players[1]);
				else
					printf("FAILED: Player1 score = %d, expected = 1  Player2 score = %d, expected = 0.\n", players[0], players[1]);
			} else if (y > x) { // Player 2 is the winner
				if (players[0] == 0 && players[1] == 1)
					printf("PASSED: Player1 score = %d, expected = 0  Player2 score = %d, expected = 1.\n", players[0], players[1]);
				else
					printf("FAILED: Player1 score = %d, expected = 0  Player2 score = %d, expected = 1.\n", players[0], players[1]);				
			} else { // x == y
				if (players[0] == 1 && players[1] == 1)
					printf("PASSED: Player1 score = %d, expected = 1  Player2 score = %d, expected = 1.\n", players[0], players[1]);
				else
					printf("FAILED: Player1 score = %d, expected = 1  Player2 score = %d, expected = 1.\n", players[0], players[1]);					
			}
		}
	}

	

}



















