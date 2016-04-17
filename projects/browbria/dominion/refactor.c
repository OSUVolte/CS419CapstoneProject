/*
 * refactor.c
 *
 *  Created on: April 10, 2016
 *      Author: Brian Brown
 */

/* Documentation of changes to dominion.c for Homework 2.
 *
 * adventure_card -- z is initialized to 1 instead of 0 to start.
 *
 * smithy_card -- in the for loop, i is pre-incremented instead of post-incremented
 *
 * great_hall_card -- changed state->numActions++; to state->numActions+=2;
 *
 * council_room_card -- changed for (i = 0; i < state->numPlayers; i++) to
 * for (i = 0; i <= state->numPlayers; i++) .. should also draw a card for current
 * player
 *
 * village_card
 *
 *
 */


