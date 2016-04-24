/******************************************************************************
 * Filename: testme.c
 * Author: Jens Bodal
 * Date: April 24, 2016
 * Description: Implement a random tester for the function testme() in testme.c that is capable of printing
 * the error message in testme().  
 * inputChar() and inputString() produce random values from the characters in POSSIBLE_CHARS 
 *****************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar() {
    char characters[] = "{}[]() axrest";
    // return random character from characters
    return characters[rand() % strlen(characters)];
}

char *inputString() {
    int strlen = 6;
    char *string = (char*) malloc(sizeof(char) * strlen);
    int i;  // for loop

    for (i = 0; i < strlen - 1; i++) {
        // grab random character
        string[i] = inputChar();
    }
    
    // null termminate string
    string[strlen-1] = '\0';
    return string;
}

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
        if (s[0] == 'r' && s[1] == 'e' &&
            s[2] == 's' && s[3] == 'e' &&
            s[4] == 't' && s[5] == '\0' &&
            state == 9) 
        {
            printf("error \n");
            exit(200);
        }
    }        
} 


int main(int argc, char *argv[]) {
    srand(time(NULL));
    testme();
    return 0;
}