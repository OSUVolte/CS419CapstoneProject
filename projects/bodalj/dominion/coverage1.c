**Use gcov to measure code coverage for all of these tests. Report findings by discussing tests' coverage (statement, branch, boundary, etc.) and describe their 
impliciations for tests here.  **


## Unit Test 1: shuffle function

    int shuffle(int player, struct gameState *state)

* check deck, hand, and discard count before and after shuffling -- it shouldn't change
* check count of cards before and after shuffle -- shouldn't change

** Coverage Results **

Function 'shuffle'
Lines executed: 100.00% of 16
Branches executed: 100.00% of 8
Taken at least once: 100.00% of 8
Calls executed: 100%.00 of 2

All code was covered in shuffle.  We could not really test whether the order of the cards change pre and post shuffle
because the order of the cards could technically stay the same after the shuffle.  If we wanted to test the randomness of
the shuffle then that might be worth looking into, however that would require more of a statisical analysis of the card order
post shuffle.


## Unit Test 2: getCost function

    int getCost(int cardNumber)

* get all card values from wiki that are declared in dominion.h and compare their values to getCost function
* ensure that getCost returns -1 if card is invalid; test invalid with negative and with large number

** Coverage Results**

Function 'getCost'
Lines executed:100.00% of 30
Branches executed:100.00% of 28
Taken at least once:100.00% of 28
No calls

First the card values needed to be obtained from an official source, I chose to gather the card values from the wiki.
After this I wrote test cases for each card to check that the value returned by getCost() was the same as the
value listed in the offical source. We received 100% test coverage for all of the results and there were no bugs found.

## Unit Test 3: drawCard function

    int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)

* Error with incrementing discard deck and count, nothing being placed into it and it's not incrementing

** Coverage Results **

Function 'discardCard'
Lines executed:100.00% of 13
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
No calls

To test this function we needed to ensure that if a card was discarded then it would end up in the discard pile
and that if it was trash then it would just need to be added to the played pile.  The discardCount should also be
incremented in order to maintain the cards that are in the discard pile.  These tests found a very severe error
in the discard function as it does not do what it is supposed to do.

## Unit Test 4: whoseTurn function

    int whoseTurn(struct gameState *state)

This function is fairly straightforward, however it is good to verify that it works in case it is changed later.
Right now the whoseTurn function simply returns the `state->whoseTurn` from the gameState. 

** Coverage Results **

Function 'whoseTurn'
Lines executed:100.00% of 2
No branches
No calls

100% coverage was reached and there were no additional branches to test. This test will serve as an integrity check
for the program if it were to be refractored later or if determining whose turn was it changes at a later time.

## Card Test 1: smithy

    int playSmithy(int currentPlayer, int handPos, struct gameState *state);

Smithy effect: Draw 3 cards

* Check that Smithy draws 3 cards
* Check that cards we had before Smithy are still there
* Check that Smithy has been discarded

** Coverage Results **

Function 'playSmithy'
Lines executed:100.00% of 5
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 2

100% coverage was achieved. For this card we need to ensure that it is discarded once played, it doesn't change
the rest of the game state, and that it draws the correct number of cards. We found that this card does not discard 
correctly and that it affects the order of the cards in the player's hand.

## Card Test 2: adventurer

    int playAdventurer(currentPlayer, struct gameState *state) 

Adventurer effect: Draw cards until 2 treasure cards drawn into hand; discard non-treasure cards

* Check that drawing silver, gold, and copper cause original hand size to only change by two
* Check that drawing non-treasure cards are discarded
* Check that if deck is empty we will shuffle discard and gain two treasure

** Coverage Results **

Function 'playAdventurer'
Lines executed:100.00% of 18
Branches executed:100.00% of 12
Taken at least once:100.00% of 12
Calls executed:100.00% of 2

100% coverage was achieved. Adventurer has some slightly complex mechanics in that it gains 2 treasure cards
and there are 3 different types of treasure cards. We need to make sure that it will keep any of the types of the
treasure cards that it draws and that it discards properly once played. It is also important to check that if
there are no treasure cards in the deck that it will not loop infinitely looking for them. 

## Card Test 3: village
    
    int playVillage(int currentPlayer, int handPos, struct gameState *state)

* Check that we drew only 1 card
* Check that we gained only 2 actions
* Check that card was discarded
* Check that numBuys is the same

** Coverage Results **

Function 'playVillage'
Lines executed:100.00% of 5
No branches
Calls executed:100.00% of 2

100% coverage was achieved. The village card draws 1 card then gains two actions so we needed to ensure that only 
those two things happened and that the card was discarded. We check the number of buys to make sure that wasn't changed
and then check the same for drawing cards and actions.

## Card Test 4: great_hall

* Check that we drew only 1 card
* Check that we gained only 1 actions
* Check that card was discarded
* Check that numBuys is the same

** Coverage Results **

Lines executed:100.00% of 5
No branches
Calls executed:100.00% of 2

100% coverage was achieved. The greate_hall card draws 1 card then gains 1 action so we needed to ensure that only 
those two things happened and that the card was discarded. We check the number of buys to make sure that wasn't changed
and then check the same for drawing cards and actions.
