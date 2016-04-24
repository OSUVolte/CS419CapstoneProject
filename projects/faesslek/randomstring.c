/******************************************************************************
 * Author: Kelby Faessler
 * Class: CS162
 *
 * My implementation of a random tester for the testme() function:
 *
 * Step 1: Understand the function being tested. This function transitions 
 *         through various "states" as it gets certain inputs. It does not 
 *         transition to state x until it has previously transitioned to state
 *         (x - 1). It starts at state 0 and the maximum state it can reach is
 *         state 9. We can only ever hit the error condition if we're in state
 *         9 so clearly our tester must make this function transition through
 *         all of the states in order. Once the function has transitioned to a
 *         state it can never go back to a previous state. This makes our job 
 *         easier and I'll talk about why that is later. Transitioning to a 
 *         new state is dependent on what state you're currently in and what
 *         the character input is. So, as long as we provide the right 
 *         character inputs we will eventually transition through all the
 *         states. Once we reach state 9, we hit the error condition if the 
 *         string input is equal to 'reset'.
 *
 * Step 2: Writing the character input function. The first character needed
 *         to transition to state 1 is '['. The next character needed is '('.
 *         It goes on like this. Since we can never go backwards in state, 
 *         that means as long as we eventually provide the '[' input we will
 *         eventually enter state 1. The same is true for '(' and state 2. 
 *         If the state got reset on a bad input and we could go backwards
 *         in state, then we would have to provide the '[' input and 
 *         immidiately afterwards we'd have to provide the next '(' input.
 *         So if our chance of getting either input was 1/10, then our chance
 *         of getting the correct first input followed by the correct second
 *         input would be (1/10) * (1/10) or 1/100. You can see how this 
 *         would be problematic with 9 inputs. My implementation of the 
 *         inputChar() function generates a random number between 0 and 8 
 *         and based on that returns one of the 9 characters the testme() 
 *         function is looking for. So if I start in state 0 I might first
 *         get the correct character needed for state 5, but eventually I 
 *         will get the one needed to go to state 1. To make this more robust
 *         I could return not just the characters the function is looking for, 
 *         but also other characters. Or I could return random bit sequences.
 *         I chose not to go this route for simplicity. Start simple and build
 *         up from there!
 *
 * Step 3: Writing the string input function. The input string is not used by
 *         the testme() function until it reaches state 9. At that point, if
 *         the input string is equal to 'reset' then we hit the error condition.
 *         The string returned from the inputString() function must be random
 *         according to the assignment guidlines. But, there are infinity 
 *         combinations of letters. So clearly this has to be paired down a 
 *         little. Since reset is 5 characters plus the trailing null to make
 *         6 characters, I chose to generate random combinations of 5 characters.
 *         But, the chances of getting the reset string are still way too small.
 *         So, I create a random number between 0 and 999. If this comes out as
 *         0 then I set the returned string to 'reset'. Otherwise, I generate a
 *         random 5 character string. This way we have a 1/1000 chance of 
 *         getting the needed return value while still testing with random
 *         inputs. To make this more robust we could test with different length
 *         strings, and special cases like null strings and so forth. Again,
 *         I went for simplicity.
 * */
