/*
Susan Eldridge
Spring 2016
CS361
This is a place to talk about bugs found in unittest[1-4] and cardtest[1-4].
*/

No bugs were found in the unit tests.
In the cardtest for adventurer and council_room, it was found that it was not adding the card to the played card pile
after it was used.
sea_hag was not take the card out of the player's hand appropriately either.  It also did not
keep the deck the same size when discarding one, but gaining another.  Curse card was not
found on top of opponent's deck after sea_hag was used.  It did not reduce the opponent's
deck size when there were no curse cards left.
