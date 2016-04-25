/*John Brown
Changes to dominion.c and dominion.h

smithy card

When playing smithy card, card effect calls playSmith function rather than
handling the card in the switch statement.  The functionality previously in
cardeffect was copied into the new function. Error Introduced: Trash flag set
to 1 when calling discard card.

adventurer card

When playing adventurer card, card effect calls playAdventurer function rather
than handling the card in the switch statement.  The functionality previously
in  cardeffect was copied into the new function. Error Introduced: Additional
cards drawn until 3 treasures found (while drawntreasure <= 2).  After
treasures are found, temp hand is discarded based on the  number of treasures
drawn -1, not the number drawn into the temp hand, meaning that only part of
the cards drawn are likely to be put in the discard pile.

village card

When playing village card, card effect calls playVillage function rather than
handling the card in the switch statement.  The functionality previously in
cardeffect was copied into the new function. Error Introduced: When calling
playVillage in cardeffect, I pass nextPlayer instead of current player.  In
the playVillage function, the cardPos of the village card  is added to the
actions instead of the literal 2.

council_room card

When playing council_room card, card effect calls playCouncil_room function
rather than handling the card in the switch statement.  The functionality
previously in  cardeffect was copied into the new function. No Errors to this
function.

salvager card

When playing salvagercard, card effect calls playSalvager function rather than
handling the card in the switch statement.  The functionality previously in
cardeffect was copied into the new function. Error Introduced: In playSalvager
function, the first if checks for true on handPos instead of choice1.  In
cardeffect error checking for playSalveger call is wrong. Checks that returned
in is > 0 instead of < 0.
*/