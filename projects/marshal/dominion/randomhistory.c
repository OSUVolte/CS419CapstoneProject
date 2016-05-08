/**
Alex Marsh
CS362 Assignment 2
randomhistory.c


    to run and compile randomtestadventurer.c and randomtestcard run: 
        make randomtestresults


    For my random testing of the adventurer card and village card I implemented a random initiation of the game. I first initiated a typical game, G, then copided that state to another game struct, played. Played gameState is the state that underwent the actually playing of the adventure and village card. The third gameState, expected, remained untouched and was used to compare to played for tests. 
    In my testing I then chose a random player as set whoseTurn to this player. Next I randomized the size of the deck, discard, and hand pile amounts. I also inserted the adventure card in a random position of the current players hand in order to ensure the card was present, but still implement some element of randomness. 
    I also randomized the amount of coin cards a player had.  Each amount of gold, silver, and copper coins where randomized. 
    Once the game state of played was intiated with random amount of cards, players, and a handpostition I copied the state of played to expected.  For testing purposes I printed the amounts of each hand, deck, and discard pile to ensure the states where the same.  After including this random state, I played the adventurer card in the played gameState by calling cardEffect. For testing purposes I set choice1, choice2, choice3, and bonus all to zero. 
    After the card was played the two states, played and expected, are assumed to be different so the testing commenced. When playing the adventurer card the business requirments are
    -the player looks through their own deck until two treasure cards are found
    -the two treasure cards are placed in the players hand
    -the other drawn cards should go into the players discard pile
    -other players game state should be untouched
    -the victory card pile supply should be untouched
    -the kingdom card pile supply should be untouched
    The testing used in my file 'cardtest2.c' was used in the testing. The process of creating a random game state and testing the states against eachother was in a for loop and run 2000 times. This spread coverage of both the test file and dominion.c. The results of randomtestadventurer and randomtestcard along with their coverage of dominion are both written to the file randomtestresults.out. 
    When constructing my random test for the adventurer card I ran into a few obstacles that ultimately results in a better coverage of my code. My first obstacle was in finding the correct place and time in my program to create the game state and then copy it for a comparison. Originally I had copied the played state to expected before I randomly assigned cards to the deck, hands, and discard piles.  This resulted in the two states being very different and thus failed every test.  I reduced the amount of iterations to only twice and was able to locate my issue.  Once I correctly matched both states I ran randomtestadventurer.c with gcov with only two iterations. This resulted in only a 83% of coverage of the 'playAdventurer' function in dominion C. I then increased my iterations to 1000 and recieved a coverage of 93%.  In the third alteration I increased the iterations to 2000, and found my coverage to increase to 100%.     
    As I wrote code for randomtestcard.c I followed a similar approach that I took for randomtestadventurer. The following are business requirements for playing the village card:
    -the player draws 1 card
    -the player discards the village card
    -after playing the village card the players hand should remain the same count as before the play
    -the player draws 1 card from their own deck
    -the player decreases their deck by 1
    -the player should recieve 2 actions (increase numActions)
    -other players game state should be untouched
    -the victory card pile supply should be untouched
    -the kingdom card pile supply should be untouched
    I began with only two iterations which resulted in only 26% coverage of the playVillage.  This time I increased the iterations to 2000 directly and saw an increase to 100% coverage of playVillage in dominion.c. 
    When running my random tests for the adventure and village card my tests showed many errors.  For the village card in randomtestcard.c the test for a count of estate cards failed for every iteration. This may be due to the bug I inserted in our first assignment.  With my bug the player draws three cards instead of the intended two. The error also is shown when the deck is empty.  The card doesn't account for this in the function. 
    I also encountered errors when testing the randomtestadventurer.c. These errors are the same as the unit tests as they indicate errors with the current players handcount, treasure count, deck count, and the other players status. As I discussed in my results for the unit tests, I introduced a bug to the implementation of the adventurer card. It results in the players cards increasing by 2 instead of 1. This has a ripple effect and can be seen in the error of count found in handcount, treasure count, and deck count. The issue with the other players status was not found with the unit tests and should be further investigated.  
    
 randomtestadventurer:
    File 'dominion.c'
    Lines executed:27.21% of 566
    Branches executed:28.06% of 417
    Taken at least once:19.90% of 417
    Calls executed:15.84% of 101

 
    function playAdventurerCard:
        called 1004 
        returned 100% 
        blocks executed 100%
    
randomtestcard: 
    File 'randomtestcard.c'
    Lines executed:75.00% of 72
    Branches executed:100.00% of 28
    Taken at least once:64.29% of 28
    Calls executed:64.29% of 28
    
    File 'dominion.c'
    Lines executed:31.80% of 566
    Branches executed:30.94% of 417
    Taken at least once:21.82% of 417
    Calls executed:24.75% of 101

    function playVillageCard:
        called 2000 
        returned 100% 
        blocks executed 100%
    

**/


