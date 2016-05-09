/*
Ryan Peters
05/06/16

Random Test Adventurer
	My first iteration had 100% of the function used for the adventurer card.  I had problems with randomly
	generated data.  The tester would crash when I used randomly generated information for all the infromation
	in the game state.  I switched to creating an empty game state the initializing a game.  Then I would randomly
	generate the information I was testing for.  I tried using the random fuction in rngs.c but it was not working.
	I followed the setup in the lectures but it was not generating random numbers.  I switched to using rand() from
	stdlib.  The random generation started working but the testing would crash.  The problem was coming from 
	making handCount, deckCount, and discardCount using MAX_HAND and MAX_DECK.  I changed the tester to use 
	random values up to 50 for handCount, deckCount, and discardCount.  The test coverage was 100% for the adventurer
	card.
	
Random Test Council Room
	I took the lessons I learned in testing the adventurer card.  I tested using MAX_HAND and MAX_DECK to see if the 
	problem was just for the adventurer card.  It caused the tester to crash, so I switched to using a max size of 50.
	The test coverage was 100% for the council room.  
*/