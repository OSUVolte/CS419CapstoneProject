// Diana O'Haver
// randomstring.c
// Random Testing quiz

/*

inputChar was simple to implement as it required calling rand() to generate a number between 0 and 8,
and then a series of if statements to determine which char would be returned. It could have been made even
more random by testing against the full ASCII table, but per the lecture materials, it didn't seem to offer
an advantage to include test cases that were outside the scope of the program.

inputString was similarly implemented, though I found that if I truly randomly assigned characters to each
of the 6 spots in the string that was returned, it took exponentially longer for the program to find the error
message. A solve for this was to randomly assign the letter characters, and fix the null terminator as the last
spot in the character array.

The program finds the error message by barraging the testme() function with randomly chosen characters from
inputChar until the correct series has been met to bring the state to 9. At that point, the values in the char
array returned from inputString become the focus of the testing. Once the char array becomes randomly assigned
to the series 'reset', all conditions of the error test are met and the error message can be output.
