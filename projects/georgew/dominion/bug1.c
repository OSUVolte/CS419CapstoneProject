Bugs Found In Unit Tests
(Assuming Unit Tests Are Correct)
gainCard()
	Discard Function not working correctly when toFlag == 1
shuffle()
	Shuffle function only giving values for 1 and 4 for the cards (perhaps need to change it so it outputs card names?)
	Also shuffle tester doubles the number of cards for the second user even though the memory settings were reset
updateCoins()
	Memory issues with the coins (could not be addressed)
discardCard()
	function worked perfectly
smithy()
	count decreased incorrectly (introduce bug)
	Hand count never came correct (possible due to introduced bug)
	Discount Card Deck never changed, cards should have been added to discard Deck
adventurer()
	Treasure cards not measured (presumably the same error as in the gain cards function)
village()
	Hand Count once again did not correct
greatHall()
	deck count decreased but hand count once again did not change correctly
	
