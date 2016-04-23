FUNCTION/CARD              BUG REPORT
-------------              -----------------------------------------------------
smithyCardEffect()         NOTE: Smithy gains from discard/deck to hand, but the
                             Smithy card itself is intended to be discarded, so
                             the NET number of new cards in hand is two (+2)

                           BUG: Similar to the note above, the discard deck
                             should see a NET reduction of two (-2) cards.  My
                             testing revealed a bug in that the Smithy is being
                             trashed rather than being put in the discard pile.
                             This was identified after noting a NET reduction
                             of three (-3) cards.  This was a bug I put in
                             during Assignment #2.

 
