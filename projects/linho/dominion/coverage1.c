32% coverage for dominion.c.
Full coverages were done for all functions unittest1-4.c.
95% coverage was done for cardtest1.c.
93% coverages were done for cardtest2.c and cardtest3.c.
90% coverage was done for cardtest1.c.

File 'dominion.c'
Lines executed:32.32% of 659
Branches executed:36.34% of 421
Taken at least once:24.47% of 421

File 'unittest1.c'
Lines executed:100.00% of 41
Branches executed:100.00% of 16
Taken at least once:75.00% of 16

File 'unittest2.c'
Lines executed:100.00% of 49
Branches executed:100.00% of 22
Taken at least once:63.64% of 22

File 'unittest3.c'
Lines executed:100.00% of 25
Branches executed:100.00% of 8
Taken at least once:75.00% of 8

File 'unittest4.c'
Lines executed:100.00% of 32
Branches executed:100.00% of 10
Taken at least once:80.00% of 10

File 'cardtest1.c'
Lines executed:95.65% of 23
Branches executed:50.00% of 4
Taken at least once:25.00% of 4

File 'cardtest2.c'
Lines executed:93.94% of 33
Branches executed:100.00% of 6
Taken at least once:50.00% of 6

File 'cardtest3.c'
Lines executed:93.94% of 33
Branches executed:66.67% of 6
Taken at least once:33.33% of 6

File 'cardtest4.c'
Lines executed:90.62% of 32
Branches executed:85.71% of 14
Taken at least once:57.14% of 14

The coverage for dominion.c is low. In my point of view this is because function tests
only test 4 functions in dominion.c and card tests are also only for 4 cards. The branches executed
are near lines executed and the reasons are basically the same. In dominion.c.gcov(which is also in
unittestresult.out) there is an obvious result shows that all cards funcions I choose to test, adventurer
for runAdventurer(), smithy for runSmithy(), village for runVillage(), and council.room() are all 
covered. These were because I modified the assert function to if statements, because if I didn't do
so, they would never be executed. The reason is that there are all bugs in these 4 cardtest funcions,
once it asserts the code would not be executed. This situation didn't happen to funcion tests though because
they didn't reveal bugs.