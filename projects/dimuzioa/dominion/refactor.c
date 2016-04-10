/*******
A list of the subtle changes I made to each refactored function:

playAdvCard - Deleted copper as one of the OR conditions for incrementing drawntreasure, requiring silver or gold to be drawn instead.

playSmithyCard - Changed for loop condition to i < 4, so it now draws 4 cards rather than 3.

playGreatHall - Great hall card is not discarded after playing, can play again if action cards permit.

playCouncilRoom - Function increments Buy step by 2, rather than 1.
********/