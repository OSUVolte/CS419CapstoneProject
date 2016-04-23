/******************************************************************************
 * Filename: unittest2.c
 * Author: Jens Bodal
 * Date: April 22, 2016
 * Description: 
 * Input: 
 * Output: 
 *****************************************************************************/

#include "dominion_helpers.h" // getCost
#include "assert.h"
#include <stdio.h>

int compareCost(int, int);
void printResult(int, int, char*);

int main() {
    int cost, expectedCost;
    char *cardName;

    // comparing values to those found on official wiki: http://wiki.dominionstrategy.com/index.php
    // card [cost]
    //
    // curse [0]
    cost = getCost(curse);
    expectedCost = 0;
    cardName = "curse";
    printResult(cost, expectedCost, cardName);
    // estate [2]
    cost = getCost(estate);
    expectedCost = 2;
    cardName = "estate";
    printResult(cost, expectedCost, cardName);
    // duchy [5]
    cost = getCost(duchy);
    expectedCost = 5;
    cardName = "duchy";
    printResult(cost, expectedCost, cardName);
    // province [8]
    cost = getCost(province);
    expectedCost = 8;
    cardName = "province";
    printResult(cost, expectedCost, cardName);
    // copper [0]
    cost = getCost(copper);
    expectedCost = 0;
    cardName = "copper";
    printResult(cost, expectedCost, cardName);
    // silver [3]
    cost = getCost(silver);
    expectedCost = 3;
    cardName = "silver";
    printResult(cost, expectedCost, cardName);
    // gold [6]
    cost = getCost(gold);
    expectedCost = 6;
    cardName = "gold";
    printResult(cost, expectedCost, cardName);
    // adventurer [6]
    cost = getCost(adventurer);
    expectedCost = 6;
    cardName = "adventurer";
    printResult(cost, expectedCost, cardName);
    // council_room [5]
    cost = getCost(council_room);
    expectedCost = 5;
    cardName = "council_room";
    printResult(cost, expectedCost, cardName);
    // feast [4]
    cost = getCost(feast);
    expectedCost = 4;
    cardName = "feast";
    printResult(cost, expectedCost, cardName);
    // gardens [4]
    cost = getCost(gardens);
    expectedCost = 4;
    cardName = "gardens";
    printResult(cost, expectedCost, cardName);
    // mine [5]
    cost = getCost(mine);
    expectedCost = 5;
    cardName = "mine";
    printResult(cost, expectedCost, cardName);
    // remodel [4]
    cost = getCost(remodel);
    expectedCost = 4;
    cardName = "remodel";
    printResult(cost, expectedCost, cardName);
    // smithy [4]
    cost = getCost(smithy);
    expectedCost = 4;
    cardName = "smithy";
    printResult(cost, expectedCost, cardName);
    // village [3]
    cost = getCost(village);
    expectedCost = 3;
    cardName = "village";
    printResult(cost, expectedCost, cardName);
    // baron [4]
    cost = getCost(baron);
    expectedCost = 4;
    cardName = "baron";
    printResult(cost, expectedCost, cardName);
    // great_hall [3]
    cost = getCost(great_hall);
    expectedCost = 3;
    cardName = "great_hall";
    printResult(cost, expectedCost, cardName);
    // minion [5]
    cost = getCost(minion);
    expectedCost = 5;
    cardName = "minion";
    printResult(cost, expectedCost, cardName);
    // steward [3]
    cost = getCost(steward);
    expectedCost = 3;
    cardName = "steward";
    printResult(cost, expectedCost, cardName);
    // tribute [5]
    cost = getCost(tribute);
    expectedCost = 5;
    cardName = "tribute";
    printResult(cost, expectedCost, cardName);
    // ambassador [3]
    cost = getCost(ambassador);
    expectedCost = 3;
    cardName = "ambassador";
    printResult(cost, expectedCost, cardName);
    // cutpurse [4]
    cost = getCost(cutpurse);
    expectedCost = 4;
    cardName = "cutpurse";
    printResult(cost, expectedCost, cardName);
    // embargo [2]
    cost = getCost(embargo);
    expectedCost = 2;
    cardName = "embargo";
    printResult(cost, expectedCost, cardName);
    // outpost [5]
    cost = getCost(outpost);
    expectedCost = 5;
    cardName = "outpost";
    printResult(cost, expectedCost, cardName);
    // salvager [4]
    cost = getCost(salvager);
    expectedCost = 4;
    cardName = "salvager";
    printResult(cost, expectedCost, cardName);
    // sea_hag [4]
    cost = getCost(sea_hag);
    expectedCost = 4;
    cardName = "sea_hag";
    printResult(cost, expectedCost, cardName);
    // treasure_map [4]
    

    return 0;
}

int compareCost(int cost, int expectedCost) {
    // if a-b == 0 then cards are equal; 0 is false so return !false if equal
    return (expectedCost-cost);
}

void printResult(int cost, int expectedCost, char* cardName) {
    int result = compareCost(cost, expectedCost);
    if (result == 0) {
        printf("SUCCESS: [%s] is of cost [%d]\n", cardName, cost);
    }
    else if (result > 0) {
        printf("FAIL: [%s] cost is too high. Should be of cost [%d] but is of cost [%d]\n", cardName, expectedCost, cost);
    }
    else {
        printf("FAIL: [%s] cost is too low. Should be of cost [%d] but is of cost [%d]\n", cardName, expectedCost, cost);
    }
}
