/*
    File Name:      testme.c
    Author:         Marc Clinedinst
    Last Modified:  16 April 2016
    Description:    This file contains my code for the second quiz for OSU CS 362.  In this
                    assignment, we were to implement the inputChar and inputString functions
                    in a way that causes the error condition to arise.  I will explain my
                    implementation of these functions below, but I wanted to point out early
                    that my implementations require a fairly long run time in order for the
                    error to arise.  After I completed my implementation, I ran the program
                    10 times, and the average number of iterations before the program 
                    was in a state that caused the error to print to the screen was 
                    28577405 iterations.  This is because I am generating a random string
                    each time that the program runs.  It simply takes quite a while before
                    the string "reset" is generated from a random string generation.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
    Function Name:  inputChar
    Parameters:     None
    Returns:        A random character from the following set of characters:
                    "abcdefghijklmnopqrstuvwxyz([{}]) "
    Description:    This function generates and returns a random character from
                    the set:  abcdefghijklmnopqrstuvwxyz([{}]) ".  It does so by
                    storing that character set in an array, and then generating a
                    random valid index in the array.  Finally, it uses the generated
                    index to return a character from the set. 
*/
char inputChar() {
    char available_characters[] = "abcdefghijklmnopqrstuvwxyz([{}]) ";
    return available_characters[rand() % 33];
}

/*
    Function Name:  inputString
    Parameters:     None
    Returns:        This function returns a random, null-terminated, six-character
                    string that is built from the folloiwng set of characters:
                    "abcdefghijklmnopqrstuvwxyz([{}]) ".  
    Description:    This function begins by allocating a pointer to a character array 
                    that can hold six characters. Next, it loops five times, each time 
                    calling the inputChar function to store a random character in an 
                    appropriate index. Finally, it appends the null terminator at the 
                    end of the string.  Then the string is returned.
*/
char *inputString() {
    char *string = malloc(sizeof(char) * 6);
    int iteration;

    for (iteration = 0; iteration < 5; iteration++) {
        string[iteration] = inputChar();
    }

    string[5] = '\0';

    return string;
}

/*
    Function Name:  testme
    Parameters:     None
    Returns:        void
    Description:    This function is the function that is under test.  It relies on calls
                    to the inputChar and inputString functions.  Specifically, it loops
                    until it has achieved all 9 states and generates the null-terminated
                    string "reset" while in the 9th state.  In each iteration, the loop
                    generates a new character which may update the test's state, and
                    generates a new string.  Once the error condition is reached, the
                    word "error" is printed to the string and the program exits with a
                    status code of 200.
*/
void testme() {
    int tcCount = 0;
    char *s;
    char c;
    int state = 0;
    while (1) {
        tcCount++;
        c = inputChar();
        s = inputString();
        printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

        if (c == '[' && state == 0) state = 1;
        if (c == '(' && state == 1) state = 2;
        if (c == '{' && state == 2) state = 3;
        if (c == ' '&& state == 3) state = 4;
        if (c == 'a' && state == 4) state = 5;
        if (c == 'x' && state == 5) state = 6;
        if (c == '}' && state == 6) state = 7;
        if (c == ')' && state == 7) state = 8;
        if (c == ']' && state == 8) state = 9;
        if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' && s[4] == 't' && s[5] == '\0' && state == 9) {
            printf("error\n");
            exit(200);
        }
    }
}

/*
    Function Name:  main
    Parameters:     This function takes parameters representing the number and actual
                    arguments passed into the program via the command line.
    Returns:        This function returns 0 if the program terminates successfully.
    Description:    This is the main function of the program.  It simply seeds the random
                    unumber generator, calls the testme function, and returns 0 if the
                    function terminates successfully.
*/
int main(int argc, char *argv[]) {
    srand(time(NULL));
    testme();
    return 0;
}