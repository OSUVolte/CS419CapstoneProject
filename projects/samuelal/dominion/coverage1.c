Alex Samuel
Assignment 3

Overall Coverage
File 'dominion.c'
Lines executed:42.75% of 559
Branches executed:50.60% of 417
Taken at least once:41.49% of 417
Calls executed:27.37% of 95

Function Coverage Data
Function 'getCost'
Lines executed:96.67% of 30
Branches executed:100.00% of 28
Taken at least once:96.43% of 28
No calls

Function 'fullDeckCount'
Lines executed:100.00% of 9
Branches executed:100.00% of 12
Taken at least once:100.00% of 12
No calls

Function 'isGameOver'
Lines executed:100.00% of 10
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

Function 'scoreFor'
Lines executed:100.00% of 24
Branches executed:100.00% of 42
Taken at least once:100.00% of 42
Calls executed:100.00% of 3

Card Coverage Data
Function 'smithyCard'
Lines executed:100.00% of 5
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 2

Function 'adventurerCard'
Lines executed:93.33% of 15
Branches executed:100.00% of 12
Taken at least once:75.00% of 12
Calls executed:50.00% of 2

Village
        -:  822:    case village:
        -:  823:      //+1 Card
        2:  824:      drawCard(currentPlayer, state);
call    0 returned 100%
        -:  825:
        -:  826:      //+2 Actions
        2:  827:      state->numActions = state->numActions + 2;
        -:  828:
        -:  829:      //discard played card from hand
        2:  830:      discardCard(handPos, currentPlayer, state, 0);
call    0 returned 100%

Function 'greathallCard'
Lines executed:100.00% of 5
No branches
Calls executed:100.00% of 2


	Based on my gcov results, I think I need to focus on improving coverage of other functions used within dominion.c other 
than the ones I tested. 3 of my 4 unit tests had 100% line, branch, and function call coverage. My unittest1 which tested the 
getCost() had nearly 100% coverage and could be slightly improved to ensure that every line is executed at least once. For my 
cardtests, I would improve my cardtest2 so I could increase my branch and function call coverage. My cardtests for smithy, 
village, and greathall all had 100% line and function call coverage. Although the village card was not implemented in a function, 
the gcov data indicates that the non-commented lines of the code were all executed at least once.
	Based on these results, I would focus my attention on increasing coverage of other portions of dominion.c. My line, branch, and 
especially function call coverage could be imroved significantly. I would especially like to focus on sections that had poor 
test coverage and are important to the core functions of the program. I would likely focus on the initializeGame function where
more than 2 players are playing. Initialization of the correct number of supplies is important to gameplay and from my test 
results, I could improve my coverage in this area. In addition, I think writing tests for playCard(), buyCard(), and endTurn() 
would also help increase testing coverage of areas that currently do not have adequate coverage and play a critical role in the 
overall program. Since a limited number of the cards were tested, I could also test more cards but I think the functions I 
listed previously are more important to the overall behavior of the game.
