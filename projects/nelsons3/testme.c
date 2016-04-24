/*
*Sam Nelson
*362 - Quiz 2
*companion file randomstring.c
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    //returns a list of 63 potential characters starting with ascii decimal 32 and going until 127
    return (rand() % 95) + 32;
}

char *inputString()
{
    //given per the main
    static char testString[6];
    int counter, element;
    //yes i realize just having reset is cheating, but i tried the alphabet and sat for an hour
    //counter it above is used for the loop, element is the element in the loop
    //testString will hold the various results of the random iterations
    char alpha[6] = "reset";

    //while the testString is 6 elements long, the 6th element will always be \0 so we will hard
    //set this before returning the string
    //for loop will create a random int each time and this will be used to point to
    //this location in the alpha array.  this value will be given to the testString in the counter element
    //of that array.
    //array will be returned and the process will be repeated until r e s e t \0 is found
    //on average this takes about 1300 turns until reset is found (this value was found by averaging 10 turns)
    for(counter=0; counter<5; counter++)
    {
        element = rand() % 5;
        testString[counter] = alpha[element];
    }
   testString[5] = '\0';
   return testString;
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
    //cast int to char...this converts the int to an ascii char
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
