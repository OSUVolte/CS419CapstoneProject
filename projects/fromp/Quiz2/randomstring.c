/**********
Development of inputChar() and inputString()

Since the testme function expect c to be a single character and s to be a string of 5 character, inputChar() and inputString() will produce randomly generated characters and strings (respectively) of those lengths.

inputChar and inputString were designed to produce a wide range of random content that could potentially trigger an error in testme(). As this is designed to test a large number of potential cases, I felt is important to create a large number of possibly valid variables.

For inputChar, a random ASCII code between 32 (the code for space) and and 126 (the code of ~) was produced and cast to a char before being returned. For inputString, a string with five random lowercase characters was produced and a string terminator ("\0") was appended to the string. 

The error message is found when state equals 9 and the string returned from inputString is "reset," an event which can take a large number of iterations to occur.
For exmample, the number of iterations that it took testme to trigger the error message is presented below for 10 runs of testme. As you can see, the number of iterations required to randomly find the error varied widely.

Test run 1:  1674751
Test run 2:  27550729
Test run 3:  882224
Test run 4:  6031155
Test run 5:  31822102
Test run 6:  688131
Test run 7:  17459435
Test run 8:  5429067
Test run 9:  19026862
Test run 10: 16725260

*******/
