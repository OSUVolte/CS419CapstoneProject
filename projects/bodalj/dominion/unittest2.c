/******************************************************************************
 * Filename: unittest2.c
 * Author: Jens Bodal
 * Date: April 22, 2016
 * Description: 
 * Input: 
 * Output: 
 *****************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h" // getCost
#include "assert.h"
#include <stdio.h>

int compareCost(int, int);

int main() {
    int cost, expectedCost;
    char *cardName;
    
    printf("Testing getCost\n");
    printf("-- SIMPLE FIXED TESTS --\n");
    // comparing values to those found on official wiki: http://wiki.dominionstrategy.com/index.php
    // card [cost]
    //
    // curse [0]
    cost = getCost(curse);
    expectedCost = 0;
    cardName = "curse";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // estate [2]
    cost = getCost(estate);
    expectedCost = 2;
    cardName = "estate";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // duchy [5]
    cost = getCost(duchy);
    expectedCost = 5;
    cardName = "duchy";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // province [8]
    cost = getCost(province);
    expectedCost = 8;
    cardName = "province";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // copper [0]
    cost = getCost(copper);
    expectedCost = 0;
    cardName = "copper";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // silver [3]
    cost = getCost(silver);
    expectedCost = 3;
    cardName = "silver";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // gold [6]
    cost = getCost(gold);
    expectedCost = 6;
    cardName = "gold";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // adventurer [6]
    cost = getCost(adventurer);
    expectedCost = 6;
    cardName = "adventurer";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // council_room [5]
    cost = getCost(council_room);
    expectedCost = 5;
    cardName = "council_room";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // feast [4]
    cost = getCost(feast);
    expectedCost = 4;
    cardName = "feast";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // gardens [4]
    cost = getCost(gardens);
    expectedCost = 4;
    cardName = "gardens";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // mine [5]
    cost = getCost(mine);
    expectedCost = 5;
    cardName = "mine";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // remodel [4]
    cost = getCost(remodel);
    expectedCost = 4;
    cardName = "remodel";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // smithy [4]
    cost = getCost(smithy);
    expectedCost = 4;
    cardName = "smithy";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // village [3]
    cost = getCost(village);
    expectedCost = 3;
    cardName = "village";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // baron [4]
    cost = getCost(baron);
    expectedCost = 4;
    cardName = "baron";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // great_hall [3]
    cost = getCost(great_hall);
    expectedCost = 3;
    cardName = "great_hall";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // minion [5]
    cost = getCost(minion);
    expectedCost = 5;
    cardName = "minion";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // steward [3]
    cost = getCost(steward);
    expectedCost = 3;
    cardName = "steward";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // tribute [5]
    cost = getCost(tribute);
    expectedCost = 5;
    cardName = "tribute";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // ambassador [3]
    cost = getCost(ambassador);
    expectedCost = 3;
    cardName = "ambassador";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // cutpurse [4]
    cost = getCost(cutpurse);
    expectedCost = 4;
    cardName = "cutpurse";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // embargo [2]
    cost = getCost(embargo);
    expectedCost = 2;
    cardName = "embargo";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // outpost [5]
    cost = getCost(outpost);
    expectedCost = 5;
    cardName = "outpost";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // salvager [4]
    cost = getCost(salvager);
    expectedCost = 4;
    cardName = "salvager";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // sea_hag [4]
    cost = getCost(sea_hag);
    expectedCost = 4;
    cardName = "sea_hag";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    // treasure_map [4]
    cost = getCost(treasure_map);
    expectedCost = 4;
    cardName = "treasure_map";
    assert(compareCost(cost, expectedCost) == 0);
    printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);

    // test invalid cards
    cost = getCost(-1);
    assert(cost == -1);
    printf("SUCCESS: [-1] returned for invalid cardNumber [-1]\n");

    cost = getCost(9999);
    assert(cost == -1);
    printf("SUCCESS: [-1] returned for invalid cardNumber [9999]\n");
    return 0;
}

int compareCost(int cost, int expectedCost) {
    // if a-b == 0 then cards are equal; 0 is false so return !false if equal
    return (expectedCost-cost);
}
