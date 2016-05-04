/* Corey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Assignment 3
 * April 24, 2016
 * coverage1.c
 */

/************************** unittest1 coverage ***************************/
/* ------------------------------------------------------------------------

unittest1 tests function isGameOver() and gets 18.07% coverage of the 
dominion.c file. I think this is a relatively low percentage of coverage
to get for the overall dominion file although the function itself is
relatively small and doesnt call very many other functions. 18.07% actually
turns out to be a high amount of coverage for a file the size of dominion.c.
The isGameOver() function is roughly 30 lines of code. 38/548 is about
18% coverage.

------------------------------------------------------------------------ */


/************************** unittest2 coverage ***************************/
/* ------------------------------------------------------------------------

unittest2 tests function initializeGame() and gets 17.88% coverage of the 
dominion.c file. For the given size of the initializeGame() function, I
think that 17.88% coverage is indeed low. I did not implement enough tests 
to cover the entire function and its branches due to its size and scope, 
but the tests I did write are fairly thorough. There simply needs to be more 
tests to get the necessary coverage for this particular function.

------------------------------------------------------------------------ */


/************************** unittest3 coverage ***************************/
/* ------------------------------------------------------------------------

unittest3 tests function endTurn() and gets 21.53% coverage of the 
dominion.c file. 21.53% coverage for this particular function is actually
quite high. This means that the tests I created were able to cover the
entire function including some coverage from all of the functions it called
itself. endTurn() is a function I feel that I was able to test very well 
and get a nice amount of coverage for. This is not to say I caught all or
any bugs for that matter, but I know I was able to test the entire functions
insides.

------------------------------------------------------------------------ */


/************************** unittest4 coverage ***************************/
/* ------------------------------------------------------------------------

unittest4 tests function buyCard() and gets 21.53% coverage of the 
dominion.c file. buyCard() coverage at 21.53% is high and is a good amount
of coverage for this given function. The function is about 14% of the total
dominion file, so from what I understand, I was able to cover the entire
function and then some. There are some tweaks I'd like to make to the
tests as I think I could get even better coverage still. And once again, I
wasn't able to catch any bugs with my tests.

------------------------------------------------------------------------ */


/************************** cardtest1 coverage ***************************/
/* ------------------------------------------------------------------------

cardtest1 tests smithy card and gets 20.44% coverage of the dominion.c 
file. Given the size of the function call, I think that the coverage I 
was able to get is quite good as it tests both drawCard() and discardCard()
functions quite extensively through testing smithy. Considering that smithy
primarily calls other functions, it is important to cover those said
functions through smithy and make sure the outcome I expect actually comes
to fruition.

------------------------------------------------------------------------ */


/************************** cardtest2 coverage ***************************/
/* ------------------------------------------------------------------------

cardtest2 tests adventurer card and gets 23.18% coverage of the dominion.c
file. The adventurer card function has a lot of issues due to the bug that
I found in shuffle() function (see bug1.c). The coverage of 23.18% is pretty
good but I think it could be a lot better if shuffle() was fixed and working
properly. There also may be a bug with adventurer card that I wasn't able
to determine was a real bug. This could affect the coverage that I got.

------------------------------------------------------------------------ */


/************************** cardtest3 coverage ***************************/
/* ------------------------------------------------------------------------

cardtest3 tests mine card and gets 25.18% coverage of the dominion.c file.
The tests I wrote for mine are probably the ones I am most confident about.
The 25.18% coverage is exceptional given the size of the function. The mine
card is also affected by the shuffle() bug so there may be some things that 
could come to light if shuffle() was fixed. From what I was able to test,
the function doesn't seem to have any bugs of its own.

------------------------------------------------------------------------ */


/************************** cardtest4 coverage ***************************/
/* ------------------------------------------------------------------------

cardtest4 tests council_room card and gets 22.08% coverage of the dominion.c 
file. Another high % of coverage for the most part and another function that
mainly tests that drawCard() is sane and does its job correctly. I was able
to test every branch of council_room and I think the coverage my tests got
was pretty good.

------------------------------------------------------------------------ */

