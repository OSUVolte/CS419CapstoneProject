//Village Test:
Development:
	When I first began, I started out with random generation of the hand, deck, 
	discard piles. As I started writing tests,because it was part of the card's
	sepcification, I wanted to test that the card was properly discarded after it 
	was played. Therefore, I realized that in addition to those three groups of card 
	I would also need to randomly generate the playedCards, because that is where
	the village card would end up after it was discarded. 

	Another alteration I found I needed to make to this test, while writing
	and executing it, that relates to the random generation of the hand, deck, etc., 
	was that I originally used the maximum hand/deck size as the maximum value to 
	randomly select the number of cards. As I continued to develop this test, I 
	realized this sometimes resulted in a game state that would not be possible in 
	actual game play. Using this method of random generation the total number of 
	cards in play for each player often ended up exceeding the maximum deck/hand 
	size. Because at some point in the game all of those cards(a number of cards 
	that is that each of the individual piles can hold), could end up in the 
	deck, hand, or one of the other piles at the same time, this was not the best
	way to test if the game functioned correctly. It might have revelaed problems 
	that result from having too many cards, but since this is not likely in actual
	play it is not a very useful test. So, I ended up changing the test so there 
	are never more than the maximum number of cards total.

Coverage: The coverage for the random village card tests was fairly low. 3.35% 
	of the statements were covered and 1.43% of the branches executed. Considering 
	only one functions was being tested, this is a good amount of coverage. All of
	the statements in the playVillage() function were run for each run of the test. 
	The function calls discardCard(). Most of the branches were taken in this 
	function. The two that were not were the branch that runs if the card is trashed 
	and the one that is taken if the village card is the only card in the hand. This
	card is not trashed, so that branch will never run when this card is played. For
	the other branch that did not get taken, I thought it would eventually get taken
	if the test kept getting run. However, even when it is run many more times than 
	the 100 times I originally ran it that branch was never executed. I realized that 
	it never gets run because it is impossible to run this branch of the test, because
	if the card is the only card in the array it is also the last card in the array
	and therefore gets discarded in the previous if statement.

Bugs: 
    1. The test found the bug taht I introduced into the code. When test ran, 
	because the function does not call the draw card function, the part of the 
	test that checks if a card is drawn fails each time.
	2. In the discard card funtion the else if statement
	( state->handCount[currentPlayer] == 1 ) on line 1289 is unnessesary 
	because any card that meets this criteria would also meet the criteria of 
	the previous if statement, so including this statement is redundant.

//Adventurer test: 
Development:
	One complication I ran into with the correctness of my sepcification when
	writing this test was with testing the cards drawn. Initially, I was 
	testing to see if the updated handCount was the original handCount + 2
	which did not take into account the discarded adventurer card. Simply 
	changing this to test for handCount + 1 solved this problem. 

	Similarly, when attempting to test that the cards drawn were treasure
	cards, I was assuming the they would be in hand[handCount] and 
	hand[handCount + 1] since 2 cards are added. I again did not take into
	account that a card is discarded. Furthermore, I did not take into account
	that only one card is added to the end of the hand array. The other one
	takes the place of the adventurer card that is discarded. 

Coverage: The coverage for the random village card tests was again fairly low. 3.87% 
	of the statements were covered and 2.39% of the branches executed. This low 
	precentage is in part due to only one function being tested and also because 
	the bug I introduced results in most of the playAdventurer function not excuting.
	When this bug is removed the coverage increases. 

Bugs: 
	1. The random test found bug I introduced that while drawntreasure>2. 
	This results in most of the playAdeventurer function not executing and therefore 
	treasures are not drawn and the tests for drawing cards and drawing treasures 
	always fail.
	2. It's not visible when the previous bug is included in the code, but when that 
	bug is removed there is an issue with treasure being drawn. When there are not 
	enough treasure cards in the deck or discard to draw two treasures,the function 
	is not able to handle this situation. Therefore the draw cards and draw treasure 
	cards tests fail. A way to handle a situation where the played is not able to 
	draw treasure cards should be added.
	3. Not exactly a bug, but there was some redundant code in playAdventurer(). Both
	that function and the drawCard function were shuffling the discard when the deck
	hit zero which was unessesary. 