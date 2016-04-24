// Jake McMillen; mcmiljac@oregonstate.edu
// CS 362 - Quiz 2 (Random Testing)
// 24 April 2016

The function testMe() makes use of two inputs: a character and a string. Upon receiving particular character inputs, the function moves from state 1 to state 9 incrementally. Once it is in state 9, if the input string it receives is "reset", then an error message is generated.

The random tester for the function testMe() makes use of two functions to randomly generate different values for the two imputs that testMe() utilizes. The first, inputchar() generates a random integer in range 0-127 and returns corresponding ASCII char. Since it returns one of only 128 possible characters, the tester progresses the testMe() function through states 1-9 very quickly.

The second function of the random tester, inputString(), returns a pointer to a string of length 5 consisting of random lowercase letters. Although is would be possible to use longer strings or allow for more possible characters, I chose to use these restrictions due to the geometric growth of the number of possible strings as the length increases. As written, there are 26^5 = 11881376 possible return strings. At the rate the tester runs, this was typically generating the error message from testMe() in an average of around 10 minutes. Since no specific requirements for how long the tester would need to run were given in the quiz, I used my jugdement and chose this as an acceptable timeframe. By using a more powerful computer or if we are willing to run the tester for longer periods of time, we could increase the number of possible strings that inputString() would generate.
 