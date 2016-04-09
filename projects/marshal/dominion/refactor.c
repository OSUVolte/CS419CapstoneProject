/*
Alex Marsh
Assignment 2

playSmithyCard- when played the smithy card is supposed to allow the player to draw 3 cards.  Inside the for-loop I changed the 'i < 3' to 'i <= 3', this way the player will actually draw 4 cards insted of the intended 3.

playAdventurerCard- the adventure card is meant to give the player a chance to draw two treasure card.  Inside my function there is a while loop that draws a card from the players deck until two treasure cards are drawn. The initial while loop states 'while(drawntreasrue<2)...', but I changed it to 'while(drawntreasrue<=2)...'.  This results in that player only recieving 1 treasure card.

playVillageCard- the village action card should give the current player ability to draw 1 card and gain 2 action cards.  I introduced a bug where the drawCard funtion was called twice.  This way the current player draws two cards from their deck. 

playGreat_HallCard-I did not introduce a bug into this function

playMinionCard- In this function I introduced a bug if the player chooses choice 2.  The action card is intended to draw 4 cards. I placed a bug in the for loop from 'i < 4' to 'i <= 4'.  This results in the player only drawing 3 cards. 



*/