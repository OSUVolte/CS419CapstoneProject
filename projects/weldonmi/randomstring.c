/*

Miranda Weldon
April 20, 2016
CS 362 Spring 2016
Random Testing Quiz
randomstring.c

The implementation of my random tester is to use two functions, inputChar() and inputString(), to give the testme function valid characters so that it will test while it runs. The first draft of the tester had inputChar pick a random number (0-8) and assign a character that testme would be looking for as one of the cases. The inputString function had it simply return "reset\0" as the output so that testme() would automatically be able to reach the code block that prints out "error ". This was deliberately made non-random so I could focus on inputChar(). Running this code a few times showed that the random generator for inputChar() was more likely to choose lower numbers than higher numbers, resulting in the state having a value between 4 and 6 for the longest time. Running gcov on this showed 96% line execution and confirmed this observation. It also showed that the final "return" in the main function can never be executed, likely because the final condition (about state equalling 9) inside the while loop exits the program before return gets the chance. 

The second draft includes a bias variable to correct the uneven distribution of rand(). Running gcov on this yielded 96.15% code execution but the distribution of did not change even after several variables within the valid range. The next draft got rid of the bias from inputChar function, but expanded the range of returnable characters. Running this shows even time within each state and the accompaning gcov document confirms that all the code that was used was used at with the same frequency. The only line that hasn't been used is the final return statement in main().

The fourth draft was devoted to updating inputString(). Originally I was going to use the same character range as in inputChar, but this didn't include the null terminator that's required for the testme function, so I decided to implement this function with a character array. The valid characters in this array are very limited as to allow the tester to have a reasonable chance of printing the error message. 

*/
