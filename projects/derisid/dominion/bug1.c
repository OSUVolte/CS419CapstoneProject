/*
numHandsCard test - ALl tests passed

playCard test - One test passed, one test failed, apparently the condition that an action
				card is present may not mean anything.


whoseTurn test - All tests passed

isGameOver test - All tests passed


Smithy card test - This tests the function I altered for a previous assigment, the first two
tests failed, reflecting the bug I inserted where the amount of cards that are added to player
and removed from pile are not what they are supposed to be, there may also be bug somewhere else
in the function that stems from this as some tests did not run.  It is also possible that there
 is an error somewhere in the code as some test loops were skipped.  
 All other successfully conducted tests passed.

Adventurer card test - Test four failed, change in deck amount was not reflected properly, this 
is also related to a bug introduced in the function code.  As above, for some reason not all tests
were executed, this may be a side effect of the aforementioned introduced bug.  All other executed
tests passed.

Treasure map card test - This is another function that had a bug introduced from a previous assignment
all tests that were executed passed save for test 4a, this test failed, as the gold values were not updated
properly.


Council room card test - 5 tests were conducted, only two passed, this was another function that
I bugged, where the each other player card draw was effected as a result, it may have also exposed
another bug not written by me where the deck and discard feature behaviors were altered as well.


*/




