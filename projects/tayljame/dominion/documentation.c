// Osbaldo Esquivel
// CS 362
// 09APR2016
// Assignment 2


1. According to the Smithy code, the cost of this card is four coins, which makes it a somewhat valuable card. With this card, a user is allowed to add three cards into their hand. The card is added to the user's deck using the playSmithy function which uses a simple loop to pick three cards from the deck. The discard function is then called to discard the Smithy card from the user's deck.

2. According to the Adventurer code, this card is worth six coins which makes it a valuable card. This card allows the user to draw cards until two treasure cards are chosen and these cards are then added to the user's deck. This works by using the drawCard function which is similar to the playSmithy function in that it loops until two treasure cards are picked.

3. The discardCard() function has four parameters it accepts: the index of the card in the user's deck as an integer (handPos), the current player as an integer, the state of the game as a struct, and a flag for if the card was trashed as an integer. If a card is not trashed which is indicated by the flag being less than one, then add it to the player's deck. Then, a card will be removed from the user's deck and the count will be decremented.

4. The updateCoins() function is fairly simple and accepts three parameters: the player integer, the state of the game as a struct, and an integer signifying a bonus. First, the coin count is reset and then coins are added to the player's count for each treasure card along with the bonus.
