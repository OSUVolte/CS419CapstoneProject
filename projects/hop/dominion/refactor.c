Author: Patrick Ho
Assignment 2
Due April 10, 2016
Description: Documentation of changes to card implementation in card.c


Files Changed:
   dominion.c
   - Refactored 5 cases in the switch statement in cardEffects() to become their individual functions. Functions are implemeneted in dominion.c.
   dominion.h
   - Modified the function prototypes and their arguments for playAdventurer(), playSmithy(), playVillage(), playFeast(), playCouncil_Room()


Cards Changed:
   adventurer
   smithy
   village
   feast
   council_room


Details:
   playAdventurer()
      - Changed "while(drawntreasure<2)" to a for loop. The intent is for the loop to exit if drawntreasure > 2, however a bug is introduced. On line: "if (drawntreasure++ > 2) break;", the increment of drawntreasure is post-increment, which means it will not evaluate true at the appropriate instance.
      - Removed the post-increment of z, "z++" and placed it directly into the index of temphand, like so "temphand[++z]". This is a benign change.
      - Changed "z=z-1" to "--z". Benign.
      - Changed the "while(z-1>=0)" to "for(;;)" loop structure with a condition "if(z<1) break" to get out of the loop. This is a benign change.


   playSmithy()
      - Introduced a bug by adding a ";" at the end of the card drawing for loop.  This will only call drawCard() once instead of 3.
      - In the call to discardCard(), passing in arguments for handPos and currentPlayer are switched. Another bug.
      - In the switch statement, under the case "smithy", did not add a "break" statement after the call to playSmithy(). This is a bug.


   playVillage()
      - This function is implemented as-is and should be functioning as intended.


   playFeast()
      - The for loop control is changed from "for (i=0; i <= state->handCount[currentPlayer]; i++)" to "for(i=0; i < state->handCount[currentPlayer]; ++i)".  The change from post-increment to pre-increment is a cosmetic change and is benign. However, the end loop condition change from "<=" to "<" is a bug. The last hand will not be recovered at the end of this play.
      - Removed variable "x" and it's corresponding "while(x==1)" loop. Instead, using "for(;;)" and a "break" statement to end loop.  This change is benign.
      - Changed statement "if (supplyCount(choice1, state) <= 0)" to "if(supplyCount(choice1, state) >= 0)". This is a bug.
      - Changed statement "else if (state->coins < getCost(choice1))" to "else if (state->coins - getCost(choice1) < 0)". This is a cosmetic change and is benign.


   playCouncil_Room()
      - Changed "for(i=0;i<4;i++)" to "for(i=0;i<4;++i)". No effect.
      - Changed "state->numBuys++" to "state->numBuys = state->numBuys + 1". No effect.
      - Removed call to "discardCard()" entirely. This is an introduced bug. Card is not placed in the discard pile and the game state is not updated to reflect the play of the council room.
