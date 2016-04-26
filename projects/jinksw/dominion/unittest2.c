/* -----------------------------------------------------------------------
		Unit Testing for gainCard() function in dominion.c
		**Used testUpdateCoins.c template for reference

		--gainCard()--
		Description: For a player, sets coins for player for that turn to equal
			the sum of the value of treasure cards in the player's hand plus bonus.

		Input:	int supplyPos - the chosen/enumerated card
						struct gameState *state - pointer to gameState var
						int toFlag - where to put the card
						int player - which player gets the card

		Return: 0 on success
		
		Algorithm PseudoCode
			1. Checks to see if card is not used in game, or if card pile is empty
			2. Checks toFlag and sends card to appropriate place
				a. 0 -> discard pile
				b. 1 -> deck
				c. 2 -> hand	
	

 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <assert.h>
#include <stdlib.h>

#define stringify( s ) #s

int main() {

		//Initialize Game
		int i;
    int seed = 777;
		int players = 2;
		int player = 0;
    int bonus = 0;
    int k[10] = {smithy, village, council_room, adventurer, feast
               , gardens, mine, remodel, baron, great_hall};
    struct gameState G, Gtest;
		initalizeGame( players, k, seed, &G );
		
		G.coins = 0;
		int handCount = 5;
		int failFlag = 0;
		int successCount = 0;
		int failCount = 0;
		int retValue;
		int discard = 0;
		int deck = 1;
		int hand = 2;
		int cardDest;
		Card currentCard;

    printf ("TESTING updateCoins():\n");
		
		//_____________________________
		//Test 1: If supply pile is Empty, Return -1, no state changes
		printf ("***TEST 1: All Cards, If Supply Pile is Empty or Card Isn't Used: Return -1. Supply, deck, hand, and discard count don't change***\n");
		memcpy( &Gtest, &G, sizeof(struct gameState));
		
		//Loop over all cards. supply is set to zero for all. 
		for( i=0; i< treasure_map+1; i++ ){
			currentCard = (CARD) i;
			Gtest.supplyCount[currentCard] = 0;
		
		
		//All cards should return -1 because supply is 0, or they aren't used in the game
		retValue = gainCard( currentCard; Gtest, 0, player ); //toFlag shouldn't matter because we should return -1 and exit
		
		printf( "%s Return value = %d, expected = -1\n", stringify( currentCard  ), retValue );
		if( !(retValue == -1 ) ){
			printf( "TEST 1 Failed: -1 not returned\n" );
			failFlag = 1;
		} 
		if ( !(Gtest.supplyCount[i] == 0 ) ){
			printf( "TEST 1 Failed: %s supplyCount = %d, expected = %d\n", stringify( currentCard ), Gtest.supplyCount[i], 0 );
			failFlag = 1;
		} 
		if ( !(Gtest.deckCount[player] == G.deckCount[player] ) ){
			printf( "TEST 1 Failed: %s deckCount = %d, expected = %d\n",stringify( currentCard ), Gtest.deckCount[player], G.deckCount[player] );
			failFlag = 1;
		} 
		if ( !(Gtest.handCount[player] == G.handCount[player] ) ){
			printf( "TEST 1 Failed: %s handCount = %d, expected = %d\n", stringify( currentCard ), Gtest.handCount[player], G.handCount[player] );
			failFlag = 1;
		} 
		if ( !(Gtest.discardCount[player] == G.discardCount[player] ) ){
			printf( "TEST 1 Failed: %s discardCount = %d, expected = %d\n", stringify( currentCard ), Gtest.discardCount[player], G.discardCount[player] );
			failFlag = 1;
		} 
		if( failFlag == 0 ){
			printf( "TEST 1 Passed: %s Returned -1, supply, deck, hand, and discard didn't change\n", stringify( currentCard ));
			successCount++;
		} else if( failFlag == 1 ){
			failCount++;
		}	
		}
		
		//_____________________________
		//Test 2: All Cards. Card is Sent to Discard, Deck, or Hand
		failFlag = 0;
		printf( "***TEST 2: All Cards. Card is Sent to Discard, Deck, or Hand. Only the place it is sent should increment. Supply Count Should Decrement. Card should be in appropriate place.***\n *** Destinations: Discard = 0, Deck = 1, Hand = 2***/n" );
		memcpy( &Gtest, &G, sizeof(struct gameState));
		
		//Loop over all cards. supply is set to 2 for all. 
		for( i=0; i< treasure_map+1; i++ ){
			currentCard = (CARD) i;
			Gtest.supplyCount[currentCard] = 2;
		
			for( cardDest = 0; cardDest< 3; cardDest++ ){
				//All cards should return 1 because supply is 2, so they are used in the game
				retValue = gainCard( currentCard; Gtest, cardDest, player ); 
		
				printf( "%s Dest: %d Return value = %d, expected = 0\n", stringify( currentCard  ), cardDest, retValue );
				if( !(retValue == 0 ) ){
					printf( "TEST 2 Failed: 0 not returned\n" );
					failFlag = 1;
				} 
				if ( !( Gtest.supplyCount[i] == ( Gtest.supplyCount[i]-1 ))){
					printf( "TEST 2 Failed: %s supplyCount = %d, expected = %d\n", stringify( currentCard ), Gtest.supplyCount[i], Gtest.supplyCount[i]-1 );
					failFlag = 1;
				} 
				//Discard Location. Count Should Increment By 1. Hand and Deck should not change
				if ( cardDest == 0){
					
					//Testing Location Count 0 increments and 1 & 2 don't 
					if ( !(Gtest.discardCount[player] == G.discardCount[player]++ ) ){
						printf( "TEST 2 Failed: %s discardCount = %d, expected = %d\n", stringify( currentCard ), Gtest.discardCount[player], G.discardCount[player]++ );
						failFlag = 1;
					}
					if( !(Gtest.deckCount[player] == G.deckCount[player] ) ){
						printf( "TEST 2 Failed: %s deckCount = %d, expected = %d\n",stringify( currentCard ), Gtest.deckCount[player], G.deckCount[player] );
						failFlag = 1;
					}
					if ( !(Gtest.handCount[player] == G.handCount[player] ) ){
						printf( "TEST 2 Failed: %s handCount = %d, expected = %d\n", stringify( currentCard ), Gtest.handCount[player], G.handCount[player] );
						failFlag = 1;
					} 

					//Testing Card only is in discard
					if ( !( Gtest.discard[player][state->discardCount[player]] == currentCard ) ){
						printf( "TEST 2 Failed: %d enum expected != %d found in discard \n", currentCard, Gtest.discard[player][state->discardCount[player]] );
						failFlag = 1;
					}
					if ( !( Gtest.deck[player][state->deckCount[player]] == G.deck[player][state->deckCount[player]] ) ){
						printf( "TEST 2 Failed: %d enum expected != %d found in deck \n", G.deck[player][state->deckCount[player]], Gtest.deck[player][state->deckCount[player]] );
						failFlag = 1;
					}
					if ( !( Gtest.hand[player][state->handCount[player]] == G.hand[player][state->handCount[player]] ) ){
						printf( "TEST 2 Failed: %d enum expected != %d found in hand \n", G.hand[player][state->handCount[player]], Gtest.hand[player][state->handCount[player]] );
						failFlag = 1;
					}
				
				//Deck Count Should Increment By 1. Hand and Discard should not change
				} else if( cardDest == 1 ){ 
					
					//Testing Location Count 1 increments and 0 & 2 don't 
					if ( !(Gtest.discardCount[player] == G.discardCount[player] ) ){
						printf( "TEST 2 Failed: %s discardCount = %d, expected = %d\n", stringify( currentCard ), Gtest.discardCount[player], G.discardCount[player] );
						failFlag = 1;
					}
					if( !(Gtest.deckCount[player] == Gtest.deckCount[player]++ ) ){
						printf( "TEST 2 Failed: %s deckCount = %d, expected = %d\n",stringify( currentCard ), Gtest.deckCount[player], G.deckCount[player] );
						failFlag = 1;
					}
					if ( !(Gtest.handCount[player] == G.handCount[player] ) ){
						printf( "TEST 2 Failed: %s handCount = %d, expected = %d\n", stringify( currentCard ), Gtest.handCount[player], G.handCount[player] );
						failFlag = 1;
					} 
 
					//Testing Card only is in Deck
					if ( !( Gtest.discard[player][state->discardCount[player]] == G.discard[player][state->discardCount[player]] ) ){
						printf( "TEST 2 Failed: %d enum expected != %d found in discard \n", G.discard[player][state->discardCount[player]], Gtest.discard[player][state->discardCount[player]] );
						failFlag = 1;
					}
					if ( !( Gtest.deck[player][state->deckCount[player]] == currentCard ) ){
						printf( "TEST 2 Failed: %d enum expected != %d found in deck \n", currentCard, Gtest.deck[player][state->deckCount[player]] );
						failFlag = 1;
					}
					if ( !( Gtest.hand[player][state->handCount[player]] == G.hand[player][state->handCount[player]] ) ){
						printf( "TEST 2 Failed: %d enum expected != %d found in hand \n", G.hand[player][state->handCount[player]], Gtest.hand[player][state->handCount[player]] );
						failFlag = 1;
					}

				//Hand Count Should Increment By 1. Deck and Discard should not change
				} else if( cardDest == 2 ){

					//Testing Location Count 2 increments and 0 & 1 don't 
					if ( !(Gtest.discardCount[player] == G.discardCount[player] ) ){
						printf( "TEST 2 Failed: %s discardCount = %d, expected = %d\n", stringify( currentCard ), Gtest.discardCount[player], G.discardCount[player] );
						failFlag = 1;
					}
					if( !(Gtest.deckCount[player] == G.deckCount[player] ) ){
						printf( "TEST 2 Failed: %s deckCount = %d, expected = %d\n",stringify( currentCard ), Gtest.deckCount[player], G.deckCount[player] );
						failFlag = 1;
					}
					if ( !(Gtest.handCount[player] == G.handCount[player] ) ){
						printf( "TEST 2 Failed: %s handCount = %d, expected = %d\n", stringify( currentCard ), Gtest.handCount[player], G.handCount[player] );
						failFlag = 1;
					} 

					//Testing Card only is in hand
					if ( !( Gtest.discard[player][state->discardCount[player]] == G.discard[player][state->discardCount[player]] ) ){
						printf( "TEST 2 Failed: %d enum expected != %d found in discard \n", G.discard[player][state->discardCount[player]], Gtest.discard[player][state->discardCount[player]] );
						failFlag = 1;
					}
					if ( !( Gtest.deck[player][state->deckCount[player]] == G.deck[player][state->deckCount[player]] ) ){
						printf( "TEST 2 Failed: %d enum expected != %d found in deck \n", G.deck[player][state->deckCount[player]], Gtest.deck[player][state->deckCount[player]] );
						failFlag = 1;
					}
					if ( !( Gtest.hand[player][state->handCount[player]] == currentCard ) ){
						printf( "TEST 2 Failed: %d enum expected != %d found in hand \n", currentCard, Gtest.hand[player][state->handCount[player]] );
						failFlag = 1;
					}
				}
				if( failFlag == 0 ){
					printf( "TEST 2 Passed: %s Returned 0, supply, deck, hand, and discard updated appropriatly\n", stringify( currentCard ));
					successCount++;
				} else if( failFlag == 1 ) {
					failCount++;
				}
			}
		}
		
	//Done Testing. Print Unit Test Results
			printf("%d tests passed -- %d tests failed\n", successCount, failCount);

    return 0;
}
