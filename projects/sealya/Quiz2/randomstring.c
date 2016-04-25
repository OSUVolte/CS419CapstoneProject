/*
Aaron Sealy
Quiz 2
CS 362
Spring 2016


1 - In  inputChar(), I generated and returned a random char (ASCII value between 32 and 127).

2 - In inputString(), I made a char * variable (st) and then used a for loop with 5 iterations
    in which a random letter is assigned to st[i].  The terminator is added at st[5] and st is
    then returned.

3 - The random results returned by inputChar() and inputString() will eventually generate the
    random results necessary to print the error message.  First, state must equal 9, and this is
    achieved when  '[' , '(' , '{', ' ', 'a', 'x', '}', ')', and then ']' are returned by inputChar().
    This runs very fast, since the desired results do not need to be returned as a string.

    Almost all of the testing time was used waiting for inputString() to randomly return the string
    "reset."  When I ran the program, it took more than 5 million iterations before the error message
    was printed.

    Results:
    Iteration 5461398: c = 4, s = eyqlr, state = 9
    Iteration 5461399: c = B, s = reset, state = 9
    error
    Process returned 200 (0xC8)   execution time : 1920.621 s
    Press any key to continue.

4 - Yes, I am aware that I could have made the test much faster by only randomly selecting from
    ([, (, {, ' ', a, x, }, ), ]) for inputChar() and from only ("r", "e", "s", "t") for inputString().
    I went the long way to (a) get some practice with more extensive testing, and (b) to make a more
    robust test that can easily test for other error-producing strings without having to change the
    two modified functions.


*/

