/* Andriy Solovyov
 * CS 362
 * April 24
 * testme.c
 * Quiz 2 Description:
	             Implement a random tester for the function testme() in testme.c that is capable of printing the error message.  
                     You should implement inputChar() and inputString() to produce random values. Write up the development of your 
                     random tester and how it finds the error message as randomstring.c. Submit testme.c and randomstring.c under 
                     your onid directory in class github. (under your onid directory and not under dominion directory).
*/

   





#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    
    // here we have 7 characters and 2 letters
    char charArr[]= {'a', 'x', ' ', '[', '{', '(', ')', '}', ']'};
    int size1 = sizeof(charArr)/sizeof(char);
    //random number selected to correspond with a char index
    int rand1 = rand()%size1;  
    return charArr[rand1]; //returns number of selected random index

    
}

char *inputString()
{
    char charArr[] = {'r', 'e', 's', 't'};
    char *strArr = (char*)malloc(sizeof(char) * 6);
    int size1 = sizeof(charArr)/sizeof(char);

    int i;
    for (i=0; i<5; i++){
     int rand1 = rand()%size1;
     strArr[i] = charArr[rand1];
   	}

    strArr[5] ='\0'; //null terminator
    return strArr;
   
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
    if (c == ' ' && state == 3) state = 4;
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