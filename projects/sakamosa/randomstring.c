Random Testing Quiz 2

inputChar() returns a random char in the ASCII range of 0 - 127 which includes all of the characters checked for in the testme function.
After multiple runs, it is equal to each of the chars needed to progres to the 9th state.

inputString() returns a pointer to a string of length 6. In true black box testing, I would have generated random size strings but with the time-outs on flip, I decided to narrow it down to just the error-producing length.
The string composed of random lower case letters. Again, I would have like to use a larger range of characters but was unable to generate the error with more 'random' testing.

Once state is equal to 9. The error code will be generated if inputString() returns 'reset\0'.