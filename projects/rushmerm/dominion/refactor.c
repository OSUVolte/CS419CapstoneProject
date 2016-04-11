/**************************************************************************************************
 * Mark Rushmere
 * CS 362
 * Assignment 2
 * Description: Documentation on changes made to dominion.c
 *************************************************************************************************/

// The first changes I made were to the switch statement in the cardEffect() function.
// I made seperate functions for the smithy, adventurer, mine, village, and remodle cards
// and called them from their appropriate cases in the swtich statement. 


// playSmithy():
// 
// The bugs that I introduced into smithy card functionallity are a less than or equal to rather
// than a less than, and a 1 instead of 0 for the trash flag in the discardCard function

// playAdventurer();
//
// The first bug that I introduced is increment z before tempHand[z] is assigned, instead of after,
// so the wrong card will be assigned. I also changed the assignment of cardDrawn, so that the second
// card will be assigned, not the top card.

// playMine():
//
// When gainCard() is called, I changed choice2 to choice1, so that the wrong card will be gained.

// playVillage():
// The implementation of the village card is unchaned from the original.

// playRemodel():
//
// The first bug introduced in this function was adding one to the handPos when the discardCard 
// function is called so that the wrong card will be discarded. I also added one to i the second
// time that the discardCard function is called
