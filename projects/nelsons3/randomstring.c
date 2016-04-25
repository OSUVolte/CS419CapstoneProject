/*
*Sam Nelson
*362 - Quiz 2
*companion file testme.c
*/

/* 
For the code to produce an error, the following have to happen in order;c == to [ forcing the state to 1, c==( forcing the state to 2, c=={ forcing the state to 3, c==space forcing the state to 4
c==a forcing the state to 5, c==x forcing the state to 6, c==} forcing the state to 7, c==) forcing the state to 8, c==] forcing the state to 9, and then the program has to iterate until it finds a random string of reset.  At this point it can print the error.  The first 9 steps won't repeat after state has been set to 9 but the last step will repeat.   

As shown below, inputChar returns an int to a char c.  This casts the int as a char..specificially it turns the int into an ascii char.
inputChar() uses the stdlib so that it can use rand().  rand is bound by 0 and 95 to get a number.  To this random int that it selects we add 32 effectively forcing our random int to be between 32-127.
This forces the ascii to include most of the special characters (all the ones we need) and both alphabets.  
    //cast int to char...this converts the int to an ascii char
    c = inputChar();
    char inputChar()
    {
        //returns a list of 63 potential characters starting with ascii decimal 32 and going until 127
        return (rand() % 95) + 32;
    }
    
    Inputstring() will return a string of 6 characters with the 6th character always being the null character '\0' per the specifications.  The 5 elements prior to the 6th will all be random characters.  The computer will select these from an array with the contents of 'r' 'e' 's' 'e' 't' for simplicity.  Additionally, it is probably un important that we test other characters as we are trying to trigger
    the error message and this requires hitting the keyword 'r' 'e' 's' 'e' 't' '\0'.  The function accomplishes this by having two arrays both of length 6, one prepopulated with reset and the other empty to fill.  It will randomly select an int between 0 and 5 each itereation and then it will grab that element out of the pre populated array and set the i'th element in the empty array == to that element.  Eventually (normally within 1800 tries) we get the empty array to be == to reset.  This is what we want.  In fact, out of 10 runs, the average length of tries it took to get reset was 1300 itereations.
            for(counter=0; counter<5; counter++)
            element = rand() % 5;
            testString[counter] = alpha[element];
            //out of loop
            testString[5] = '\0';
            
*/