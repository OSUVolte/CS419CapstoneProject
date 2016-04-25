/*
Behnam Saeedi
Saeedib
932217697

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



*/
