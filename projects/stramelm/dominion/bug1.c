FUNCTION/CARD              BUG REPORT
-------------              -----------------------------------------------------
smithyCardEffect()         NOTE: Smithy gains three (+3) from deck/discard to
                             hand, but the Smithy card itself is discarded to
                             the played pile (where so far as I can tell it
                             stays), so the number of new cards in
                             hand should be two (+2), while the number of cards
                             out of deck/discard will be three (-3)

                           BUG: I added a bug to this function in Assignment 2.
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

                           BUG: There are actually two bugs - one of which is
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

                           BUG: The bug in this function is that the one (+1)
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

                           BUG: I added a bug to this function in Assignment 2.
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