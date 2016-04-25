/*
Changes to dominion.c to introduce bugs:

function playAdventurer:
    Removed else statement before removal on non-treasure cards from hand. 
    Now all coin cards will be be counted and then removed and all other cards are lost.
    The number of cards in the discard pile and the player's hand will be incorrect.
    No treasure cards will be added to the players hand.

function playSmithy:
    Trash flag is set to true fo smithy card will be trashed instead of discarded
    This will occur anytime the card is played. The number of cards in the discard pile will be less than 
    expected.

function playSalvager:
    When function is called, the parameters for handPos and selected card to trash are swapped.
    The salavager card will be trashed and the card chosen for trashing will be discarded.
 
function playEmbargo:
    choice1 is set to 0 instead of 1 making the trash flag false so the card will be discarded instead.
    The number of cards in the players discard pile will be incorrect by 1.
    
function playSeahag:
    decrement discard count and fail to decrement deck count for each discard.
    The deck counts and discard counts will be off.
    The number of cards discarded will be incorrect.
 */
