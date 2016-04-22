/*
 * Created by Sam Schultz
 * Date: 4/10/2016
 * Documentation.c
 *
 * Card Documentation:
 * Smithy: Action card that costs four coins. When the card is played the player draws 3 cards then the card is placed into the discard pile.
 * Adventurer:Action card that costs 6 coins to purchase. When played the player draws cards until two treasure cards (coins) are revealed. Upon revealing two treasure cards the player stops drawing cards and puts the treasure cards into their hand and discard all other cards revealed.
 *
 *
 * Code Documentation:
 *
 * Smithy: When this card is played the drawCard() method is called 3 times and then the smithy card is discarded. Current implimentation (the one given) does not check for deck countor shuffle if needed.
 *
 * Adventurer:  When the adventurer is played the drawCard() method as many times as needed until 2 treasure cards are revealed, Acounter increments a treasure couter everytime a treasure is drawn. Upon hitting 2 treasures the other cards revealed which were not treasure cards were placed into a temp hand which is then discarded, followed by the discarding of the adventurer card that was played.
 *
 * discardCard():
 * Input: int handPos: Position of card to be discarded in players hand. 
 * int  currentPlayer: Reference to which players hand is being used.
 * *state gameState: Current state of the game struct.
 * int trashFlag: Flag the determines if it goes to trash pile (permanent discard) or played pile (reshuffles into deck).
 * Returns 0
 *
 * The method is used to discard a specific card from a players hand. The card goes to the designated pile based off of the trashFlag under these rules <1 = played pile, >1 trash pile. Once the card is removed from the hand the positions of the cards after the discarded card is shifted down to remove gaps in the hand and updates handcount in game state.
 *
 *
 * updateCoins():
 * Inputs: int player: which player is effected.
 * *state gameState: Game state struct.
 * int bonus: coin bonus from action cards.
 *
 * Returns 0
 *
 * The method is used to calculate tota coins when an action card gives a player aditional coins. The additional coins is passed in with the bonus argument and it adds the value of current coins in hand and updates game state.
 *
 * */ 
 *
