/************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  refactor.c
** Date:  4/8/16
** Due Date: 4/10/16
**
** Description:  This is a text file that is will be used to 
** document the bugs that have been introduced into the 
** Card Effects of Smithy, Adventurer, and the three other 
** Kingdom Cards of my choice.
*************************************************************/


/************************************************************
** SMITHY BUG DOCUMENTATION
**
** Description:
** Added an equal sign to the for loop to change the amount of
** cards drawn from +3 to +4.  Winning!
*************************************************************/


/************************************************************
** ADVENTURER BUG DOCUMENTATION
**
** Description:  
** Changed the condition of the while loop to stop drawing
** new cards once the drawntreasure = 1.  That means that the 
** currentPlayer will only be able to draw up to 1 treasure 
** card if the Adventurer is played as an action.
*************************************************************/


/************************************************************
** GREAT_HALL BUG DOCUMENTATION
**
** Description:
** Changed the parameter passed to discardCard().  Instead of
** passing a 0, a 1 was passed which will result in the 
** Great Hall card being trashed instead of stored as able
** played card.  Did not change anything else.
*************************************************************/


/************************************************************
** EMBARGO BUG DOCUMENTATION
**
** Description:
** Instead of adding 2 coins to the current player's state...
** only 1 is added.  Also, when passing the trashFlag to 
** discardCard(), a zero is passed resulting in the card
** being stored as a played card, rather than trashed.
*************************************************************/


/************************************************************
** CUTPURSE BUG DOCUMENTATION
**
** Description:
** Current Player gets +3 bonus instead of +4.  Also, instead 
** of removing a copper card from each other enemy player, a 
** gold card is removed if contained in their hands.  WINNING!
*************************************************************/