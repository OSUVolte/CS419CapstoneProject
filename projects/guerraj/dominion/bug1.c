Bugs found during unit testing for assignment 3 by James Guerra

for unit test cardtest1 smithy card:
incorect number of cards were drawn when smithy card was played

for unit test cardtest2 Adventeruer card:
incorect numner of cards drawn.  Adventeruer card not discarded asexpected.  

for unit test cardtest3 remodel card:
card failed to work as expected.  Looking through the dominion code, 
found a > in place of needed < for cost if statement

for unit test cardtest4 Salvage card:
no error was found.  
issue was found at first with coin number reported as 9 instead of expected 5
, but was quickly solved as a mistake on the programmer's 
understanding of the updateCoin method.  

for unit test unittest1 updateCoin function:
no error was found.  correct number of coins were counted in both test cases.

for unit test unittest2 playCard function:
no error was found.  correct gamestate and action number was recorded, 
and sucessful implementation of card, and its post game state, was found.  

for unit test unittest3 getValue function:
no error was found.  correct values were returned for card costs,  

for unit test unittest4 scoreFor function:
no error was found.  correct values were returned for each player's score, and correctly 
changed with new cards in play.




