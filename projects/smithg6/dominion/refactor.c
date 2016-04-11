/*
Grant Smith
CS362
Assignment2
Refactor documentation

Additionally, there seems to be an intermittent segmatation fault
somewhere in the program. I have tested with the same random seed
over and over, and cannot replicate it consistently. Running the
make file twice helps, but does not entirely eliminate it. This
may be due to running the program on flip.

SMITHY Refactor:
The bug I've introduced with the Smithy is
that the discardCard function will call
the index i (used in the previous for loop).
This will result in the third card being discarded
rather than the Smithy card that was played.
The problem will only be evident to someone looking at the 
discardCard parameters, and comparing those
with the variables within the cardSmithy function.

ADVENTURER Refactor:
For adventurer, I removed one of the logical
or statements regarding recognition of a treasure card.
This will result in a subtle change to the gameplay,
but should not be immediately obvious when compiling
or running the game. The downside of this bug is that
comparing the "right" function to my modified one,
the change may be easy to see. To mitigate this,
I have modified the blocking and white space.

VILLAGE Refactor:
The bug in the cardVillage function is that it
sets the number of actions "numActions" to the
"numPlayers" variable + 2, instead of using the
right variable. This has happened to me often
and is meant to simulate allowing the IDE
to complete a variable name, but not double checking
the name.

COUNCIL_ROOM Refactor:
For the cardCouncil_room function, I decided to
modify the logic allowing all other players to draw cards.
The loop now erroneously checks if p holds the current player value.
This should result in no other players drawing cards
when council room is played.

OUTPOST Refactor:
For outpost I put in an int i to check the outpostPlayed
flag, but the logic should cause the flag statement to
be skipped.


*/