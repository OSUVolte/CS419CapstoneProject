FUNCTION/CARD              BUG REPORT
-------------              -----------------------------------------------------
smithyCardEffect()         NOTE: Smithy gains three (+3) from discard/deck to
                             hand, but the Smithy card itself is intended to be
                             discarded, so the NET number of new cards in hand
                             should be two (+2)

                           BUG: Similar to the note above, the discard/deck
                             should see a NET reduction of two (-2) cards.  My
                             testing revealed a bug in that the Smithy is being
                             trashed rather than being put in the discard pile.
                             This was identified after noting a NET reduction
                             of three (-3) cards.  This was a bug I put in
                             during Assignment #2.

-------------              -----------------------------------------------------
adventurerCardEffect()     NOTE: Adventurer gains two (+2) treasure from
                             discard/deck to hand, but Adventurer card itself is
                             intended to be discarded, so the NET number of new
                             cards in hand should be one (+1) - both TREASURE

                           BUG: There are actually two bugs - one of which is
                             built into the original source code and one of which
                             I added during Assignment #2.  This bug is that the
                             code continues to draw until three (+3) TREASURE
                             cards have been drawn instead of two.  Additionally,
                             there is no call to discardCard() in the original
                             source, to the Adventurer card itself is not
                             discarded.  These errors together result in a NET
                             three (+3) cards in hand - all of which are TREASURE.


