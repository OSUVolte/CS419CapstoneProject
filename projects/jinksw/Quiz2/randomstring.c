/*
	Random Tester for testme.c

	implements: inputChar() and inputString() to produce random values

	inputChar()
	This function generates 1 of 9 of the random characters required to increment state. 
	I just used a character array of those 9 characters to speed up the time to get the error message printed. 
	By using all characters, we could slow down the time required to get the error message.

	inputString()
	This function creates a 6 char array withe the first five characters being randomly selected from the 'a-z' inclusive. 
	Char 6 is the null terminator because we want string represenation.
	Assuming we knew the string that would cause an error, then we could have our random characters to select from be 'rest', but this is unlikely in the real world.
	I used this to test that the error would print. 
	We could also include capital letters if we wanted to make our testing more robust. 
	We would probably need to test combinations of upper and lower case letters, spaces, numbers, strings, and 
	other characters in the real world to have robust testing if we wanted to find possible strings that could 
	cause an error.  


*/
