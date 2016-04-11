Michael Bamesberger
Software Engineering II
Assignment 2: documentation.c
4-10-2016


The code for both the Smithy and Adventurer cards is contained within the
playdom.c and dominion.c file. 

In function main of playdom.c, the 10 available cards are grouped into
an array called 'k'. A gameState struct is initialized to hold
player data. Then, the program enters a while loop, which
checks each iteration whether the game is over.

Inside the while loop, the program iterates through each card in the player's hand
and updates local variables based on the type of card. If the player
has a smithy card, the program updates a smithyPos variable with
the position of the card in the hand. It does the same for the adventurer card. 

After a test for whether it is the player's turn, there is a test for
the smithyPos variable. If a Smithy card exists in the hand (smithyPos is
not equal to -1), the Smithy card is played by being sent to the playCard
function in the dominion.c file. There, the function checks if the card
is an action card, then passes the card to the cardEffect() function. 

The cardEffect() function is a large switch, which contains the code for the
card actions. At the Smithy card case, the code simply calls the drawCard
function three times. Then the program calls discardCard() function, which
adds the current card (Smithy) to the played cards pile in the gameState
struct. Then the function tests to see how many cards are left in the hand.
If there are one or more, that card is removed from the hand. Otherwise, the
discarded card is replaced with another card. Finally, the program returns to
the playCard() function, where the updateCoins() function is then called.
This function resets the player's coin count, adds coins in the player's
hand, then adds that number to the player's gameState struct. 

Back in playdom.c, after the Smithy card is played, the program iterates back
through the player's cards, totaling up the amount of money (treasure cards)
the player has. 

The program then moves to several statements where buying cards (treasure,
province or Smithy) is allowed. If the player has 4 or more money, and the
number of Smithy cards is less than 2, the program buys a smithy card for
the player. 

If, however, there are no Smithy cards in the player's hand
(smithyPos == -1), the program then checks for the presence of an
Adventurer card. If one exists in the player's hand, the card is
played by calling the playCard() function in the dominion.c file.
In Adventurer card case, there is a while loop which tests whether a
drawntreasure variable is less than two (remember, the purpose of the
Adventurer card is to draw two treasure card from the hand). Inside the
while loop, the code draws a card from the hand and tests whether it is
a treasure card. If it is, the drawntreasure variable is incremented.
If not, the  card is removed from consideration. Finally, the program
returns to the playCard() function, where the updateCoins() function
is then called. This function resets the player's coin count, adds coins
in the player's hand, then adds that number to the player's gameState struct. 

Back at the playdom.c file, the program iterates back through the
player's cards, totaling up the amount of money (treasure cards) the
player has. And again, the program moves to several statements where
it's possible to buy cards. If the player has 6 or more money and the
number of Adventurer cards is less than 2, the player then buys an
Adventurer card.

Finally the turn ends, and the program returns to the top of the while loop. 


