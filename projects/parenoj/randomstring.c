/* For my development of this random tester, I first started with inputChar().
	I noticed that c could be almost any character. Therefore I assigned a random value
	between 0 and 127 (the standard ASCII range) to be returned. This will advance the states from
	0 to 9 really quickly. 
	
	For inputString(), I initially had it return the string in question (reset), but that was
	no fun. I thought about creating a character array with 'r', 'e', 's', and 't', and randomly
	assigning those to a position in the string to be returned, but that also encountered the error
	very quickly. 
	
	I decided to assign a random ASCII value between 101 and 116 to the first 5 positions of the string
	which is the range of characters from 'e' to 't'. I could have done the whole ASCII range again, but
	that might have taken a lot longer to get all of the right characters to be in the right spot. As it is
	now, the program may iterate over 1 million times before it "encounters" the error.
	
	The most Iterations it has taken for me is 3.5 million, but it does find the error.

*/	