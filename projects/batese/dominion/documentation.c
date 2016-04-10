/*

Adventurer:
The adventurer card makes players draw 2 treasure from their deck. The first while statement covers actually drawing the cards, and for each loop; if the deck is empty it is shuffled and reset,
then a card is drawn. This drawncard is checked using an if statement, and if it is a treasure the counter is incremented. If if is not a treasure then it is effectively discarded by reducing
state->handCount by 1.

Smithy:
A for loop repeats 3 times, calling drawCard to add 1 card to the players hand each time.

Discard Card:
This function takes 4 arguments; handPos is the position of the card (being discarded) in the player's hand, currentPlayer is the player in question, state is the game state, and trashFlag
is a flag showing whether the card is trashed. The first part of this function adds the card to playedCards (if it is not being trashed). Next the card is removed from the players hand. If
the card is in the highest hand position, or if the player has only 1 card in their hand then this is done by reducing the hand size by 1. If it is not the final card in the players hand then
it is swapped with the final card in the hand before the hand size is reduced.

Update Coins:
This function takes 3 parameters; player which is the player number, state which is the game state, and bonus which is the number of bonus coins to be added to the players coin count. First the 
number of coins is reset. Then a for loop checks the players hand for treasure cards and adds them up accordingly. Finally the bonus is added to to this total.

*/