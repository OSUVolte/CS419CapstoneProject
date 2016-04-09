//
// Josh Geller (gellerj@oregonstate.edu)
//
// The Smithy card uses a for loop to add three cards to the current player's hand. This is achieved by calling
// drawCard during each iteration of the loop. Once the card effect has been applied, the Smithy card is discarded
// from the player's hand using the discardCard method.
//
// The Adventurer card draws cards from the current hand (re-shuffling and drawing from the discard deck as necessary),
// until two treasure cards are drawn. If the card is not a treasure card, it is added to an array which tracks the a
// temporary hand. If two treasure cards have been drawn, they are left in the active deck, and all of the cards in
// the temporary deck are discarded. This has the effect that the two treasure cards remain in the player's deck, while
// any non-treasure cards that were drawn are discarded.
//
// The discardCard() method takes four arguments: the position of the card in the current hand, the current player,
// the current game state, and a flag which indicates whether the card should be trashed. First, the trash flag is
// checked. If the flag is not set, the card is added to the played pile, and the played cards counter is incremented.
// The card is marked as "played" by settings its value to -1 in the player's hand, then either decrementing the
// card count to simulate a discard (if there is only one card), or, if there is more than one card, by replacing the
// discarded card with whatever card is currently in the back of the deck.
//
// The updateCoins() method calculates the current value of all of the treasure cards for the given player. In addition
// to summing the values for copper, silver, and gold treasure cards, this method also adds any bonus value that was
// passed to the function.
//