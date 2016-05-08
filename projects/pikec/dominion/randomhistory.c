/********************************
** filename: randomhistory.c
** author: Candis Pike
** date: May 4, 2016
** description: random testing analysis
***********************************/
For both card tests the random tests were limited to 50 tests. This gave enough to cover the edge cases. All deck counts were limited to 150 for berevity. 
(4 player dominion games start with 310 cards. The card limit is about half of that.)

Adventurer:
The random test of the adventure card is still finidng the bugs that were intoduced in assignment1. There is an error in the adventur card test where
the wrong pile was examined to see if any coin cards were discarded. The random test does now show the bug were silver coin cards are being discarded.
The radnom test triggers a shuffle of the discard pile as needed. This means that there is greater coverage of the adventurer card function.
The random test also catches edges case, those of deck being or discard being 0, and both being 0.

For the case of discard being 0, there is no abnormal behavior in the random test. 

For the case of deck being 0, there appears to be a bug within the shuffle function. The shuffle card function shuffles the current deck, 
it does not shuffle the discard and make that the new deck. However the draw card function, checks for an empty deck and shuffles the discard to create a new deck.
Somewhere in the shuffle creates the bug, becasue the final results have the post hand count being less then the pre and as a result the post coin count is less then pre.
It appears that the adventurer card function is removing cards that are already in the hand when the deck count is  0. 
Overall, this bug is rare due to the following constraint. That being that there must be a minimum of 2 coin cards in the discard stack.

For the case of both deck and discard being 0. The bug is caused by the same rational for what triggers it for the deck being 0 and the discard not containing
enough coin cards.

Adventurer Coverage:
Random Test:
Function 'playAdventurer'
Lines executed:100.00% of 18
Branches executed:100.00% of 10
Taken at least once:100.00% of 10
Calls executed:100.00% of 3

File 'dominion.c'
Lines executed:24.60% of 565
Branches executed:25.30% of 415
Taken at least once:18.80% of 415
Calls executed:13.00% of 100

Original Card Test:
Function 'playAdventurer'
Lines executed:66.67% of 18
Branches executed:80.00% of 10
Taken at least once:50.00% of 10
Calls executed:66.67% of 3

With the random test there is now 100% coverage of the adventurer function. This is a hefty improvement over the 66.67% of the card test function. 
There is also 100% coverage of the shuffle function now. The random test catches some edge cases which assists in increasing the confidence in the code. 


Village:
The random test of Village still finds the bugs introduced with assignment 1. 
The random test also catches edge cases, those of deck being 0 or discard being 0, and both being 0.
When both deck and discard are both 0, the player recieves less cards then before the card funtion is called. This is because the player has no cards from
which to draw from and thereofre only the village card is being discarded. To prevent an infinite loop, the draw card function returns -1 if the deck count remains 0.
When the discard count is 0 there is no abnormal behavior.
When the draw count is 0 there is no abnormal behavior.

Coverage:
File 'randomtestcard.c'
Lines executed:77.16% of 162
Branches executed:93.94% of 66
Taken at least once:75.76% of 66
Calls executed:73.33% of 45

Function 'playVillage'
Lines executed:100.00% of 6
No branches
Calls executed:100.00% of 3

As with the original card test there is 100% coverage of the village function. The random test increases the coverge of dominion.c when drawcard is called by 
having the case where the deck is 0. When this happens the shuffle function is called. Therefore, there is more overall coverage of dominion with the random
test then with the original card test.



