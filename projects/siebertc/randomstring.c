/*

Author: Charles Siebert
Class:	CS362-400
Date:	4/24/16 
File:	randomstring.c

Description: This file contains development process and thoughts in creating a random
	test function, testme.c. The functions are inputChar() and inputString().
	
main(): To get the perror at the end, the conditional statement is:
	if (s[0] == 'r' && s[1] == 'e'
		   && s[2] == 's' && s[3] == 'e'
		   && s[4] == 't' && s[5] == '\0'
		   && state == 9)
		   
	based on a return string, being called by inputString(), returns a string "reset\0"
	and under the condition that state == 9. The only way to increase the given state, is
	by all the prior conditions leading up to it.
	
	if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
	
	...
	
	if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
	
inputChar(): the function I made simply returns a random number between 0-9 that references
	the input char call by c = inputChar().
	The array to satisfy the conditional statements are put in array at a size of 10,
	and will reiterate when state and char DO NOT match up. Only when the proper returned
	char will increase the state.
	
	Each conditional statement has a 1/10 chance for c to return the proper value, and there's 9 checks.
	
inputString(): the function I made is similar to inputChar, except it will store the array values of the
	string "reset\0" and make a new string, iterating from 0-5, to input a random value from the string
	"reset\0".
	
	once the string is finished being concatonated, it will return to main() and test against
	the final value when state == 9 (only time the inputString truly is necessary). This will not
	satisfy the condition if it is solved prior to reaching state == 9.
	
	The chance to properly concatonate inputString == "reset\0" is based on a 1/5 chance nearly for
	the first 5 array iterations. positions for 'e' has a slightly higher chance, as 'e' occurs twice
	in the given array to look in. This results in a larger amount of iterations for state == 9.
	
	My program ended around 700-900 iterations normally, sometimes higher and lower, to produce "reset\0"
	
*/