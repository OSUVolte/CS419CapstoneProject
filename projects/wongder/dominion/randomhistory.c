//Derek Wong
//CS362

~~~randomtestcard~~~

File 'randomtestcard.c'
Lines executed:90.00% of 80
Branches executed:100.00% of 18
Taken at least once:77.78% of 18
Calls executed:91.84% of 49
Creating 'randomtestcard.c.gcov'

File 'dominion.c'
Lines executed:27.79% of 565
Branches executed:27.71% of 415
Taken at least once:20.72% of 415
Calls executed:15.79% of 95
Creating 'dominion.c.gcov'

In randomtestcard.c I tested the smithy card. I ran this test a total of 10 times. I could of done more like 100 or 1000
for more accuracy but I felt like 10 is enough for this assignment. I have 90% lines executed for just the 
randomtestcard which is really good and the reason why it isn't 100% is because of some if statments. The 100%
branches executed shows that it ran through all my code. When I tested randomtestcard.c against dominion.c I got
27.79% lines excuted which is reasonable. I only use the functions that was require in the smithyCard function when
it was tested against dominion.c so not everything was used. I tested the handCount, deckCount, playedCardCount, and
returnValue in my random testing. Everything always passed except for the playedCardCount. The reason of this is because
I introduced a bug in this function in the previous assignments so when smithy is played it doesn't go into the played
card pile. Some improvements I can make to this test is to test for more things such as other players game state. I 
could also check if the number of Action and number of Buy was changed when the smithy card was used.

~~~randomtestadventurer~~~

File 'randomtestcard.c'
Lines executed:90.00% of 80
Branches executed:100.00% of 18
Taken at least once:77.78% of 18
Calls executed:91.84% of 49
Creating 'randomtestcard.c.gcov'

File 'dominion.c'
Lines executed:27.79% of 565
Branches executed:27.71% of 415
Taken at least once:20.72% of 415
Calls executed:15.79% of 95
Creating 'dominion.c.gcov'

In randomtestadventurer.c I tested the adventurer card. I ran this test a total of 10 times as well. The lines
excuted is 90% and branches executed is 100% when tested against itself. This tell me that most of my code ran.
When I tested randomtestadventurer.c against dominion.c the lines executed is 27.79% and branches executed is 27.71%.
This is really similar to randomtestcard because I used the same code structure. The layout of my testing code is about the same. I set up my deck, hand, and discard pile randomly in both cases and called the cardEffect and passed in the 
card I wanted to test. But for the adventurer card I checked for more variables. In addition to handCount, deckCount,
and playedCardCount, I also checked for discardCard and treasureCount. The reason for this is because the adventurer 
card effect affects them. When I checked for treasure count most of the times it passed but there are some random cases where it didn't. I'm assuming there is a bug in there somewhere and some random case triggers it. And because of that
it affects the other tests as well. My deckCount fails when treasureCount fails. Overall, I think I tested this card
thoroughly. Some improvements I can make on this test is by increasing the number of test trials and checking for other
players game state besides the current player.