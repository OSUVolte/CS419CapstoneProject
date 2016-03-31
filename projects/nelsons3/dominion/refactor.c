/********************************************************
*														*
* Author: Sam Nelson									*
* Class: CS 362											*
* Assignment: Assignment 2 								*
* Date: 4/1/2016										*
* Description: refactor smithy, adventurer, baron,		*
* and feast and village									*
*														*
*********************************************************

Village card refactor:
Card left stock...aka no errors introduced (or not knowingly anyways)
    case village:
    //+1 Card
    drawCard(currentPlayer, state);
			
    //+2 Actions
    state->numActions = state->numActions + 2;
			
    //discard played card from hand
    discardCard(handPos, currentPlayer, state, 0);

Baron card:
The code has been changed so as to reward a province instead of 
an estate.  This results in a score change of +6 instead of +1
	
	case baron:
    state->numBuys++;//Increase buys by 1!
    if (choice1 > 0)
	{//Boolean true or going to discard an estate
		int p = 0;//Iterator for hand!
		int card_not_discarded = 1;//Flag for discard set!
		while(card_not_discarded)
		{
			if (state->hand[currentPlayer][p] == estate)
			{//Found an estate card!
				state->coins += 4;//Add 4 coins to the amount of coins
				state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
				state->discardCount[currentPlayer]++;
				for (;p < state->handCount[currentPlayer]; p++)
				{
					state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
				}
				state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
				state->handCount[currentPlayer]--;
				card_not_discarded = 0;//Exit the loop
			}
			else if (p > state->handCount[currentPlayer])
			{
				if(DEBUG) 
				{
					printf("No estate cards in your hand, invalid choice\n");
					printf("Must gain an estate if there are any\n");
				}
				if (supplyCount(estate, state) > 0)
				{
					gainCard(estate, state, 0, currentPlayer);
					state->supplyCount[estate]--;//Decrement estates
					if (supplyCount(estate, state) == 0)
					{
						isGameOver(state);
					}
				}
				card_not_discarded = 0;//Exit the loop
			}
			else{
				p++;//Next card
			}
		}
    }
	else{
		if(supplyCount(province, state) > 0)
		{
			gainCard(province, state, 0, currentPlayer);
			state->supplyCount[province]--;
		}
	}
	return 0;

smithy card:
In the loop I changed the for loop to be i=1 instead of i=0...this results in 1 less card
being awarded....good luck!

    case smithy:
    //+3 Cards
    for (i = 1; i < 3; i++)
	{
		drawCard(currentPlayer, state);
	}		
    //discard card from hand
    discardCard(handPos, currentPlayer, state, 0);
return 0;
	
adventurer card:
modified the loop so now the user actually gets 3 treasures
case adventurer:
    while(drawntreasure<=2){
		if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else{
			temphand[z]=cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while(z-1>=0){
		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
		z=z-1;
    }
return 0;

feast:
changed number of cards the user could buy with the 5 coins.
while( x == 1) was changed to while( x >= 0)
and on line 99 x=0 was changed to x--;// CHANGE MADE HERE No more buying cards

    case feast:
    //gain card with cost up to 5
    //Backup hand
    for (i = 0; i <= state->handCount[currentPlayer]; i++)
	{
		temphand[i] = state->hand[currentPlayer][i];//Backup card
		state->hand[currentPlayer][i] = -1;//Set to nothing
    }
    //Backup hand

    //Update Coins for Buy
    updateCoins(currentPlayer, state, 5);
    x = 2;//Condition to loop on
    while( x >= 0) 
	{//Buy one card
		if (supplyCount(choice1, state) <= 0)
		{
			if (DEBUG)
				printf("None of that card left, sorry!\n");

			if (DEBUG)
			{
				printf("Cards Left: %d\n", supplyCount(choice1, state));
			}
		}
		else if (state->coins < getCost(choice1)){
			printf("That card is too expensive!\n");

			if (DEBUG)
			{
				printf("Coins: %d < %d\n", state->coins, getCost(choice1));
			}
		}
		else{

			if (DEBUG)
			{
				printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
			}

			gainCard(choice1, state, 0, currentPlayer);//Gain the card
			x--;// CHANGE MADE HERE No more buying cards

			if (DEBUG)
			{
				printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
			}
		}
    }     

    //Reset Hand
    for (i = 0; i <= state->handCount[currentPlayer]; i++)
	{
		state->hand[currentPlayer][i] = temphand[i];
		temphand[i] = -1;
    }
    //Reset Hand
return 0;