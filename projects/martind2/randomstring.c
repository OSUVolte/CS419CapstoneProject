/* Random Testing Quiz 2 write up
 * By Dave Martinez, martind2@oregonstate.edu

	I created a random number generator that generated
	numbers from 0 to 32. This random number generator
	was used insid the inputChar() function, which returned
	lowercase letters, braces, brackets, parens or space,
	depending on the random number.

	My inputString() function first allocated new memory
	for a c-string of length 6. It set the first five 
	characters using the inputChar() function and set
	the last character to null.

	I also added a statement to free the allocated 
	memory at the end of the testme() function.

	From here, I simply ran the program. On my first
	try, it took 6994841 iterations to find 'reset'
	under state 9. Here's a list of iterations
	and tries:
		* 1: 6994841
		* 2: 12944823
		* 3: 49039775
		* 4: 72882242
		* 5: 3504362

	To execute the program, simply type 'make'

*/