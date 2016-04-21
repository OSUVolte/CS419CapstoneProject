Assignment 3 - Joseph Cuellar

COVERAGE:

BASIC STATS:
File 'dominion.c'
Lines executed:23.26% of 559
Branches executed:18.23% of 417
Taken at least once:16.07% of 417
Calls executed:12.77% of 94

INDIVIDUAL UNIT TEST STATS:
discardCard()			-	function discardCard called 6490 returned 100% blocks executed 89%
shuffle()				-	function shuffle called 417 returned 100% blocks executed 94%
isGameOver()			-	function isGameOver called 5 returned 100% blocks executed 100%
buyCard()				-	function buyCard called 202 returned 100% blocks executed 100%
callSmithyCard()		-	function callSmithyCard called 500 returned 100% blocks executed 100%
callAdventurerCard()	-	function callAdventurerCard called 0 returned 0% blocks executed 0%
callVillageCard()		-	function callVillageCard called 500 returned 100% blocks executed 100%
callEmbargoCard()		-	function callEmbargoCard called 5400 returned 100% blocks executed 80%

REVIEW:
It was very surprising to me how little of the program actually gets executed. Additionally, it is clear to me now how 
useful of a tool gcov really is. I would have expected it to be easier for a human to go through the code, but writing the
tests just saved so much time and probably uncovered data that a human wouldn't catch.

In the results above, the line calls were happening quite a bit, while the branches were pretty low.
I was expecting more branch coverage. I think part of this could be the bugs that were put in for Assignment 2. 
If conditions aren’t being met that lead to other areas of the program, branch coverage could be misleading. 
As for the individual unit tests, isGameOver(), buyCard(), callSmithyCard(), and callVillageCard() all had 100% branch coverage, 
while all the others did not. This shows me that there are likely other areas of application that I need to learn more about. 
If my tests are not hitting all of the possible branches areas the application can go for individual functions, this means 
there are other areas of the ENTIRE application that might not be getting called which need to be. This could help explain the lower
branch coverage in dominion.c. I was suprised that it showed callAdventurerCard as being called zero times, because it was clearly
called in my unit tests. I believe this has to do with the bug I introduced into the dominion.c file.

