/* ---------------------------------------------------------------------
* Jon Patterson
* Random Testing Quiz 2
* ---------------------------------------------------------------------/

testme.c
	The testme() function wants to error out when it encounters certain characters
	within a sequence, bumping the system to a state. Once the state is in state '9'
	and the char array is "reset\0", it causes the program to error. The character
	implementation was easy to implement, just set a random integer in the range 32-127
	and cast it to the corresponding ASCII character. 

	So this piece went through fine, the second piece I initially tried to impelment by
	having all 5 characters be selected from the space of the 26 lowercase alphabet.
	This didn't work very well, as I was going through millions of iterations at state
	'9' without "reset" coming up. So I decided to cheat, make the attack space only two
	letters, and hard-code 'res__\0' as the string. This worked much faster, as it
	only took just over a thousand iterations before causing the program to error.

	I guess this is an example of the annoyance of brute forcing random attacks, because
	you could go for a long while and think everything is fine, but there is still a
	bug that you can find if you only iterate enough times.