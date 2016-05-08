/*Analysis of random testing. John Brown

To compile everything:  make unittestresults.out

Using the statement coverage method, confirmed number of lines executed:
increased from 29.77% out of 571 with unit testing to 33.98% out of 571.  This
is  more than a 4% increase. This really is to be expected  as I did not test
any new functions and the functions previously tested had good coverage.  Also
this coverage is for the entire program code.  Using the randomized  test
cases I did obtain 100% statement and branch coverage for the playSmithy and
playAdventurer functions that I tested.  The aditional  coverage I picked up
was from certain cases like reshuffling the deck.  My approach to testing the
functions randomly was very similiar to what I used for the unit tests, only
many more test cases were generated.  I generated test cases then  checked the
game state properties against the expected values.  The bugs located were
really the same that I had noted in my previous  write up.  However, the
random testing did accomplish a couple of things.  For one, this allowed me to
basically test  many combinations of different cards in play to see if any
such combination caused faults.  The other concern that this  random testing
really made me more of aware of is that the program as written is not very
robust.  For instance, I would like  to be able to test with truly random,
almost junk input, but the program as written will corrupt the game  state and
crash in many cases haulting the testing. The  program has internal trust that
if you are passing the hand location of the smithy card for instance, it
proceeds as if this is the correct location. There is no checking to see if
this really is the correct card.  Inputing more eradic inputs in my  random
testing can generate seg faults as the program can easily get confused as to
the actual number of cards left if bad inputs are fed in  at the function
level.

