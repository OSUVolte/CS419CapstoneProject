#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    int num = (rand() % 9);
	switch(num) {
		case 0: return '['; 		
		case 1: return '('; 
		case 2: return '{'; 
		case 3: return ' '; 
		case 4: return 'a'; 
		case 5: return 'x'; 
		case 6: return '}'; 
		case 7: return ')'; 
		case 8: return ']'; 
	}
    return 0;
}

char *inputString()
{
    char myString [] = "rrrrr";
	for (int i = 0; i < 5; i++) {
		int num = (rand() % 4);
		switch(num) {
			case 0: myString[i] = 'r';
			  break;
			case 1: myString[i] = 'e';
			  break;
			case 2: myString[i] = 's';
			  break;
			case 3: myString[i] = 't';
		}
	}
	char* myCharStar = myString;
    return myCharStar;
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
