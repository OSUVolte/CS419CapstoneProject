/* Aleksandr Balab
   Assigment2 

The cards refactored: Adventurer, Smithy, Remodel, Baron and CouncilRoom

1.ref_Adventurer:
In first while loop - drawntreasure <2 , made to drawntreasure <=2 thus making it search for 3 treasure cards not 2.
        in if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) deleted  cardDrawn == gold part,
		so gold cards wont be counted as a tresuare card. 

2.ref_Smithy:
In for loop for (i = 0; i < 3; i++) changed to (i = 0; i <= 3; i++) will  add 4 cards instead of 3.

3.ref_Remodel: 
In the for loop put break; stamement before the discardCard. The trashed card will never get discarted.

4.ref_Baron:
In the next to last if statement  state->supplyCount[estate]--; changed to state->supplyCount[estate];
Thus the number of estates available will not change thus effecting the outcome of the game. 

5.ref_CounsilRoom:
In for (i = 0; i < 4; i++) changed it to for (i = 0; i <= 4; i++). Player will get 5 cards instead of 4
In the state->numBuys++; changed it to state->numBuys; so no additional bonus for the player. 

*/