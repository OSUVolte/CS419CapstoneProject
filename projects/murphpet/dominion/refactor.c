hanged council_room card to call its own fucntion council_room_function. The bug is in the loop that allows each other player to draw one card each. I set the i= 1 not allowing player 0 to draw a card. Also doubles the number of buys instead of incrementing it. Lastly, discards cards to next player’s discard pile. 

Changed adventurer card to call its own function. Introduced a bug that decrements the drawn treasure when a treasure card is not drawn. 
Changed smithy card to call its own function. Introduced a bug that calls discard on the next player. I believe it discards one of the next players cards. I also set the discard trash flag so it take the card out of play. 

Changed sea hag card to call its own function. Introduced a bug that see hag’s negative effects only effect the player playing the card. 
Changed Salvager card to call its own function. Introduced a bug that trashs the card that should be discarded and discards the card that should be trashed. 

