Results: 

File 'unittest1.c'
Lines executed:100.00% of 92
Branches executed:100.00% of 54
Taken at least once:55.56% of 54
Calls executed:66.67% of 72
Creating 'unittest1.c.gcov'

File 'dominion.c'
Lines executed:15.61% of 570
Branches executed:15.35% of 417
Taken at least once:12.71% of 417
Calls executed:7.00% of 100
Creating 'dominion.c.gcov'

File 'unittest2.c'
Lines executed:100.00% of 72
Branches executed:100.00% of 40
Taken at least once:55.00% of 40
Calls executed:68.42% of 57
Creating 'unittest2.c.gcov'

File 'dominion.c'
Lines executed:17.89% of 570
Branches executed:16.79% of 417
Taken at least once:13.67% of 417
Calls executed:7.00% of 100
Creating 'dominion.c.gcov'

File 'unittest3.c'
Lines executed:100.00% of 42
Branches executed:100.00% of 22
Taken at least once:59.09% of 22
Calls executed:66.67% of 27
Creating 'unittest3.c.gcov'

File 'dominion.c'
Lines executed:17.89% of 570
Branches executed:16.79% of 417
Taken at least once:13.67% of 417
Calls executed:7.00% of 100
Creating 'dominion.c.gcov'

File 'unittest4.c'
Lines executed:100.00% of 75
Branches executed:100.00% of 24
Taken at least once:91.67% of 24
Calls executed:92.31% of 26
Creating 'unittest4.c.gcov'

File 'dominion.c'
Lines executed:23.68% of 570
Branches executed:29.74% of 417
Taken at least once:26.62% of 417
Calls executed:10.00% of 100
Creating 'dominion.c.gcov'

File 'cardtest1.c'
Lines executed:100.00% of 38
Branches executed:100.00% of 18
Taken at least once:55.56% of 18
Calls executed:66.67% of 24
Creating 'cardtest1.c.gcov'

File 'dominion.c'
Lines executed:26.84% of 570
Branches executed:35.73% of 417
Taken at least once:27.58% of 417
Calls executed:15.00% of 100
Creating 'dominion.c.gcov'

File 'cardtest2.c'
Lines executed:100.00% of 107
No branches
Calls executed:100.00% of 75
Creating 'cardtest2.c.gcov'

File 'dominion.c'
Lines executed:32.11% of 570
Branches executed:39.57% of 417
Taken at least once:31.41% of 417
Calls executed:20.00% of 100
Creating 'dominion.c.gcov'

File 'cardtest3.c'
Lines executed:100.00% of 47
Branches executed:100.00% of 20
Taken at least once:55.00% of 20
Calls executed:70.00% of 30
Creating 'cardtest3.c.gcov'

File 'dominion.c'
Lines executed:35.09% of 570
Branches executed:41.49% of 417
Taken at least once:33.81% of 417
Calls executed:25.00% of 100
Creating 'dominion.c.gcov'

File 'cardtest4.c'
Lines executed:100.00% of 48
Branches executed:100.00% of 24
Taken at least once:54.17% of 24
Calls executed:64.52% of 31
Creating 'cardtest4.c.gcov'

File 'dominion.c'
Lines executed:36.49% of 570
Branches executed:41.49% of 417
Taken at least once:34.05% of 417
Calls executed:29.00% of 100
Creating 'dominion.c.gcov'

Most of the file is not covered because there are only 4 cards and 4 game functions being covered. I think that branch
coverage can be improved by creating a wider variety of a players cards when running tests for some of the functions.
100% of lines were executed for all the unit tests completed because if the test case did not pass for anything, then
it would have failed and aborted the program. For the sake of writing coverage1.c and collecting, I decided to fix
the tests to bypass aborting when the test cases are not correct. In the future, I will change them so that they
do no abort when the test fails.

I'm sure that some functions could be tested better. For example, while testing scoreFor, I did not go through
every option and card combo, with varying deck and hand sizes. Coverage for this is important because there are so
many factors for it, whereas simplier tests such as the smithy test that only adds 3 cards to the players hand
can be quickly checked.

Additionally, I think it would have been more wise to fix bugs I've found in the code and rerun the tests. Though
I'm not entirely sure the bugs I've found are working as intended or not.

A final note is that I should create test cases with a larger variety of cards. The dominion game is supposed to be
played with a random selection of treasure cards each time, but I set up my tests to use the same set of cards
over and over for each test. Additionally, 7/8 of my tests only contained 2 players. My lack of variety leaves a lot
to be covered, which is something to think about for future tests.