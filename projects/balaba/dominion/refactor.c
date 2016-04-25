/* Aleksandr Balab
   Assigment2 

The cards refactored: Adventurer, Smithy, CouncilRoom, Salvager and Village 

1.Adventurer:
Bug: in the  discard all cards in play that have been drawn the has tempHand to be tempHand[z-1],
but instead is from z. It'll discard 1 additional card instead. 

2.Smithy:
Bug: Change flag from discardCard() from 0 to 1, will trash the card instead of discard. 

3.Salvager: 
Bug: In   state->coins = state->coins - getCost( handCard(choice1, state) ); Changed the + into -. Thus 
the player will not be getting goins equal to trashed card will get less or crash. 

4. Village: 
No bugs. 

5.CounsilRoom:
In for (i = 0; i < 4; i++) changed it to for (i = 0; i <= 4; i++). Player will get 5 cards instead of 4
*/