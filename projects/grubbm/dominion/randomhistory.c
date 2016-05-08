Random Test Card
----------------------------------
Relevant Coverage Results: 

File 'dominion.c'
Lines executed:22.26% of 548
Branches executed:23.26% of 417
Taken at least once:15.59% of 417
Calls executed:11.11% of 90
Creating 'dominion.c.gcov'

Function 'compare'
Lines executed:83.33% of 6
Branches executed:100.00% of 4
Taken at least once:75.00% of 4
No calls

Function 'initializeGame'
Lines executed:95.16% of 62
Branches executed:100.00% of 46
Taken at least once:91.30% of 46
Calls executed:100.00% of 5

Function 'shuffle'
Lines executed:93.75% of 16
Branches executed:100.00% of 8
Taken at least once:87.50% of 8
Calls executed:100.00% of 2

Function 'drawCard'
Lines executed:36.36% of 22
Branches executed:33.33% of 6
Taken at least once:16.67% of 6
Calls executed:0.00% of 1

Function 'cardEffect'
Lines executed:5.51% of 236
Branches executed:11.56% of 199
Taken at least once:1.51% of 199
Calls executed:4.69% of 64

Function 'discardCard'
Lines executed:84.62% of 13
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
No calls

Function 'updateCoins'
Lines executed:81.82% of 11
Branches executed:100.00% of 8
Taken at least once:75.00% of 8
No calls

All other functions had 0% coverage, execution and calls 

These results do make sense as we were targeting a specific portion of the gameplay: card effects.  
The results are similar to last week's, where we did test card effects, but these were randomized 
and run 75 times in my case.  Looking at the overall coverage in dominion.c, we do see smaller numbers
for our results.  This is attributed to the fact that we were targeting a small part of the overall game.
However, these tests did simulate hands being played so we came close to a realistic representation of 
game play.  The reason for the disparity between running through full hand game play with multiple players, 
and a smaller amount of overall coverage is that we were only testing one card, which limits our results 
significantly. Take for example, the small coverage numbers for 'cardEffect': 

Function 'cardEffect'
Lines executed:5.51% of 236
Branches executed:11.56% of 199
Taken at least once:1.51% of 199
Calls executed:4.69% of 64

This is a larger function with 236 lines, so we can expect smaller coverage if it is only interacting 
with the case of the 'Village'. 

Likewise for the other functions, where coverage did not reach 100%, but was significantly higher.  
There will be some portions of the code that a test on a single card will not reach. However, it should
be noted that the rest of functions where there was coverage, we are likely looking at the best results 
we could get because they deal more with the random card dealings: How many coins one has etc. For this 
reason it is hard to reach full coverage because it is almost, if not completely, impossible to simulate 
hands that meet all the criteria in the updateCoins function, for example. Indeed, for most of the functions
that experienced coverage, there was 100% branch coverage for the overall test set. 


Random Adventurer Test 
------------------------------------------------------------

Function 'updateCoins'
Lines executed:63.64% of 11
Branches executed:50.00% of 8
Taken at least once:37.50% of 8
No calls

Function 'cardEffect'
Lines executed:9.75% of 236
Branches executed:17.59% of 199
Taken at least once:7.54% of 199
Calls executed:4.69% of 64

Function 'drawCard'
Lines executed:100.00% of 22
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 1


Function 'whoseTurn'
Lines executed:100.00% of 2
No branches
No calls


Function 'shuffle'
Lines executed:100.00% of 16
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
Calls executed:100.00% of 2

Function 'initializeGame'
Lines executed:95.16% of 62
Branches executed:100.00% of 46
Taken at least once:91.30% of 46
Calls executed:100.00% of 5

Function 'compare'
Lines executed:100.00% of 6
Branches executed:100.00% of 4
Taken at least once:100.00% of 4
No calls

File 'dominion.c'
Lines executed:24.64% of 548
Branches executed:24.70% of 417
Taken at least once:18.71% of 417
Calls executed:12.22% of 90
Creating 'dominion.c.gcov'



We see similar results for the adventurer test.  There are some test failures, about 2 out of 50 for each test run 
these deal with coin counts, and card counts.  I haven't been able to identify the reason, but I suspect that it 
is a result of interactions with other players, where changes due to their plays are not fully accounted for by my tests. 
