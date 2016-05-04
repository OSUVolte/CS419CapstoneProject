//
// Created by Michael Loo on 4/24/16.
//

/*
 * Here is my bug report:
 *
Testing numCards function
Testing supplyCount function
Testing updateCoins function
The coin count is not correct!
Testing whoseTurn function
Testing smithy card
Smithy does not add correct number of cards
Smithy does not add correct number of cards
Smithy does not add correct number of cards
Testing adventurer card
Two cards were not drawn from the deck
Testing village card
The village card did not add two actions!
The village card did not add two actions!
The village card did not add two actions!
The village card did not add two actions!
The village card did not add two actions!
Testing Great Hall card

 As we can see, my biggest surprise is that my unit test found an error in coin counting, which was not correct

 the smithy function loops through 5 times, so after 2, it stops working correctly.  Notsure why

 Adventurer card doesn't draw two cards from the deck

 Village card doesn't correctly add two actions.

 These are the bugs I found with my code.
 */