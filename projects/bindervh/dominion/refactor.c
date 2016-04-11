simthy
	call to playsmithy() added to switch statement in cardEffect()
	code for drawing three cards moved to playsmithy() function
	i, current player declared in playsmithy()
	Bug: in for statement < changed to <= so four cards instead of three are drawn

adventurer
	call to playAdventurer() added to switch statement in cardEffect()
	code for adventurer moved to playAdventurer function
	variables required by adventurer declared locally in function
	Bug: in if statement checking if card drawn is a treasure card, == was changed to = so all cards will be read as copper

Great_Hall
	call to PlayGreat_Hall() added to switch statement
	Code moved to new PlayGreat_Hall function
	Bug: No bug introduced

Feast
	call to playFeast() in switch statement
	code for Feast added to new playFeast function
	Bug: in statement checking if card chosen is too expensive [else if (state->coins > getCost(choice1))], > is changed to <

Remodel
	call to playRemodel() in swith statement
	code for remodel card moved to new function
	Bug: do not call return 0; after calling playRemodel() in switch statement in cardEffect().  
	This causes the next case to occur, as if a smithy card were also played.