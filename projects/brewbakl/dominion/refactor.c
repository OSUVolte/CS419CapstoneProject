Adding bugs to dominion.c

Smith card:
	Finds 6 instead of 3 cards.

Adventurer card:
	Only finds gold and silver treasures and not copper.

Council Room:
	Gives +2 and not +4 cards.
	Skips some users.

Treasure Map:
	Gain 1 gold goin, instead of 4.
	Does not trash treasure cards gained.
	Removes at  line 1205: 
		  //trash both treasure cards
		  discardCard(handPos, currentPlayer, state, 1);
		  discardCard(index, currentPlayer, state, 1);
		  
Village:
	No changes.