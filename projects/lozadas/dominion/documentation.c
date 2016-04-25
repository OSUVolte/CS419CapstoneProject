
/*
Smithy action:
Draws three cards by invoking drawCard function three times in a for loop. Once the action is performed the card is discarted by calling
the discardCards function. The smithy cost is 4 coins.   

Adventurer action:
While drawnTreasure is less than 2, invoke drawCardi function to reveal cards from desk.If the card is a treasure card increment drawnTreasure variable by one else add card to tempHand
If the deck is empty shuffle discard and add card to deck.Place treasure card into hand and discard all cards in play that have being drawn by performing second while loop where discardCard 
is invoked until tempHand is empty. The adventurer cost is 6 coins.

discardCard():
If trashflag is false add card to played pile and increase playedCardCount. Set played card state to -1. If last card in the hand is played reduce the number of cards in the hand else
replace discarted card with last card in the hand.Set last card state to -1 and reduce the number of cards in the hand.    

updateCoins():
Reset coins balance to then add coins for each treasure card in the players hand. Add bonus coins when applicable.


*/
