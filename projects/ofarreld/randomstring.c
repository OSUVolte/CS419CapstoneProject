/*

Name:
Course:
Date Created:
Last Modification Date:

Summary:
	Test Quiz 2 is an attempt to implement a random character generator and a random string.
	However, in order to achieve meaningful results, random must be handled in a realistic
	manner.

	inputChar():
	In order for inputChar() to meet the input criteria, a string with all testing characters
	was used, "({[ ax]})". Next, this a rand() call is made of length of the test character 
	string. This would treat the original string as an array. Finally, that specific character 
	was returned.

	inputString():
	According to the requirements of testme(), state [9] is looking for the string "reset". 
	Therefore a base string was created containing "rest". These are the four characters that
	make up "reset". They are randomly chosen to create a 5 character string. This random 
	string is returned.
	
	main():
	The library <unistd> is added. This is to allow for atoi() to be used.
	main() has been modified to allow for command line arguments of an int. This is in order 
	to set a seed for random testing. Now, the testing results can be standardized and return
	reliable findings.


*/
