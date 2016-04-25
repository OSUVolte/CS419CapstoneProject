//
//  coverage1.c
//  xa3
//
//  Created by Dane Schoonover on 4/24/16.
//  Copyright © 2016 dane. All rights reserved.


/*

Overall coverage of dominion was good. Over 40% of the branches were executed off of just 8 tests. However, this does not offer any insight to the quality of the unit tests. Over time the tests could be refined and more robust. Even though the coverage seems high based on 8 tests, it should not be correlated with the quality of tests, since many function calls occurred within functions that were being tested. These internal functions were not necessarily tested and could easily have bugs within them that were not found, due to their effects only being visible in other parts of the game state or program.

Function and card test coverage was excellent. Generally speaking, the only time lines were not executed were if the test passed and thus the 'test failed' message did not print. Also, if a conditional were in place to trigger based on a treasure card, that conditional may not have triggered if, for exampke, a copper card was triggered as opposed to a silver card. Bugs would not originate from this unexecuted code, but in future tests it should be noted that incorrect treasure card values could be a result of bugs from other functions.

Results:

dominion.c
Lines executed:36.00% of 650
Branches executed:43.88% of 417
Taken at least once:34.29% of 417
No calls

unittest1.c
Lines executed:84.62% of 26
Branches executed:100.00% of 8
Taken at least once:75.00% of 8
No calls

unittest2.c
Lines executed:72.73% of 22
Branches executed:100.00% of 8
Taken at least once:62.50% of 8
No calls

unittest3.c
Lines executed:96.88% of 32
Branches executed:100.00% of 12
Taken at least once:91.67% of 12
No calls

unittest4.c
Danes-iMac:xa3 Dane$ gcov -b unittest4.c 
File 'unittest4.c'
Lines executed:80.77% of 26
Branches executed:100.00% of 10
Taken at least once:50.00% of 10
No calls

cardtest1.c
File 'cardtest1.c'
Lines executed:85.00% of 20
Branches executed:100.00% of 8
Taken at least once:50.00% of 8
No calls

cardtest2.c
Lines executed:80.00% of 25
Branches executed:66.67% of 12
Taken at least once:41.67% of 12
No calls

cardtest3.c
Lines executed:80.00% of 30
Branches executed:100.00% of 16
Taken at least once:62.50% of 16
No calls

cardtest4.c
File 'cardtest4.c'
Lines executed:82.61% of 23
Branches executed:100.00% of 8
Taken at least once:50.00% of 8
No calls

*/