/**************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 4
* Filename:  randomhistory.c
* Description: development of random testers, including improvements in 
* coverage and effort to check the correctness of specification
*
*
* randomtestadventurer.c -----------------------------------------------
* Started with randomly filling the current players hand deck with 
* both cards and treasures. The algorithm randomly decided if its
* going to add a card or a treasure and then randomy chooses amongst 
* the respective array of cards or treasures.
* The test oracle check that the current player has two more cards, that
* those two new cards are indeed treasures, that other players decks
* and hands have not changed, and the supply has not changed.
*
* Originally had numPlayer = 2, then decided to increase coverage
* we should random determine the number of players. Originally I
* decided this would be = rand() % 5. This caused an issue as the program
* could not handle when 0 players were entered. I added 1 to the equation
* so the number of players if now choosen randomly from 1 - 5. This also
* caused a segment fault from time to time, so I had to limit it to 3 players
* max. This is a bug that needs to be fixed. The program shouldnt fail due
* to an incorrect number of players instead an error message should be 
* displayed. By increasing the number of players, the coverage rose from
* 30.86% to 32.10%. Note these numbers are slightly lower when run on
* a the OSU terminal.
*
* randomtestcard.c -------------------------------------------------------
* The players hand, deck and discard pile are randomly filled with cards
* and treasures. A smithy is also randomly placed in the player hand.
* The playSmithy function is called and the test oracle is run. The test
* oracle for playSmithy checks that the current player has three more
* cards in their hand, that the other players decks and hands have not 
* changed and that the supply has not changed. It also checks that the 
* current players deck count is three less.
*
* This test initially was testing to see if smithy was discarded. I then
* realized the discarding of the card should actually happen within the 
* play card function. This is still a bug, as the smithy card is never
* discarded. 
*
* This test did little to increase coverage since we already increased
* the coverage with multiple players in the precvious test. The test 
* was run a greater number of times, which means we got to test more
* inputs. The issue here is that the smithy function has very limited
* functionality with only one branch. It appears random testing is
* more beneficial for tests with many branches. 
**************************************************************************/	
