/*******************************************************************************
Michael Hueter | CS362 Assignment 2 | 9 April 2016

Cards:

  Smithy:
    The smithy is an action card, which is played during the action phase at the
    beginning of the turn. The action of the smithy lets the player draw three
    cards. This was implemented in the original Code by giving `case smithy` a
    for loop that runs 3 times, each time calling `drawCard()`. Afterwards,
    `discardCard()` is called so the card leaves the player's hand.

  Adventurer:
    The adventurer is also an action card. This one lets the player keep drawing
    cards until two treasure cards are drawn (treasure cards include: copper,
    silver, and gold), and the other cards are discarded. This is currently
    implemented with a while loop with two conditional checks.
      First we check if the deckCount of currentPlayer is less than one; if it
      is, the discarded pile is shuffled into the deck to give the player
      something to draw from.
      Next `drawcard()` is called and the drawn card is set to the top card in the
      player's hand.
      Then the code checks if it is a treasure card; if so, `drawntreasure` is
      incremented. If not, the code removes it from the player hand and puts it
      in a temp hand. After the treasure cards are drawn or the deck runs out,
      the temp hand is completely discarded.

Functions:

  discardCard():
    Removes the card from the current player's hand. Takes the position in hand,
    the current player id, a pointer to the game status struct, and `trashFlag`
    as parameters.
    If the `trashflag` is not set, the card gets sent to the played
    cards pile. Otherwise it is removed from the game entirely.
    The card is removed from the player's hand, and the last card in hand moves
    into the vacant position. If there are no cards left in the hand, decrement
    the `handCount`.

  updateCoins():
    Tallies the player's money count based on treasure and bonuses. Accepts
    current player id, a pointer to the game status struct, and a bonus int.
    A for loop iterates through the cards in the player's hand and adds the
    value of each treasure card (copper, silver, or gold) and, lastly, any bonus
    to the `coins` value for the turn.
