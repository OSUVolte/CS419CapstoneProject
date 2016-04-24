**Use gcov to measure code coverage for all of these tests. Report findings by discussing tests' coverage (statement, branch, boundary, etc.) and describe their 
impliciations for tests here.  **


## Unit Test 1: shuffle function

    int shuffle(int player, struct gameState *state)


## Unit Test 2: getCost function

    int getCost(int cardNumber)

* get all card values from wiki that are declared in dominion.h and compare their values to getCost function
* ensure that getCost returns -1 if card is invalid; test invalid with negative and with large number

## Unit Test 3: drawCard function

    int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)

* Error with incrementing discard deck and count, nothing being placed into it and it's not incrementing

## Card Test 1: smithy

    int playSmithy(int currentPlayer, int handPos, struct gameState *state);

Smithy effect: Draw 3 cards

* Check that Smithy draws 3 cards
* Check that cards we had before Smithy are still there
* Check that Smithy has been discarded

## Card Test 2: adventurer

    int playAdventurer(currentPlayer, struct gameState *state) 

Adventurer effect: Draw cards until 2 treasure cards drawn into hand; discard non-treasure cards

* Check that drawing silver, gold, and copper cause original hand size to only change by two
* Check that drawing non-treasure cards are discarded
* Check that if deck is empty we will shuffle discard and gain two treasure

## Card Test 3: village

## Card Test 4: great_hall


