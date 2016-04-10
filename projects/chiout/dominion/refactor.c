Bugs introduced into dominion.c.

Adventurer: The code in the switch statement for adventurer is replaced by the standalone function, adventurerDrawn. This function pretty much uses the exact same code and variables, however two bugs are introduced. The first while loop's conditional statement is modified from drawntreasure<2 to drawntreasure<=2, meaning that 3 treasure cards will be drawn instead of 2. The second bug is in the second while loop's conditional statement, which was modified from z-1>=0 to z-1>0. This change will prevent one card from being discarded from the current hand.

Smithy: smithyDrawn is the new function that replaces the code in the switch statement for case smithy. The bug introduced into the code is the change from i<3 to i<=3 in the for loop condition. This change means that 4 cards will be drawn instead of 3.

Steward: stewardDrawn is the new function that replaces the code for case steward in the switch statement. The first bug that is introduced is in the else if (choice1==2) condition. If that condition was true, then the player would get 3 more coins instead of 2. The next few bugs are all found in the discardCard function calls. The calls with a trashFlag of 1 are changed to 0, and the call with a flag of 0 is changed to 1. This causes the cards which need to be trashed to only be discarded and vice versa.

Remodel: Code for remodel case was refactored to be in remodelDrawn function. The first bug introduced is in the condition of the first if statement. getCost(choice2) is replaced by getCost(choice1) in the if statement condition, which means that the if statement is evaluating the wrong condition. The second bug is found in the discardCard function call, where the trashFlag parameter is changed from 0 to 1. This would cause the discarded card to be trashed and removed from the game.

Village: Code for case Village was refactored to be in villageDrawn function. No bugs were introduced.

