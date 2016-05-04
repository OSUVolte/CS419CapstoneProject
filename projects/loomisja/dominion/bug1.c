Jason Loomis
4/24/2016
Assignment 3: Unit Testing
Filename: bug1.c

=== Bugs found by unit tests of dominion.c ===
There were many bugs that my unit tests revealed in the dominion.c codebase.
TOTAL BUGS FOUND: 8

* unittest1.c (tests dominion.c fullDeckCount() function)
fullDeckCount as implemented counts the number of a particular card type found in a player's complete deck (that is, the deck + hand + discard).
NO BUGS found based on unit testing.
Function works as advertised for all card types.

* unittest2.c (tests dominion.c getCost() function)
getCost as implemented gets the cost of each enumerated card type.
NO BUGS found based on unit testing.
Function returns correct costs for all card types per the reference costs found here: https://dominionstrategy.com/all-cards/
Function also returns the expected -1 for card type values outside the enumeration bounds.

* unittest3.c (tests dominion.c scoreFor() function)
scoreFor is supposed to calculate the game scores for each player.
scoreFor fails a variety of tests and does not properly calculate game scores under many conditions.
There appear to be 2 distinct bugs:
1. The scoring for gardens cards is not calculated correctly. 
The typical implementation looks like this:
score = score + (fullDeckCount(player, 0, state) / 10)
Which calculates the fullDeckCount for card 0, the curse card only. The Rule for gardens is that it adds +1 victory point for every 10 cards in the player's deck, so the gardens score contribution SHOULD be [count of all cards in player's hand + deck + discard] / 10. This leads to lower scores than expected. The same bug occurs in the loops calculating the score contributions for the player's cards in hand, deck, and discard.
2. The loop termination condition is incorrect for the calculation of the score contribution of the player's deck. The loop is based on the discardCount, where it should be based on the deckCount (since it is iterating over the deck cards). This leads to unpredictable scoring, since it can loop over more than the valid range or less than the valid range for the user's. If it loops beyond the valid range of the deck, it could include invalid values or uninitialized garbage that may be stored there.

* unittest4.c (tests dominion.c isGameOver() function)
isGameOver as implemented is supposed to determine when the game is over. Per the documentation here: http://riograndegames.com/getFile.php?id=348 (see page 8 of PDF), the game is over when all the Province cards are gone OR when any three supply card piles are gone.
There appears to be 1 bug:
1. My unit test tests all combinations of "three empty supply card piles". As the function is implemented, combinations where piles that contained card 25 (sea_hag)or 26 (treasure_map) are empty are not inspected, so these will not be counted when checking for game-over when the kingdom includes these cards.
(2) Another bug *could* occur if any function changed the game state to make any non-used supply card piles have count of 0--the function inspects all supply card piles (including unused ones), so unused piles with zero-values could signal a game-over. However, as it is implemented now, the initializeGame function ensures that unused supplies have a non-zero value.

* cardtest1.c (tests cardEffect for smithy)
The Smithy Rule is "+3 cards".
As implemented, the smithy card effect does not work quite as expected.
Unit testing revealed 1 bug:
1. The smithy card effect draws 4 cards instead of the expected 3. This is due to an incorrect loop termination on the loop that draws the cards, which I had introduced intentionally. Note that initially, for assignment 2, I had introduced a bug that would cause a buffer overflow due to improper indexing, but I fixed that bug and introduced the "draw 4 cards" bug instead so that I could continue testing.

* cardtest2.c (tests cardEffect for adventurer)
The Adventurer Rule is "Reveal cards from your deck until you reveal 2 Treasure cards. Put those treasure cards in your hand and discard the other revealed cards."
As implemented, the adventurer card effect does not work quite as expected.
Unit testing revealed 3 bugs:
1. There was a buffer/stack overflow in which the function would just continue recycling the discarded deck if fewer than the requisite 2 treasure cards were found. I fixed this bug by adding in a counter for the number of shuffles performed so that I could continue running tests.
2. My unit testing revealed the bug I introduced for Assignment 2, where I changed the conditions checked by the function for the card drawn. Per the Rule, the reveal is supposed to end after revealing any 2 treasure cards (copper, silver, or gold). The function was failing to recognize silver as a treasure card due to the bug I had added. This lead to silver cards being discarded and excess cards being revealed.
3. My unit testing revealed a somewhat less obvious bug as well. This bug only reveals itself in the context of the actions of the adventurer (or possibly other cards that are implemented in a similar fashion): the adventurer pulls cards from the player's deck into a temporary hand (they are not discarded directly); when this happens, all the cards are drawn from the deck and effectively "disappear", so if the discard pile was empty to begin with, when drawCard attempts to draw and both the discard and deck are empty, it returns an error value of -1. Adventurer does not check this return value, and assumes that a valid card was drawn. It then removes the assumed card from the player's hand if it was not treasure, which eventually will (unintentionally) also deplete the player's hand.
(4) Another bug *could* have been that the adventurer did not call discardCard at the end of the effect, so the player would have been allowed to keep the card. However, I fixed that bug when I was working on Assignment 2.

* cardtest3.c (tests cardEffect for council_room)
The Council Room Rule is "+4 Cards, +1 Buy, Each other player draws a card".
As implemented, the council_room card effect does not work quite as expected with respect to drawing cards for the other players. Other actions work as expected.
Unit testing revealed 1 bug:
1. For Assignment 2, I changed the if condition for the step in the function that draws cards for the other players--it was checking that the player being drawn for was NOT the current player, but I changed it to be "less than" the current player. Consequently, when the current player is not the last player index, not all the other players receive the card they are supposed to receive.

* cardtest4.c (tests cardEffect for village)
The Village Rule is "+1 Cards, +2 Actions, each other player draws a card".
The village card effect was NOT one that I altered for Assignment 2.
NO BUGS found based on unit testing. The player properly receives +2 actions and draws +1 extra card.