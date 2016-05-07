#tatyana vlaskin

28.42% of 570
The coverage of dominion is not great. Only 28.42% of 570 lines were executed using the unit tests that we implemeted.
This was expected because first of all only 6 functions were tested and at the same time the functions and cards
that I have chosen to test were not very long. However, even though taking into concideration that only 8
functions were tested, we can say that 28.42% is a deceit coverage and if more tests will be implemeneted to
test the rest of the functions, I will be able to get close to 100%. However, as I already stated in the bug1.c
file my unit test are not perfect as one of the errors was not detected by the unit test for the Adventure card.
This gave me a better picture of the unit testing and how they are to be omtimized. Overeall, I would say that
the unit testing that I have desiged are not that greate. As already mentioned above one of them did not detec the
bug that I have introduced last week. Also for the isGameOver() function I have not tested all possible senarios
to make sure that the game will NOT end.

If we look at the invidual covereages of the 8 unit test, they look really good. However, we need to remember
that high coverage numbers does not nessessrity translate to goo unit tests. A lot of the functions that I have
tested are used by other functions in the code that we not tested and they might have bugs. At the same time
as already mentioned above the unit tests that I have implemetned does not cover all possible senatios and even
in the Adventure unit test bug was not detected, but the coverage looks really good:

File 'cardtest2.c'
    Lines executed:92.86% of 14
    Branches executed:100.00% of 2
    Taken at least once:50.00% of 2
    Calls executed:87.50% of 8
    Creating 'cardtest2.c.gcov'

Overall if we look at the lines executed for the 8 unit tests, the numbers a really high, and it seems that
the only lines that were not executed are those that were not supposed to be executed - for example if the
test passed then the failed code will not be executed or vice versa.


File 'unittest1.c'
    Lines executed:83.33% of 24
    Branches executed:100.00% of 6
    Taken at least once:66.67% of 6
    Calls executed:70.59% of 17

File 'unittest2.c'
    Lines executed:100.00% of 18
    Branches executed:100.00% of 4
    Taken at least once:50.00% of 4
    Calls executed:77.78% of 9
    Creating 'unittest2.c.gcov'

File 'unittest3.c'
    Lines executed:80.00% of 25
    Branches executed:66.67% of 12
    Taken at least once:33.33% of 12
    Calls executed:66.67% of 15
    Creating 'unittest3.c.gcov'

File 'unittest4.c'
    Lines executed:84.21% of 19
    Branches executed:100.00% of 6
    Taken at least once:50.00% of 6
    Calls executed:72.73% of 11
    Creating 'unittest4.c.gcov'

File 'cardtest1.c'
    Lines executed:92.86% of 14
    Branches executed:100.00% of 2
    Taken at least once:50.00% of 2
    Calls executed:87.50% of 8
    Creating 'cardtest1.c.gcov'


File 'cardtest2.c'
    Lines executed:92.86% of 14
    Branches executed:100.00% of 2
    Taken at least once:50.00% of 2
    Calls executed:87.50% of 8
    Creating 'cardtest2.c.gcov'

File 'cardtest3.c'
    Lines executed:90.00% of 20
    Branches executed:100.00% of 4
    Taken at least once:50.00% of 4
    Calls executed:83.33% of 12
    Creating 'cardtest3.c.gcov'


File 'cardtest4.c'
    Lines executed:90.00% of 20
    Branches executed:100.00% of 4
    Taken at least once:50.00% of 4
    Calls executed:83.33% of 12
    Creating 'cardtest4.c.gcov'

File 'dominion.c'
    Lines executed:28.42% of 570
    Branches executed:28.06% of 417
    Taken at least once:19.18% of 417
    Calls executed:25.00% of 100
    Creating 'dominion.c.gcov'


