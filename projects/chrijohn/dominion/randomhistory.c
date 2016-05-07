Play Adventurer :
The following inputs are randomized :
	Number of actions(0 - 100)
	Number of buys(0 - 100)
	Number of coins(0 - 100)
	Number of cards in hand(0 - 100)
	Number of cards in deck(0 - 100)
	Number of cards in discard(0 - 100)
	Which cards in hand(0 - 25 for each card)
	Which cards in deck(0 - 25 for each card)
	Which cards in discard(0 - 25 for each card)
The following items are checked before and after playing card to ensure correctness :
	Number of actions(should remain the same)
	Number of buys(should remain the same)
	Number of coins(should remain the same)
	Number of cards in hand(should increase 1)
	Number of cards in discard and deck combined(should decrease 1)
	Number of treasures in hand(should increase 2)
	Number of treasures in discard + deck + played (should decrease 2)
	Number of cards in each supply pile(should remain the same)
	Number of cards in opponents hand, deck and discard(all should remain the same)
I selected the random inputs based on what should affect the Adventurer card.The key inputs to be randomized are the user’s hand, deck and discard count and which cards in each position.By randomized the range of each to be 0 - 100 that is larger than any realistic game situation and by randomizing each individual card it also goes beyond realistic situations(like having 100 Gold cards) to stress the function.I kept many inputs(such as opponents hand, kingdom cards, supply pile counts) non - random since they do not affect the Adventurer card.If I found them changing during the test(indicating a bug), I would have randomized in an attempt to find more details about the bug.

I did restrict two aspects of the randomness to prevent false errors(testing reports error when there isn’t one in the source code).First, I put the Adventurer card in position 0 in the player’s hand.This is the card that gets played and discarded.If a treasure card was in this position, it would report incorrect treasure counts in both hand and deck / discard.Secondly, I ensured there are 2 treasures in the deck and discard piles.Having fewer than two causes some weird results since the player cannot draw 2 treasures as directed to by the card.

The testing found errors in every 1, 000 test cases.  526 errors was in treasure counts(both hand and deck + discard).After looking at the source code, there is a bug that will draw 2 cards until a copper, smithy or gold is drawn instead of copper, silver or gold.This bug caused an error 52.6% of the time(which makes sense from a probability perspective).  995 errors were found in the hand and deck / discard counts.This is caused by not discarding adventurer card.In isolation, this should have been an error 100 % of the time, but the .5% success rate is due to a rare combination of both errors.This .5% condition is when there are only 1 copper, smithy or gold cards(but more silvers) in the player’s deck and discard.Only one card can be drawn causing a second error that cancels the first out.All other tests passed every 1, 000 times.

In terms of coverage, it covered 24 % of lines, 25 % of branches and 13 % of calls in dominion.c.In the playadventurer function, it returned 100 % and executed 100 % of blocks.This is an improvement from the unit testing when it did not reach all lines due to not needing to scuffle the deck.

In order to test correctness, I corrected the source code(changing smithy to silver and actually discarding the card).This produced 100 % successful tests.I also introduced other random bugs(changing number of coins, supply counts, opponents cards…) and the test also picked up those bugs.

Play Village :
The following inputs were randomized :
	Number of actions(0 - 100)
	Number of buys(0 - 100)
	Number of coins(0 - 100)
	Number of cards in hand(1 - 100)
	Number of cards in deck(1 - 100)
	Number of cards in discard(1 - 100)
	Which cards in hand, deck and discard(0 - 25 for each card)
The following items are checked before and after playing card to ensure correctness :
	Number of actions(should increase 2)
	Number of buys(should remain the same)
	Number of coins(should remain the same)
	The number cards in hand(should remain the same : discard village but draw another card)
	Number of cards in deck + discard + played(should remain the same : gain discarded village but lose drawn called)
	Number of card in each supply pile(should remain the same)
	Number of cards in opponents hand, deck and discard(all should remain the same)

Similar to the adventurer test, I randomized the inputs that should have an effect and kept the non - relevant inputs non - random.

I made similar decisions to limit false positive in errors.First, I put the Village card in position 0 in the player’s hand.Secondly, I adjusted the randomization for hand, deck and discard to be from 1 - 100 instead of 0 - 100.  Both 0 and 1 cards in either pile is not realistic, but ensure at least 1 card is in each makes it impossible that there is no cards in the deck and discard pile, which would cause errors(since the Village card requires a card to be drawn).These two decision prevent errors messages that aren’t really bugs.

The tests passed every 1, 000 runs.

In terms of coverage, the random test executed 20 % of lines, 23 % of branches and 11 % of calls in dominion.c.Every line of the village function was called every time for 100 % coverage.

To confirm the test is correct, I introduced bugs to see if the random test could find them.I changed the actions added, drawing the card, changing opponent’s cards count, and coin count.The test picked up on all of these bugs.
