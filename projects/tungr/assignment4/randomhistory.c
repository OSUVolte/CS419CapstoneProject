/*
	Rosa Tung
	CS 362 Assignment 4
	randomhistory.c
		Write up and Check in the development of your rnaomd testers, including improvements in coverage
		and effort to check the correctness of your specification. Be detailed and thorough

		**this time I included the .out files in the assignment folder unlike last assignment**
*/

/*adventurer card*/

/* * * * * * * * * * * RANDOMTESTADVENTURER.C * * * * * * * * * * */
File 'randomtestadventurer.c'
Lines executed:96.88% of 64
Creating 'randomtestadventurer.c.gcov'

File 'randomtestadventurer.c'
Lines executed:96.88% of 64
Branches executed:100.00% of 28
Taken at least once:96.43% of 28
Calls executed:97.50% of 40
Creating 'randomtestadventurer.c.gcov'

/*From previous test*/
/*
	File 'cardtest2.c'
	Lines executed:71.93% of 57
	Branches executed:100.00% of 18
	Taken at least once:55.56% of 18
	Calls executed:60.53% of 38
*/

/* * * * * * * * * * * OVERALL * * * * * * * * * * */

/*previous
	File 'dominion.c'
	Lines executed:35.15% of 569
	Branches executed:34.29% of 417
	Taken at least once:25.90% of 417
	Calls executed:27.00% of 100
*/

File 'dominion.c'
Lines executed:29.00% of 569
Branches executed:28.06% of 417
Taken at least once:20.38% of 417
Calls executed:18.00% of 100
Creating 'dominion.c.gcov'

/* * * * * * * * * * * OVERALL BY FUNCTION * * * * * * * * * * */
Function 'updateCoins'
Lines executed:81.82% of 11
Branches executed:100.00% of 8
Taken at least once:75.00% of 8
No calls

Function 'gainCard'
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 1

Function 'discardCard'
Lines executed:84.62% of 13
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
No calls

Function 'playFeast'
Lines executed:0.00% of 17
Branches executed:0.00% of 10
Taken at least once:0.00% of 10
Calls executed:0.00% of 6

Function 'playCouncil_Room'
Lines executed:100.00% of 10
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 4

Function 'playVillage'
Lines executed:0.00% of 6
No branches
Calls executed:0.00% of 3

Function 'playSmithy'
Lines executed:0.00% of 6
Branches executed:0.00% of 2
Taken at least once:0.00% of 2
Calls executed:0.00% of 3

/*playAdventurer from last test*/

/*
	Function 'playAdventurer'
	Lines executed:66.67% of 18
	Branches executed:66.67% of 12
	Taken at least once:41.67% of 12
	Calls executed:66.67% of 3
*/

Function 'playAdventurer'
Lines executed:100.00% of 18
Branches executed:100.00% of 12
Taken at least once:100.00% of 12
Calls executed:100.00% of 3

Function 'cardEffect'
Lines executed:6.00% of 200
Branches executed:13.61% of 169
Taken at least once:1.18% of 169
Calls executed:5.45% of 55

Function 'getCost'
Lines executed:0.00% of 30
Branches executed:0.00% of 28
Taken at least once:0.00% of 28
No calls

/*previous
	Function 'drawCard'
	Lines executed:77.27% of 22
	Branches executed:100.00% of 6
	Taken at least once:66.67% of 6
	Calls executed:100.00% of 1
*/
Function 'drawCard'
Lines executed:100.00% of 22
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 1

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
Lines executed:0.00% of 2
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
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 4

Function 'playCard'
Lines executed:0.00% of 14
Branches executed:0.00% of 10
Taken at least once:0.00% of 10
Calls executed:0.00% of 3

Function 'shuffle'
Lines executed:100.00% of 16
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
Calls executed:100.00% of 2

Function 'initializeGame'
Lines executed:90.32% of 62
Branches executed:95.65% of 46
Taken at least once:82.61% of 46
Calls executed:100.00% of 5

Function 'kingdomCards'
Lines executed:0.00% of 13
No branches
No calls

Function 'newGame'
Lines executed:100.00% of 3
No branches
No calls

Function 'compare'
Lines executed:100.00% of 6
Branches executed:100.00% of 4
Taken at least once:100.00% of 4
No calls

/*Update*/

