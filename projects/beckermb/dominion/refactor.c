Assignment 2 Refactor:
 * adventurer effect moved into method adventurerCardEffect
 * smithy card effect moved into method smithyCardEffect
 * village effect moved into method villageCardEffect
 * great_hall effect moved into method villageCardEffect
 * outpost effect moved into method outpostCardEffect

Bugs introduced:
  * Smithy card changed so that is trashed rather than discarded after use.
  * Adventurer card changed so that the temphand has a max size of 7. This will cause a crash if more than 7 cards need to be drawn before 2 treasures are found.
  * Changed great_hall card so that the first player always draws the card, regardless of whose turn it is.
  * Changed village card so that the player does not receive the additional actions.
  * Outpost card is unchanged.
