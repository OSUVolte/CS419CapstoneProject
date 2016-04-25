//Derek Wong
//CS362
//Bug1.c

unittest1 (Shuffle): No Bug 

unittest2 (isGameOver): No Bug

unittest3 (drawCard): No Bug

unittest4 (discardCard): No Bug

cardtest1 (smithy): No Bug

cardtest2 (council_room): 1 Bug
I introduced a bug in this function in the previous assignment. The cards adds 4 cards to the current players hand, increase numBuy by 1, and adds 1 cards to every other player. The bug is that the current player gets another card during the code where it is passing out 1 card to every other player. So the current player is getting 5 cards because of this. This decreases the deck count of the current player by 1 extra and increases the hand count of current player by 1 extra as well.

cardtest3 (village): 1 Bug
I introduced a bug in this function in the previous assignment. The card adds 1 card to the hand and adds 2 actions. The bug is that the number of action getting added is incorrect. It is acutally adding the number of buys + 2 instead of number of action + 2.

cardtest4 (steward): No Bug

