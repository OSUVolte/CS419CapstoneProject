/**************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 3
* Filename: bug1.c
* Description: Describes bugs found from unittests
*
******************************* BUGS *************************************
* 1 - discardCard() allows you to discard a card even when the handCount
* is 0. This results in a negative handCount, which is impossible.
*
* 2 - discardCard() allows you to remove a card from an invalid hand 
* position, which means it artifically decrements the hand count.
*
* 3 - playAdventurer can be called w a player other than the actual current
* player and it will add treasure cards to the other players hand. This
* is actually a problem with a lot of the code. Since there is a member
* variable "whoseTurn", we should really use that to determine who is
* the current player. This will help reduce potential bugs.
*
* 4 - playAdventurer goes on an infinite loop if there are no treasure
* cards left in the player's deck or discard pile. 
*
* 5 - playAdventurer doesnt not add the treasure cards from the players
* discard pile. I'm not sure where this bug is originating from. 
*
* 6 - playAdventurer does not remove the playAdventurer card from the 
* players hand. The function doesnt even know what pos the card is in
* to remove it.
*
* 7 - playSmithy has known bugs that are recorded in the refactor.c file.
* These include only adding one card to the players hand before returning
* as well as not discarding the smithy card. 
*
* 8 - playEmbargo adds an embargo coin to the supply pile. This is suppose
* to cause players to gain one curse card per embargo token on that pile
* when they purchase a card. The buyCard function does not check to see
* the embargo tokens at all.
*
* 9 - playEmbargo check the supplyCount of a pile to -1 to see if its 
* empty, when an empty supplyPile is actually 0. 
*
* 10 - playCutpurse is adding three additional coins to the current'
* player instead of two. Other player's bronze is not being removed.
* These are bugs already documented in refactor.c
*
* 11 - playCutpurse the if statement on line 1391 will never be true. 
* This condititonal should actually be if (j == state->handCount[i] - 1)
* which is when the players last card has been reached.
*
* 12 - When a player end's their turn, their hand is discarded and only
* the nextPlayers hand is filled. This presented an issue for playCutpurse
* as the other players wont have any cards in their hand and thus they will
* never have to get rid of a bronze. 
**************************************************************************/