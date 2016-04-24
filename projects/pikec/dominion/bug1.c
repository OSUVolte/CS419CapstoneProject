/********************************
** filename: bug1.c
** author: Candis Pike
** date: April 22, 2016
** description: bug analysis
***********************************/
prioritiy
high: effects game play to give a player an unfair advantage 
medium: efects game play. no obvious advantage
low: may effect game play. low occurance

****unittest1.c*******
No bugs found.

****unittest2.c*******
No bugs found.

****unittest3.c*******
No bugs found.

****unittest4.c*******
No bugs found.

****cardtest1.c*******
Test of smith card
Bugs found: 1

Bug 1SM:	
priority: high
description:
	The test to confim that the current player recieved 3 new cards from his/her deck failed.
	With no other bugs this implies that the player is recieving the improper number of cards.
	Disclaimer: This bug was introduced in assignment 2.

****cardtest2.c*******
Test of adventurer card
Bugs found: 2

Bug 1AD: 
priority: high
description:
	The player does has more cards in his/her hand then allowed. Taken into account that the adventurer card is discarded after play. The hand count 
	is showing 3 cards more in the hand based on the count before calling the function vs. after the call. This could be caused by a variety of factors
	1.) more cards are being drawn. 2.) adventurer card not properly discarded. Disclaimer: This bug was introduced in assignment 2.
	
Bug 2AD:
priority: high
description:
	Adventurer card is not showing as being discarded. This could be becuase it was discarded to the wrong stack or still remains in the playes hand.
	Disclaimer: This bug was introduced in assignment 2.

****cardtest3.c*******
Test of village card
Bugs found: 2

Bug 1VI:
priority: high
description: 
	Player is only receiving 1 additional action. This could be caused by the number of actions incorrectly being incremented.
	Disclaimer: This bug was introduced in assignment 2.

Bug 2VI:
priority: high
description:
	Village card is not discarded to the proper deck. Village should be discarded to the played card deck unitl the end of the round where it should be added
	to the discard pile. Disclaimer: This bug was introduced in assignment 2.
	
****cardtest4.c*******
Test of cutpurse card
Bugs found: 8

Bug 1CP:
priorty: high
description:
	Current player is not reeiving a bonus of 2 coins. Coin count remains the same. 
	Disclaimer: This bug is not real. Player is receiving the bonus it is a residual result of another bug introduced in Assignment 2.

Bug 2CP:
priority: high
description:
		Current player hand count is less then it should be. Disclaimer: This bug was introduced in assignment 2.
		
Bug 3CP,4CP, 5CP:
priority: high	
description: 
		Player 2 still has copper cards remaining in his/her hand. Disclaimer: This bug was introduced in assignment 2.
		
Bug 6CP:
priority: high
description: 
	No coppper card is discarded into played pile. Disclaimer: This bug was introduced in assignment 2.

Bug 7CP:
priority: high
description:
	Other player coin count does not show a decrease in coin count due to the removal of copper coin cards. Disclaimer: This bug was introduced in assignment 2.		
		
Bug 8CP:
priority: high
description:
	Cutpurse is not in the played card pile. Disclaimer: this is an residual bug caused by the bug introduced in assignment 2. With the 
	current players hand being impacted with coin card removal cutpurse position is shuffled to another hand postion.
	
