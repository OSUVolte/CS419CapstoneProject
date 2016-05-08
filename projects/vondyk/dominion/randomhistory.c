/****************
** File name: randomhistory.c
** Description: This file contains documentation for 
**		the random testing of the adventurer and 
** 		smithy cards. 
****************/

****************************
** General Random Testing **
****************************
In general I determined ideal ranges for a valid, yet random, 
game state. The lectures showed how completely random test 
variables would not be of any use if the functions being tested
depend on the game state being valid.

Each file randomizes the number of players and the kingdom cards
prior to initializing the game state for testing. 

Each file runs 2000 random tests to see how various inputs change 
the outcome of the tests. The number 2000 was chosen because it 
is large enough to give a good amount of data, yet small enough 
to be manageable. Also because it was the number used in the example
(i.e. the betterTestDrawCard file provided)

**************************
** randomtestadventurer **
**************************
gcov: 76.38% of 199 lines executed

In order to truly test the Adventurer card, I needed to make sure
that treasure cards were randomly placed in the deck. So I have one
set of tests with a truly random deck, and another where I force two 
treasure cards into the deck at random locations. This way, if the 
adventurer function called from cardEffect is working properly it 
will at least pass all the tests where the treasure cards are placed
into the deck. 

Since these tests were modeled after the tests I used in my card test
file that tested the Adventurer card, I assumed I would get similar
results. This proved to be true. The bugs I introduced prevented the 
drawCard function from being called when adventurer card is played so 
this caused a lot of the tests to fail. 

Coverage--clearly my coverage was not as effective as it could have 
been. At 76.38%, it is acceptable, but there is room for improvement.


********************
** randomtestcard **
********************
gcov: 83.87% of 62 lines executed

For this test, I chose to test the Smithy card. Between the Smithy
and the Adventurer, these cards have been the focus of the last few
assignments so I chose to stick to them. 

This test was modeled after the card test file on Smithy I did for 
Assignment 3. The difference was that I randomly generated the
players, deck count, deck cards and hand count before running the
20 tests. This produced clear evidence that the bugs I introduced
still exist in the Smithy card. This means that the discard of 
Smithy goes to the wrong place, (not the played pile) and that the
player draws 4 cards instead of 3. 