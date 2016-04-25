/*
Ben Beckerman
4/24/16
Quiz 2

The first step of my development process was to read through the completed parts of the source code of test me. After examination, I saw that it required two functions -- one to generate a random character, and one to generate a random word. The random character was used to increment a counter, and the random word was used when the counter reached 9. If that random word matched the trigger word, 'reset', the program would exit with the error message.

For inputChar, I used the rand() function to generate a pseudo random number in the range of 20 - 126, which is the range of ascii printable characters. The character is then returned to the main function, where after enough iterations, the counter reaches 9. For the inputString method, I also used the rand() function to generate a random number, but in this case limited the range to lower case letters, so that the output was a word.

Then running the main function, we can eventually trigger the error condition. First the counter must be incremented enough to change the program 'state' to where an error is possible. Then when the inputString method produces the string 'reset', the error is thrown. The first run through triggered the error afer 23051394 iterations, and the second after 11006481, indicating the high number of random repetitions necessary to trigger some obscure errors, and thus the value of using random testing.
*/
