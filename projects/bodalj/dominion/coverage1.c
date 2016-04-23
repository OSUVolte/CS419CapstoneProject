**Use gcov to measure code coverage for all of these tests. Report findings by discussing tests' coverage (statement, branch, boundary, etc.) and describe their 
impliciations for tests here.  **


## Unit Test 1: initializeGame function

    initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state);

* number of players needs to be between 2 - max players
* kingdom cards must be different
* must be 10 kingdom cards total (not a requirement?) it's a game requirement, so I should add it
* number of curse cards 

## Unit Test 2: getCost function

    getCost(int cardNumber)

* get all card values from wiki that are declared in dominion.h and compare their values to getCost function
* ensure that getCost returns -1 if card is invalid; test invalid with negative and with large number


