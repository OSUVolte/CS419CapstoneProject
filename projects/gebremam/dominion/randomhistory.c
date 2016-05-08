/* -----------------------------------------------------------------------
 * Martha Gebremariam
 * CS362_SP2016
 * Assignment 4
 * Description: randomhistory.c detailing development of your random testers, 
 * including improvements in coverage and effort to correctness 
 * -----------------------------------------------------------------------
 */
/*


DEVELOPMENT OF RANDOM TESTERS
The cards I tested were smithy and adventurer. 
My main effort was to generate random inputs to check the associated functions (adventurerRefactored and smithyRefactored).

The main input for the associated functions was the game state. The game state has several components that are somewhat related.
I first studied the  adventurerRefactored and smithyRefactored functions to understand which components they or other methods they 
call affect. 
To randomize game state components, I fist called initializeGame method to initialize the game. My main purpose for doing that was
to know what the supply initially looks like. 
After that, I created random deck, random discard pile, and a random hand. 
To account for the 10 cards that are initially placed in player's decks, I randomly added 7 copper and 3 estate cards to either deck,
discard, or hand.
I also randomly placed the adventurer/smithy cards within hand.
Then I called the cardEffect method with the corresponding cards, the game state, and hand position of the cards. 
cardEffect then calls corresponding methods.

Initially, I tried to implement a loop to complete several tests in one try but it was taking long. So, I decided to stick with one 
random test per run since it can be ran several times if several test cases were preferred. Other than the selected kingdom cards,
each component will be random.

Both tests failed due to bugs introduced in previous assignment. 
In Adventurer, revealed non treasure cards were not being properly discarded and in smithy, 4 cards were being drawn instead of 3.


IMPROVEMENTS IN COVERAGE
Comparison of coverage rates from last week below:

TEST COVERAGE FOR DOMINION
LAST WEEK
Running 'gcov -b dominion' results:-
Lines executed:42.45% of 556
Branches executed:45.32% of 417
Taken at least once:35.25% of 417
Calls executed:30.53% of 95
Creating 'dominion.c.gcov'

THIS WEEK
Running 'gcov -b dominion' results:-
Lines executed:38.43% of 562
Branches executed:40.05% of 417
Taken at least once:33.09% of 417
Calls executed:22.92% of 96
Creating 'dominion.c.gcov'

The slight reduction is mainly because the tests were covering 8 functions last week vs 2 functions this week


TEST COVERAGE FOR ADVENTURER
LAST WEEK
Running 'gcov -b cardtest1' results:-
File 'cardtest1.c'
Lines executed:91.67% of 24
Branches executed:100.00% of 2
Taken at least once:50.00% of 2
Calls executed:88.89% of 9
Creating 'cardtest1.c.gcov'

THIS WEEK
Running 'gcov -b randomtestadventurer' results:-
File 'randomtestadventurer.c'
Lines executed:95.14% of 144
Branches executed:100.00% of 64
Taken at least once:92.19% of 64
Calls executed:90.91% of 33
Creating 'randomtestadventurer.c.gcov'

As you can see, there is an improvement for adventurer card.


TEST COVERAGE FOR SMITHY
LAST WEEK
Running 'gcov -b cardtest2' results:-
File 'cardtest2.c'
Lines executed:91.67% of 24
Branches executed:100.00% of 2
Taken at least once:50.00% of 2
Calls executed:88.89% of 9
Creating 'cardtest2.c.gcov'

THIS WEEK
Running 'gcov -b randomtestcard' results:-
File 'randomtestcard.c'
Lines executed:96.32% of 136
Branches executed:100.00% of 62
Taken at least once:93.55% of 62
Calls executed:92.86% of 28
Creating 'randomtestcard.c.gcov'

As you can see, there is also an improvement for smithy card.

*/

