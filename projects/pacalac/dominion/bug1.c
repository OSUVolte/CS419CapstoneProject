Bugs:

unittest1 - no bugs found in fullDeckCount()

unittest2 - no bugs found in gainCard()

unittest3 - no bugs found in discardCard

unittest4 - bug found. buyCard() fails to add a card to the player's hand after it is successfully 
	purchased. It adds it to the discard instead.
	
cardtest1 - bug found. Adventurer card is not discarded after it is played.

cardtest2 - bug found. Smithy card is not discarded after it is played.

cardtest3 - bug found. Council Room adds 1 extra card to player and doesn't increment the buy count for the player.

cardtest4 - bug found. The way Steward adds coins to the player doesn't actually update the player's coins.
	The Steward card also does not discard two cards when that option is selected, it is the only card discarded in that case.