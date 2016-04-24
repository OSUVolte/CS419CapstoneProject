#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    
    char randChar; //Will be a randomly generated char
    char possibleChar[34] = "abcdefghijklmnopqrstuvwxyz[](){} "; //The possible characters that can be randomly selected.
    
    //Chooses a character from the possibleChar array at random.
    int randomizer;
    randomizer = 0 + rand()%33;
    randChar = possibleChar[randomizer];
    
    return randChar;
}

char *inputString()
{
    // TODO: rewrite this function
    
    char possibleChar[5] = "reset";
    char zero, one, two, three, four, five;
    
    zero = possibleChar[(rand() % (5))];
    one = possibleChar[(rand() % (5))];
    two = possibleChar[(rand() % (5))];
    three = possibleChar[(rand() % (5))];
    four = possibleChar[(rand() % (5))];
    five = possibleChar[(rand() % (5))];
    
    char *returnString = (char *) malloc(sizeof(char) * 5);
    
    returnString[0] = one;
    returnString[1] = two;
    returnString[2] = three;
    returnString[3] = four;
    returnString[4] = five;
    returnString[5] = '\0';
    
    return returnString;
}

void testme()
{
    int tcCount = 0;
    char *s;
    char c;
    int state = 0;
    while (1)
    {
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
        if (s[0] == 'r' && s[1] == 'e'
            && s[2] == 's' && s[3] == 'e'
            && s[4] == 't' && s[5] == '\0'
            && state == 9)
        {
            printf("error ");
            exit(200);
        }
    }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}