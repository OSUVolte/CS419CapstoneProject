/*
Functions:
1. scoreFor()
	Test score for all zero from hand, discard and deck
	Result = 0; Expected = 0
	Test score combining positive and negative value from hand, discard and deck
	Result = 10; Expected = 10
	Test score including positive value only from hand, discard and deck
	Result = 40; Expected = 40
	Conclusion: All tests passed, thus NO BUGS.

2. updateCoins()
	Test if no coins 
	Result = 0; Expected = 0
	Test if all coins are copper
	Result = 5; Expected = 5
	Test if the coins consist of copper, silver and gold
	Result = 10; Expected = 10
	Test if bonus exists too
	Result = 10; Expected 10
	Conclusion: All tests passed, thus NO BUGS

3. isGameOver() 
	*1 means game over, 0 means game not over
	Test if the number of province card supply is negative
	Result = 0; Expected = 1
	Test if dutchy piles empty
	Result = 0; Expected = 0
	Test if estate piles empty
	Result = 0; Expected = 0
	Test when 4 supply piles empty (duchy, estate, curse and gold)
	Result = 1; Expected = 1
	Test when 2 supply piles empty, 1 of othem is province supply
	Result = 1; Expected = 1
	Conclusion: Test when number of province supply is negative NOT PASSED, thus THERE IS A BUG.
	Observation: Dominion need condition "state -> supplyCount[province] <= 0" not just "state -> supplyCount[province] == 0"
				 to prevent negative number of card.

4. fullDeckCount()
	*Specific card for this test: Adventurer
	Test when no adventurer card at deck, discard and hand
	Result = 0; Expected = 0
	Test when no adventurer card at deck and discard, but 1 at hand
	Result = 1; Expected = 1
	Test when no adventurer card at deck and discard, but 1 at player 1 hand & 1 at player 2 hand
	Result = 1; Expected = 1
	Test 1 adventurer at deck, discard and hand
	Result = 3; Expected = 3
	Conclusion: All tests passed, thus NO BUGS

Cards:
1. Smithy
	Test to see current player's hand card after smithy
	Result = 9; Expected = 7
	Test to see current player's deck size after smithy
	Result = 0; Expected = 2
	Test to see other player's hand card and deck size
	Result (deck) = 5; Expected = 5
	Result (hand) = 5; Expected = 5
	Test to see no change in victory piles
	Result = NO CHANGE
	Test to see no change in kingdom piles
	Result = NO CHANGE
	Conclusion: Test to see current player's hand card & deck after smithy NOT PASSED, thus THERE ARE BUGS.
	Observation: 1) Smithy increases player's hand card by 4 in this test AND Smithy doesn't discard itself after calling.
				 2) Smithy decreases player's deck card by 5 in this test.

2. Adventurer
	Test to see current player's hand card after adventurer call (2 treasure card at top, means there shouldn't be any discard)
	Result = -121; Expected = 6
	Test to see current player's hand card after adventurer call (2 treasure card below 1 card from top of deck, means 1 discard expected)
	Result (hand) = -121; Expected = 6
	Result (discard) = 131; Expected = 1
	Test to see other player's hand card and deck size
	Result (deck) = 5; Expected = 5
	Result (hand) = 5; Expected = 5
	Test to see no change in victory piles
	Result = NO CHANGE
	Test to see no change in kingdom piles
	Result = NO CHANGE
	Conclusion: Test to see current player's hand card after adventurer (for both conditions) NOT PASSED, thus THERE ARE BUGS.
	Observation: The Result value and Expected value shows a really wide difference. This indicates that some of the function
				 calls in "void adventurerCard(struct gameState *state){" doesn't work. Furthermore, there is a possibility in
				 logic error in calculating the treasure card & discard card.

3. Village
	Test to see current player's hand card after village 
	Result = 5; Expected = 5
	Test to see current player's action after village
	Result = 5; Expected = 3
	Test to see other player's hand card and deck size
	Result (deck) = 5; Expected = 5
	Result (hand) = 5; Expected = 5
	Test to see no change in victory piles
	Result = NO CHANGE
	Test to see no change in kingdom piles
	Result = NO CHANGE
	Conclusion: Test to see current player's action after village call NOT PASSED, thus THERE IS A BUG.
	Observation: In villageCard() function, "state-> numActions" is added with "4" instead of "2". Thus
				 player's action after calling village card becomes 5 instead of 3.

4. Council Room
	Test to see current player's hand card after council room 
	Result = 6; Expected = 8
	Test to see current player's buy after council room
	Result = 3; Expected = 2
	Test to see other player's hand card and deck size
	Result (deck) = 4; Expected = 4
	Result (hand) = 6; Expected = 6
	Test to see no change in victory piles
	Result = NO CHANGE
	Test to see no change in kingdom piles
	Result = NO CHANGE
	Conclusion: Test to see current player's hand and buy after council room call NOT PASSED, thus THERE ARE BUGS.
	Observation: In councilRoomCard() function, "state-> numBuys" is added with "2" instead of "1". Thus
				 player's action after calling council room card becomes 5 instead of 3.
				 The for loop tells to call drawCard 2 times instead of 4 times. Thus player's hand card after
				 calling council room card becomes 6 instead of 8.

*/