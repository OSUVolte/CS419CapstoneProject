/*
Development of your random testers: 

For rantomtestadventurer.c, I used a fuzzer to produce random info in my gamestate. Then I randomized the number
of players (between 2 and 4) and the current player. Then, I created a random deck, hand, and discard for the current player.
I ran my tests this way 2000 times.

For randomtestcard.c, I tested the cutpurse card. I did much of the same as what I did for the randomtestadventurer.c.
I used a fuzzer to produce random info in my game state. I then replaced certain variables, using random values
for them as well. For instance, I used a random number of players between 2 and 4, I changed the active player
randomly, I set the played card count to a number between 0 and 19, and I randomized the deck, discard,
and hand of every player since all players are to be affected by this function. I also ran my tests using these
random variables 2000 times.

Improvements in coverage:

One thing that was exciting about the random test is that it made one more assert fail in my cutpurse test than 
I was able to make fail with regular unit tests. Now, the test that checks to see whether or not the other players
has either discarded a coin card or do not have one fails. This fails because I introduced a bug which
makes the current player lose cards instead of the other player. So the fact that this fails makes sense.

Also, my coverage for cutpurse went up. Originally it was:

Function 'cutpurseAction'
Lines executed:76.92% of 13
Branches executed:66.67% of 12
Taken at least once:50.00% of 12
Calls executed:100.00% of 3

Now it's:
Function 'cutpurseAction'
Lines executed:84.62% of 13
Branches executed:83.33% of 12
Taken at least once:75.00% of 12
Calls executed:100.00% of 3

This is because randomly generating cards creates more types of coin cards than just initializing a
regular game. Thus, more of the cutpurse function must be used to deal with copper, silver, and gold
rather than just copper. Now we know that lines for all three of these coin types work.

The adventurer function always had 100% line and branch coverage, so this remained the same.

Effort to check correctness:

It took some trial and error in order to replace the random bits created by the fuzzer to valid values. For instance,
it took me some time to realize that the played card count was a variable used by the discard function, so it needed to be
set in order to keep my tests from crashing the program when testing cutpurse.

My largest issue with this program has been setting my hand, discard, and deck piles so that they had a good random range
but so they also didn't become so large so as to run over other data and make the test crash. Originally, I set discard and deck both to
create sizes in the range of 0 to the maximum hand size. However, this caused problems when the discard pile was too large
to accept new cards and overflowed into other data. 

Both test files also required minimum sizes for the deck, as both took action with these cards, so it was not possible to
randomize this value starting from 0.


*/