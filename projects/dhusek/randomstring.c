//
//  randomstring.c
//  Kristen Dhuse
//
//  Description: Implement a random tester for the function testme() in testme.c
//  that is capable of printing the error message.  You should implement inputChar()
//  and inputString() to produce random values. Write up the development of your
//  random tester and how it finds the error message as randomstring.c. Submit
//  testme.c and randomstring.c under your onid directory in class github.
//  (under your onid directory and not under dominion directory).
//

/*
 I implemented inputChar() to return a random ASCII character between ' ' and '~'
 inclusive.  This was sufficient to increment the state to 9 by the 348th iteration.
 Then, in order for the error message to be printed, inputString() needed to return
 'reset\0'.  This was a little harder because the probability that the letters 
 r-e-s-e-t are going to be chosen randomly and in that order is much smaller than
 just returning a certain character randomly as was required to increment the state.
 I increased the probability that this would happen by always generating a 6 character
 string with the last character being '\0'.  It was still taking a really long
 time to randomly generate the correct string so I narrowed the pool of characters
 that could randomly be chosen to the set of lowercase alpha characters.  When I 
 did this, the error message was printed as fast as iteration 419065, but most of
 the time it took well over 2 million iterations to print the error message!
*/