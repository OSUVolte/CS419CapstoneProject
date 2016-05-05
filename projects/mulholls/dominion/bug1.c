Bugs Found:

1) isGameOver()
	This bug was due to a limit in how the suppieCounts were checked.
	It only checked cards 1-24, and ignored 25,26,27. Because it was a
	hardcoded value instead of the convention of treasure_map+1 it was
	pretty easy to miss. This is bad because if those three unchecked
	states were all 0, the game could be in a game over condition and the
	function could return a false game continues. I found this by checking
	the function with a specific state set up with 0 supplies in 25,26,& 27

2) discardCard()
	This bug I found just by looking at the code (and followed up by my)
	tests. This doesn't affect the discard[] or discardCount states at all.
	This is important because thats the whole point of the function. It was
	easily found by checking the number of states that should be changed.
	I also checked the discard state directly and the discard count directly.
	I also set the test up so that to check to see if the expected card was
	actually discarded. No discard call exists, so obviously these failed.

	I also noticed redundant code. Its not necessarily a bug, its just not
	neccessary. If the first condition is checking to see if its the last
	card location in the players hand, this is logically equivalent to the case
	where there is only 1 card left in the hand (which is what the second check)
	looks for.

3)adventurerCard()
	I found 3 bugs in this card: the first is that it doesn't perform its
	basic tasks fully. I checked the last 2 slots of the players hand with
	only gardens cards and coppers cards, and the newest two cards in the
	players hands weren't both coppers.

	The second is that the card is never actually discarded from the players
	hand. I found this by noticing that there was no discard call to remove
	the card, and so I checked it explicitly.

	The third bug I found was that it still found treasures when they didn't
	exist in the deck or discard to be found. This was due to the bug I
	introduced.

4) smithyCard()
	I found 3 bugs with the smithy card: the first is that it didn't perform
	its basic tasks fully. I believe this is due to the bug I introduced
	but the handCount of the state after the function is run is not equal
	to 2 higher than the initial handCount. If 3 cards are drawn and 1 is
	discarded, there should be a net change of +2 cards.

	The next bug is that the handCount should definitely change in the smithy
	card. I found that as its written in my dominion (my bug), the hand count
	isn't actually changing.

	The third bug is that running a total card count for the deck, hand, and
	discard before and after doesn't produce equal counts. Something is losing
	and or gaining cards.

5) villageCard()
	I found that the village card has 2 bugs. The first is that after running
	the number of actions isn't one action higher. If you use one action, and
	the card adds two actions there is a net gain of 1 action in numActions.

	The other bug is that the discard is showing that its not changing.
	I believe this is due to the discardCount() function bug I mentioned earlier
	.

6) stewardCard()
	This function had issues discarding as well due to the discardCard()
	function.
	Because the discard function is nested in the stewardCard(), it blocks
	my other state checks in my stateCheck function. Removing it, I also find
	that The deck isn't being changed during the draw option checks. The deck
	was set up to have 27 cards to begin with, so they shouldn't have to shuffle
	and the by drawing 2 cards the deck should change. On inspection, it appears
	the drawCard function doesn't update the deck to remove the card. It changes
	the size of the deck and adds it to the hand, but doesn't actually update
	the deck.
