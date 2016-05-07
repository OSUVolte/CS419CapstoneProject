/*
Behnam Saeedi
Saeedib
932217697

UPDATE:
	an unexpected change in repo cause me to lose my original code beofre i was aqctually able to
upload it to the repo, apparently someone had reverted the repo and when i pulled it overwrote my code
i tried to get my code back It wasnt successful since i hadn't submitted it back to repository and i lost my 
code as i was trying to submit it

I tried to recover some of the code back but the time was just too short

Bug reports:
in coinUpdate, if the bonus is negative the function does not return 0 or a positive value
This could be avoided by making sure the the value received as input is always positive
This function essentially faild w2hen the value of bonus is too big or negative since it 
over flows

in isGameOver we tested all the features that it had and all 4 tests that i ran did not found any bugs
The operations happened as long as the data made sence and it had a decent coverage for the function

The Kingdomcards function worked as expected, we created 2 arrays and compared them and
asserted the stored values in the memory to make sure values are matching
further more, the memory was handled poroperly and the output matched

scorefor successfully calculated the score upon add and remove and change of different cards
we did not discover any bugs and covered a ove 96 percent of the function according to gcov
analysis

Card test: Smithy failed at 2 points:
- It added 2 cards instead of 3 cards that it was supposed to add
- discard count was incorrect and did not get updated
The gcov shows that the test covered 93% of the code in cardtest1.c which contained the test code for
smithy card

The adventurer testcode did not found anybugs eventhough I knew that there is a bug in implementation
the test did not find it since the memory allocation for that part of test was incorrect

*/
