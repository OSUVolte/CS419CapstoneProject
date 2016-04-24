/*******************************************************************************
*** Filename: bug1.c
*** Author: Aleksandr Balab
*** Class: CS362-400
*** Spring 2016
*** Assignment 3
*** Description: Execute your unit tests and describe any bugs you 
*** find in a file named bug1.c.
*********************************************************************************/


/*
Unittest1 (updateCoins) - Worked correctly. No bugs encountered. 

Unittest2 (discardCard) - Worked correctly. No bugs encountered. 

Unittest 3 (whoseTurn) - Didn't initiate  whos turn correctly. 
						 Even thou the test run and was successful, i do believe 
						 there are bugs. 

Unittest4 (fullDeckCount) - Worked correctly. No bugs encountered. 


cardtest1 (adventurer)- Failed for every single itteration. The number of card expected and actual was always
						different. Due to the introduced bug that would discard one more additional card.

cardtest2 (smithy)	- Passed despite the introduction of the bug that would trash the card instead of discarding it.
					I only tested the amount of card on hand. The bug will only effect the game when the desk
					will be shuffled again and the card won't be in the desk anymore since we discarded it. 
					We would have to check the amount of cards discarded vs actual cards in the deck, but as far
					as logic for the smithy goes- it passed. 

cardtest3 (village) -  Worked correctly. No bugs encountered. Didn't introduce any additional bugs for this card.

cardtest4 (salvager) - Failed every single itteration. Since the bug would just substract the card's coin value
						everytime. It leaves the the player constantly with 0 coins from the substraction instead
						of intendend( by the game ) action. 




*/