/*
	So after implementing and running the reports on the new adventurer test I wrote I see that there have been an improvement on code to coverage
	ratio. I actually wrote less code but got more coverage. As you can see instead of getting just 66.67% Lines executed, 66.67% of Branches executed, 41.67%
	Taken at least once and 66.67% calls executing this time around I got 100% all around. I also increased my efficiency for my test, which before I only executed
	around 70% of lines and took only around 50% of brances and executed only around 60% of the calls this time for my test I executed 96.88% of my lines,
	took 96.43% of my branches at least once and executed 97.50% of my calls, which is a big improvement. I also increased my coverage for my drawCard function
	which before showed only 77.27% of lines exectued and 66.67% branches taken at least once, and this time I got it all to 100% which means that the random tests
	have helped. My actual output files as well as the passes and fails also give more information (for both adventurer and village) and I was able to see more 
	easily the flow of information better and could easily pick out mistakes that affected the correctness of my program. 
*/
	
/* * * * * * * * * * * RANDOMTESTCARD.C * * * * * * * * * * */
File 'randomtestcard.c'
Lines executed:91.78% of 73
Creating 'randomtestcard.c.gcov'

File 'randomtestcard.c'
Lines executed:91.78% of 73
Branches executed:100.00% of 16
Taken at least once:81.25% of 16
Calls executed:93.48% of 46
Creating 'randomtestcard.c.gcov'

/* * * * * * * * * * * OVERALL * * * * * * * * * * */
File 'dominion.c'
Lines executed:30.58% of 569
Creating 'dominion.c.gcov'

File 'dominion.c'
Lines executed:30.58% of 569
Branches executed:28.06% of 417
Taken at least once:20.86% of 417
Calls executed:22.00% of 100
Creating 'dominion.c.gcov'

/* * * * * * * * * * * OVERALL FUNCTIONS * * * * * * * * * * */
Function 'updateCoins'
Lines executed:81.82% of 11
Branches executed:100.00% of 8
Taken at least once:75.00% of 8
No calls

Function 'gainCard'
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 1

Function 'discardCard'
Lines executed:92.31% of 13
Branches executed:100.00% of 6
Taken at least once:66.67% of 6
No calls

Function 'playFeast'
Lines executed:0.00% of 17
Branches executed:0.00% of 10
Taken at least once:0.00% of 10
Calls executed:0.00% of 6

Function 'playCouncil_Room'
Lines executed:100.00% of 10
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 4

Function 'playVillage'
Lines executed:100.00% of 6
No branches
Calls executed:100.00% of 3

Function 'playSmithy'
Lines executed:0.00% of 6
Branches executed:0.00% of 2
Taken at least once:0.00% of 2
Calls executed:0.00% of 3

Function 'playAdventurer'
Lines executed:100.00% of 18
Branches executed:100.00% of 12
Taken at least once:100.00% of 12
Calls executed:100.00% of 3

Function 'cardEffect'
Lines executed:7.00% of 200
Branches executed:13.61% of 169
Taken at least once:1.78% of 169
Calls executed:7.27% of 55

Function 'getCost'
Lines executed:0.00% of 30
Branches executed:0.00% of 28
Taken at least once:0.00% of 28
No calls

Function 'drawCard'
Lines executed:100.00% of 22
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 1

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
Lines executed:0.00% of 2
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
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 4

Function 'playCard'
Lines executed:0.00% of 14
Branches executed:0.00% of 10
Taken at least once:0.00% of 10
Calls executed:0.00% of 3

Function 'shuffle'
Lines executed:100.00% of 16
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
Calls executed:100.00% of 2

Function 'initializeGame'
Lines executed:90.32% of 62
Branches executed:95.65% of 46
Taken at least once:82.61% of 46
Calls executed:100.00% of 5

Function 'kingdomCards'
Lines executed:0.00% of 13
No branches
No calls

Function 'newGame'
Lines executed:100.00% of 3
No branches
No calls

Function 'compare'
Lines executed:100.00% of 6
Branches executed:100.00% of 4
Taken at least once:100.00% of 4
No calls

/*
	So for the village card I can see that the bug I produced has popped up in my randomtestcard.out file, if you run the test and take a look
	at it you will see that instead of the user ending up with +2 actions they end up with +4 actions, therefore very often failing that part of the 
	test. I have 100% coverage for my functions, and as for my unit test the coverage is not 100% and if you take a look at the .out file again you 
	will see that the results were either all the same in one section (pass or fail). However, this function alone does garner more coverage than 
	the 8 tests I wrote from the last assignment alone.
*/