/*
Behnam Saeedi
Saeedib
932-217-697
Random String writeup:

	For generating the character we have a gate that could be any number from 0 to 20
when gate is 1, we select a number from 0 to 512 (including invalid characters) and cast it to char
when it is any other number we take a number from 32 to 127 and cast it to char (without special characters)
then we return the character

	for generating the string we generate a limit for our length at random from 1 to 64

	then we generate a length from 1 to limit

	after that we call the inputChar to generate a random character for us and in a for loop we
occupy the string.

	then at the end of the loop we put the '\0' (Null) terminate  as the last member of the string to end
the string properly.

	after that we return the address of the dynamically allocated character array.

Important information:
	- You can set len to 6 to increase your chance of getting the "error"
	- You can use the luck variable that goes from 0 to 6 to increase your luck of getting error
	- I added a free function to testme() make sure i return the dynamically allocated memory to heap

*/
