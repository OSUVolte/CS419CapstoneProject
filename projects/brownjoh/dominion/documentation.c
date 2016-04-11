/*John Brown
Documentation for smithy and adventurer cards.


Smithy Card:

Playing this card allows the player to draw three additional cards.  After
this is completed the Smithy card is discarded. This card is  enumerated in
dominion.h as an integer value of 13.  Interface.c allows for the retrieval of
card name and cost by switching on the  enumeration value of smithy.  When
this card is played, smithy is passed to the cardeffect function.  The
drawcard function is iterated through 3 times  then the handpos (position of
the card in hand) is passed to the discardcard function which discards the
smithy.  Playing of this card is then ended and play continues.  In
interface.c, the card has a cardNumToName of "Smithy" and the getcost function
in dominion.c returns the card  cost value of 4.

Adventurer Card:

Playing this card allows the player to reveal cards from their deck until two
treasure cards are revealed.  All the revealed cards and the adventurer card
are discarded.  This card is  enumerated in dominion.h as an integer value of
17.  Interface.c allows for the retrieval of card name and  cost by switching
on the  enumeration value of adventurer.  When this card is played, adventurer is
passed to the cardeffect function.  While loop in effective until two treasure
cards are uncovered.  Each card drawn is placed in a temphand variable, and
checked against  the three treasure card types.  If card is a treasure, it is
added to player's hand.  If  not another card is drawn.  If deck is empty,
shuffle is called.  After two treasures  are uncovered, temp deck is looped
through and passed to the discarcard function Playing of this card is then
ended and play continues.  In interface.c, the card has a cardNumToName of
"Adventuer" and the getcost function in dominion.c returns the card  cost
value of 6.

Discardcard function

Used to discard one card from the player's hand.  The hand position of the
card, the current player,  the game state and a trash flag are all passed to
the function.  If card trash is set to 1, the card is placed in the played
pile (otherwise trashed card functions like discarded.  Because trashed card
not   added to the played pile, when it is removed from the hand it is rmeoved
from the game). If only one card in the   hand or last card in hand array is
played, the legnth of the card array is simply reduced by one.  Otherwise, the
last card replaces the discarded card and the legnth of the hand array is
reduced by one.

UpdateCoins function

This function is used to update the amount of coins player has for a given
turn, normally  during the buy phase.  The player, game state, and bonus coin
amount are passed in to  the function.  First the player coin amount is
initialized to 0.  The current player's hand is iterated through.  Each card
in the hand  is tested for being one of the three treasure types.  For copper,
silver and gold the  coin is incresed by 1, 2 or 3 respectively.  Finally, any
bonus coin amounts are added to the coin total.*/
