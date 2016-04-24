Refactored Code:
I chose to refactor the Adventurer, Smithy, Village, Feast, and Council Room cards
since they already had function prototypes in the dominion.h file.  To do this,
I added 5 functions to the dominion.c file play[x] where [x] is the card name.
For each of the 5 functions, I cut the appropriate code from the cardEffect function
and pasted it in the new function for that card and I replaced the code in the
switch section of the cardEffect function with a call to my new function.
Then, I made sure that I was passing the appropriate variables into the function
from the cardEffect function to the card specific function.  I had to add a few
parameters to the given function prototypes so that my new functions would work
properly and have the correct variables available to them.  The functions for each
card return zero when they have completed successfully and this is captured as
the return value for the cardEffect function too.  Since I made functions for cards
that add actions, I decided to fix a bug that I noticed in the Adventurer card.
Previously, the Adventurer card did not get discarded after it was used, so if
the player had multiple actions, theorhetically, they could use the same Adventurer
card multiple times.  I fixed this by adding a line to the playAdventurer() function
to discard the card before returning zero.  Since I made a function for Feast,
which gets trashed when it is used instead of just being discarded, I decided to
also fix a bug that I noticed in the discardCard() function.  Previously, the
discardCard() function was not keeping track of trashed cards, it was just not
adding them to the playedCards pile.  Since there are some Dominion cards that
allow cards to be recovered from the trash pile, I made a trash pile and a way
to add cards to it based on the trashFlag in the discardCard() function.

Bugs:
Adventurer - When adding temphand to the discard pile, index z is used instead of
z-1.  This will make the player discard something that they didn't draw.  It will
depend on previous uses of Adventurer for what this might be.  The first card in
temphand (zero index) never gets discarded.

Smithy - Player draws 4 cards instead of 3 because loop condition is set to <=
instead of <.

Village - Village gets trashed instead of just discarded because trashFlag is set
to 1.

Council Room - Current player draws another card instead of each other player
because the if condition checks for i being equal to currentPlayer instead of not
equal.