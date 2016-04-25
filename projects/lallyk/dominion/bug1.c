/********************************************************************
 * Kara Franco
 * bug1.c
 * Due Date: April 24, 2016
 * ****************************************************************/
/*
Unit Tests Bugs: 
	It is apparent that the function compare() does not have bugs. This function I began
with since it is simple and easy to understand. The tests ran conclude that the function measures inequality
correctly. The function numHandCards on the other hand is hard to determine if there truely are no bugs. 
Although the tests I wrote passed, there are still areas to explore. For instance, numHandCards() relies on 
the function whoseTurn(). So, further investigation of this function was needed to search for more bugs. The 
function isGameOver() has passed three tests and failed one test! The dominion game ends when there are no more 
Province cards, or when there are three supply piles empty. My tests passed for the Province card test, and passed 
when there were one non-Province card pile empty. isGameOver, however, did not pass when there were three non-Province 
cards empty. We were expecting 1 (true) to be returned upon this case, however, the game continued. This was exciting 
to find the first bug! Lastly, whoseTurn() was tested, and the two tests passed, meaning that the players turn is being 
recorded.  

Card Tests Bugs:
	The adventurer() card was known to have bugs, and it did prove to fail. It appears that the adventurer() card is 
giving the player 3 treasure cards, rather than 2! What a deal. The cards in the deck, also match this result, where we have 
less cards in the deck than expected. The smithy() card was also known to have bugs, and it also proved to fail. The smithy()
gave the player 1 new cards, rather than 3. The cards in the deck were also not as expected, since the player was given less cards.
The village() card passed all of it's tests (correct execution and actions) however, it did not give the correct number of new 
cards. The village() card gave the player NO new card! Lastly, the council_room() card had one bug, the player was given 3 new cards 
rather than 4. The council_room passed all other tests, including the extra buy. 
	

