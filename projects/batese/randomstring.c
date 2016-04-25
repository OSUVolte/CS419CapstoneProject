/*
File: randomstring.c
Author: Elliot Bates
Email: batese@oregonstate.edu

inputChar():
	It is clear from the program that this function needed to generate a random character to match the if statements in the testme function. There
	are 9 possibilities here, therefore I generated a random number and passed that to a switch statement to get a pseudo-random character.

inputString():
	This function gave me a little more freedom, as from the rest of the program we can tell that it just need to at some point randomly generate a
	5 character string of "reset". To achieve this I decided to again use switch statement and random number generation to randomly pick one of either
	of the 4 letters(r, e, s, and t), and then put these 5 random letters into a string. This means that eventually the function will randomly produce
	the string "reset".
*/
