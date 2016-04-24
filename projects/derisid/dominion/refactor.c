/*
adventurer - Line 1252 changed state->deckCount[currentPlayer] <1 to state->deckCount[currentPlayer] >1, 
this alteration in the conditions changes how an empty deck is handled.

council_room - changed != to <= in the conditional on line 1285


smithy - altered loop count from 3 to 4 at line 1298, this will yield an extra card for the player


embargo - changed conditional on line 1313 from -1 to 0

treasure_map - changed the toFlag argument to 2 in the function call on line 1347

*/