/***************************************************************************
** Author: James Pool
** ONID: 932664412
** OSU Email: poolj@oregonstate.edu
** Date: 24 April 2016
**
** Program Filename: bug1.c
** Description: This is the report file for bugs discovered from performing
**				the unit tests and card tests.
***************************************************************************/

Results for Unit Test 1:
	Tested Function: numHandCards()
	Analysis: PASSED
	Bugs: None
	
Results for Unit Test 2:
	Tested Function: buyCard()
	Analysis: PASSED
	Bugs: None

Results for Unit Test 3:
	Tested Function: scoreFor()
	Analysis: FAILED
	Bugs: 2 determined
		UT3-B1: Points for cards within the player's deck are incorrectly scored. This is due to the counter in the "score from deck" section using the discardCount not deckCount for it's loop upper limit.
		UT3-B2: Points related to the gardens card are incorrectly scored. This is due to an improper implementation of fullDeckCount. As written, fullDeckCount will only count instances of specific cards (parameter 2 [card]) instead of a total of all cards that is required for the scoring of gardens. Currently it only counts card 0, which is the curse card.
		
Results for Unit Test 4:
	Tested Function: fullDeckCount()
	Analysis: PASSED
	Bugs: None
	**Note: While this function will correctly count the instances of a particular card in the hand, discard, and deck, this might not be a correct implementation for it's usage (see bugs from unit test 3).**
	
Results for Card Test 1:
	Tested Card: Smithy
	Analysis: FAILED
	Bugs: 
		CT1-B1: The current implementation of the Smithy card appears to draw an additional card from the deck which is placed into the hand. It draws 4 cards instead of the intended 3.
		
Results for Card Test 2:
	Tested Card: Adventurer
	Analysis: FAILED
	Bugs:
		CT2-B1: During the phase of searching for treasure cards, the cards seem to go missing. The expected total card count (hand + deck + played) should be 10 for this initalization, in reality the total card count is 3, meaning that for this particular run 7 cards have been removed from the game entirely.
		
Results for Card Test 3:
	Tested Card: Village
	Analysis: PASSED
	Bugs: None

Results for Card Test 4:
	Tested Card: Remodel
	Analysis: FAILED
	Bugs:
		CT4-B1: The current implementation of the Remodel card appears to place the card destened for the hand into the deck.
		CT4-B2: The actual played count is higher that expected (2 instead of 1). A probably cause is the card that is suspose to be trashed ending up in the played pile instead.