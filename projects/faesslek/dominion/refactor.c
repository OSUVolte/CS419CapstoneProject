/*
CS 362 - Assignment 2
Kelby Faessler
ONID: faesslek

Smithy card refactor:
    --Moved smithy switch statement code to its own function
    --Pass state struct, currentPlayer integer, handpos integer to new function
    --bug introduced: increase loop to run 4 times instead of 3. Will cause
      too many cards to be drawn.

Adventurer card refactor:
    --Moved adventurer switch statement code to its own function
    --Pass state struct, currentPlayer integer to new function
    --bug introduced: removed check whether drawn card is gold, now only checks whether
      it's copper/silver

Great Hall card refactor:
    --Moved great hall switch statement code to its own function
    --Pass state struct, currentPlayer integer to new function
    --bug introduced: increase actions by 2 instead of 1

Steward card refactor:
    --Moved steward switch statement code to its own function
    --Pass state struct, currentPlayer integer, handpos integer, choice1, choice2,
      choice3 integers to new function
    --Add 2 coins for (choice1 == 1) instead of drawing 2 cards.
      Draw 2 cards for (choice1 == 2) instead of adding 2 coins

Council room card refactor:
    --Moved council room switch statement code to its own function
    --Pass state struct, currentPlayer integer, handpos integer to new function
    --When adding card for each other player, remove if check on whether the player
      is current player. That way current player will get 1 too many cards

*/