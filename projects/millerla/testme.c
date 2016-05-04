#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//returns a random char in the range of "[" to "}" ASCII and space
char inputChar()
{
	int lowerlimit = 91;//ASCII "[", the lower limit of characters that might be generated
	int upperlimit = 125;//ASCII "}", the upper limit of characters that might be generated
	int randomint = lowerlimit + rand()%(upperlimit-lowerlimit+2);//int of char to be returned plus one for the space
	if(randomint == upperlimit + 1) {
		randomint = 32;//the ASCII space
	}
	char randomchar = (char)randomint;//the char to be returned

    return randomchar;
}

//returns a string of random characters from inputChar of length 10
char *inputString()
{
	int stringmax = 10;//the maximum number of characters in the string
    int stringsize = 1 + rand()%stringmax;//the number of characters in the string returned 	
	char* randomstring = malloc((stringsize+1)*sizeof(char));//the string to be returned
	int i;
	
	for(i = 0; i < stringsize; i++) {
		randomstring[i] = inputChar();
	}
	randomstring[stringsize] = '\0';
	
    return randomstring;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  int lowerchar, upperchar, space, slength;// for tester
  
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
	
	//tester for Random Testing Quiz 2 - start
	
	//testing that all necessary chars for the state conditions would be printed
	
	if(c == '[') {
		lowerchar = 1;
	}
	
	if(c == '}') {
		upperchar = 1;
	}
	
	if(c == ' ') {
		space = 1;
	}
	
	//testing that s may be of length 5
	if(s[5] == '\0') {
		slength = 1;
	}
	
	if(upperchar == 1 && lowerchar == 1 && space == 1 && slength == 1) {
		state = 9;//setting the state directly
		s = "reset\0";
	}
	
	//tester for Random Testing Quiz 2 - end
	
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
