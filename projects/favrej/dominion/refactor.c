Note on Refactored Code in dominion.c and dominion.h:
I chose the following cards to refactor: Adventurer, Smithy, Great Hall, 
Village, and Council Room. Of the five chosen cards, four of them (Adventuer, 
Smithy, Village, and Council Room) already had function prototypes in dominion.h 
file. The already coded prototypes required additional parameters in order to be
useful and effective, then I coded a function prototype for Great Hall in order
to complete the function prototypes. For the refactoring of the five cards in
dominion.c, I started by adding the functions in the buttom of the file, each
named play[name of card]. Once the skeletons for the functions where implemented
I moved the appropriate code of each card into its respected function skeleton.
In placed for the moved code under the card's case condition was a return paired 
with a function call to play the card. Each function returns a value of zero to
the caller in the case condition in the cardEffect function, which will return
that returned zero, as well. Once all code was moved and polished, I tested to
make sure that all code would compile and run by running Makefile. After fixing
a few bugs and adding needed variables, all five functions compile without
errors or warnings.

Bugs:
Of the five card functions created, four were implemented with subtle bugs. The
following is information about the bugs implemented in the selected cards:

Adventurer - When drawing for treasure cards, the loop is only looking for gold
and copper treasure cards, instead of gold, copper, and SILVER treasure cards.
The logic condition for "silver" was removed. This means that whenever a silver
treasure is drawn, it will be treated as a non-treasure card and placed in
the temporary hand instead.

Council Room - This card was originally implemented to draw 4 cards when played.
The logic in the for loop, i < 4, was changed to i <= 4, which will have the 
loop draw 5 cards instead of 4. 

Smithy - When the card is to be discarded after it has been played, it is 
suppose to be discarded in the player's played pile. However, the attribute
in the discardCard() function corresponding to the trash condition was changed 
from 0 to 1, marking the card to be trashed instead of added to the played pile.

Village - For this card, the player is allowed to play 2 action cards; however,
the line of code, pState->numActions = pState->numActions + 2 was changed to
pState->numActions = pState->numActions + 3, making the card play 3 action 
cards instead of 2.
