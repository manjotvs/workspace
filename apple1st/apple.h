#ifndef APPLE_H
#define APPLE_H

/* Uncomment the following macro to enable debug prints */
#define DEBUG_CARDS

/* Global Constants */
#define MIN_PILES 3
#define MAX_PILES 5

typedef struct card
{
	uint32_t val;
	struct card *next;
}card_t;


/**
 * This function prints all the elements present in a deck
 * in the their given order.
 * @param - Pointer holding head of the deck.
 * @return - void
 */
#ifdef DEBUG_CARDS
void displayDeck(card_t *head);
#endif

/**
 * Check if the deck is in order.
 * @param - Pointer to shuffled deck
 * @return - true(In-order) or false(Out-of-Order).
 */
bool isDeckInOrder(card_t* deck);

/**
 * This function reverses the elements stored in piles.
 * @param - (pile)Pointer to pointer holding the head of pile.
 * @return - void
 */
void reversePilesElements(card_t** pile);

/**
 * This function creates the orginal deck in-order.
 * @param - (n)Variable holding the number of cards in deck
 * @return - (card_t *) Pointer to head of the deck.
 */
card_t *createDeck(uint32_t n);

/**
 * This function creates the piles.
 * 
 * @param - 
 * 		Pointer to pointer holding the head of deck.
 *		Variable holding the number of piles to be created.
 * @return - void.
 */
card_t* createPiles(card_t** deck, uint8_t num_piles);

/**
 * This function combines all the piles back into deck.
 * @param - 
 * 		Pointer to pointer holding the head of deck.
 *		Pointer to array of piles.
 *		Variable holding the number of piles
 * @return - void.
 */
void combinePilesIntoDeck(card_t** deck, card_t *piles, uint8_t num_piles);

/**
 * This function creates piles and put them back into deck.
 * It also checks for the order of the deck, and calculate the 
 * total number of rounds needed to put a deck back into the 
 * original order.
 * @param - Pointer to pointer holding the head of deck.
 * @return - Number of rounds needed to bring the deck in order.
 */
uint32_t dealCards(card_t** deck, uint32_t num_cards);

#endif
