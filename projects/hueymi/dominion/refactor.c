Cutpurse – playCutpurse()
1. In theory, the cutpurse card will look through every card in every other player’s hand and discard a copper. However, in the refactored cutpurse function, the function will discard the wrong cards from the wrong player, as long as i in the for loop does not equal j in that for loops.  For example, if the jth card in the hand of player i is a copper, the discard function will instead discard the ith card of player j. 
2. In theory, the cutpurse card will only force the other players to reveal every item in their hand if they have no coppers. However, in the refactored function, every player will reveal every item in their hand (instead of only if the hand has no Copper).  


Ambassador – playAmbassador()
1. In theory, the ambassador card will choose a card to reveal, and n copies of the revealed card will be placed into the other players’ decks. However, instead of the chosen revealed card, the game will reveal the nth card of the player’s hand.  
2. In theory, the ambassador card will be put into the discard pile once finished, and all the cards that have been returned to supply will be trashed. However, in the refactored ambassador function, the ambassador card itself will be trashed and the copies of the revealed card will be put into the discard pile. 


Remodel – playRemodel()
Although refactored, there is no error in the playRemodel() function.  


Smithy – playSmithy()
1. In theory, the smithy card will allow the user to play three more cards in the game. However, set up as a do-while loop with an uninitialized i, the player will receive an unknown number of cards. 
2. In theory, the smithy card with hand position x will be discarded from the current player y’s hand. However, instead, the card with hand position y (number of current player) will be discarded from player x’s hand. 


Adventurer – playAdventurer()
1. In theory, the adventurer card will keep adding drawn cards to a temporary hand, temphand, starting from index 0. However, in the refactored adventurer deck, z has been initialized to the number of the current player, so when the player number is greater than 0, it will add to the temporary pile and then keep discarding too many cards. 
2. In theory, after the player has drawn a card that isn’t a treasure card, the card will be removed from the deck. However, in this function, after refactoring, the function assigns the current handCount to a new variable, then decrements that variable, essentially leaving any non-treasure card in the player’s hand. 
