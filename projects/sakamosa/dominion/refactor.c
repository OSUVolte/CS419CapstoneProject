/*
Changes to dominion.c to introduce bugs:

function playAdventurer:
    removed else statement before removal on non-treasure cards from hand. 
    Now all coin cards will be be counted and then removed and all other cards are lost.

function playSmithy:
    trash falg is set to true fo smithy card will be trashed instead of discarded

function playSalvager:
    when function is called, the parameters for handPos and selected card to trash are swapped

function playEmbargo:
    choice1 is set to 0 instead of 1 making the trash flag false so the card will be discarded instead
    
function playSeahag:
    decrement discard count and fail to decrement deck count for each discard
 */
