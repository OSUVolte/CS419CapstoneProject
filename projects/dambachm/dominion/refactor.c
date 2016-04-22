I moved the adventurer, smithy, great_hall, steward and minion cards to their own function called playAdventurer, playSmithy, playGreat_Hall, playSteward and playMinion.
BUGS INTRODUCED:
for Adventurer, I removed the silver from the if statement that increments the treasureCount variable.
This means that players will keep drawing cards until the have two copper or gold, but can get many more
silver cards.

for Smithy, I set the for loop to be <=3. This will result in players drawing four cards instead of three.

for Steward, I added the plus 2 coins to the else statement. This will result in players getting
two extra coins whenver they choose to trash two cards.

for Minion, I changed the for (i=0... to for (i=1...
This will result in the first player not redawing their hand when they should.

I did not make any changes to the Great_hall function.
