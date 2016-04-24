//bugs found using unit testing.


/*
Error found using cardtest1 to test playSmithy function.  This function added three cards to the 
hand as expected (net of two after smithy removed).  However, the number of Smithy's in the player's 
entire card collection also goes down by one when it was expected to remain the same.  This is because 
the smithy card is trashed instead of discarded in the playSmithy function. 

Errors found using cardtest2 to test playAdventurer function.  Testing the number of treasures in hand before 
and after with known condition, treasures in deck >= 2 should result in treasuses in hand increasing by two.  
Error in function caused three treasure cards to be added (loop checks for <=2).  Also tested for cards 
under players control before and after the function call.  This should remain constant as cards are 
discarded, not trashed.  However, this does not behave as expected as the incorrect number of cards were discarded 
from the temp hand in playAdventurer and placed into discard.

Error found using cardtest3 to test playVillage function.  Both the expected number of actions and the number of 
cards in hand do not return the expected value for all test cases.  This is because the next player rather than 
current player is passed to the function, wrong player receives the village card effect.

*/