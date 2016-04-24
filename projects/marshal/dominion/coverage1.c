/*
Alex Marsh
CS362 Assignment 2
Coverage

    After running my unit tests for the cards (smithy, adventurer, village, great_hall) and functions (scoreFor(), getCost(), fullDeckCount(), whoseTurn()) I created a test suit inside my makefile and ran coverage throughout them and their coverage of the dominion code. I found that typically the branches of my unit tests took 100% of their branches, but only 50% of the branches in the dominion code. The lines executed in my test units ranged from 38% to 88%.  This can be accounted for by the numerous print statements that I commented out or set to be quiet when 'NOISY' test was not initiated. 
    The gcov coverage showed that the dominion code had 46.11% of 566 lines executed.  Around 50% of 417 branches were taken and 39.57% of 417 branches were taken at least once. Out of 101 calls only 37.62% were executed.  
    My test units only executed 46% of the dominion code.  This can be attributed to poor testing, but more likey is due to the small amount of testing between 4 card implementations and 4 functions. 
    Looking at the unexecuted code in dominion.c I found that in updateCoins the else statements for gold and silver coins were unexecuted. This may be because I only used the copper coins in my testing.  I did this because of the simplicity with +1, however in the future I plan to broaden my test with the use of silver and gold coins. Specifically for my scoreFor unit test. 
    In the gainCard function the 'toFlag' was never set to 1 or 2 so the if statements where never executed. Similarly the supplyCount was never 0. In the discardCard function, there was never only one card in the players hand and the card to discard was never the last card in the users hand so these if statements never executed.In the future I should test with different settings of the flags and positions of the card for the user.
    Since my tests only tested 4 cards, several branches and cards were never executed in the cardEffect function. 
    In several of my tests I had failed tests with the players hand being too few or too many cards.  Looking at the drawCard function I saw several lines that increment or decrement the deck, hand, and discard count were not executed.  This could be the main issue of the inaccurate counts. 
    The function getWinner, newGame, kingdomCards, playMinionCard, playCard, and isGameOver was never called and thus never executed. In the future I plan to include test cases that either use or test these functions. 
    In the function scoreFor my test ran through the first two for loops:
    for (i = 0; i < state->handCount[player]; i++)
and 
    for (i = 0; i < state->discardCount[player]; i++)
both with 90% or above execution/ branch rate. However the third for loop that shoul execute for the deck is mislabeled with:
    for (i = 0; i < state->discardCount[player]; i++)
and is thus is also taken with 90%, but is inaccurate. 
    My function test for whoseTurn returns 100% of the blocks executed 100%.
    A major issue that is presented in the gcov coverage is that my refractored function playAdventurer is never called and thus is never executed.  This a huge issue since my cardtest2 never showed this during testing. If my function to play the adventurer card is never called, how could any of my tests ever show they pass? In the future I need to look further in this issue. 
    
    

_____________Unit1 Test________
Lines executed:64.62% of 212
Creating 'unittest1.c.gcov'

File 'unittest1.c'
Lines executed:64.62% of 212
Branches executed:75.86% of 116
Taken at least once:68.10% of 116
Calls executed:70.00% of 30

____________Unit2 Test___________
File 'unittest2.c'
Lines executed:38.20% of 89
Creating 'unittest2.c.gcov'

File 'unittest2.c'
Lines executed:38.20% of 89
Branches executed:100.00% of 56
Taken at least once:50.00% of 56
Calls executed:51.72% of 58

____________Unit3 Test___________
File 'unittest3.c'
Lines executed:88.16% of 76
Creating 'unittest3.c.gcov'

File 'unittest3.c'
Lines executed:88.16% of 76
Branches executed:100.00% of 34
Taken at least once:85.29% of 34
Calls executed:68.75% of 16

____________Unit4 Test___________
File 'unittest4.c'
Lines executed:82.76% of 29
Creating 'unittest4.c.gcov'

File 'unittest4.c'
Lines executed:82.76% of 29
Branches executed:100.00% of 12
Taken at least once:75.00% of 12
Calls executed:70.00% of 10

____________CardTest1 Test___________
File 'cardtest1.c'
Lines executed:73.58% of 53
Creating 'cardtest1.c.gcov'

File 'cardtest1.c'
Lines executed:73.58% of 53
Branches executed:100.00% of 22
Taken at least once:54.55% of 22
Calls executed:46.67% of 15

____________CardTest2 Test___________

File 'cardtest2.c'
Lines executed:75.00% of 64
Creating 'cardtest2.c.gcov'

File 'cardtest2.c'
Lines executed:75.00% of 64
Branches executed:100.00% of 40
Taken at least once:62.50% of 40
Calls executed:43.75% of 16

____________CardTest3 Test___________
File 'cardtest3.c'
Lines executed:71.43% of 56
Creating 'cardtest3.c.gcov'

File 'cardtest3.c'
Lines executed:71.43% of 56
Branches executed:100.00% of 24
Taken at least once:54.17% of 24
Calls executed:43.75% of 16

____________CardTest4 Test___________
File 'cardtest4.c'
Lines executed:67.86% of 56
Creating 'cardtest4.c.gcov'

File 'cardtest4.c'
Lines executed:67.86% of 56
Branches executed:100.00% of 24
Taken at least once:54.17% of 24
Calls executed:37.50% of 16

___________dominion.c__________________
File 'dominion.c'
Lines executed:46.11% of 566
Creating 'dominion.c.gcov'

File 'dominion.c'
Lines executed:46.11% of 566
Branches executed:50.60% of 417
Taken at least once:39.57% of 417
Calls executed:37.62% of 101

*/