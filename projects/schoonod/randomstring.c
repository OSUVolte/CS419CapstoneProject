//
//  randomstring.c
//  Random Testing Quiz 2
//
//  Created by Dane Schoonover on 4/24/16.
//  Copyright © 2016 dane. All rights reserved.

/*

 Result: Iteration 104: c = x, s = reset, state = 9

 inputChar(): Here I made a string with the characters required to trigger all of the 'if'
 conditions related to the char 'c' in testme(), created a random number between 0 and its
 length(9), then returned the string at the random index.
 
 inputString(): Here I made a string with the characters required to trigger true all of
 the && operators in the last 'if' conditional in testme(), started a while loop,
 created a random number between 0 and its length(5), then inserted a random character
 into the string and returned the string once it was full.
 
 testme() then made calls until the correct ordering of characters were received by
 calls to inputChar() and inputString(). Surprisingly, the error message was found within
 104 interations. I think this was just luck though, b/c the next run took 1417
 iterations.
 
*/