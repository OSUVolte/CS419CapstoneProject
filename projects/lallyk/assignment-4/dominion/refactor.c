/* 
Kara Franco									                     refactor.c
CS.362-400
Assignment #2
Due: April 10, 2016

*** Cards Refactored: Smithy, Adventurer, Gardens, Great Hall and Minion ***

refactorSmithy( ) : In for loop (i = 0; i < 3; i++); set index to 1 (i = 1; i < 3; i++). This will change the 
action of the Smithy Card; the card now will only give the player 2 cards, rather than 3. 

refactorAdventurer( ) : In the while loop (drawnTreasure < 2) set condition to (drawnTreasure  <= 2). This will
change the action of the Adventurer card to now give the player 3 Treasure Cards, rather than 2.  Also, remove
the silver coin in the if statement so that they are not counted as Treasure Cards. 

refactorGardens( ) : The Gardens Card is a Victory Card that gives the player 1 victory point for every 10 
cards in the player’s deck. I added an extra perk to this card, an extra line that gives the player 2 coins as
well. I used this line: state->coins = state->coins + 2. This card now has an effect during the game and also 
after the game (when tallying victory points)!

refactorGreatHall( ) : The Great Hall Card is an Action and Victory Card that gives the player one victory 
point and the player may draw another card and may play another action. In the line after the 
state->numActions++, I wrote state->numActions--. This reverses the action from the card, not giving the 
player the additional action. 

refactorMinion( ) : The Minion Card is an Action and Attack Card that gives the player an additional action, 
and then gives them the option of either getting two coins, or discarding their hand and drawing four cards, 
and each player with more than 5 cards in their hand, must discard and draw four cards. In this refactoring, 
the for loop for the other players drawing (j = 0; j < 4; j++), the increment was changed to +2, 
(j = 0; j < 4; j+=2). This attacks the other players even more, since now they are at the disadvantage of only
having 2 cards in their hand, rather than 4. 

*/
