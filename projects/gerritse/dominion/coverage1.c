/*******************************
Ellard Gerritsen van der Hoop
CS362- Assignment 3

coverage1.c
******************************/

Quick Note:
Based on the nature of these unit tests and the fact we were only 
essentially covering specific scenarios(in this case certain card effects
and game play functions), code coverage was not really expected to be great.
In fact a large portion of dominion.c was not even tested. Go to bottom of this 
file to see potential solution


---------------Unit Test 1-------------------
Lines executed:19.50% of 559
Branches executed:16.87% of 415
Taken at least once:13.73% of 415
Calls executed:10.64% of 94

Decent coverage for the function. Lines and branches
executed had similar percentages. 

---------------Unit Test 2-------------------
Lines executed:15.92% of 559
Branches executed:15.42% of 415
Taken at least once:12.77% of 415
Calls executed:7.45% of 94

Decent coverage for the function. Lines and branches
executed had similar percentages. This test's boundary could be improved
by potentially allowing for bigger hands or testing what happens
when there are no treasure cards.
---------------Unit Test 3-------------------
Lines executed:5.19% of 559
Branches executed:6.75% of 415
Taken at least once:6.51% of 415
Calls executed:0.00% of 94

This unit test had particularly low coverage due
to the fact that the function in question only
returns the cost of a card and does not really interact
with the gameState or players decks. I will need to find a 
way to improve this test in some way in the future.

---------------Unit Test 4-------------------
Lines executed:18.78% of 559
Branches executed:17.83% of 415
Taken at least once:14.70% of 415
Calls executed:8.51% of 94

Coverage seems okay for the scale of the test. This test's boundary coverage was
okay but could be improved by testing what happens when supplyCount
of a card reaches 0.

---------------Card Test 1-------------------
Lines executed:21.47% of 559
Branches executed:23.37% of 415
Taken at least once:14.70% of 415
Calls executed:13.83% of 94

This was the Smithy card test. Decent coverage of branch and lines. The gameState was 
checked for both players to see what happens after smithy. Test could be improved by
maybe allowing the second player to use a smithy card as well. Could also test what 
happens to hand and deck when a smithy card effect happens without a smithy card actually
being in the hand. Would it remove an incorrect card, etc...

---------------Card Test 2-------------------
Lines executed:24.87% of 559
Branches executed:27.23% of 415
Taken at least once:17.83% of 415
Calls executed:14.89% of 94

This was the Adventurer card test. Coverage on par with smithy's. Slighly higher branch
coverage. This test was able to cover the drawCard function, shuffle function, and whoseTurn. 
Test could be improved by checking what happens supplyCounts are low of treasure cards.

---------------Card Test 3-------------------
Lines executed:22.18% of 559
Branches executed:24.82% of 415
Taken at least once:16.63% of 415
Calls executed:11.70% of 94
 
This was the Council Room test. Coverage was decent. This test was able to look at 
discardCard function as well since its called within the Council room effect. Test could be 
improved by seeing if number of Buys actually carries over correctly. 


---------------Card Test 4-------------------
Lines executed:21.29% of 559
Branches executed:24.82% of 415
Taken at least once:15.66% of 415
Calls executed:11.70% of 94

Cutpurse card test. This test looked at the effect along with updateCoins, discardCard functions that used
within the cutpurse card effect. Decent coverage but boundary testing could be improved by looking at what 
happens when the other players do not have any copper treasure cards. Or trying the same thing with more players than
just 2-3. 


The coverage could definitely be improved for next time if I want to increase the scale 
of these unit tests. My idea would be to essentially put together 
a unit test that not only tests for a certain specific component but then actually 
runs through an entire length of a normal Dominion game. This likely still wouldn't 
encompass all the code possible but it would likely give better coverage than what it is now.
 