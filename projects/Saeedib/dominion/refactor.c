/*************************************************
**		  Behnam Saeedi			**
**		     Saeedib			**
**		   932-217-697			**
**	  	   refactor.c			**
**	         cards selected:		**
**		   -Smithy			**
**		   -Adventurer			**
**		   -Feast			**
**		   -Village			**
**		   -minion			**
*************************************************/
/*		   DESCRIBTION:			*/
// switch cases are replaced with Functions in cardEffect
// The arguments are passed and tested
// The program seems to be compiling
// There are bugs in the code

// Bug types are:
// - Wrong numbers pass (These bugs are commented with tripple star: //***)
// - Wrong pointer and variable handling (these bugs are where we need to pass by refrence)

// Each function has atleast 1 bug
// The functions are listed bellow (pay attention *** for bugs):

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int Smithy(int currentPlayer, int handPos, struct gameState * state)
{
	// + 3 cards
	for(int i = 0; i < 2; i++) // *** +2 cards
	{
		drawCard(currentPlayer, state);
	}
	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	// return value is the value of getCost
	return 4;
}

int Adventurer(int currentPlayer, int handPos, struct gameState * state,int * temphand)
{
	int drawntreasure = 0;
	int cardDrawn;
	int z =0;
	while(drawntreasure < 2)
	{
		if (state->deckCount[currentPlayer] <1)
		{
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
		{
			drawntreasure++;
		}else{
			temphand[z]=cardDrawn;
			state->handCount[currentPlayer]--;
			z++;
		}
	}
	while(z>=0) // *** z-1
	{
		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
		z=z-1;
	}
	//return value is the value of getCost()
	return 6;
}

int Feast(int currentPlayer, int handPos, struct gameState * state, int * temphand, int choice1)
{
	int x;
	//Backup hand
	for (int i = 1; i <= state->handCount[currentPlayer]; i++)//*** lost first card
	{
		temphand[i] = state->hand[currentPlayer][i];//Backup card
		state->hand[currentPlayer][i] = -1;//Set to nothing
	}
	//Backup hand
	//Update Coins for Buy
	updateCoins(currentPlayer, state, 5);
	x = 1;//Condition to loop on
	while( x == 1)
	{
		if (state->coins < getCost(choice1))
		{
			printf("That card is too expensive!\n");
		}
		else
		{
			gainCard(choice1, state, 0, currentPlayer);//Gain the card
			x = 0;//No more buying cards
		}
	}
	//Reset Hand
	for (int i = 0; i <= state->handCount[currentPlayer]; i++)
	{
		state->hand[currentPlayer][i] = temphand[i];
		temphand[i] = 0; //*** wrong value! -1
	}
	//Reset Hand
	return 4;
}

int Village(int currentPlayer, int handPos, struct gameState * state)
{
	//+1 Card
	drawCard(currentPlayer, state);
	//+2 Actions
	state->numActions = state->numActions + 1; //*** action won't increase by  2
	//discard played card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 3;
}

int Minion(int currentPlayer, int handPos, struct gameState * state, int choice1, int choice2)
{
	//+1 action
	state->numActions++;
	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	if (choice1)		//+2 coins
	{
		state->coins = state->coins; //*** no coins added
	}
	else
	if (choice2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
	{
		//discard hand
		while(numHandCards(state) > 0)
		{
			discardCard(handPos, currentPlayer, state, 0);
		}
		//draw 4
		for (int i = 0; i < 4; i++)
		{
			drawCard(currentPlayer, state);
		}
		//other players discard hand and redraw if hand size > 4
		for (int i = 0; i < state->numPlayers; i++)
		{
			if (i != currentPlayer)
			{
				if ( state->handCount[i] > 4 )
				{
					//discard hand
					while( state->handCount[i] > 0 )
					{
						discardCard(handPos, i, state, 0);
					}
					//draw 4
					for (int j = 0; j < 4; j++)
					{
						drawCard(i, state);
					}
				}
			}
		}
	}
	return 5;
}
