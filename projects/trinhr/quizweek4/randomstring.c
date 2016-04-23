The interface are calls to a function.

The values the code is expected to handle for the random generation of
characters are from the pool of printable ASCII characters with values
of 32 to 126 except for the command delete.

inputChar() needs to generate values of: [,(, {,' ',a, x, },),] at mininum
in order to print the error message.

inputString() needs to generate the null terminated string: 'reset\0' at some point
when the state is 9.

The failure case is if both of these functions never generate the values that are
needed and the testme() is stuck in an infinite loop.
The pass case is if these functions are able to generate teh values that are needed and
the error message is printed.

For the test we need to at least that inputChar() and inputString() can even generate
the values that needs to be generated.

So we hardcode the range of the random input for a single character and check that
inputChar() is working correctly. The oracle will say that inputChar fails if after 
100,000 loops it can't generate the needed character and exit with a message and which
character it failed to generate. The oracle will say it passed if inputChar() was able 
to produce all the necessary values in the sequence necessary.


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

                if( loopCtr == 100000 ){
                        printf("Failure: Could not generate: testchar[%c]\n", testchar[i]);
                        exit(1);
                }
        }
        printf("Success:%c == testchar[i], After: %i\n",c,loopCtr);
    }
    return 0;

}

The same thing is done to check inputString, but instead for looking for it to generate 
the exact word it just needs to generate the necessary character at each index since the
probablity to randomonly output 'reset' as a word is very difficult.

int testString(){
    char testString[] = "reset";

    int stringlength = strlen(testString);
    int i;
    int loopCtr = 0;


    for( i = 0; i < stringlength; i++ ){
        char *s;
        s = inputString();

        while( testString[i] != s[i]){
                s = inputString();

                loopCtr++;

                if( loopCtr == 100000 ){
                        printf("Failure: Could not generate: %c at teststring index %i\n", testString[i]);
                        exit(1);
                }
        }
        printf("Success:%c == testString[i] at index %i after %i loops\n",s[i],i,loopCtr);
    }
    return 0;

}