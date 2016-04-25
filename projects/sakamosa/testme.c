#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


char inputChar()
{
    // Generate a random character between 32 - 125
    char rand_char = (rand() % 94) + 32;
    return rand_char;
}

char *inputString()
{
    int n = 6;
    char *test_string;
    test_string = malloc(sizeof(char) * n);
    if(test_string == NULL){
        printf("no memory");
        return NULL;
    }
    char rand_string[n];
    int i;
    //Generate random lower case letters
    for(i = 0; i < n-1; i++){
        rand_string[i] = (rand() % 26) + 97;
    }
    rand_string[n-1] = '\0';
    strcpy(test_string, rand_string);
    return test_string;
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