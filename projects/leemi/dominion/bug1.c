//=============================BUGS===========================
//==========card Tests==============
//In testCardCouncil

increases hand by 3 not three the player gets to draw 4 cards, but
	it should discard one so the resulting hand = + 3

//in testCardAdventurer

adventurer grabs three coin cards instead of two coin cards also card
	adventurer is not discarded from the hand shuffle works as expected

//in testCardSmithy

smithy adds 4 cards and discards the smithy card should only add 3 cards

//in testCardOutpost

no bugs found in outpost

//===========unit Tests=============
//in updateCoins

no bugs found in updateCoins

//in discardCard

can discard cards that doesnt exist resulting in handCount becoming negative

//in gainCard

no bugs found

//in isGameOver
possible bug: game will not be over if the supply counts become negative




	
