/**
Michael Hueter
CS 362 Assignment 3
unitTest1.c - testing the getCost function
**/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int testAssert(int expected, int actual, char *a){
  if (expected != actual){
    printf ("\n ! ASSERTION FAILED: EXPECTED %s == %d, NOT %d). \n", a, expected, actual);
    return 1;
  }
  printf ("\n PASSED: %s == %d.\n", a, actual);
  return 0;
}


int main() {
  int failures = 0; // keep track of how many tests failed
  int cost;

  printf ("\n******* FUNCTION UNDER TEST: getCost() *******\n");

  printf ("\n------- UNIT TEST 1 STARTING -------\n");
  cost = getCost(curse);
  failures += testAssert(0, cost, "curse");
  cost = getCost(estate);
  failures += testAssert(2, cost, "estate");
  cost = getCost(duchy);
  failures += testAssert(5, cost, "duchy");
  cost = getCost(province);
  failures += testAssert(8, cost, "province");
  cost = getCost(copper);
  failures += testAssert(0, cost, "copper");
  cost = getCost(silver);
  failures += testAssert(3, cost, "silver");
  cost = getCost(gold);
  failures += testAssert(6, cost, "gold");
  cost = getCost(adventurer);
  failures += testAssert(6, cost, "adventurer");
  cost = getCost(council_room);
  failures += testAssert(5, cost, "council_room");
  cost = getCost(feast);
  failures += testAssert(4, cost, "feast");
  cost = getCost(gardens);
  failures += testAssert(4, cost, "gardens");
  cost = getCost(mine);
  failures += testAssert(5, cost, "mine");
  cost = getCost(remodel);
  failures += testAssert(4, cost, "remodel");
  cost = getCost(smithy);
  failures += testAssert(4, cost, "smithy");
  cost = getCost(village);
  failures += testAssert(3, cost, "village");
  cost = getCost(baron);
  failures += testAssert(4, cost, "baron");
  cost = getCost(great_hall);
  failures += testAssert(3, cost, "great_hall");
  cost = getCost(minion);
  failures += testAssert(5, cost, "minion");
  cost = getCost(steward);
  failures += testAssert(3, cost, "steward");
  cost = getCost(tribute);
  failures += testAssert(5, cost, "tribute");
  cost = getCost(ambassador);
  failures += testAssert(3, cost, "ambassador");
  cost = getCost(cutpurse);
  failures += testAssert(4, cost, "cutpurse");
  cost = getCost(embargo);
  failures += testAssert(2, cost, "embargo");
  cost = getCost(outpost);
  failures += testAssert(5, cost, "outpost");
  cost = getCost(salvager);
  failures += testAssert(4, cost, "salvager");
  cost = getCost(sea_hag);
  failures += testAssert(4, cost, "sea_hag");
  cost = getCost(treasure_map);
  failures += testAssert(4, cost, "treasure_map");

  printf ("\n------- UNIT TEST 1 COMPLETE -------\n");
  if(failures == 0){
    printf("  All assertions passed!\n\n");
  }
  else{
    printf ("  FAILURES: %d \n\n", failures);
  }
  return 0;
}
