/*
Smithy card- This allows the current player to draw three new cards. Then, the card is discarded and this block of code returns 0.

Adventurer card- The card allows the current player to continually draw cards from his or her deck until he or she draws two treasure cards. If the player’s deck becomes empty, the discard pile is shuffled and added back to his or her deck so that more cards can be drawn. Finally, when the player has drawn two treasure cards, the player discards all of the cards that have been drawn. At the end, this block of code returns 0;

discardCard()- It checks to see if the card has been trashed by the player. If not, the card is added to the player’s played pile. The card is removed from the player’s hand by setting that space in the hand to -1, then checking to see the position of the card to be removed, moving over the last card if necessary to fill the gap left by the discarded card, and decreasing the count by 1. Then, this function returns 0.

updateCoins()- The coin count is reset to 0. The coin count is incremented for every treasure card in the player’s hand: one for copper, two for silver, and three for gold. If there is a bonus, that is also added. Then, this function returns 0.
*/
