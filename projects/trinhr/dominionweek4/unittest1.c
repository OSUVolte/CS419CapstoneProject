#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
//This is a unit test for the updateCoins() function.
//Input: int player --> current player
//	 struct gamestate
//	 int bonus --> bonus coins
//Business Rules:
//1. It needs to count the number of treasure cards
//in the players hand and return the correct number.
//2. If there is a bonus, it needs to correctly add the bonus
//to the number of coins.
//3. The rest of the game state needs to remain unchanged.

int main () {

  struct gameState expected, actual;
  //Current Player
  int player = 1;
  //Number of Cards in Player's Hand.
  int handCount = 5;

  //Initialize Player 1's Hand Count to 5
  expected.handCount[player] = handCount;
  //Initialize Player's Hand to five cards.
  expected.hand[player][0] = embargo;
  expected.hand[player][1] = copper;
  expected.hand[player][2] = village;
  expected.hand[player][3] = silver;
  expected.hand[player][4] = gold;
 
  int bonus = 3;
  int treasure_cards = 6;
  expected.coins = 0;
  
  //Set the expected Results.
  //Coins = Bonus + Silver(2) + Copper(1) + Gold(3).
  expected.coins = bonus + treasure_cards;
  int expected_coins = expected.coins;

  //Copy the game state to the pre game state test case.
  memcpy(&actual, &expected, sizeof(struct gameState));

  printf("EXPECTED COINS:%i  ACTUAL COINS:%i\n", expected.coins, actual.coins);
  assert(memcmp(&expected, &actual, sizeof(struct gameState)) == 0);
  printf("Both EXPECTED & ACTUAL GAME STATES ARE EQUIVALENT before calling the function.\n");
 
  printf("---Testing UpdateCoins()-----\n");
  updateCoins(player, &actual, bonus);
  int actual_coins = actual.coins;

  //Check if the rest of the game state is affected.
  actual.coins = expected.coins = 0;
  assert(memcmp(&expected, &actual, sizeof(struct gameState)) == 0);
  printf("Both EXPECTED & ACTUAL game states are equivalent after calling the function.\n");  
 
  //Check if the function returned the correct number of coins.
  printf("EXPECTED COINS:%i  ACTUAL COINS:%i\n", expected_coins, actual_coins);
  assert(expected_coins == actual_coins);

  return 0;

}
