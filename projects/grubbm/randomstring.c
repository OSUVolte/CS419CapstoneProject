/* Max Grubb randomstring.c */


1. inputChar sets up an input array of the state-character pair characters and calls rand() to determine and return a random character 
2. inside of a for loop, inputString sets up an input array of the possible characters 'r', 'e', 's' or 't' and creates a 
character array of the possible 5 character combinations that can be made. 

A random character is created and then it is paired with the state counter, then the character array is run through until a match is found. 
Initially, I populated the entire arrays with the entire alphabet and special characters but the program would run for minutes without finding
an error and I terminated the program manually.  I believe eventually the program would halt, but it could possibly run on for too long of a time 
to be effective.
