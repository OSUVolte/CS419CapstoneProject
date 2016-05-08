/***********************************************************************
* Class:  CS 362 - Software Engineering II 
* Author:  Ellard Gerritsen
* File:  randomhistory.c
************************************************************************/



The first random tester was for the adventurer card. The test results from this card effect were not good. Though this is expected due to the fact
that I refactored this card.When I refactored the adventurer I made it so that if a silver was drawn during the
card effect it would be ignored. Some of the big issues I ran across when running the test is that the every few iterations the treasure card 
count for a players current hand would be off. For example it would be expecting a total of 37 treasure cards but instead it comes up with 42. 
This is interesting because technically I do not think my refactored code would do this. Silver cards would just be drawn and the removed because it
wouldn't consider it a "drawntreasure" like copper and gold. This might be something to look into. Another issue is that 
essentially every iteration had errors with hand count being off and deck count being off for the other players. The hand count was also off by 1 
and the deck count for the other player for some reason changed by 1. This shouldn't be happening. 


For my second random tester I chose the council room card because I wanted to use a card I used
for my earlier unit tests as a means of comparison. The council room card does a few important things that
need to be looked at in order to have better assurance its doing the job it is supposed to do.
The first thing is that 4 cards are supposed to be drawn. So factor in that the card is also discarded on use,
that means a total of 3 new cards should be in the players hand after use. According to my testing results, this was
the case. Thus that passed. Another important effect is that the other players in the game also gain 1 card. So its important
to check to make sure that the current player isn't getting this effect in addition to making sure that the other players do in 
fact get their card. According to my testing results, this also checked out. The last important effect it has is that it also 
increases the number of buys for that turn. So this needs to be tested for as well to make sure its actually happening. My testing results 
told me that indeed was. In summary, the testing results for my randomtestcard.c came back with a 100% pass. 







Now lets look at the actual test coverage of dominion and the adventurerCardEffect. The coverage for dominion.c was pretty decent and 
actually slightly above the general percentage of the earlier unit tests. However, this is only like a couple of percent more.  This is likely
due to the fact that a good portion of the game isn't being utilized because we are focusing in on certain cards. The adventurerCardEffect on 
the other hand had 100% coverage for lines and branches. The unit test also had this coverage though. Thus the leaves the question whether a random
 tester is more useful than a specific unit test. My idea is that they both have their uses. A unit test can fine tune on certain criteria you
  are looking to pass. You can then use the random tester and really ram it with quantifiable tests. 

File 'dominion.c'
Lines executed:27.91% of 559
Branches executed:28.19% of 415
Taken at least once:20.48% of 415
Calls executed:15.96% of 94
Creating 'dominion.c.gcov'

Function 'AdventurerCardEffect'
Lines executed:100.00% of 16
Branches executed:100.00% of 10
Taken at least once:100.00% of 10
Calls executed:100.00% of 2

For the randomtestcard, the council room wasn't refactored into its own function so I couldn't use the data like I did before for 
the adventurerCardEffect.  That being I looked at the individual lines of the coverage test and it looks like every line was covered in 
the test. All branches were taken on one occasion or another so that is good as well.  



File 'dominion.c'
Lines executed:24.69% of 559
Branches executed:25.78% of 415
Taken at least once:17.83% of 415
Calls executed:12.77% of 94
Creating 'dominion.c.gcov'


