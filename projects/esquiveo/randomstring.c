Osbaldo Esquivel
CS 362
Random Testing Quiz 2

There are two functions in testme.c that produce a string and char: inputString() and inputChar(). The program will loop through until the string is "reset\0". Then, the function will print the error message, "error" and exit with the value 200.

The inputString() function will generate a random string using the four chars held in the validStr[] array. Then, the function will add a null terminator to the end of the string. This function will be called in the testme() function and if the string matches "rest\0", testme() will print the error message and exit.

The inputChar() function is fairly simple and generates a random number from 0 to 8. Then, a char from an array of valid chars is returned. This function is also called in the testme() function to set a char value for setting the state.