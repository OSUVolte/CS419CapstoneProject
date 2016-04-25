#tatyana vlaskin
#cs362, spring 2016
#04/10/2016
#refactor.c


simthy
    smithy card code is moved to the int card_Smithy(struct gameState *state, int handPos) function
    function card_Smithy(state,handPos) is called in the case smithy:
    all required variables are declared locally in the int card_Smithy(struct gameState *state, int handPos) function
	Bug: in for statement the loop is started at 1 instead of 0

adventurer
    adventurer card code is moved to the card_Adventure() function
    function card_Adventurer() is called in the case adventurer:
    all required variables are declared locally in the card_Adventurer() function
	Bug: if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) to the
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn != gold)

council_room
    countcil_room code is moved to the card_Council_Room(state, handPos); function
    function card_Council_Room(state, handPos); is called in the case council_room:
    all required variables are declared locally in the card_Council_Room(state, handPos) function
	Bug:        //+1 Buy      //state->numBuys++; is removed from the function



village
    village code is moved to the card_Village(state, handPos); function
    function card_Village(state, handPos); is called in the case village:
    all required variables are declared locally in the card_Village(state, handPos); function
	Bug:  state->numActions = state->numActions + 2; is replaced with  state->numActions = state->numActions + 3;


Feast
    feast code is moved to the int card_Feast(struct gameState *state, int choice1) function
    function card_Feast(state, choice1) is called in the case feast:
    all required variables are declared locally in the 	int card_Feast(struct gameState *state, int choice1) function
	Bug: no bugs were introduced



