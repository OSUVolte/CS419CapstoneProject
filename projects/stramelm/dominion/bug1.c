FUNCTION/CARD              BUG REPORT
-------------              -----------------------------------------------------
smithyCardEffect()         NOTE: Smithy gains three (+3) from deck/discard to
                             hand, but the Smithy card itself is discarded to
                             the played pile (where so far as I can tell it
                             stays), so the number of new cards in
                             hand should be two (+2), while the number of cards
                             out of deck/discard will be three (-3)

                           BUGS: I added a bug to this function in Assignment 2.
                             The bug sends smithy to the trash instead of to the
                             played pile.  However, the current suite of tests
                             aren't sufficient to detect this bug because it
                             doesn't appear that the code is yet implemented to
                             move cards back from the played pile to the discard
                             pile.  Right now setting the trash flag to 0 or 1
                             makes no difference.  That said, it does show up as
                             a failed test due to this missing implementation.

-------------              -----------------------------------------------------
adventurerCardEffect()     NOTE: Adventurer gains two (+2) treasure from
                             discard/deck to hand, but Adventurer card itself is
                             intended to be discarded to the played pile, so the
                             NET number of new cards in hand should be one (+1)
                             in total, but both of the added cards are new
                             treasure cards.  Meanwhile, the total number of cards
                             out of the deck/discard should be one (-1).

                           BUGS: There are actually two bugs - one of which is
                             built into the original source code and one of which
                             I added during Assignment #2.  This bug is that the
                             code continues to draw until three (+3) TREASURE
                             cards have been drawn instead of two (+2).
                             Additionally, there is no call to discardCard() in
                             the original source, so the Adventurer card itself is
                             not discarded.  These errors together result in a NET
                             three (+3) cards in hand - all of which are TREASURE.

                             Another problem is that there is code implemented to
                             add drawn non-treasure cards back to the discard pile.
                             This is inconsistent with other methods used by other
                             functions.

-------------              -----------------------------------------------------
council_roomCardEffect()   NOTE: Council_room gains four (+4) cards, one (+1)
                             buy, and one (+1) card for every other player.  The
                             council_room card itself is discarded to the played
                             pile (where so far as I can tell it stays), so the
                             number of new cards in hand should be three (+3),
                             while the number of cards out of deck/discard will
                             be four (-4) for the current player.  It will be
                             +1/-1 for other players

                           BUGS: The bug in this function is that the one (+1)
                             card that each OTHER players are suppossed to get
                             doesn't happen.  Instead, the CURRENT player gets
                             an additional one (+1) card.  So their are test
                             failures in that the other players are unchanged and
                             that the current player has too many cards in his
                             hand/out of deck/discard.

-------------              -----------------------------------------------------
villageCardEffect()        NOTE: Village gains one (+1) card and two (+2) actions.
                             The village card itself is discarded to the played
							 pile (where so far as I can tell it stays), so the
							 number of new cards in hand should be zero (0),
                             while the number of cards out of deck/discard will
                             be one (-1) for the current player.

                           BUGS: I added a bug to this function in Assignment 2.
                             The bug sends smithy to the trash instead of to the
                             played pile.  However, the current suite of tests
                             aren't sufficient to detect this bug because it
                             doesn't appear that the code is yet implemented to
                             move cards back from the played pile to the discard
                             pile.  Right now setting the trash flag to 0 or 1
                             makes no difference.  That said, it does show up as
                             a failed test due to this missing implementation.

                             There remains some question over whether or not the
                             incomplete discard implementation is a "bug" or just
                             code that needs re-factoring or completing.

-------------              -----------------------------------------------------
isGameOver()               NOTE: Function should return 1 if no more province cards
                             or if any 3 other cards are empty.

                           BUGS: Fairly simply function but I did find a bug.  The
                             function incorrectly reports FALSE (GAME NOT OVER) if
                             1 or 2 of the 3 NON-province cards that are required
                             to be empty in combination are the sea-hag or
                             treasure_map cards.  The function is setup with a loop
                             to check just the first 25 cards but there are 27 in
                             the CARD enum.

                             The function is tailor made for random testing.  I
                             refrained from random testing however due to the
                             instructions to do unit testing only.

-------------              -----------------------------------------------------
scoreFor()                 NOTE: Function should return the total score for a given
                             player based on the sum of the scores of the victory
                             cards (and curses) in his hand, deck, and discard piles.

                           BUGS: All tests of scoreFor() fail because of a couple of
                             different bugs.  First, to get to deck score the counter
                             is using the number of cards in the discard pile.  Second,
                             scoreFor() makes a call to fullDeckCount() but uses it
                             incorrectly.  fullDeckCount() gives the total number of
                             a particular card type in the deck, not the total number of
                             ANY card type in the deck.  fullDeckCount() is being called
                             in such a way that it always counts ONLY curse cards.
                             Additionally, there is no need to call fullDeckCount at all
                             because the total number of cards can be determined via the
                             loops that already exist in scoreFor().

                             Finally, my test didn't reveal this, but it becomes apparent
                             in the discussion of the call to fullDeckCount().  scoreFor()
                             is currently (trying to) assess the score for garden() by
                             taking each hand/deck/discard total and dividing by 10
                             individually and then summing those results.  It should be
                             summing the card totals first and then dividing by 10.  It's
                             subtle but could result in "off-by-1" errors in the return vals.

-------------              -----------------------------------------------------
fullDeckCount()            NOTE: Function should return the count of a specific card in
                             a specific player's possession (hand, deck, and discard piles).

                           BUGS: This is a fairly simple function.  I found no bugs.
