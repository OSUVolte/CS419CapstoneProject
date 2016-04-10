Jessica Siano
CS 362 Software Engineering 2
Assignment 2

For all of these cards, I moved the code out of the switch statement, and in to a function at the bottom of the code.  I also included a prototype of each function at the top.
In the smithy function, I made it so that only two cards will actually be drawn by setting my index variable to start and 1 and go until it is less than 3, instead of having it go until it is less than or equal to 3, or starting it as 0 as the original code had it.
In the village function, I made it so that only one action is added, instead of 2.
In the adventurer function, I made it so that the while loop iterates while drawntreasure is less than 3, instead of 2, so that the player will be able to draw too many times.
In council_room, I removed the code that added the buy, so the player will not get the extra buy option during his or her turn.
In steward, I swapped the values of the choices, is if the user chooses to draw two cards, they will instead get two coins, and if they choose to get two coins, they will instead draw two cards.
