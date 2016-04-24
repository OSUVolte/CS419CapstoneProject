/* Alisha Crawley-Davis
 * CS 362 Quiz 2
 * 4/22/2016
 * Assignment: Implement a random tester for the function testme() that is
 *             capable of printing the error message.
 *             Implement inputChar() and inputString() to produce random
 *             values.
 *
 * Note code is modified from class examples and internet resources 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/* Desciption: inputChar() will return a random character from a..z or []{}() or ' '
 * Parameters: none
 * Returns: a random character from a..z or []{}() or space
 */
char inputChar()
{
    char ranChar = "abcdefghijklmnopqrstuvwxy z(){}[]"[random () % 33];
    return ranChar;
}

/* Description: inpuString() will return a random 5-character string of lower case letters
 * Parameters: none
 * Returns: a 5-character string of lower case letters ending with the null terminator
 */
char *inputString()
{
    int i;
    static char ranString[6];
    for (i = 0; i < 5; i++)
    {
      ranString[i] = "abcdefghijklmnopqrstuvwxyz"[random () % 26];
    }
    ranString[5] = '\0';
    return ranString;
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
