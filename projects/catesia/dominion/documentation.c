Smithy card:

Description:
When the smithy card is played by a player. That player will draw three cards, then discard the smithy card.

Code Explination:
  When the smithy function is called two things must be known. First whose turn it is, and second which card in that players hand is the smithy card. Once smithy is played the drawCard() function will be called three times, then the discard function is called to make the player discard the smithy card.

Adventurer Card:
Description:
When a player plays the adventurer card. That player reaveals cards from their deck until they find two treasure cards, then all non-treasure cards revealed this way are discarded.

Code Explination:
This card is a little more difficult to implement then it first looks. The first thing you need to do is keep track of how many treasure cards you have revealed, and when you reveal two the function needs to go to the discard step. To do this a fake hand is created where cards are drawn into untill two treasure cards are drawn. Along the way if at any point the deck runs out of cards the discard pile is shuffled into the deck. Once the two treasure cards are in the fake hand they are moved to the current players hand, and all other cards are discarded from the fake hand.

discardCard:

  Discard card works by taking in the current player, the position of the card to be discarded in the players hand, and whether or not the card should be trashed. If the card is to be trashed, then it is removed from the players hand and deck entirely. Next if the card is not trashed, then it is added to the cards in play. Once it is in play the gap on the players hand is filled by moving the other cards over, and the players total card count is reduced by one.

updateCoins:

    The update coin function works by starting the coin count at zero. Then it moves throught the player's hand looking for any coins. For each copper the coint count is incremented by one, for silver two, and gold three. Next it checks for any bonus values that may have been added. Then it has the total coin amount.
													
