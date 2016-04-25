******************************************************************************
* bug1.c
* 
* Jarrad Favre
*
* 4-24-2016
*
*******************************************************************************


-------------------- Testing Function discardCard() --------------------

TEST CASE 1: Trashed card does not show up in played cards pile

**** Test Successful ****
Expect amount of cards in played cards pile: 0
Actual amount: 0

TEST CASE 2: Discarded card added to played cards pile

**** Test Successful ****
Expect amount of cards in played cards pile: 1
Actual amount: 1

TEST CASE 3: Hand count shows 0 when player only has 1 card on hand to discard

**** Test Successful ****
Player 1's expected count of count for their hand: 0
Actual count: 0

TEST CASE 4: Hand count has a value of 1 after player discards card with a hand of 2 cards

**** Test Successful ****
Player 1's expected count of count for their hand: 1
Actual count: 1

TEST CASE 5: When player has a hand greater than 3, the discarded card is replaced with the last card on hand

**** Test Successful ****
Expected card to replaced discarded one in player 1's hand: village
The actual card that replaced it: village


**No found bugs


-------------------- Testing Function updateCoins() --------------------

TEST CASE 1: Test that has treasure cards in player's hand and function returns correct amount with 0 bonuses

**** Test Successful ****
Player 1's expect amount of treasure: 6
Actual amount of treasure: 6

TEST CASE 2: Test that has treasure cards in player's hand and function returns correct amount with bonus

**** Test Successful ****
Player 1's expect amount of treasure: 10
Actual amount of treasure: 10

TEST CASE 3: Hand count shows 0 when player only has 1 card on hand to discard

**** Test Successful ****
Player 1's expect amount of treasure: 0
Actual amount of treasure: 0
flip2 ~/CS362/cs362sp16/projects/favrej/dominion 1013% vim unittestresults.out
flip2 ~/CS362/cs362sp16/projects/favrej/dominion 1014% unittest1


-------------------- Testing Function isGameOver() --------------------

TEST CASE 1: Game does not end when stack of Province cards is not empty or when none of the supplies are empty

**** Test Successful ****
Expected boolean value returned from isGameOver: 0
Actual boolean value: 0

TEST CASE 2: Game does not end when 2 of supplies are empty

**** Test Successful ****
Expected boolean value returned from isGameOver: 0
Actual boolean value: 0

TEST CASE 3: Game ends when 3 supplies are empty

**** Test Successful ****
Expected boolean value returned from isGameOver: 1
Actual boolean value: 1

TEST CASE 4: Game ends when province supply empties

**** Test Successful ****
Expected boolean value returned from isGameOver: 1
Actual boolean value: 1


**No bugs found

-------------------- Testing Function scoreFor() --------------------

TEST CASE 1: All cards from Player 1 are tallied instead of Player 2's

**** Test Successful ****
Returned score matches player 1's hand score
Score returned from scoreFor(): 3
Player 1's hand score: 3
Player 2's hand score: 9

TEST CASE 2: Combining positive scores only

**** Test Failed ****
Score returned from scoreFor(): 30
Player 1's victory points: 31

TEST CASE 3: Score when player 1 has zero victory points

**** Test Successful ****
Score returned from scoreFor(): 0
Player 1's victory points: 0

TEST CASE 4: Combining scores with positive and negative victory points

**** Test Failed ****
Score returned from scoreFor(): 9
Player 1's victory points: 14

** The following bugs were found:
   If you will look at test cases 2 and 4, you will find that that these tests failed. The result
   of these failures was due to the wrong counter used in the for loop for the deck. Instead of 
   using the deckCount as the counter up to, the discardCount was used instead. So, in instances
   like in test cases 2 and 4, where I had more cards allocated for the deck than discared, we
   run into the problem of not having all of our victory points counted for.

-------------------- Testing Card Smithy --------------------

TEST CASE 1: Player 1 draws 3 cards and discards Smithy from hand

**** Test Successful ****
Player 1's expected hand count: 7
Actual hand count: 7

TEST CASE 2: No state change for player 2

**** Test Successful ****
Player's 2 expected hand count: 0
Actual hand count: 0

TEST CASE 3: Cards were drawn from Player 1's deck and not Player's 2

**** Test Successful ****
Player 1's expected deck count: 2
Actual deck count: 2

Player 2's expected deck count: 10
Actual deck count: 10

TEST CASE 4: Card was properly discarded to played cards pile and not trash

