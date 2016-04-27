/*********************************************************
* Kara Franco
* randomHistory.c
* Due Date: May 8th 2016
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
of tests, and eventually settled on 500 so that I would have a large enough pool of FAIL/PASS to make an analysis.  

Next, before calling cardEffect() I set the hand, deck and discard piles to a random number within their MAX 500 (found 
in the dominion header file). This will give random start points for the preDeckCount and preHandCount variables. Lastly, 
I added the treasure card test, to enhance the test from last assignment. 

To check for correctness I hand traced (on a whiteboard) what the new test would cover, and what the random values 
for the deck and hand variables will look like in a sample test. I also used print statements for debugging. Overall, 
the coverage from the random test of the adventurer card 

Village Random Tester:
		I found a mistake in my previous test!! I had the handcount + 1!! Opps, 