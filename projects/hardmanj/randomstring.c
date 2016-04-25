Requirments: Implement a random tester for the function testme() in testme.c that is 
			 capable of printing the error message.  You should implement inputChar() 
			 and inputString() to produce random values.

Context: From a black box perspective inputChar() and inputString() should generate 
		 take any char or any string. However skimming through testme() and how they
		 are used I can tell that testme() is looking for a char from inputCHar() that
		 is any one of characters in the array of '[', '(', '{', ' ', 'a', 'x', '}', ')',
		 ']', and a string made up of the characters 'r', 'e', 's', and 't'.
		 
		 Also since the c string s is referencing up to s[5] with it being the null terminator
		 the inputString function is expected to create a string of 6 character including the 
		 null terminator.
		 
Process: While I could implement a completely random character generator for any ASCII character on
		 inputChar() and inputString() it is clear that the testme() will just ignore it, making it not
		 very helpful inputs. Also I could make the size of the string any size, but by the implementation
		 of testme(), anything less than 6 characters will segfault and more than 6 will only add runtime 
		 and will be ignored.
		 
		 Therefore the restraints of our input domain are the characters: 
		 '[', '(', '{', ' ', 'a', 'x', '}', ')', ']', 'r', 'e', 's', 't' 
		 and and input string of length 6.
		 

testme(): The function is a continous loop with each iteration getting a new character and a string from the
		  functions I provided. After getting new inputs, each iteration goes down a list of if statements which
		  ultimately checks the single character and pushes the state variable to the value 9. Note once the state 
		  is pushed to the next (say from 1 to 2), it cannot go back (from 2 to 1). So as we input random single 
		  characters, it very quickly pushes the state value to 9. Once the state is 9, then the only thing preventing
		  the function from getting the error code is getting the string "reset" which has a very low chance of randomly
		  generating. However once inputString provides the string "reset", then it satifies the if statment and prints error
		  with exit code 200.