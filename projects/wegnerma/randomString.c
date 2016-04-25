//Name: Marta Wegner
//CS 362 Quiz 2

random character generation: In the function inputChar(), I used 
	rand() to generate a random number between 21 and 126 which 
	correspond to the ASCII characters from ! to ~. This value is 
	retured from the inputChar() function and used for testing the 
	testme() function.
	
random string generation: In the function, inputString(), I 
	created an array of the characters r, e, s, and t. I used 
	rand() to generate a random number between 0 and 3 which 
	correspond to the characters in the array. This was done 
	five times for each of the characters in a five character 
	long string. The string was null terminated and returned
	from the inputString() function. 

For six executions of the test the number of runs needed to find 
the error were:
	1. 1365
	2. 1464
	3. 2006
	4. 2143
	5. 1544
	6. 5166	

Coverage:
	Lines executed:97.22% of 36
	Branches executed:100.00% of 52
	Taken at least once:98.08% of 52
	Calls executed:100.00% of 10 
