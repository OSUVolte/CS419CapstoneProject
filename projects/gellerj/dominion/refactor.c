//
// Josh Geller (gellerj@oregonstate.edu)
//
// The Smithy card is played by called playSmithy(), and passing along the current game state
// and the position of the card in the current hand. playSmithy uses state->whoseTurn to
// determine the current player. BUG: The Smithy card is marked to be trashed during discard.
//
// The Adventurer card is played by calling playAdventurer(), and passing along the current game
// state. playAdventurer uses state->whoseTurn to determine the current player. BUG: When checking
// to see if a treasure card was drawn, playAdventurer fails to check for gold treasure cards.
//
// The Village card is played by calling playVillage(), and passing along the current game state
// and the position of the card in the current hand. playVillage uses state->whoseTurn to
// determine the current player. BUG: The Village card sets the number of actions to be 2, instead
// of incrementing the existing number of actions by 2.
//
// The Steward card is played by calling playSteward(), and passing along the current game state,
// the choice as to which action to take, and the position of the card in the current hand.
// playSteward uses state->whoseTurn to determine the current player. BUG: The Steward card is not
// discarded after it is played.
//
// The Council Room card is played by calling playCouncilRoom(), and passing along the current game
// state and the position of the card in the current hand. playSmithy uses state->whoseTurn to
// determine the current player. BUG: There are no bugs in this function.
//