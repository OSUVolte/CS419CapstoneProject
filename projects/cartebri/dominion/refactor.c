Brianna Carter
refactor.c: explains changes to 5 cards in dominion.c
4/10/16

Smithy: Code will only draw cards if the next player number is greater than the number of players. 
	There is a conditional before the for loop.

Adventurer: Reveal whole deck no matter how many treasure cards are revealed. The while loop was alterd to 
	continue while the current players hand is > 0. Every card is added to the temp hand, including treasure cards.

Feast: Player can gain multiple cards totaling 5 coins instead of just one card up to 5 coins.
	The conditional x should be initialized to 1 instead of 5, the while loop on should be x==1  and when a 
	card is purchased x should be updated to 0 instead of subtracting the cost.

Village: No change

Council Room: Instead of each player drawing a card, the current player draws as many cards as there are
	players. The if statement in the for loom should be != current player.