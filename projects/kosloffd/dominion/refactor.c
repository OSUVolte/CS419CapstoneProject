Updated code to replace the switch() statements for smithy, adventurer, , ,  to use the following functions:
playSmithy()
playAdventurer()
playMinion()
playSteward()
playCutpurse()

In playAdventurer() a bug was introduced to the code so that the player draws until three treasure cards are found instead of two.
In playSmithy() a bug was introduced so that at the end of the player's turn, instead of discarding the Smithy card, the card in the same position as the FIRST player's hand (which may or may not be the one who played Smithy) is trashed (not just discarded).
In playMinion() these bugs were introduced:
		-If option one is chosen, the player loses two coins (instead of gaining two)
		-If option two is chosen: 
			+ The player only discards down to one card (instead of her entire hand) before drawing four more cards
			+ The conditional is removed which ensured only the other players in the game discarded and drew 4 cards, so the player who plays the card now discards his hand with everyone else and draws four new cards for a hand (since he held one due to the previous bug and then drew 4, so his five cards will be over the 4-card threshold).
In playCutpurse() A bug was introced by removing the break after discardCard for each copper.  This way all of a player's copper will be discarded from their hand.  Also, the if(j == handCount) statement was replaced by a if(j<=handCount) so that after discarding all the copper in that person's hand, they will reveal their hand (if the DEBUG flag is set).