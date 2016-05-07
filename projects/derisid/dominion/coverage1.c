/*
Dominion Coverage:  31.37% of lines were executed using the unit tests that were written.  This likely
due to the fact that the unit tests themselves were simply not designed to utilize all of the code
present in the dominion.c file.  Based on the coverage results from each individual test execution
it can be seen that not every command in the test files were executed either, though, given the 
context of the assignment I have to assume that we weren't meant to get everything 100% at this point
and based on what we've learned so far there is no real absolute way to do so.  As stated in bug1.c document
the functions tested had bugs added to them and may also have pre-existing bugs or have relationships
with other functions that contained bugs as well, this could have usurped the testing suite in unforeseen
ways at the time of implementation.  There may also be bugs in the tests themselves.  
Tests should and do need likely improvement in order to achieve greater effectiveness and 
thoroughness, as, they are clearly not at this point.

Here is some data:

File 'unittest1.c'
Lines executed:90.00% of 20
Branches executed:100.00% of 4
Taken at least once:50.00% of 4
Calls executed:81.82% of 11
Creating 'unittest1.c.gcov'

File 'unittest2.c'
Lines executed:89.47% of 19
Branches executed:100.00% of 4
Taken at least once:50.00% of 4
Calls executed:81.82% of 11
Creating 'unittest2.c.gcov'


File 'unittest3.c'
Lines executed:90.48% of 21
Branches executed:100.00% of 4
Taken at least once:50.00% of 4
Calls executed:81.82% of 11
Creating 'unittest3.c.gcov'

File 'unittest4.c'
Lines executed:88.89% of 27
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:80.00% of 15
Creating 'unittest4.c.gcov'

File 'cardtest1.c'
Lines executed:76.47% of 102
Branches executed:91.30% of 46
Taken at least once:47.83% of 46
Calls executed:67.16% of 67
Creating 'cardtest1.c.gcov'


File 'cardtest2.c'
Lines executed:76.67% of 60
Branches executed:84.62% of 26
Taken at least once:46.15% of 26
Calls executed:65.71% of 35
Creating 'cardtest2.c.gcov'

File 'cardtest3.c'
Lines executed:77.63% of 76
Branches executed:88.24% of 34
Taken at least once:50.00% of 34
Calls executed:65.91% of 44
Creating 'cardtest3.c.gcov'

File 'cardtest4.c'
Lines executed:86.84% of 38
Branches executed:100.00% of 10
Taken at least once:50.00% of 10
Calls executed:73.68% of 19
Creating 'cardtest4.c.gcov'

File 'dominion.c'
Lines executed:31.37% of 561
Branches executed:28.78% of 417
Taken at least once:23.50% of 417
Calls executed:22.11% of 95
Creating 'dominion.c.gcov

References
https://github.com/aburasali/cs362sp16/tree/master/projects/vlaskint
https://github.com/aburasali/cs362sp16/tree/60654150b4db7e43929c411ba977b3c4fc6d2afa/projects/lallyk
https://github.com/aburasali/cs362sp16/tree/master/projects/creesl
Assignment supplements provided by Ali, like cardtest4.c and UpdateCoinsTest.c
Also just some general repo cruising looking for ways to expand on my tests.

*/