**** Test Failed ****
Expected count in played pile: 1
Actual count in played pile: 0

Smithy should be in contents of played cards pile
Contents of played cards pile:

** The following bug was found:
   This is a bug that I implemented myself. Instead of Smithy being discarded to the played
   pile, I have the trash parameter in discarCard function set to 1, meaning that it is to
   dispose of the card. As a result, we see the following error occur in test case 4.

-------------------- Testing Card Adventurer --------------------

TEST CASE 1: Player 1 has 2 treasure cards added to hand

**** Test Successful ****
Player 1's expected hand count: 7
Actual hand count: 7

Top 2 cards on Player 1's hand should be treasure cards
Top Card = copper
2nd Top Card = gold

TEST CASE 2: No state change for player 2

**** Test Successful ****
Player's 2 expected hand count: 0
Actual hand count: 0

TEST CASE 3: Cards were drawn from Player 1's deck and not Player's 2

**** Test Successful ****
Player 1's expected deck count: 4
Actual deck count: 4

Player 2's expected deck count: 10
Actual deck count: 10

TEST CASE 4: All treasure cards found are being kept and not discarded

**** Test Failed ****

Player 1's discarded cards should not have treasure cards in them
silver
silver
smithy
minion

TEST CASE 5: Cards to be discarded should not be discarded in Player 2's discard pile

**** Test Successful ****
Player 2's discard pile count: 0
Actual discard count: 0

** The following bugs were found:
   This is a result of a bug I implemented. Originally, Adventurer is suppose to look and keep
   all treasure cards: copper, silver, and gold. However, I removed a condition that made it
   to look for only copper and gold. So, when I implemented in my test case a deck a number of
   all three treasure cards on the top of the deck, we get the following errors we see in 
   test case 4, where silver cards are discarded in the discarded pile and not kept.

-------------------- Testing Card Council Room --------------------

TEST CASE 1: Player 1 draws 4 cards and discards Council Room from hand

**** Test Failed ****
Player's 1 expected hand count: 8
Actual hand count: 9

TEST CASE 2: Buy status was increased to 1

**** Test Successful ****
Expected number of buys: 2
Actual number of buys: 2

TEST CASE 3: No major state change for player 2 and that they drew 1 card

**** Test Successful ****
Player's 2 expected hand count: 1
Actual hand count: 1

TEST CASE 4: Cards were drawn from Player 1's deck and not Player 2's

**** Test Successful ****

Player 2's expected deck count: 9
Actual deck count: 9

TEST CASE 5: Card was properly discarded to played cards pile and not trash

**** Test Successful ****
Expected count in played pile: 1
Actual count in played pile: 1

Council Room could be in contents of played cards pile
Contents of played cards pile:
council room

** The following bugs were found:
   This is a bug that I implemented. In test case 1, we find that have no more card on our
   hand than the expected amount. This could of be 1 of two reasons. The first is that the 
   player never discarded was it was suppose to, but if we look at test case 5, we find that
   it was properly discarded. So, that leaves the second reason, which is the the condition
   in the for loop to draw cards was changed from less than 4 to less than or equal to 4. 
   The modification results in the error that we see in test case 1.

-------------------- Testing Card Sea Hag --------------------

TEST CASE 1: Player 1 should not have discarded top card in deck and replace it with curse card

**** Test Successful ****
Player 1's expected count of cards in discard pile: 0
Actual count of cards in discard pile: 0
Player 1's top card: copper

TEST CASE 2: Player 2's top card in deck was discarded and replaced with curse card

**** Test Failed ****
Expected number of cards in deck: 10
Actual number of cards in deck: 7
Player 2's top card: copper

TEST CASE 3: Player 2's top card was discarded in their discard pile

**** Test Successful ****
Player 2's expected count of cards in discard pile: 1
Actual count of cards in discard pile: 1
Count of cards in player 1's discard pile: 0

** The following bugs were found:
   The sea hag card is suppose to allow everyone but the current player to discard their top
   card on their deck and replace it a curse card. As we see in test case 2, this is not the 
   case. When inspecting the code, I found that the deckCount for the passed player was being
   decremented 3 times. After the number is decremented twice, the card in that place of the
   deck is being replaced with the curse card. Then, after the deckCount erroneously decrements
   again, the curse card is completely lost. Because of this, we get the error of having the
   other players from the current player being shorted 3 cards from their deck and the curse
   card never being added to their deck.
