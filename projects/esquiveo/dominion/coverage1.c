// Osbaldo Esquivel
// CS 362
// Assignment 3

unittest1.c: The coverage on this test was 56% which is far from ideal. But, with edits that I made to this test, I could not get this to improve before I ran out of time for this. Initially, I found that I had to add an extra for-loop in the test function to improve this. I suspect that  I randomized the deck but I am not calling a function where it needs to be called. This will definitely need to be tweaked for better coverage.

unittest2.c: The coverage on this test started a bit low but not as bad as unit test 1. After adding while loops for randomness, I was able to get this coverage to 78%. This can still be improved but there is not much tweaking left on this test. Testing for shuffle was simillar to other deck functions because it would randomize the same methods: deck, hand, and discard several thousand times.

unittest3.c: At 73% coverage, unit test 3 is close to unit test 2 and there were similar bugs that I encountered. However, in the actual function in dominion.c, there was nothing to change as it is a very simple, one-line function. This tested the number of cards in the hand which meant randomizing the and and hand count as well as the deck count.

unittest4.c: The function in dominion.c did not seem to need any changes as I could not find any bugs. As such, the coverage showed this with 94% coverage. Since the function was for a full deck count, I decided to test the various states of the deck. This mean using while loops to change deck, hand, and discard.

cardtest1.c: I could not get my code to compile so there were no lines to execute for gcov. The while loop in the test function should check for treasure as this is the adventurer card, but somewhere in the code, I am missing where to return or it is stuck in an infinite loop. This will need to be adjusted to actually compile.

cardtest2.c: I could not get my code to compile for this card, either. As with the adventurer, for the smithy card, I was hoping to randomize the state of the deck and hand. Then, with the two draws and a discard, it should have worked. Somehow, it is not compiling and will need to be fixed.

cardtest3.c: The gardens card had 100% coverage as it is a fairly simple card. It returns -1 for cardEffect and this behavior was consistent. I was testing 4000 times and randomizing the state including, deckCount, deck, hand, discard, and handPos. This gave a very good test for these methods and the coverage showed this.

cardtest4.c: For the village card, I expected it to give the player a card, give them two actions, and then discard a card. I was not able to get the coverage for this as it would not compile, but the requirements were clear and the code matched the requirements. 
