/****************************************
* Name:		Robert Tang
* Class:	CS362, Fall 2016
* Filename:	randomhistory.c
****************************************/

First I worked on adventurer.

I decided to have "NUM_CHECKS" be the number of checks done.

Then I realized that I had to know how adventurer worked "in the hand".
It 'could work' by adding 2 treasure cards randomly to the hand. However, 
I worked on it on the assumption that the last two cards are the last two cards drawn.
Due to this, a more concise means to determine what cards were drawn can be done.

Then the game is run NUM_CHECKS times, with each seed randomized. I suppose it 
could have been done incrementally as well considering how rand()%1000 works. 

adventurrerTest(...) is the main function for testing.
Some of the things to determine before testing are:
	whose turn it is
	currentHandSize
	currentScore
	position of the adventurer card in the hand.
		*note* the adventurer card has to be put in the hand randomly.
		
Then the activation of "play Adventurer" card.

and test for:
	How many cards are in the hand
		is the size of the hand +1? (play card -1, draw two treasure cards +2)
	what the current score is
		has it been modified ?
	Check for treasure effect
		are the last two cards added treasure cards?


		
Upon reflection, checking the smithy cards uses the same setup, abiet slightly different
Using the same process, the number of cards in hand are +2
The current score is also not modified
There is no check for treasure cards



However I feel that I am forgetting something but my mind is occupied with midterms, and other
life matters. 