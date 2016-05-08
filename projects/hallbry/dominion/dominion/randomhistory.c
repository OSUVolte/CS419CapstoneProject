Assigment 4 Writeup
Bryant Hall (hallbry)
5/8/2016
CS 362 Spring Quarter

DIRECTIONS:  run the command 'make randomtests' the generate and run all the tests. The results and gcov information will be stored in randomtestcard.out
and randomtestadventurer.out


The following writeup covers the development of the random cards for assigment 4.   I chose to develop for the salvager card and the required adventurer card. 
I originally developed salvager first and used that as a template for the adventurer. While both had some similarities, both functions were different that the setup
and tests had to vary a little bit.  


Salvager

The salvager function allows the user to select a card from their hand and discard it for the coin value of the card.  To build up a random function for this, I set up a generator
to randomize the cards that would be called.  It would completly randomize the userhand and pick a random card to be discarded.  For this test I would record some previous 
information such as the number of coins, actions, buys and a few other values in the game state in variables.Salvager chooses a card to discard for coins 
so I also recorded the expected value of this randomely chosen card.  These with a few modifiers would form the expected values, while the actual values would come from the gamestate
after running the card. 

I then ran the function for the card effect using the salvager and the card of choice to discard for inputs.  I then had a function to compare the expected value versus the actual value in the game
state.  This test would then record the results, and print to screen if a failure occured. It would then move on to the next player and repeat.  This whole series of tests would be several
thousand times and it gave some good data to analyze.    
  
One of my test metrics was to record how many tests were succesful, versus failed so I included a array to record these values.  If a test failed its result came out on the screen. 
My tests were successful about 95% of the time.  The coin values were occasionally wrong when the card to discard was the first card in the deck. Another error happened with the number of cards in hand which needs to be investigated further.   

The coverage for this function was 100% with every line of the code being executed multiple times and every branch being hit. 


Adventurer

The second card I tested was the adventurer card.  This card goes through the deck until we find 2 treasure cards to add to the hand.  I used a similar approach but I had to tailor
this test to this card specifically. I expanded my randomize function to randomize all the cards in the deck, hand, and discard. I also added 2 copper cards to the bottom of the discard deck. 
When I first tried to run my test, if i didn't put some treasure cards in the bottom, this function could enter into a endless loop until the OS did a core dump.  One other function 
I added to this program to record the number of treasure cards in a hand. I also recorded the total number of cards in every deck for a player. 

Otherwise it was fairly similar to the salvager setup. I had variables record old values before I ran the card effect function. I then compared the values I recorded with a expected value that made up the expected value with the actual value in the game state. I used the same comparetest function
from the other card, and the same array to record out results. 

Results from this showed that failed roughly 20% of the unit tests, all of them which involved the number of cards in all the decks.  This makes sense because in my refactor,
I introduced a bug which would cause exactly this. Otherwise all other tests completed succesfully.  Statement coverage in this function was 100% and every branch was taken. 

Overall I was very pleased with my random testers. I ran 200,000 trials and caught a few bugs in the programs as well.  

