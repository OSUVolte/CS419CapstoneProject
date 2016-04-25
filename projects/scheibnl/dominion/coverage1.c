/*
In general, I had really strong coverage for most of my functions. There 
was one (cutpurse) that was noticeably weaker than the rest.

cardtest1-
Testing: smithy

Function 'smithyAction'
Lines executed:100.00% of 5
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 2

cardtest2-
Testing: adventurer

Function 'adventurerAction'
Lines executed:100.00% of 15
Branches executed:100.00% of 12
Taken at least once:83.33% of 12
Calls executed:100.00% of 2

cardtest3-
Testing: cutpurse

Function 'cutpurseAction'
Lines executed:76.92% of 13
Branches executed:66.67% of 12
Taken at least once:50.00% of 12
Calls executed:100.00% of 3

This function had my weakest coverage. I never covered the case where the user
had to reveal some of their cards (because they didn't have a copper to cut from
the hand.) This was probably partially because of the bug I introduced, making it
so that the cutpurse actually happens to the current player instead of the other
players. However, I could have set up the current player's hand so as to test this code.



cardtest4-
Testing: sea_hag

Function 'sea_hagAction'
Lines executed:100.00% of 8
Branches executed:100.00% of 4
Taken at least once:100.00% of 4
No calls

unittest1-
Testing: discardCard

Function 'discardCard'
Lines executed:92.31% of 13
Branches executed:100.00% of 6
Taken at least once:83.33% of 6
No calls


unittest2-
Testing: updateCoins

Function 'updateCoins'
Lines executed:81.82% of 11
Branches executed:100.00% of 8
Taken at least once:75.00% of 8
No calls

This was the function I covered second-least. However, the lines I missed
covering here don't seem as detrimental as the ones I missed in cutpurse. Here,
I just didn't test the lines that dealt with silver and gold cards instead of 
copper cards. And while it is important to make sure that this function also adds
these cards correctly, it's pretty easy to see from the code that the addition is
simple and is written the same as for the copper. Thus, it's very probable that this
function would add those cards correctly if they were encountered.

This would also be an easy thing to test, however, by inserting these cards manually
into the hand before running the function in the tests.:

unittest3-
Testing: gainCard

Function 'gainCard'
Lines executed:100.00% of 13
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 1

unittest4-
Testing: isGameOver

Function 'isGameOver'
Lines executed:100.00% of 10
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

*/