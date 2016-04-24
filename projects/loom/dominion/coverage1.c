//
// Created by Michael Loo on 4/24/16.
//
/*

flip2 ~/CS362/dominion 125% gcov -b unittest1.c
File 'unittest1.c'
Lines executed:90.00% of 10
Branches executed:100.00% of 4
Taken at least once:75.00% of 4
Calls executed:80.00% of 5
Creating 'unittest1.c.gcov'

flip2 ~/CS362/dominion 126% gcov -b unittest2.c
File 'unittest2.c'
Lines executed:90.91% of 11
Branches executed:100.00% of 6
Taken at least once:83.33% of 6
Calls executed:80.00% of 5
Creating 'unittest2.c.gcov'

flip2 ~/CS362/dominion 127% gcov -b unittest3.c
File 'unittest3.c'
Lines executed:100.00% of 19
Branches executed:100.00% of 8
Taken at least once:87.50% of 8
Calls executed:100.00% of 6
Creating 'unittest3.c.gcov'

flip2 ~/CS362/dominion 128% gcov -b unittest4.c
File 'unittest4.c'
Lines executed:93.75% of 16
Branches executed:100.00% of 4
Taken at least once:75.00% of 4
Calls executed:87.50% of 8
Creating 'unittest4.c.gcov'

flip2 ~/CS362/dominion 129% gcov -b cardTest1.c
File 'cardTest1.c'
Lines executed:100.00% of 15
Branches executed:100.00% of 4
Taken at least once:75.00% of 4
Calls executed:100.00% of 7
Creating 'cardTest1.c.gcov'

flip2 ~/CS362/dominion 130% gcov -b cardTest2.c
File 'cardTest2.c'
Lines executed:100.00% of 17
Branches executed:100.00% of 4
Taken at least once:50.00% of 4
Calls executed:100.00% of 8
Creating 'cardTest2.c.gcov'

flip2 ~/CS362/dominion 131% gcov -b cardTest3.c
File 'cardTest3.c'
Lines executed:95.45% of 22
Branches executed:100.00% of 8
Taken at least once:62.50% of 8
Calls executed:88.89% of 9
Creating 'cardTest3.c.gcov'

flip2 ~/CS362/dominion 132% gcov -b cardTest4.c
File 'cardTest4.c'
Lines executed:90.91% of 22
Branches executed:100.00% of 8
Taken at least once:62.50% of 8
Calls executed:77.78% of 9
Creating 'cardTest4.c.gcov'

flip2 ~/CS362/dominion 133% gcov -b dominion.c
File 'dominion.c'
Lines executed:43.68% of 570
Branches executed:52.29% of 415
Taken at least once:33.25% of 415
Calls executed:30.00% of 100
Creating 'dominion.c.gcov'

 As you can see, I've covered most of the code in all of my tests, at least 90%.
 For unit tests, I think that I might have not checked a very small amount of the coin couting one,
 as I added only a small bonus.

 For each of the cards, I also executed at least 90% of all of the cards.  The lowest one is the great hall card,
 which is most likely due to the nature of the switching mechanism within the play card function, as there really is no
 way to not execute 100% of the code when using that part of the function.

 As for the dominion code, I executed a little under half of the code.  This makes sense when we factor in that we
 changed a lot of the functions, as well as the fact that we are specifically testing only certain functions instead
 of every single one.
 */


