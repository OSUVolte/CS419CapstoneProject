/*
Filename: randomhistory.c
Aleksandr Balab
Class: CS362-400

Assignment 4
Description: Write up and check in the development of your random testers, including improvements in coverage and effort to check the correctness
             of your specification, as randomhistory.c.

Bias/Development: Looking back at this assigment I understood that since i've introduced the bugs myself i knew what i would have to be testing in order to find the bugs,
		    	 so my tests reflected this fact. I believe that if i didn't know what the bugs were i would've take a different approach in testing these cards.
			      All the test that i was running were failing- meaning they were locating the bug, which is the idea of these tests and since the bugs that i've introduced
			     (please refer to refactor.c) had major effect on the outcome of the game - they were fairly easy to locate.
			      I can definetly see that if the bugs were on a lot smaller scale and more sublte then the random testing would've been a lot more efficient way to find the
			      those bugs.
			      I think that radomizing test that multiple meaninful variable to test will  make it harder to  figure out exactly what the bug is, but on the other hand
			      doing the random testing one can find bugs that you dont think about to check and we cannot manually check scanarios that we can

Random test card: playSalvager()
				For testing this card I decided to randomilly assign values to as many variable within
				this function as made sense. Since Salvager is a trash for benefit card and it allows you to trash one card from your hand and get +Coin
				equal to its cost to spend this turn, the randomly assigned variables are as follows: 
					1. Randomize numPlayer ( non card specific , but allows to see wether the number of players would change the output)
					2. Random hand Card ( number of cards on hand)
					3. Current Player ( randomly assign who is current player) 
					4. Randomize number of cards to trash.

Random test card: playAdventurer()
					For testing this card I decided to randomilly assign values to as many variable within
					1. Randomize numPlayer ( non card specific , but allows to see wether the number of players would change the output)
					2. Random hand Card ( number of cards on hand)
					3. Current Player ( randomly assign who is current player)
					4. Randomize number of cards to trash.

The coverage of has imporved over the cardtest1.c / cardtest4.c  ,but not significantly. I think the reason for it is that i've tested the randomized
				inputs that had less effect on the other function calls. I was testing if the player has the right amount of cards on his hand to what
				i was expecting him/her to have. Additional tests would've greatly imporved the  coverage. If I had to do this one again i would've incorporated
				additional test such as checking the expected amount vs actual amount of cards in TRASH and Hands. 




*/