//tester implemented to trigger error message from testme.c
//including write up on development and how it finds the error message

//set string to length 6 always else will have segfaults (if looks up to index 5)
//to trigger error random string must be "reset\0"
//and state must be 9, which only occurs after c has in order been
//'[', '(', '{', ' ', 'a', 'x', '}', ')', ']'

//going to take a lot of iterations - probability over standard ASCII space (127 characters) 
//of getting exactly reset\0 is 127^6 == BIG NUMBER!

//instead going to limit domain for our characters to the following 33 characters,
//thus getting a probability of 33^6 = 1.2 billion runs

//0 = \0
//40, 41 = '(', ')'
//91, 93 = '[', ']'
//97 to 122 = a to z
//123, 125 = '{', '}'

//even simpler - limit domain for string to first 5 characters being ASCII r,s,e,t with 
//means 4^5 = 1024 cycles to catch
//for character - limit to the 8 characters = 8*8 = ~64 runs

//so for string - take random integer and mod 4 to get 
//0 -> 101 (e)
//1 -> 114 (r)
//2 -> 115 (s)
//3 -> 116 (t)

//for character, take random integer and mod 9 to get
//0 -> 40 (
//1 -> 41 )
//2 -> 91 [
//3 -> 93 ]
//4 -> 97 a
//5 -> 120 x
//6 -> 123 {
//7 -> 125 }
//8 -> 32 ' '
