After running all of my unit tests and card tests on my refactored dominion.c code, my adventurer (cardtest1.c), smithy(cardtest2.c), and great hall (cardtest3) testcases picked up on some bugs. The adventurer card is supposed to have the current player draw cards from the deck array until they draw 2 treasure cards. The drawn non-treasure cards are then discarded into the player's discard array, and the 2 treasure cards stay in the player's hand. Cardtest1.c performs a series of tests to make sure after playing adventurer, the current player's hand count increases by 2, the hand array has 2 extra treasure cards, the total number of cards in the deck and discard array combined is 2 less than before, and their combined cards is missing the 2 treasure cards that are now in the player's hand. This unit test also tests that the counts and hand, discard, and deck arrays for other players do not change. Cardtest1.c ran the same test 4 times with different inputs on adventurer and all four runs came back with all failures for the current player, and all successes for other players. The results for the first run are below:

Current Player:
FAILURE: Total card count is incorrect (deck+hand+discard).
FAILURE: The handCount did not increase by 2.
FAILURE: The hand array did not increase by 2 cards.
FAILURE: The hand array did not increase by 2 treasure cards.
FAILURE: The total cards in deck+discard is not 2 cards less than before.
FAILURE: The deck and discard are either missing or containing invalid cards.

Other Players:
SUCCESS: Player 0's hand count did not change.
SUCCESS: Player 0's hand cards are the same.
SUCCESS: Player 0's deck count did not change.
SUCCESS: Player 0's deck cards are the same.
SUCCESS: Player 0's discard count did not change.
SUCCESS: Player 0's discard cards are the same.

The subtle bugs that I introduced into the refactored adventurer code was enough to mess with the hand count, hand array, deck array, and discard array. Since all of the tests failed, it can be deduced that the player may have drawn the wrong number of cards as that would cause the the player's hand, discard, and deck array and counts to be incorrect. Overall I think my input choices were pretty good, as they detected the bugs pretty instantly - although it could be that the bugs were very easy to detect. The inputs I used were gamestates with different hand, deck and discard counts; two out of the four gameStates I tested had empty decks. Since each of the four runs all failed for the current player, the bug seems to be very prevalent despite the input choices.

The next failures that I had were from the cardtest2.c, which tests smithy. Smithy has the current player draw 3 cards and discard one into the played pile. Cardtest2.c tests to makes sure that the player's hand has a net gain of 2 cards, the played card count increases by 1, and that the deck and discard decks together lose the same 3 cards that the current player draws. Cardtest2.c also evaluates other players to make sure their hand, deck, and discard counts are unchanged. Cardtest2.c ran 4 of the same tests with different inputs; the results for the first run are below:

Current Player:
FAILURE: The player's hand count shows a net gain of more than 2 cards.
SUCCESS: The player's played card count increased by 1.
SUCCESS: The player's total card count is correct.
FAILURE: The deck+discard pile lost more than 3 cards.
FAILURE: More than 3 cards from discard+deck are in the hand or played cards pile.

Other Players:
SUCCESS: Player 0's hand count is unchanged.
SUCCESS: Player 0's deck count is unchanged.
SUCCESS: Player 0's discard count is unchanged.

Based on the failures, one can deduce that the bug is that the current player must have drawn more than 3 cards from the deck. All the other 3 runs came back with the exact same success and failures as shown above. Like adventurer, the different input choices involved having different deck, hand, and discard counts. As the bug was caught in all four runs, it seems that the bug is easy to detect overall.









