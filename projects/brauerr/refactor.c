//summary of subtle bugs introduced as part of assignment 2

/*adventurer
  when setting the value of cardDrawn - the value should be set to 
  state->hand[currentPlayer][state->handCount[currentPlayer] - 1]
  but the subtract 1 has been omitted
  the cardDrawn in this case will be an index beyond the actual cards in hand
  so likely have a value of -1
  
  another interesting aspect of the implementation of adventurer in the source code
  that was refactored for this assignment
  is that the card is not discarded - so technically could be played again if the user
  had previously played a card giving +2 actions - probably a bug?
*/

/*smithy
  card is not discarded at end of function, so if the user was +2 actions before playing, 
  could be played again
*/

/*mine
  in if statement checking whether card is not a treasure card chosen to trash - 
  the predicate uses an AND statement - and thus will never evaluate to true
  effectively enabling the player to trash any card to gain a treasure card costing up to 3 more than it
*/

/*remodel
  in the if statement comparing costs, the LHS call to getCost should be passed
  state->hand[currentPlayer][trashChoice] but instead is passed just
  state->hand[currentPlayer], which will likely return the integer value of the pointer to the
  first index of the array, and looking at the implementation of the getCost() method, should return -1,
  which should then always result in the statement evaluating to false and essentially enabling the user to
  trash any card to get any card
*/