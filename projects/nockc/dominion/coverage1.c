/*dominion.c coverage
Lines executed:33.69% of 561
Branches executed:36.45% of 417
Taken at least once:26.38% of 417
Calls executed:20.83% of 96
cardtest1.c coverage
Lines executed:84.95% of 93
Branches executed:100.00% of 40
Taken at least once:65.00% of 40
Calls executed:77.78% of 27
cardtest2.c coverage
Lines executed:84.16% of 101
Branches executed:100.00% of 54
Taken at least once:57.41% of 54
Calls executed:70.00% of 30
cardtest3.c coverage
Lines executed:81.90% of 105
Branches executed:100.00% of 40
Taken at least once:57.50% of 40
Calls executed:69.70% of 33
cardtest4.c coverage
Lines executed:82.00% of 100
Branches executed:100.00% of 36
Taken at least once:58.33% of 36
Calls executed:68.75% of 32
unittest1.c  coverage
Lines executed:65.38% of 104
Branches executed:100.00% of 52
Taken at least once:65.38% of 52
Calls executed:45.45% of 33
unittest2.c coverage
Lines executed:61.70% of 94
Branches executed:100.00% of 52
Taken at least once:65.38% of 52
Calls executed:43.75% of 32
unittest3.c coverage
Lines executed:95.45% of 44
Branches executed:100.00% of 18
Taken at least once:94.44% of 18
Calls executed:80.00% of 5
unittest4.c coverage
Lines executed:85.07% of 67
Branches executed:100.00% of 18
Taken at least once:72.22% of 18
Calls executed:75.00% of 20
Implications: The coverage is lower for dominion.c because I only tested four functions and four cards. In hindsight, maybe if I had chosen to test functions with more lines of code like initializeGame or cardEffect maybe my dominion.c coverage would have improved. I kept track of total passes and fails, with multiple if else statements for each test (one to increment count and one for printing messages). However since tests can’t both pass and fail many of these lines won’t execute. For the card tests there are internal functions called (like DrawCard and DiscardCard which call the shuffle function) which I may not have covered thoroughly enough. Also there was the fact that there were bugs in the code (from my refactoring and also in some cases inherent bug) which caused some lines not to execute. For the unit tests, there was the same if-else routing problem mentioned above but also for two unit tests I had a gamestate function which used if and for statements to test every aspect of game state to see if it changed from previous to post gamestate. For each of these if’s, it only executed the statements on fail (in the case the particular aspect had changed.) In the unit tests where I included this function, coverage was lower because none of these if’s were ever accessed. To improve my test coverage it would help to test more functions, maybe have some random tests and simulate the full game and this would probably catch more bugs. 
*/
