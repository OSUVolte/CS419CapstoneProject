// Not compilable C code

initializeGame():
After running:
* gameState->numberPlayers should == numberPlayers passed in
* numberPlayers should not be allowed to be greater than MAX_PLAYERS or less than 2
	- if otherwise, return error
* each kingdom card must be different
	- if otherwise, return error
* each player has 3 estate cards and 7 copper
	- estate cards do not come from available cards on table
* for two players, eight each of provinces, duchies, and estates available
	- for three or four players, use 12 each instead
* ten curse cards available for each player beyond the first player
* first player draws 5 cards
	- so first player has 7 copper, 3 estates, shuffled, and 5 random other cards
* first player may perform action once and buy once
* begin with phase count 0, 0 cards played, 0 outpost played, 1st player's turn

kingdomCards():
* returned array should have the same values as were passed in
* kingdomCards() should validate the types of cards passed in by range

shuffle():
* player's cards should be shuffled between discard and deck
	- none should be missing
	- no new cards should be added
* other players' cards should not be modified

fullDeckCount():
* should return the count of the specified card in the player's hand, deck, and discard pile
* should not change the player's cards

~~~~~~~~~~~~~~~~ CARD TESTS ~~~~~~~~~~~~~~~
smithy:
* player should draw 3 cards from their deck to their hand
* player's played (smithy) card should be 
* no other players should be affected

adventurer:
* digs through deck until 2 treasure cards are found
* any cards pulled before those treasure cards are found are discarded