/*
*  Alex Marsh
*  CS362  Quiz 2
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    //get a random character 
    //58 possible characters that meet preconditions
    char possibleChar[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz {}[]()";
    int randNum = rand() % 59;
    char randomChar = possibleChar[randNum];
    return randomChar;
}

char *inputString()
{
    int i;
    char randChar;
    //create possible characters
    char possibleChar[] = "reset";
    
    //create string
    char *randString = malloc( sizeof(char) * 6);
    
    //randomly assign letters from possibleChar 
    //to positions in randString
    for(i=0; i < 5; i++){
        //get random number
        randChar = rand() % 5;
        //assign letter in possibleChar to string
        randString[i] = possibleChar[randChar];
    }
    
    
    //set the end of the string to '\0'
    //end of string will always be '\0'
    randString[5] = '\0'; 
    
    //return random string
    return randString;
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
