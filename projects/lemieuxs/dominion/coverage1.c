/*
Here is the gcov data after running all of my tests:

File 'dominion.c'
Lines executed:33.87% of 561
Branches executed:40.33% of 419
Taken at least once:25.54% of 419
Calls executed:27.08% of 96
Creating 'dominion.c.gcov'

**************************************************************

Here is some gcov data for functions:
Function 'play_outpost'
Lines executed:0.00% of 4
No branches
Calls executed:0.00% of 1

Function 'play_embargo'
Lines executed:0.00% of 8
Branches executed:0.00% of 2
Taken at least once:0.00% of 2
Calls executed:0.00% of 1

Function 'play_minion'
Lines executed:0.00% of 19
Branches executed:0.00% of 18
Taken at least once:0.00% of 18
Calls executed:0.00% of 6

Function 'play_adventurer'
Lines executed:60.00% of 15
Branches executed:100.00% of 14
Taken at least once:64.29% of 14
Calls executed:50.00% of 2

Function 'play_smithy'
Lines executed:100.00% of 6
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 3

Function 'updateCoins'
Lines executed:100.00% of 11
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

Function 'gainCard'
Lines executed:100.00% of 13
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 1

Function 'discardCard'
Lines executed:84.62% of 13
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
No calls

Function 'cardEffect'
Lines executed:16.24% of 197
Branches executed:23.64% of 165
Taken at least once:11.52% of 165
Calls executed:17.54% of 57

Function 'getCost'
Lines executed:16.67% of 30
Branches executed:100.00% of 28
Taken at least once:10.71% of 28
No calls

Function 'drawCard'
Lines executed:36.36% of 22
Branches executed:33.33% of 6
Taken at least once:16.67% of 6
Calls executed:0.00% of 1

Function 'getWinners'
Lines executed:0.00% of 24
Branches executed:0.00% of 22
Taken at least once:0.00% of 22
Calls executed:0.00% of 2

Function 'scoreFor'
Lines executed:0.00% of 24
Branches executed:0.00% of 42
Taken at least once:0.00% of 42
Calls executed:0.00% of 3

Function 'isGameOver'
Lines executed:0.00% of 10
Branches executed:0.00% of 8
Taken at least once:0.00% of 8
No calls

Function 'endTurn'
Lines executed:0.00% of 20
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 3

Function 'whoseTurn'
Lines executed:100.00% of 2
No branches
No calls

Function 'fullDeckCount'
Lines executed:0.00% of 9
Branches executed:0.00% of 12
Taken at least once:0.00% of 12
No calls

Function 'supplyCount'
Lines executed:100.00% of 2
No branches
No calls

Function 'handCard'
Lines executed:0.00% of 3
No branches
Calls executed:0.00% of 1

Function 'numHandCards'
Lines executed:0.00% of 2
No branches
Calls executed:0.00% of 1

Function 'buyCard'
Lines executed:100.00% of 13
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 4

Function 'playCard'
Lines executed:0.00% of 14
Branches executed:0.00% of 10
Taken at least once:0.00% of 10
Calls executed:0.00% of 3

Function 'shuffle'
Lines executed:93.75% of 16
Branches executed:100.00% of 8
Taken at least once:87.50% of 8
Calls executed:100.00% of 2

Function 'initializeGame'
Lines executed:93.55% of 62
Branches executed:100.00% of 46
Taken at least once:86.96% of 46
Calls executed:100.00% of 5

Function 'kingdomCards'
Lines executed:0.00% of 13
No branches
No calls

Function 'newGame'
Lines executed:0.00% of 3
No branches
No calls

Function 'compare'
Lines executed:83.33% of 6
Branches executed:100.00% of 4
Taken at least once:75.00% of 4
No calls

File 'dominion.c'
Lines executed:33.87% of 561
Branches executed:40.33% of 419
Taken at least once:25.54% of 419
Calls executed:27.08% of 96
Creating 'dominion.c.gcov'

The data shows that less than half of the lines in dominion.c were executed.
This makes sense, considering that only four function and eight cards are being tested.

My block coverage could have been improved a lot, especially when checking the Adventurer card.
That was the only function or card where there were lines not covered
(not counting the feast card, where I had to comment out some lines to prevent the infinite loop from happening).
I didn't consider some of the possibilities for the Adventure card, such as the deck being empty.
While testing, I did encounter the bugs I introduced in the Smithy and Adventurer cards, as well as some other bugs
documented in 'bug1.c'. Knowing that my test had at least found some bugs was reassuring, but of course testing
can't prove the absence of bugs.

Since only 33.87% of 561 lines were executed, I think that testing the other functions in
Dominion could give a much more useful coverage percentage. 




*/