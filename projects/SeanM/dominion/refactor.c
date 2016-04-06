

/------Adventurer Card Bug-------/
I think of top generally as the first element so I switched out the line accessing the top card to read 0 instead of (handsize - 1). This causes a segfault depending on which position the card is played from (but not all the time!).

/---------Smithy Card Bug--------/
I added in a bunch of red herring code that doesn't actually accomplish anything of significance. It looks like the drawn cards are tracked in a temporary hand,and the values of the cards are stored. I added a second loop that is meant to be an obvious bug in that it tries to discard what appears to be the three stored cards immediately, but the real bug arrises in the discardCard command. I changed the 4th argument from a hardcoded 0, to a "drawnCard" variable that is used mostly in the red herring code. The problem if they just remove the loop is the variable will still be valid, and should always be within the scope of the player's hand.

/--------Steward Card Bug------/
I swapped the the handPos and currentPlayer variables in the stewardCard() function call in the switch statement.

/-------Baron Card Bug -------/
I made it appear like I changed the purpose of the card_not_discarded variable. I changed the comment so it looks like a count of the not discarded cards (for an incomplete reason), and then in the else section where p is incremented I also increment card_not_discarded. The while loop still works because its just a bool looking at card_not_discarded as the flag it was originally intended so as it increments it doesn't affect the loop. The bug is that when an estate card is found it only decrements card_not_discarded by 1. So if this is the first loop iteration, and the player has an estate card in the first slot the baron card works as expected. But, if the player has something else in the first slot the baron card will discard ALL the estate cards and add 4 gold for each until the p variable is greater than the hand size at which point it should terminate.

/--------Village Card Bug -------/
This was a simple bug that's a bit superfluous, but actually a bit subtle at the same time. Instead of incrementing the action, I rewrote the line as assigning a value of 2 to the actions. In this way, the Village card still works almost as intended in that the player will have another action. However, if the player should have more than 2 action remaining it will reset the action count to 2!

