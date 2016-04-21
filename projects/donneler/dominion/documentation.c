/*************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 2
* Documenting understanding of smithy cards, adventurer cards, 
* discardCard method, and the updateCoins method.
*************************************************************************/

/**************************************************************************
smithy cards - When a player plays a smithy card, the player draws a total of three 
card via the drawCard method. Then the smithy card is discarded.

adventurer cards - When a player plays an adventurer card, there is a loop that continues 
until the player has drawn 2 treasures. First if the deck is empty then the discard pile 
is shuffled and added to the deck. The player then draws a card via the drawCard method. 
If the card is a treasure, then we add to the drawnTreasure count. If the card drawn is 
not a treasure card, then it puts the card in a temporary hand and the drawn card is 
removed from the players hand. Once the player has drawn 2 treasure cards, all the cards 
in the temp hand are discarded. A deviation from the rules is that there is not limit on 
the number of times you shuffle, while the game only allows for you to shuffle once. This
potentially could cause the code to get stuck in an infinite while loop. I noticed that
this card as well as (Feast, baron, tribute, sea_hag, treasure_map) are not discarded
after the turn, this violates the clean-up phase of the game where all cards in play are
to be discarded and a new hand of 5 cards is drawn.

discardCard method - It takes in the handPos, currentPlayer, a pointer to the gameState 
variable, and a trashFlag. If the trashflag is less than one (card is not trashed), then 
the card is added to the playedCards pile. The played card in the players hand is set to 
-1. The played card is removed from the player's hand.

updateCoins method - The updateCoins method takes in the player, a pointer to the 
gameState variable, and an integer of bonus coins. First, the coins count is
reset to zero. For each card in a players hand, it adds 1 to the coins count if the 
card is copper, 2 if the card is silver, and 3 if the card is gold. Then the bonus 
points are added to the coins count. 
**************************************************************************/

