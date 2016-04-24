/*

randomtest.c - Jordan White 4/23/16 CS 362

inputChar() 

* Returns random chars from 32 (space) to 126 (~).
* This will eventually return all the charactes that testme() checks for when changing states
* The end result is that testme() will eventually always move from state 0 to state 9

inputString()
* In the interest of time this only returns 5 char strings made of lowercase letters 
  so that the string will eventually equal 'reset' in a resonable amount of time
* This will result in returning the string "reset" once in ~12 million tests (26^5) (when in "state 9").
* The sting equalling 'reset' is required to meet the error condition

*/
