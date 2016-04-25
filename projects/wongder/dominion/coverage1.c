//Derek Wong
//CS362
//coverage1.c

~~~Coverage Test unittest1~~~

File 'dominion.c'
Lines executed:3.54% of 565
Branches executed:2.89% of 415
Taken at least once:2.41% of 415
Calls executed:2.11% of 95
Creating 'dominion.c.gcov'

In this unit test I tested the shuffle function. The first thing I did in this unit test was to add cards into each players hand, deck, and discard pile. I didn't want to use the initializeGame because the game began with a lot of the same cards in the player's deck, so it would've been kind of hard to see if it shuffled or not. I first tested if the shuffle function actually shuffled by comparing the deck before and after shuffle. The other tests were just to see if other game state changed. For example, checking if the hand has been modify or if other players hand or deck has been modified.  The lines executed 3.54% of the dominion code which is reasonably because the shuffle function isn't a big part of the code. When I tested it inidivually my lines executed 89.74% which should be correct because I had if statements in the code so not all lines would be hit. It was surprising that my branch wasn't at 100%. I can't find any reason why all my code wasn't being hit. All the test cases passed as expected, because shuffle isn't very complicated.

~~~Coverage Test unittest2~~~

File 'dominion.c'
Lines executed:17.70% of 565
Branches executed:17.83% of 415
Taken at least once:15.18% of 415
Calls executed:7.37% of 95
Creating 'dominion.c.gcov'

In this unit test I tested the isGameOver function. The first cases I check were the conditions for the game to end. This includes 3 empty supply piles and empty province. Other cases I test for if the game ended in different circumstances. I also checked for player's hand, deck, and empty pile. This makes it so that more code is covered in dominion than just isGameOver itself. I called isGameOver 13 times in unit test 2. I reset the game state every time I finished testing one case and called it again in the next. I had 100% branch coverage when I tested unittest2.c by itself and a Line executed 89.93%. Line executed isn't 100% because I have if statement and 100% branch coverage means that every part of my code was hit. This doesn't really mean much other than the fact that all my code in unittest2 was used. 

~~~Coverage Test unittest3~~~

File 'dominion.c'
Lines executed:17.70% of 565
Branches executed:17.83% of 415
Taken at least once:15.18% of 415
Calls executed:7.37% of 95
Creating 'dominion.c.gcov'

In this unit test I tested the drawCard function. First I checked if the player recieved a card from the drawCard function. Then I checked if the deckCount decreased by one. After that I checked for if other player's state changed. For example, if another player gained a card in their hand or if their deck changed at all. I also checked the game state of the board such as all the supply cards to see if any were missing. The drawCard function is used a lot because a lot of the cards in dominion lets player gain more cards. I also had to access other functions to check each players hand and deck which contributed to the test coverage. It covered more than just the drawCard function itself.

~~~Coverage Test unittest4~~~

File 'dominion.c'
Lines executed:19.65% of 565
Branches executed:19.28% of 415
Taken at least once:15.90% of 415
Calls executed:7.37% of 95
Creating 'dominion.c.gcov'

In this unit test I tested the discardCard function. I first checked if player hand count decreased by 1 because that is the whole point of the card. The next basic test I did was to see if the card went into the correct pile such as discard pile or played pile depending on the flag it was passed. The other cases I checked if other player's game state change. And I also checked if the supply cards on the board has been changed as well. One way I could of improved on this test is to check if the correct card was discarded. The lines executed and branches executed is relatively higher than the shuffle function as well because discardCard is used more often and it happens every time a player ends their turn. 

~~~Coverage Test cardtest1~~~

File 'dominion.c'
Lines executed:22.65% of 565
Branches executed:25.30% of 415
Taken at least once:17.11% of 415
Calls executed:11.58% of 95
Creating 'dominion.c.gcov'

In this unit test I tested the smithy card function. The smithy card is really simple. It basically calls drawCard 3 times. I checked if the player gained 3 cards and checked if the deck decreased by 3. Other test cases were to check if any other player's game state changed. 


~~~Coverage Test cardtest2~~~

File 'dominion.c'
Lines executed:24.60% of 565
Branches executed:26.27% of 415
Taken at least once:18.31% of 415
Calls executed:15.79% of 95
Creating 'dominion.c.gcov'

In this unit test I tested council_room. This card adds 4 card to the players hand, adds 1 buy, and lets other player's draw a card. This was the first unit test where I had some fails. This was because I introduced some bugs in the previous assignment in this function. The bug is that the current player gains an extra card when this is called. I tested if the player hand count increased by 4 and if their buy count increase by 1. Then I checked if other player's hand count increased by 1. I also check to see if their deck changed and if the supply cards state changed at all. I checked what ever the card stated that it would change and if it changed any other state that it wasn't suppose to. There was a lot of testing so 26.27% for branches executed seems reasonably.

~~~Coverage Test cardtest3~~~

File 'dominion.c'
Lines executed:25.84% of 565
Branches executed:26.27% of 415
Taken at least once:18.55% of 415
Calls executed:18.95% of 95
Creating 'dominion.c.gcov'

In this unit test I tested village. The village card is pretty simple. It adds 1 card to the player's hand and adds 2 actions. I first checked if those happened after calling the card. Then I checked if it changed other player's state and the state of the supply cards. 


~~~Coverage Test cardtest4~~~

File 'dominion.c'
Lines executed:27.96% of 565
Branches executed:27.23% of 415
Taken at least once:19.76% of 415
Calls executed:25.26% of 95
Creating 'dominion.c.gcov'

In this unit test tested steward. I first check if the correct codes get executed depening on the player's choice. This card has couple effect and it depends on which effect the player wants to use. After checking if it executed the correct code I checked if it affected other player's state. 

~~~~~~~~~~~~~~~~~Overall~~~~~~~~~~~~~~~~~~~

I felt like a lot of the test cases could be used in multiple unit tests. Such as testing if the player hand and deck changed. To improve my test suite I believe I should test more specific cases. I could use more loops to test each increments for my cases.