/***************
Author: James Taylor
Date: 10/25/15
Updated: 4/10/16

***************/
Refactored cards:
	Adventurer
	Smithy
	Council Room
	gardens
	Great Hall
	
introduced bugs:
	Adventurer_ref: changed < to > when checking deck for enough cards
	Smithy_ref: set i to 1
	Council Room: removed statement :        discardCard(handPos, currentPlayer, state, 0);
	Gardens: return 0 instead of -1.
	