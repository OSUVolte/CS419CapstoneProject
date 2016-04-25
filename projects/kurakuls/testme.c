#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    char characterChoices[] = {'{', '[', '(', ' ', 'a', 'x', ')', '}', ']'};
    int i = rand() % 9;

    return characterChoices[i];

}

char *inputString(char *s)
{

    char characterChoices[] = {'r', 'e', 's', 'e', 't'};

    int i = 0;
    int termPlace=0;
    for(i = 0; i < 5; i++)
    {
        int j = rand() % 5;
        s[i] = characterChoices[j];
        termPlace = i+1;
    }

    s[termPlace] = '\0';

    return s;

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
    s = inputString(s);
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
    int i;
    for(i=0; i<=10000; i++){
        printf("%i", i);
        testme();
    }
    // gcc -o testme testme.c -g testme.o
    return 0;
}