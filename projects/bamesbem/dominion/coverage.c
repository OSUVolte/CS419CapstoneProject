/*
Michael Bamesberger
CS362 - Assignment 3
coverage.c

 Here is my gcov coverage report for dominion.
 
 File 'dominion.c'
 Lines executed:49.38% of 725
 Branches executed:54.87% of 421
 Taken at least once:37.05% of 421
 No calls
 dominion.c:creating 'dominion.c.gcov'
 
 It shows that nearly 50% of the lines were covered, as well as more than 50%
 branches. Overall, for only testing 8 of the functions in the dominion.c
 file, I believe that is satisfactory. 
 
 Let's take a look at some of the card functions I tested:
 
 Function 'playAdventurer'
 Lines executed:55.56% of 18
 Branches executed:100.00% of 12
 Taken at least once:75.00% of 12
 No calls
 
 Function 'playCouncilRoom'
 Lines executed:100.00% of 12
 Branches executed:100.00% of 6
 Taken at least once:100.00% of 6
 No calls
 
 Function 'playVillage'
 Lines executed:100.00% of 5
 No branches
 No calls
 
 Function 'playSmithy'
 Lines executed:100.00% of 10
 Branches executed:100.00% of 4
 Taken at least once:75.00% of 4
 No calls

 It looks like I was able to reach 100% line (and in some cases
 100% branch coverage) for three of my four card tests. It looks like 
 I was able to execute 100% of branches in the playAdventurer function, but 
 only aroudn 56% of the line coverage. This means I likely need to
 add more testing to reach more lines in the function.
 
 Finally, lets look at the other functions I tested.
 
 Function 'isGameOver'
 Lines executed:100.00% of 15
 Branches executed:100.00% of 8
 Taken at least once:100.00% of 8
 No calls
 
 Function 'gainCard'
 Lines executed:93.75% of 16
 Branches executed:100.00% of 6
 Taken at least once:83.33% of 6
 No calls

 Function 'updateCoins'
 Lines executed:100.00% of 16
 Branches executed:100.00% of 8
 Taken at least once:100.00% of 8
 No calls
 
 Function 'discardCard'
 Lines executed:87.50% of 16
 Branches executed:100.00% of 6
 Taken at least once:83.33% of 6
 No calls
 

 For this batch of tests, it appears that I was able to reach
 100% line and branch coverage of the updateCoins and isGameOver
 functions. I reached about 94 percent of the lines in gainCard
 and only 87 percent of lines in discardCard. This means I need
 to add more tests to increase my coverage. y
 

 



*/