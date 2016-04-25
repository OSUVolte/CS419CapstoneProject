/**********************************
 * How inputChar() works:
 * 	It finds a random integer between 32 (the ASCII value for
 *	a space) and 125 (the ASCII value for a right bracket) and returns
 *	its char value. Because these represent the lowest and highest
 *	characters required to advance in state (with all others in between
 *	those values), this will increase the chances that the state gets
 *	to 9.
 *
 * How inputString() works:
 *	It allocates enough memory for a 5 character string, plus an extra
 *	allocated char for the null-termination character. Then, it iterates
 *	through all the even digits (0, 2, and 4), assigning those a random
 *	character value between r and t. Since that encompasses only 3
 *	characters, there is a relatively good chance of this. Finally, it
 *	iterates through all the odd digits (1 and 3), assigning those a
 *	random lower-case letter, making the likelihood that it will hit an
 *	'e' approximately 1 in 26 for each. 
 *
 *
 * ********************************/
