Dane Schoonover
CS362_400
Assignment 2, part 3

Cards: adventurer, council_room, feast, mine, smithy


adventurer:
	Change -> Added adventurerCard() function (line 12), and refactored cardEffect() switch case adventurer to call adventurerCard().

	Bug -> I changed the drawntreasure conditional in the while statement to be less than <2 rather than 1, which would allow an additional treasure card to be drawn. BLING BLING!
			    while(drawntreasure<2) -->     while(drawntreasure<3){


council_room
	Change -> Added councilRoomCard() function (line 36), and refactored cardEffect() switch case council_room to call councilRoomCard().

	Bug -> I changed the number of buys added by this card to 5, so the player will now have 5 additional buys rather than 1.
			    state->numBuys+=1 --> state->numBuys+=5

feast:
	Change -> Added feastCard() function (line 62), and refactored cardEffect() switch case feast to call feastCard().
	
	Bug -> No bugs added to this card.


mine:
	Change -> Added mineCard() function (line 116), and refactored cardEffect() switch case mine to call mineCard().

	Bug -> I changed the toFlag of the gainCard() function to 0, so that the card will not be added to the handcount.

	    gainCard(choice2, state, 2, currentPlayer); -->  gainCard(choice2, state, 0, currentPlayer);

smithy:
	Change -> Added smithyCard() function (line 157), and refactored cardEffect() switch case smithy to call smithyCard().
	Bug ->	I allowed for an additional card to be drawn by playing the smithy card:
		    for (i = 0; i < 3; i++) -->  for (i = 0; i < 4; i++)


