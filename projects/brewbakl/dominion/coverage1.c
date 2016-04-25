/*


Unit Test 1:

For unit test 1, I decided to test the initialization of the game state itself.  I do this by create a new game, and initializing it, then checking all the values that get returned against those in the dominion.c file.  There are several issues I am enoucntering with this test.  I setup the game as:

	struct gameState *game = newGame();
	int kingdomCards[10] = {adventurer, council_room, mine, remodel, village, smithy, ambassador, embargo, sea_hag, mine};
	int numPlayers = 2;
	result = initializeGame(numPlayers, kingdomCards, 2, game);
	
Result is used to check the return values in the function from dominion.c

Players initialize correctly.
Kingdom cards to not.
Supply of curse cards does not.
Suppy of victory cards do not.
Supply of treasure cards do not.
Decks are not initialized correctly, both P1 and P2.
Embargo tokens are initialized correctly.
There are 8 errors in total when initializing the game.

I am not sure why this is.  For example, if there are 2 players, there should be 10 curse cards total: 
	if ((game->supplyCount[curse] != 10)){
		printf("FAIL: Supply count of curse didn't initalize correctly.\n");
		errors++;
	}
	else{
		printf("PASS: Curse cards intialized correctly\n");
	}
	
This returns false.   Again, I am not sure why it does not initialize properly.

*/

/*
Unit test2:

For unit test 2, I test the buyCard() function.   I attempt to buy two cards, Mine and Village. I first buy the cards, and then check to see if the card count went up, and if that card was in hand.

When testing, the player gets +1 card in hand, but it cant "find" the cards.  I am not sure what is going on here either.  I'll continue to work on this because it does seem like the cards get bought, it just can't find it. I think the issue is finding a card in hand by a string rather than card ID.

*/


/*

Unit Test 3:

Unit Test 3 is testing the isGameOver() function.  The isGameOver() function has several different variables that will set the game over, the first is the count of province cards.  When province cards = 0, the function returns 1 and the game is over.  I test the function by initializing a game, then setting provice cards to 0 and checking  the  isGameOver() function.  It works, and the game ends appropriately.

This seemed like a quick way to check if the function works, however I do not test the other isGameOver() criteria of 3 supply piles at 0. 
*/


/*
Unit Test 4:

Unit Test 4 checks the cost of each card to play.  I pass each card id number into the getCost() function, and check the return value with what it should be.  Every card I checked passes the test in this instance.


*/


/*
Card Test 1:

Card Test 1 is the smithy card test.  The smithy card in dominion gives the player +3 cards when played.  My test compares the starting hand count and the hand count after playing smithy, if the hand count isn't +3 after smithy is played the test fails.

In my dominion files I modified the smithy card to draw 6 cards instead of 3, so the test fails in this case.


*/

/* 
Card Test 2:

Card Test 2 is a test of the adventurer card.  The adventurer card reveals cards from your deck until 2 treasure cards are found and then places those cards into your hand, and discards the rest.  My test checks to see if +2 cards are added to the hand.  It also checks the discard pile amount.

My tests fail because of how I modified the adventurer card in the refactor.  I made adventurer only find silver and gold and not copper.  I suspect this is goofing up the results of the test because it does not draw any cards, and does not discard any cards either.

*/

/* 
Card Test 3:

Card Test 3 tests the council room card.  The council room gives the player +4 cards, +1 buy, and each other player draws +1 card. The tests I created all fail, likely because of how I changed the council room card.  My council room gives the platyer +2 and not +4 cards, and skips the other uses. 

My test method checks the buy counts before and after the card is played, and also the hand count of the player before and after.  Since the player only gets +2 cards, I suspect the game is stuck in the beginning loop of the council room card that is supposed to count +4 cards:

      for (i = 0; i < 4; i++)
	{
	  drawCard(currentPlayer, state);
	}

If the game is stuck in this loop, it makes sense why the other parts of the function do not get executed.

*/

/*
Card Test 4

Card Test 4 tests the feast card.  When played, the feast card is discarded (trashed) and you gain +5 value.

I test the card functionality by counting the discard count after the card is played and comparing it to the value 1, which it should be.  If it equals one, the test passes, if not the test fails.  I also check the value after the card is played, if the value after is plus 5 of the value before, the test passes.

Since I did not modify the feast card, the tests all pass.  The card is discarded, and +5 value is added to the player.

*/


/*

Total coverage for my tests is 38.83% of 546 lines. Which is not a great amount of code covered. Ideally, I should have checked several functions related to playing cards themselves, such as playCard(), buyCard(), drawCard() and handCard().  Making sure those functions work is essential to individual card functionality.  I should also revisit some individual tests to make sure I cover each method in the functions correctly, I only visited the ones I deemed important to that particular function.  

*/
