Smithy card
    Action type card
    Player draws 3 cards. Then discards this card from hand.
    
Adventurer card
    Action type card
    Player continuously draws card from their deck until they get 2 treasure cards.
        if the deck is empty, they need to shuffle the discard and add it to the deck.
    If the card is not a treasure card, the card will be discarded.
    
discardCard()
    takes handPos, currentPlayer, gameState, and trashFlag
    if the trashFlag is not set, add it to the played cards pile, increase 
        playedCardCount by one.
    change the player hand position to -1
    if it is the last card played, reduce the number of cards in hand by one and
    if there is only one card in hand, reduece the number of cards in hand by one
    else the current handPos card will be replaced with the following card in the hand.
        the last card in the hand will be set to -1
        the number of cards in the players hand will be reduced by 1
        
updateCoins()
    takes player, gameState, bonus
    set the coin count to 0
    go through the players entire hand
        if the card is a copper, += 1 to the coin count
        else if the card is a silver, += 2 the coin count
        else if the card is a gold, += 3 to the coin count
    add any bonuses to the coin count
    
    