/* Diana O'Haver
   Assignment 4
   Writeup of random testers

   The first tester that I wrote was the tester for smithy. Of the initial three tests that
   I wrote, only two functioned as expected. My second test, which was supposed to test that
   a random player who used the smithy card received the net 2 cards as spec'd by the game,
   only sometimes ended with a net increase of 3 (the net increase of 3 was expected, due to
   the bugs introduced in an earlier assignment). This was corrected by clearing the player's
   hand and using the same strategy to re-draw a new hand.

   The second tester was the required tester for adventurer. Due to the bug that I introduced
   previously, I expected most of the tests to fail. What I didn't anticipate was forgetting
   to seed my rand() function, so I initially had puzzlingly static values for what were
   supposed to be random inputs being generated. Once that was fixed, the testing behaved as
   expected. Because drawntreasure was being incremented by 2 instead of 1 with each treasure
   draw, the deck was not reduced as expected without the bug, and the hand size was also not
   incremented as anticipated in a bug-free environment.

   I covered Smithy in the unit tests, and my coverage in the random testing equaled that of
   the unit testing: all values were 100%. The random testing for Adventurer also performed
   exactly the same as I had in the unit tests - all values 100%, with the exception of "taken
   at least once."
*/
