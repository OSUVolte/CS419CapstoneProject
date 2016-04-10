Title: Errors introduced to the refactored dominion.c code from week 2

Explanation: Below, errors are numbered by the card they affect.
For each error, the erroneous line appears beneath the correct line.
The correct line has been commented out. Some errors are errors of omission.
The missing line(s) is then shown as being commented-out.
Nothing is shown beneath the comment.

Cards:

Adventurer

(1) One of the treasure cards is never tested, which leads it to be ignored when adding treasure to the player's hand
	//if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	if (cardDrawn == silver || cardDrawn == gold)

(2) [error in original file?] The Adventurer card appears not to be discarted after it is played.
    //discardCard(handPos, currentPlayer, state, 0);

Smithy

(1) Four cards are added instead of three. This is caused by the use of "<=" instead of "<"
    //for (i = 0; i < 3; i++)
    for (i = 0; i <= 3; i++)

(2) The Adventurer card appears not to be discarted after it is played.
    //discardCard(handPos, currentPlayer, state, 0);

Feast (Action: Trash this card. Gain a card costing up to $5.)

(1) Only 2 coins (and not 5) are added to the player's purse.
    //updateCoins(currentPlayer, state, 5);
    updateCoins(currentPlayer, state, 2);

(2) The comparitor is incorrect, <= rather than <. This compounds error 1 without erasing it.
    //else if (state->coins < getCost(choice1)){
    else if (state->coins <= getCost(choice1)){

(3) The player does not gain the card that was purchased. This may only show up by looking at the deck post-play.
    //gainCard(choice1, state, 0, currentPlayer);//Gain the card

council_room (Action: +4 Cards; +1 Buy. Each other player draws a card.)

(1) Opponents do not gain a card even though they should.
    //Each other player draws a card
    //for (i = 0; i < state->numPlayers; i++)
	//{
    //    if ( i != currentPlayer )
	//    {
    //        drawCard(i, state);
	//    }
	//}
