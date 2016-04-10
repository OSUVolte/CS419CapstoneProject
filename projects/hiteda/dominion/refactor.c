David Hite
refactor.c

To the prototype of playAdventurer() in dominion.h, I added an argument const int currentPlayer, which
is passed in from cardEffect(). I moved the contents of the adventurer section of the switch statement
in cardEffect() into the playAdventurer() function, and I introduced a bug by initializing the int z as
1 instead of 0. I also removed the increment of z from the while (drawntreasure<2) statement.

I also added the argument const int currentPlayer to the protoype of playSmithy() in dominion.h. I 
created playSmithy() in dominion.c and moved the contents of the smithy section of the switch statement
in cardEffect() into playSmithy(). I added a handPos++ statement to the for loop.

To the prototype of playVillage() in dominion.h, I also added const int currentPlayer. I moved the
contents of the village section of the switch statement in cardEffect() into the playVillage() function,
and I introduced a bug by replacing state->numActions = state->numActions + 2 with state->numActions++.

To the prototype of playFeast() in dominion.h, I also added const int currentPlayer. I moved the
contents of the feast section of the switch statement in cardEffect() into the playFeast() function,
and I introduced a bug by replacing -1 with 0 in the for loop that backs up the hand. I also started the
reset hand for loop with i = 1 instead of i = 0. I also reversed the last two arguments in the function
call.

To the prototype of playCouncil_Room() in dominion.h, I also added const int currentPlayer. I created
playCouncil_Room() in dominion.c and moved the contents of the council_room section of the switch
statement in cardEffect() into it. I introduced a bug by switching the != comparison operator in the
for loop that should draw cards for other players to ==.