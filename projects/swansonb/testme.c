#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// declared globally to avoid thrashing heap during execution
char* stringBuffer = 0;

char inputChar()
{
    const int ASCII_RANGE = 256;
    return rand() % ASCII_RANGE;
}

char *inputString()
{
    const int STRING_SIZE = 5;

    if (!stringBuffer){
        stringBuffer = malloc(STRING_SIZE);
    }
    char *cur = stringBuffer;
    while (cur - stringBuffer < STRING_SIZE){

        // First test 5 char string generated as combination of all 256 chars
        //*(cur++) = inputChar();

        // Second version of test generates 5 char lower case alpha string
        //*(cur++) = rand()%('z'-'a'+1) + 'a';

        // Third version of test generates 5 lower case alpha with
        // with a 5% chance to choose a value from entire ASCII range
        int bias = rand()%100;
        if (bias < 5) {
            *(cur++) = inputChar();
        } else {
            *(cur++) = rand()%('z'-'a'+1) + 'a';
        }
    }
    *cur = 0;
    return stringBuffer;
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
