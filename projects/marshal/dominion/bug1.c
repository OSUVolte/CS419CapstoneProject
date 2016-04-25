/*
Alex Marsh
CS362 Assignment 2

Unittest1 Bug
    My unittest1.c tests the scoreFor function.  This funciton is intended to return teh overall score of a player by counting the estate cards in their deck, hand, and discard pile.  The function accounts for the number of each card and adds or subtracts the appropriate points for the card.  While running my unit test on the function I noticed that when I filled the deck with any number of each card, my test returned positive.  For example, when I tested a deck filled with only 3 estate cards, the appropriate score should be 3 since each estate card is worth one point. However the scoreFor() function returned 0.  The function was found to return a zero for any card put in the deck. Upon further review of the scoreFor function I found that the third for loop that is intended to loop through the deck is written as:
    for (i = 0; i < state->discardCount[player]; i++)
The lines should instead be:
    for (i = 0; i < state->deckCount[player]; i++)
Written as it is now, the function will only execute for the amount of cards in the discard pile.  So if there are no cards in teh discard pile, the loop will not execute. This is what happened in my test.  Coincidently, if there are cards in the discard pile the loop will execute, but may not reach all of the estate cards in the deck.  I found that one of my tests actually missed this information as I put the same amount of cards in each hand, deck, and discard, but only put victory cards in one pile.  Though the discard pile had only 8 copper cards, the loop executed and the 8 estate cards in the deck were counted. 

Unittest2 
    My unittest2.c tests the getCost function in dominion. The function is meant to return the cost of the card.  For example a feast card will cost 4 units.  With my test, I did not find any bugs and all tests returned correctly and passed. 
    
Unittest3
    The code I wrote for unittest3 tests the fullDeckCount() function.  This function is passed the game struct, player, and the specific card you wish to count.  The function is meant to return the total amount of those cards in the players hand, deck, and discard pile.  To test this function I used four for-loops.  My first loop tested the functions ability to correctly add all of the cards in each pile. I added a card (0-166) to each pile and then called the function. I then tested the functions accuracy in testing the count of each individual pile. I only added the copper card to one pile and estate cards to the other two.  The function is supposed to only count copper cards and should return the correct amount even though the card we seek is in only 1 pile.  The function did not return any bugs. 
    
Unittest4
    Unittest4 tests the function whoseTurn() in dominion.c.  whoseTurn() is passed the game state and will return an integer representing the current player.  The players integer begin with 0 and can increase to 3 as there are 4 players allowed.  I tested the function by in a for-loop (10 times) first creating an instance of the game and checking that the current player returned from whoseTurn matched 0 who is by default the first player.  I then included another for-loop that went through all 4 possible players that called endTurn on the current player and checked that whoseTurn returned the proper next player. whoseTurn is also meant to loop back to the first player (0) if all the players have had a turn.  I accounted for this in my inside for-loop by looping through one more than the allowed players.  I then checked that the current player was indeed 0.  All tests passed for whoseTurn and no bugs where found. 
    
Cardtest1
    My cardtest1 is a unit test for the smithy card. When playing the smithy card the user is expected to:
        -gain 3 cards from their own deck
        -players deckCount should be 3 less than it's previous state
        -other players game state should be untouched
        -the victory card pile supply should be untouched
        -the kingdom card pile supply should be untouched
In my unit test I accounted for all of the requirements above.  In my testing I encountered 3 errors. The first error I found was that the players hand count did match the expected 7 (gain 3 cards and discard 1 so 5+3-1=7). Instead the user had a hand count of 8.  This is a result of the bug I introduced in assignment2 that caused the player to draw 4 cards.  The code is written: 
    for (i = 0; i <= 3; i++)
Where it should be:
    for (i = 0; i < 3; i++)
Unfortunately, this bug had a ripple effect as it cause the second error I found.  The deck count for the current player is also effected.  The deck count, which started at 5 was expected to be 2 (minus the 3 drawn cards). Instead the users deck count was 0 since the player overdrew from their deck.  Though this did confirm that the player was drawing from their own deck, the count was off.  The third error I found was in the supply count for a victory card.  While the kingdom supply cards where untouched, the estate supply card were expected to be at an 8 count and instead were at a 6 count. 2 estate cards were removed when the player played the smithy card. 

Cardtest2
    Cardtest2 is a unit test for the adventurer card.  When playing the adventurer card the business requirments are:
    -the player looks through their own deck until two treasure cards are found
    -the two treasure cards are placed in the players hand
    -the other drawn cards should go into the players discard pile
    -other players game state should be untouched
    -the victory card pile supply should be untouched
    -the kingdom card pile supply should be untouched
Cardtest2 will acount for all of the requirements above.  Similar to my unit test for the smithy card, my test encountered 3 errors. The first being in the players hand.  When the player uses the adventurer card, it is expected that they will gain 2 treasure cards and discard the adventure card.  Thus the players had is supposed to increase by 1.  However my test showed that the players hand was increasing my two.  This is due to the bug I introduced in assingment two where the code shows: 
    while(drawntreasure<=2)
when it should be: 
    while(drawntreasure<2)
Like in cardtest1, this had a ripple effect for the deck count of the player.  My unit test found this second error. The deck count is should decrease by two cards that the player has drawn, but instead the deck is again empty as a result of the player drawing more cards than intended. The third error found was again the estate card supply pile being two less than it should be.  This bug is taking two cards from the pile where the test game returns 6 when there should be 8 estate cards. 

Cardtest3
    The unit test in cardtest3 covers the playing of the village card.  The village card is intended to have the player draw one card increasing their hand by 1. Then the player should discard the village card which results in the players hand remain the same count as before they played the village card. The following are business requirements for playing the village card:
    -the player draws 1 card
    -the player discards the village card
    -after playing the village card the players hand should remain the same count as before the play
    -the player draws 1 card from their own deck
    -the player decreases their deck by 1
    -the player should recieve 2 actions (increase numActions)
    -other players game state should be untouched
    -the victory card pile supply should be untouched
    -the kingdom card pile supply should be untouched
Just as the two previous cardtests, this unit test has resulted in 3 fails.  The first error found was that the player had increased their hand size by 1 more card than expected.  This again is a result of the bug I added in assignment 2.  In my refactoring function I called the draw function twice instead of once.  This made the player draw two cards instead of the intended 1. Thus the test failed with a players hand count being 6 instead of the expected 5. 
    The next failed test was in the deck count.  Because the player is supposed to draw 1 card the deck should only decrease by 1.  But because of my error from assignment 2, the player drew 2 cards and thus the deck is decreased by two.  So my test showed that the deck count was 3 instead of the expected 4. 
    The last failed test is one that has been present in all of my card unit tests, the count of the estate supply pile.  As the previous unit tests have revealed the supply count for the estate pile is 6 where it is expected to be 8. This may be a bug not in the playing of the cards, but in the initialization of the game or playing a card in general. 
    
Cardtest4
    cardtest4 covers a unit test for playing the great hall card. When a player plays this card, certain business requirments are meant to be met. Such as:
    -the player draws 1 card
    -the player discards the village card
    -after playing the village card the players hand should remain the same count as before the play
    -the player draws 1 card from their own deck
    -the player should recieve 1 action (increase numActions by 1)
    -the player decreases their deck by 1
    -other players game state should be untouched
    -the victory card pile supply should be untouched
    -the kingdom card pile supply should be untouched
 I wrote my unit test to cover these specific requirements. During my testing cardtest4 found 2 failed tests.  These failed tests are different than the pattern found in cardtest1, cardtest2, and cardtest3.  In cardtest4 the first test that failed was the hand count.  Since the player draws 1 card, but then discards the great hall card their hand count should remain the same as before they played the card.  In my test the expected result was a hand count of 5, but my test revealed the hand count to really be only 1. In assignment 2 I did not introduce a bug to playing the great hall card.
    The second error the unit test revealved was not with the estate supply count as the previous cardtests, but instead an inaccurate count of actions for the player.  The great hall card gives the player an extra action move which should increment the players numActions in the game state.  I found that the game states numActions was increased by 2 instead of the intended 1.  My test showed that the actual state had an action count of 3 where it is intended to only have 2 after playing the great hall card. 


*/