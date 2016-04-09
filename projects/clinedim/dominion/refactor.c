/*
	In this file, I will be providing documentation for the refactorings I made to
	both the dominion.h and dominion.c files.  This documentation appears below.

	I began my work by adding several function prototypes to the dominion.h file, based
	on what I would need in order to implement functions to handle the playing of five
	different card types.  The prototypes that I added are listed below:

		int playAdventurer(int drawntreasure, struct gameState *state, int currentPlayer, int *temphand, int z);
		int playSmithy(int currentPlayer, struct gameState *state, int handPos, int trashFlag);
		int playVillage(int currentPlayer, struct gameState *state, int handPos);
		int playCouncil_Room(int currentPlayer, struct gameState *state, int handPos, int trashFlag);
		int playGardens();

	In addition to adding the prototypes listed above, I also added function definitions 
	to the dominion.c files.  These were fairly easy to implement--I mainly used the code
	that was in the case statements.  It wasn't entirely that simple, though, and there was a
	bit more refactoring for some of the functions, such as playAdventurer.  This function was
	the most complicated and required making some changes to the actual code.

	While I was performing the refactorings to dominion.c, I ran into a bug where Player 0 was the
	only one who was "playing" the game.  It took me a while to figure it out, but I realized that
	I was neglecting to break out of the case statements that I had created and was "falling through"
	to the next case statement.  For instance, here's how I initially refactored the adventurer case
	statement:

		case adventurer:
			playAdventurer(drawntreasure, state, currentPlayer, temphand, z);

	There was no return statement in what was above, so after the playAdventurer function terminated, the
	code was "falling through" to the next case statement which was producing the bug.  I ended up needing
	to change this for all of my refactored case statements.

	After comfirming that my functions were behaving as expected, I performed some additional refactorings
	to introduce bugs into the program.  These are described below:

			*** playAdventurer:  The Adventurer card is meant to look through the player's deck to find treasure
			cards.  There is an branch in the code that performs this check on each card that is drawn:

				if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
					drawntreasure++;
				}

			I introduced a bug by removing the copper check so that only silver and gold cards pass the if
			check:

				if (cardDrawn == silver || cardDrawn == gold) {
        			drawntreasure++;
        		}

			*** playSmithy:  The Smithy card is allows the player to draw three new cards.  I introduced a bug
			that makes it draw four cards instead.  Here is the original code:

				for (index = 0; index < 3; index++) {
					drawCard(currentPlayer, state);
  				}

  			Here is the version of the code containing the bug that I introduced:

  				for (index = 0; index < 4; index++) {
					drawCard(currentPlayer, state);
  				}

  			*** playVillage:  The Village card allows the user to draw an additional card and get two extra actions.
  			I introduced a bug where the card does not allow the user to get an additional card and the player gets
  			three extra actions.  Here is the original code:

				drawCard(currentPlayer, state);
				state->numActions = state->numActions + 2;

			I changed it to what appears below:

				state->numActions = state->numActions + 3;

			*** playCouncil_Room:  The Council Room card allows the player to draw four cards and make an additional 
			buy, but also allows every other player to draw a card.  I introduced a bug where the player draws 3 cards
			instead and the number of buys is decremented.  Here is the original code:

				for (index = 0; index < 4; index++) {
					drawCard(currentPlayer, state);
				}

				state->numBuys++;

			Here is the buggy code:

				for (index = 0; index < 3; index++) {
					drawCard(currentPlayer, state);
				}

				state->numBuys--;

			*** playGardens:  The Gardens card is worth 1 victory point for every 10 cards in the deck.  In the original
			version of the code, the function simply returned -1.  I introduced a bug by making it return 0 instead.
*/