# Quiz 2

Jens Bodal

bodalj@oregonstate.edu

## Documentation for testme.c error message finding

The goal for this quiz was to successfully produce the "error " message in the function `testme()` by producing random character and string values.

The `testme()` function uses a while loop to produce random character and string values and then if criteria are met a `state` value is 
set.  The `state` value starts at `0` and incrememnts to `9`, at which point if the `state` value is `9` and the string is equal
to `reset`, then the message `error ` is printed and the program exits.

## State Values

As mentioned the `state` value in `testme()` starts at 0.  The state value will increase at each of the following progressions, 
with `c` being the random character and `s` being the random string.

1. `IF c IS '[' AND state IS 0 THEN state = 1
2. `IF c IS '(' AND state IS 1 THEN state = 2
3. `IF c IS '{' AND state IS 2 THEN state = 3
4. `IF c IS ' ' AND state IS 3 THEN state = 4
5. `IF c IS 'a' AND state IS 4 THEN state = 5
6. `IF c IS 'x' AND state IS 5 THEN state = 6
7. `IF c IS '}' AND state IS 6 THEN state = 7
8. `IF c IS ')' AND state IS 7 THEN state = 8
9. `IF c IS ']' AND state IS 8 THEN state = 9
10. `IF s IS 'reset' AND state IS 9 THEN print 'error ' and exit with code 200.

The random characters do not have to be produced in that exact order in exact succession.  For example once
the character '[' is generated the `state` becomes `1` for the duration of the while loop.  Once the `state=1`
and the character `(` is generated then the `state` becomes `2`, and so on.

After each character is generated and the `state` value has increased to `9` we then see if the randomly generated
string is equal to `reset`.  Once `reset` is generated the error message is printed and the program exits with
code 200.

## Generating Random Characters

The random characters that need to be seen are `'[',']','(',')','{','}',' ','a','x'` and the characters that 
form the random string that needs to be seen are `'r','e','s','t'`.  As such we create an array of characters
which contain all of these characters `char characters[] = "{}[]() axrest"`. Our `inputChar()` function then
returns one of these characters using the `rand()` function to generate an index from `0` to `strlen(characters)`
or `0 to 13`.  As each character that needs to be generated in order to produce the error message are contained
within the `characters` array, it will be possible to randomly generate one of these values.

## Generating a Random String

The randomly generated string that needs to be seen is the word `reset`.  To generate a random string we simply
create a character array of length 6 (for each of the 5 letters plus the null terminator) and then using a for loop
we fill the character array with a randomly generated character from the `inputChar()` function. As all of the 
characters needed to form the word `reset` can be generated from the `inputChar()` function it will be possible
to at some point generate the word `reset. 

## Error Generation

Each iteration of the while loop in `testme()` has a 1/13 chance of producing the correct character needed to
increment the `state` by 1. Once our `state` is equal to `9`, each iteration of the while loop has a `(1/13)^5` 
(1/371293 or .0003%) chance of producing the word `reset`. 

This would mean on average it would take 13 iterations to produce each of the 9 random characters, and 371293 
iterations to produce the word "reset", for a total of 371,410 (13*9+371293) iterations needed on average to 
generate the error message.

## Testing

10 sample runs were generated which output the number of iterations needed to generate the error message.  The number 
of iterations needed for each sample are below:

1. 533443
2. 325305
3. 928330
4. 18233
5. 356304
6. 13760
7. 105058
8. 259303
9. 44749
10. 765649

While our sample size is nowhere sufficient to have much significance, the average number of iterations needed
to produce the error message in our sample size of 10 was 335,013 which is not far off from the average calculated above
of 371,410.  
