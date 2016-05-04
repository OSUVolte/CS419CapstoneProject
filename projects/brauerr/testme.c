#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function to produce random values
    int r = rand() % 9;
    switch(r) {
      case 0:
        return '(';
      case 1:
        return ')';
      case 2:
        return '[';
      case 3:
        return ']';
      case 4:
        return 'a';
      case 5:
        return 'x';
      case 6:
        return '{';
      case 7:
        return '}';
      case 8:
        return ' ';
      default:
        return ' ';
    }
    
    return ' ';
}

char * inputString()
{
    // TODO: rewrite this function to produce random values
    int i = 0;
    static char randomString[6];
    int r = 0;
    for (i = 0; i < 5; i++) {
      r = rand() % 4;
      printf("%d", r);
      switch(r) {
        case 0:
          randomString[i] = 'e';
          break;
        case 1:
          randomString[i] = 'r';
          break;
        case 2:
          randomString[i] = 's';
          break;
        case 3:
          randomString[i] = 't';
          break;
      }
    }
    randomString[5] = '\0';
    return randomString;
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
