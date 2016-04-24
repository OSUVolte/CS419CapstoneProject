Simthy:
	Under the case for smithy in the switch statment, UseSmithy() is called.
	UseSmithy uses the same code from the original case statment with i and 
	currentPlayer declared to make it complie. The bug I added in was instead
	of '<3' in the for statement I changed it to '<=3' so four cards are drawn as opposed to 3.
	Before: "for (i = 0; i < 3; i++)"
	After: "for (i = 0; i <= 3; i++)"
	

Adventurer:
	Under the case for Adventurer in the switch statment, UseAdventurer() is called.
	UseAdventurer uses the same code from the original case statment with the required
	variables defined locally in the function so it can complie. The bug I added was 
	removing the return after the function was executed so that it would roll into council_room
	and execute that card as well.

Council Room:
	Under the case for council_room in the switch statment, UseCouncilRoom() is called.
	UseCouncilRoom uses the same code from the original case statment with i and 
	currentPlayer declared to make it complie. The bug I added in was instead
	of using '!=' in the if statement check for the treasure cards I changed it to '==' so
	instead of all other players drawing a card, only the active player draws a card. 
	
	Before: "if ( i != currentPlayer )"
	After: "if ( i == currentPlayer )"
	
Village:
	Under the case for village in the switch statment, UseVillage() is called.
	UseVillage uses the same code from the original case statment with currentPlayer declared
	locally to make it complie. I did not introduce any bugs with village.
	
Remodel:
	Under the case for remodel in the switch statment, UseRemodel() is called.
	UseRemodel uses the same code from the original case statment with the required
	variables defined locally in the function so it can complie. The bug I added switched
	the '>' in the if statement to '<' meaning that it will only accept cards that are greater
	than 2 coins more expensive than then less than.
	
	Before: "if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )"
	After: "if ( (getCost(state->hand[currentPlayer][choice1]) + 2) < getCost(choice2) )"
	