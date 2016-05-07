//quiz 2
/*
Description: Implement a random tester for the function testme() in testme.c that is capable of printing the error message.
You should implement inputChar() and inputString() to produce random values.
Write up the development of your random tester and how it finds the error message as randomstring.c.
Submit testme.c and randomstring.c under your onid directory in class github. (under your onid directory and not under dominion directory).
*/

//TO COMPLIE THE FILE RUN
//gcc -o testme testme.c

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//this function is implemented using the refference below:
//http://stackoverflow.com/questions/19724346/generate-random-characters-in-c

char inputChar(){
    //this would work with any encoding (including EBCDIC, ASCII, UTF-8, ISO-Latin-1)
    //....where each A...Z letter is encoded by a single char.
    //srand(time(NULL));
    char randomletter = "abcdefghijklmnopqrstuvwxyz[]() {}"[random () % 34];
    return randomletter;
}


//this function is implemented using the refference below:
//http://codereview.stackexchange.com/questions/29198/random-string-generator-in-c
char *inputString() {

    static char charset[] = "abcdefghijklmnopqrstuvwxyz\0";
    char *randomString = NULL;

    if (5) {
        randomString = malloc(sizeof(char) * (5 +1));
        if (randomString) {
            int n;
            for (n = 0;n < 5;n++) {
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[5] = '\0';
        }
    }

    return randomString;
}


void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1){
    tcCount++;
    c = inputChar();
    //LENGTH IS SET TO 6
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
      free(s);
      printf("error ");
      exit(200);
    }
    free(s);
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
