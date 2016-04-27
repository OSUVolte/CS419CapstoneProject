/*********************************************************
* Kara Franco
* randomHistory.c
* Due Date: May 8, 2016
*********************************************************/

Adventurer Random Tester:
	The first step I took in developing the random tester for the Adventurer Card was to re-visit the code coverage 
from Assignment 3 and determine if there are any cases or code that were not covered. Upon reviewing the adventure card 
coverage, I decided my previous tests fell short in four areas: 

- I only tested for 2 players, more tests are needed to cover the other player options
- I only tested with one seed value (10) other seed values may change the program behaviour
- I did not test if the cards drawn were actually treasure cards
- Lastly, I did not test for different values of the deck and hand counts

	Before initializing the game, I set the number of players and the seed to a random number (within the player 
specifications, a random number between 2 and 4). I also decided to define a MAX_TESTS so that I can alter the number 
of tests, and eventually settled on 1500 so that I would have a large enough pool of FAILs to make an analysis.  

	Next, before calling cardEffect() I set the hand, deck and discard piles to a random number within their MAX 500 (found 
in the dominion header file). This will give random start points for the preDeckCount and preHandCount variables. Lastly, 
I added the treasure card test, to enhance the test from last assignment. This test verifies that the cards kept were indeed 
treasure cards (copper, silver or gold).

	To check for correctness I hand traced (on a whiteboard) what the new test would cover, and what the random values 
for the deck and hand variables will look like in a sample test. I also used print statements for debugging and understanding the 
results from the subtests. The line execution coverage of the randomtestadventurer.c program was 100%. This is an increase from the 
cardtest1, which was 84.38% coverage. The test results themselves showed that there are 3/1500 times that the Adventure function
produced the correct number of cards (2). It was expected that the function fail this test, since I had put a bug to return 3 cards.
What is interesting is I did not put a bug in for the cards to be non-treasure cards. And as we see in subtest 2 (Adventurer card gave
treasure cards) that there was an instance when a card was given to a player that was not a treasure card. This could lead to more tests,
such as chacking what the cards were that were given.   

Village Random Tester:
	To begin, I found a mistake in my previous test from Assignment 3! I tested the handCount for after the Village card play to 
be handCount + 1, where I should have checked for it to be simply handCount. My first step for developing the random tests for 
Village card was to fix this error, and then re-visit the code coverage from Assignment 3. I determined that there were three 
areas where my tests fell short:    

- I only tested for 2 players, more tests are needed to cover the other player options
- I only tested with one seed value (10) other seed values may change the program behaviour
- Lastly, I did not test the handCount and deckCount values correctly, this needed fixing

	I set up my random tester for the Village card in the same manner as the Adventurer card. I gave random values to the number of
players and the random number generator before initializing the game. And after the game was initailized, I re-set the values for 
the actions, discard and hand for the players to add more randomness to the test. Also, like the Adventurer test, I ran 1500 tests to
increase the pool of results. 
	To check for correctness I used the same method as the Adventurer card, where I used print statements to track what subtests were 
running (with a small test number - 6) and debugged. I also kept checking the results from the coverage tests, to determine where I needed
to add tests. The line execution coverage of the randomtestcard.c program was 93.55%. This is a dramatic increase from the coverage of 
cardtest3.c, which was 78.95%. The test results themselves showed that I corrected the previous test error. The Village card never failed 
the card and action tests. This suggested that Village card does not have an error in this part of the function and is working properly. What
was very interesting was that there were 3/1500 errors (or FAILs) for the test "Village card did not change the discardCount". This leads me
think that there may be an error in the discardCard() function. Further investigation of that function will be needed, such as do certain 
pairing of parameters create an error in discarding.  
