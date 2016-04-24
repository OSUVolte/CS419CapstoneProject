//smithy - current player draws 3 cards, then discards the played smithy card
//adventurer - draw cards until current player receives 2 treasure cards, cards that are not treasure 
//cards are discarded
//discardCard - card added to discard pile if the trash flag is false, then the hand and hand count for
//the current player are updated
//updateCoins - coins are calculated based on treasure cards in player's hand, 
//coins are held in the state struct, it's first reset to 0, then different amounts are added for
//silver, gold, copper 
