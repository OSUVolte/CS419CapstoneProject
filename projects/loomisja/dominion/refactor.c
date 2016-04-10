Jason Loomis
4/10/2016
Assignment 2: Refactoring
Filename: refactor.c

=== CHANGES TO dominion.c ===

ADVENTURER
Added cardEffectAdventurer() function to encapsulate the adventurer card effect.
(Bugfix) The function also calls discardCard() to mark the card as played.

Updated switch statement in cardEffect() to call cardEffectAdventurer() for the
adventurer card.


COUNCILROOM
Added cardEffectCouncilRoom() function to encapsulate the council_room card
effect.

Updated switch statement in cardEffect() to call cardEffectCouncilRoom() for
the council_room card.


FEAST
Added cardEffectFeast() function to encapsulate the feast card effect.
(Bugfix) The function also calls discardCard() to mark the card as played.

Updated switch statement in cardEffect() to call cardEffectFeast() for the
feast card.


MINE
Added cardEffectMine() function to encapsulate the mine card effect.

Updated switch statement in cardEffect() to call cardEffectMine() for the
feast card.


REMODEL
Added cardEffectRemodel() function to encapsulate the remodel card effect.

Updated switch statement in cardEffect() to call cardEffectRemodel() for the
feast card.


SMITHY
Added cardEffectSmithy() function to encapsulate the smithy card effect.

Updated switch statement in cardEffect() to call cardEffectSmithy() for the
smithy card.


=== BUGS INTRODUCED ===

in cardEffectAdventurer():
1) Changed while loop termination condition to while(drawntreasure<=2). This will
cause the card effect to draw 3 cards instead of the 2 that is is supposed to
draw.
2) Changed the if statement that inspects the treasure card from
if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) to
if (cardDrawn == copper || cardDrawn == copper || cardDrawn == gold), which
will cause the loop to skip over silver treasure cards when the cards are being
revealed.

in cardEffectCouncilRoom():
1) In the loop drawing cards for the other players, changed the if statement
condition from if(i != player) to if(i < player) which will cause cards to be
drawn only by the other players whose indices are less than the current player,
rather than ALL other players to draw a card.

in cardEffectFeast():
1) modified the call from gainCard(choice1, state, 0, player) to
gainCard(choice1, state, 2, player), which adds the card gained to the player's
hand, rather than to the discard pile (where it is supposed to go).

in cardEffectMine():
* Card already contains bugs--the trashed treasure cards are discarded to the
discard pile, not actually trashed (as they are supposed to be); as a result,
the player keeps his trashed treasure cards in addition to the cards gained.
Additionally, the implementation looks incomplete as it does not check which
card the player has chosen, and as such may allow the player to choose a non-
treasure card to gain (the Mine allows you to gain treasure cards only).

in cardEffectRemodel():
1) Changed gainCard() call such that the player will gain the same card he is
trashing (choice1 value), instead of card he has chosen (choice2 value).
* Card already contains bugs--the if-statement that compares the (cost + 2) of
the card the player is trashing with the card he has chosen has the inequality
reversed--it should be checking if the cost of the card being trashed + 2 is
less than the cost of the card being gained.

in cardEffectSmithy():
1) Changed drawCard(player, state) call in the for loop to drawCard(i, state).
This will cause players 0 to 2 to gain cards, assuming the game has 3 players.
If there are fewer than 3 players, the result will be unpredictable and may
cause the program to crash (buffer overflow).