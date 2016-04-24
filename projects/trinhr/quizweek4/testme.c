#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function

    //Only obtain the printable characters from the ASCII table.
    //Range of printable charactes are 32-126(INCLUSIVE) 32 126
    int randNum = (rand() % 126 - 33) + 33;
    char randChar = (char) randNum;	
    return randChar;
}


int testCharacter(){
    char testchar[] = "[({ ax})]";
   
    int charlength = strlen(testchar);
    int i;
    int loopCtr = 0;


    for( i = 0; i < charlength; i++ ){
	char c = inputChar();

	while( testchar[i] != c){
		c = inputChar();
		
		loopCtr++;
		
		if( loopCtr == 1000000 ){
			printf("Failure: Could not generate: testchar[%c]\n", testchar[i]);
			exit(1);	
		}
	}
	printf("Success:%c == testchar[i], After: %i\n",c,loopCtr);
    }
    return 0;

}
char *inputString()
{
    // TODO: rewrite this function
    //Length for the random string: 5 characters because of reset.
    int length = 5;
    //Allocate a character array for that length.. CAn't forget the null terminator.
    char *randString = malloc( sizeof(char) * length + 1 );

    //Generate a random character for the length of the string.
    int i;
    for( i = 0; i < length; i++){
        int randNum = (rand() % 26) + 97;
        char randChar = (char)randNum;
    	randString[i] = randChar; 
    }

    randString[5] = 0; 
	
    return randString;
}

int testString(){
    char testString[] = "reset";

    int stringlength = strlen(testString);
    int i;
    int loopCtr = 0;

    for( i = 0; i < stringlength; i++){
	char *s;
	s = inputString();

	while( testString[i] != s[i]){
		s = inputString();

		loopCtr++;

		if( loopCtr == 100000 ){
			printf("Failure Could not generate: %c at teststring index %i\n", testString[i]);
			exit(1);
		}

	}
	printf("Success:%c == testString[i] at index %i after %i loops\n", s[i], i, loopCtr);
	}
	return 0;

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
    if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' && s[4] == 't') exit(1);
    } 
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testCharacter();
    testString();
    //char *s = inputString();
    //printf("%s\n",s );
    //testme();
    return 0;
}
