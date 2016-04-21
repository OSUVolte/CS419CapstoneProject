/*
William Maillard
Quiz 2
4/21/16
CS 362

I developed the random tester by first returning any random ASCII character value from the 
inputChar() function and a string of any length  up to 509 characters (the string literal max
for C89) and containing any ASCII characters from the inputString() function.  I realized very quickly 
that the input domain for these random characters and strings was extremely large and would probably 
not find the bug in any reasonable amount of time (the probability of finding the bug was 
1 in 509 * 128^(5)).  Based on this fact, I inspected the testMe() function and decided to 
limit the input domain to type-able characters from inputChar() and null-terminated lowercase latin
character strings of length 6 from inputString().  This reduced the probability of finding the
bug to about 1 in 26^5 (or 1 in 11,881,376) and the program was able to find the bug
within 10,906,135 iterations.
*/