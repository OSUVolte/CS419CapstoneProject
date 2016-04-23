randomstring.c

inputChar() Implementation

	Once invoked, inputChar() randomly returns values from 32 to 125.  This range covers all the printable ascii values from space, to punctuations, lower case, and upper case letters.  As a random character matches a condition in testme(), the 'state' variable is incremented. Once the state variable is incremented to the value 9, the string variable 's' takes over to reach the final condition.  inputString() function randomly generates 's', which is a 6 character string, not including the null character.

inputString() Implementation

	In its initial implementation, inputString() randomly returns a set of 5 characters from 97 to 122, which are the set of lower case alphabets.  However, this requires an unreasonable amount of computation time and the number of iterations exceed +10^7 (see results below). Therefore, I have confined random generations of characters from the set {e,r,s,t} since the error message, "reset" is made up of these characters. Array position 6 or s[5] is manually null terminated.

Results

	Five tests are simulated and the number of iterations have been recorded. They are as follows:

	Simulation-# of iterations

	random range [97,122]
	1:30953709
	random range from {e,r,s,t}
	1:5356
	2:1993
	3:4404
	4:3501
	5:1795


