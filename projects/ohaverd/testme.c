#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    int num;
    char c;

    // rand is seeded in main so no need to seed here
    num = rand() % 9;

    if (num == 0) {
        c = '[';
    }
    if (num == 1) {
        c = '(';
    }
    if (num == 2) {
        c = '{';
    }
    if (num == 3) {
        c = ' ';
    }
    if (num == 4) {
        c = 'a';
    }
    if (num == 5) {
        c = 'x';
    }
    if (num == 6) {
        c = '}';
    }
    if (num == 7) {
        c = ')';
    }
    if (num == 8) {
        c = ']';
    }

    return c;
}

char *inputString()
{
    char ch1 = 'r';
    char ch2 = 'e';
    char ch3 = 's';
    char ch4 = 'e';
    char ch5 = 't';
    char ch6 = '\0';

    static char string[6];

    int i;
    int num;

    for (i = 0; i < 5; i++) {
        num = (rand() % (6 - 1) + 1);

        if (num == 1) {
            string[i] = ch1;
        }
        if (num == 2) {
            string[i] = ch2;
        }
        if (num == 3) {
            string[i] = ch3;
        }
        if (num == 4) {
            string[i] = ch4;
        }
        if (num == 5) {
            string[i] = ch5;
        }
    }

    string[5] = ch6;
    return string;
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
