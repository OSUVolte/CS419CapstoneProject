//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// dominion.c Refactoring
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//	Function #1: useSmithy
//	Proper Action: +3 Cards
//	Bug: Four cards get added, not 3. Then, the smithy card gets discarded, but
//			so does the next card, which will have just been added. The user
//			will have +3 cards, but an extra will have been erroneously drawn and
//			discarded.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//	Function #2: useAdventurer
//	Proper Action: +2 Treasure cards from deck, discarding all cards in between
//	Bug: Everything happens correctly, but when this action card is discarded, 
//			it is erroneously trashed. The user will not know that is has been trashed
//			until he notices that it never came up again, which will take a number of turns.
//			
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//	Function #3: useVillage
//	Proper Action: +1 Card, +2 Actions
//	Bug: One card is drawn, but instead of `currentPlayer` getting drawn, the static
//			number 0 is plugged into the `drawCard` function. As long as the user is 
//			playing as `currentPlayer`, he will not notice this bug, unless the bot
//			plays this card and the user mysteriously has an extra card.			
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//	Function #4: useMine
//	Proper Action: Trash treasure card `choice1`, gain a treasure card costing +3 `choice1`
//	Bug: Everything happens correctly, but when this action card is discarded, 
//			it is erroneously trashed. The user will not know that is has been trashed
//			until he notices that it never came up again, which will take a number of turns.
//			
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//
//	Function #5: useMinion
//	Proper Action: +1 action, +2 coins for `choice1` or discard hand, redraw 4 and other players redraw
//	Bug: No bugs introduced in this function
//			
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


