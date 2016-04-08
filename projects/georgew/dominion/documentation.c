smithy card
//Purpose: 	
//1)Call the drawCard method with the current player at the current state, if remaining cards are 0 shuffle the discard pile back into the deck and shuffle the deck. 
//2)Next draw a card three times, each time decrementing deckCount and incrementing handCount 
//3)Then discard smithy card from hand by setting card to -1 and removing from players hand 
//4)Then either replace with last card in hand and reduce cards in hand by 1. If cards in hand is 1 or it is the last one then just reduce number of cards in hand to 0.
	


adventurer card
//Purpose: Add two treasure cards to hand
//1)Look for treasure cards in deck while you've only drawn less than two
//2)if deck is empty shuffle discard and add to deck
//3)draw a card
//4)if card is treasure increment drawn treasure 
//5)else place card in temp hand and decrement handcount to remove drawn card and redraw
//6)place all drawn non-treasure cards in discard pile
     


Discard Card Method
//1)Check if card is going to played pile by using the trash flag
//1a) If going to played pile increase played card count
//2) If not set state to -1
//3) remove from players hand
//3a) If it's the last card or there is only one card in hand then just reduce number of cards by one
//3b) Else replace card with last card in deck
//4) Reduce number of cards in hand by 1
	

updateCoins Method
//1) Reset coin count
//2) Add coins for each treasure card in hand including 1 for copper, 2 for silver, and 3 for gold
//3) Add bonus coins to total
