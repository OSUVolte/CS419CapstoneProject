Bugs found during unit testing for assignment 3 by James Guerra

for unit test cardtest1 smithy card
incorect number of cards were drawn when smithy card was played
for unit test cardtest2 Adventeruer card
incorect numner of cards drawn.  Adventeruer card not discarded asexpected.  
for unit test cardtest3 remodel card
card failed to work as expected.  Looking through the dominion code, 
found a > in place of needed < for cost if statement
for unit test cardtest4 Salvage card
no error was found.  
issue was found at first with coin number reported as 9 instead of expected 5
, but was quickly solved as a mistake on the programmer's 
understanding of the updateCoin method.  

