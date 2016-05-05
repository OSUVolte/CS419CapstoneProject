/*
unittest1: Almost all tests passed for init except for checking the amount of great hall cards for 4 players. A check for a deck size of ten after the drawing of five of the starting cards failed.
untitest2: This tested the buy card function and checked for updating the number of buys and coins and whether it would stop the player from buying more of a card there was no more of.
unittest3: This tested the end turn function and tested whether the player was switched and whether the hand count of the previous player had was 0.
unittest4: This tested the discard function and checked for a decremented hand count, whether it was put in the played list when the function was given the 0 trash flag, and whether the card in the played card list was the card that was discarded.

cardtest1: This tested the adventurer card and failed the check of whether the hand count was changed to 6 and passed the check of whether the discard pile had increased.
cardtest2: This tested the smithy and if the function changed the hand count to 7, which it failed.
cardtest3: This tested the council room and failed the hand count check and the check of whether the card was added to the dicard pile.
cardtest4: This tested the feast and checked if the player had five cards after buying a 5 coin card and discarding the feast card and failed. It also failed the check of whether it was added to the discard pile.






*/