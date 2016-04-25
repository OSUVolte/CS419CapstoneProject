Mine: For the mine card I removed a break statement from the loop statement that deals with discarding trashed cards. By doing this more cards will be discarded then should be.

Adventurer: Changed the loop counter from z-1>0 to z>0 in a for loop that checks how many cards should be discarded from the temp hand. This change will cause the cards to not be discarded properly.

Smithy: The part of the code that discards the smithy card after its use has been removed. Meaning the card will stay in the players hand after it has been used.

Village: The card will not increase the number of player actions as it should.