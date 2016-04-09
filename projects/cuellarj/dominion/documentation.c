Joe Cuellar
Documentation.c 

Dominion Documentation

Adventurer Card:
    Cards are drawn from deck till 2 treasure cards are drawn
    Non-treasure cards are discarded
    Treasure cards remain in hand

Smithy Card:
    Draw 3 cards
    Discard 1 card

discardCard()
    input: int handPos
           int currentPlayer
           struct gameState
           int trashFlag

    use the handPos value to determine the cards place in the hand
    currentPlayer used to identify which hand
    apply trashFlag to discarded card

updateCoins()
    input: int player
           struct gameState
           int bonus

    reset coins for player to 0
    tally up value of all treasure cards in hand
    add bonus
