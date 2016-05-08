
For my testing of the card statements, I wanted to make sure that I had all inputs were covered for the cardeffect()
function. There were 7 variables being passed into the cardeffect() function. 

For the other function inputs, I devised a for loop that would continously run tests and would change inputs for:
player, 
choice1,
choice2,
choice3,
bonus

The other variables were more static like handPos and gameState. I did not want to change these.

THe most effective random test was chosing player and was the most difficult. The function did not pass in player so 
I had to figure out how the function new which player was utilizng the function. I found that it was running whoseTurn(state)
function which means I had to make sure that the game state regoncized my random player as being that players turn.

I ran testG.whoseTurn = thisPlayer to make sure my random player was chosen in the function.

choice1, choice2, choice3, and bonus were randomized but did not affect the overall outcome of the function. There was no code in 
the cards I chose that utilized these variables. So, I did not spend a lot of time on them.

Another difficult task was determing if the test passed or not. For this, I had to take the state before running the cardEffect 
function and the state after. I then had to access how many cards / treasures it should have after the run. I had to do this by 
taking a look at the number of cards in the deck. If a card allowed 3 cards to be drawn, but there were only 2, then I had to make 
sure my tests knew only to expect 2 cards instead of 3. 

I found that my tests ran 99% of the time successfully. There were some invalid failures every once in a while but it was easy to see
if it was a true failure because of my test output had a lot of details.

Overall, I did not find much of a difference between unit testing and random testing. I kind of prefered being able to specify the
tests and outcomes with the unit tests and know exactly what outcome I am supposed to achieve with the test. I was able to run more random
tests then unit tests; however, I dont feel that the tests were any better then unit testing. For the smaller execercises that have small 
numbers of input, I believe unit testing would be best. For larger systems with many different inputs, possibly random testing would be
better because you dont have to write a test for each variation. You could write the code that creates the variations and let it run many
times to make sure that all scenerios were covered.




