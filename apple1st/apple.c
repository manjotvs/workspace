#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "apple.h"

/* Working Methodology */
/**
 * Following assumptions are made to solve the given problem.
 * N - N can be as large as 32-bit variable varying from  (0 to 4,294,967,295).
 * Piles pattern will vary from 3 to 5 as given. Start with 3 piles, then 4, then 5, 
 * then loop back to 3, then 4 and so on.
 *
 * Working Example:
 * N = 9
 * Inital card Sequence - 1 2 3 4 5 6 7 8 9
 * 1st Round
 *  P1: 7 4 1
 *  P2: 8 5 2
 *  P3: 9 6 3
 *  New Sequence after 1st round: 7 4 1 8 5 2 9 6 3
 *
 * 2nd round
 *	P1: 3 5 7
 *	P2: 2 4
 *	P3: 9 1
 *	P4: 6 8
 *  New Sequence after 2nd round: 3 5 7 2 4 9 1 6 8
 * 
 * 3rd Round
 * P1: 9 3
 * P2: 1 5
 * P3: 6 7
 * P4: 8 2
 * P5: 4
 * New Sequence after 3rd round: 9 3 1 5 6 7 8 2 4
 *
 * This will continue until deck comes back into initial order.
 */

/**
 * This function prints all the elements present in a deck
 * in the their given order.
 * @param - Pointer holding head of the deck.
 * @return - void
 */
#ifdef DEBUG_CARDS
void displayDeck(card_t *head)
{
	printf("Current Cards Sequence:");
	while(head)
	{
		printf(" %d", head->val);
		head = head->next;
	}
	printf("\n");
}
#endif

/**
 * Check if the deck is in order.
 * @param - Pointer to shuffled deck
 * @return - true(In-order) or false(Out-of-Order).
 */
bool isDeckInOrder(card_t* deck)
{
	int i = 1;
	while(deck)
	{
		if(deck->val != i)
			return false;
		i++;
		deck = deck->next;
	}
	return true;
}

/**
 * This function reverses the elements stored in piles.
 * @param - (pile)Pointer to pointer holding the head of pile.
 * @return - void
 */
void reversePilesElements(card_t** pile)
{
	card_t* curr = *pile;
	card_t* prev = NULL;
	card_t* next = NULL;
	while(curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*pile = prev;
}

/**
 * This function creates the orginal deck in-order.
 * @param - (n)Variable holding the number of cards in deck
 * @return - (card_t *) Pointer to head of the deck.
 */
card_t *createDeck(uint32_t n)
{
	if(n == 0)
	{
		return NULL;
	}
	card_t* d = (card_t*)malloc(sizeof(card_t*));
	card_t* itr = d;
	uint32_t i = 1;
	while(i<n)
	{
		itr->val = i;
		itr->next = (card_t*)malloc(sizeof(card_t*));
		itr = itr->next;
		i++;
	}
    itr->val = i;
	itr->next = NULL;
	return d;
}


/**
 * This function creates the piles.
 * 
 * @param - 
 * 		Pointer to pointer holding the head of deck.
 *		Variable holding the number of piles to be created.
 * @return - void.
 */
card_t* createPiles(card_t** deck, uint8_t num_piles)
{	
	card_t* c = *deck;
	card_t* piles = (card_t*)malloc(sizeof(card_t*)*num_piles);
	card_t *piles_itr[MAX_PILES];
	card_t *temp;
	int i = 0;
	/* Following loop will add very first elements into each piles */
	while(i < num_piles)
	{
		piles[i].val = -1;
		temp = c->next;
		c->next = NULL;
		piles[i].next = c;
		piles_itr[i] = piles[i].next;
    	c = temp;
    	i++;
    }
	i = 0;
	while(c)
	{
		temp = c->next;
		c->next = NULL;
		piles_itr[i]->next = c;
		piles_itr[i] = piles_itr[i]->next;
		i = (i +1) % num_piles;
		c = temp;
	}
	i = 0;
	while(i < num_piles)
	{
		reversePilesElements(&(piles[i++].next));
	}
	return piles;
}


/**
 * This function combines all the piles back into deck.
 * It will also free the dynamic memory allocated to piles.
 * @param - 
 * 		Pointer to pointer holding the head of deck.
 *		Pointer to array of piles.
 *		Variable holding the number of piles
 * @return - void.
 */
void combinePilesIntoDeck(card_t** deck, card_t *piles, uint8_t num_piles)
{
	int i =0;
	card_t *piles_itr[num_piles];
	card_t new_deck;
    card_t *deck_itr = &new_deck;
	while(i < num_piles)
	{
#ifdef DEBUG_CARDS
		printf("P%d:",i+1);
#endif
		piles_itr[i] = piles[i].next;
		
		deck_itr->next = piles[i].next;
		deck_itr = deck_itr->next;
		while(piles_itr[i])
		{
#ifdef DEBUG_CARDS
			printf(" %d", piles_itr[i]->val);
#endif
			if(piles_itr[i]->next != NULL)
			{
				deck_itr->next = piles_itr[i]->next;
				deck_itr = deck_itr->next;
			}
			piles_itr[i] = piles_itr[i]->next;	
		}
#ifdef DEBUG_CARDS
		printf("\n");
#endif
		i++;
	}
	*deck = new_deck.next;
#ifdef DEBUG_CARDS
	printf("Added piles back into deck!\n");
#endif
	free(piles);
	piles = NULL;
}


/**
 * This function creates piles and put them back into deck.
 * It also checks for the order of the deck, and calculate the 
 * total number of rounds needed to put a deck back into the 
 * original order.
 * @param - Pointer to pointer holding the head of deck.
 * @return - Number of rounds needed to bring the deck in order.
 */
uint32_t dealCards(card_t** deck, uint32_t num_cards)
{
	if(num_cards <= MIN_PILES)
		return 0;
	uint32_t count = 0;
	uint8_t i = MIN_PILES;
	card_t* piles;
	while(1)
	{
		piles = createPiles(deck,i);
		combinePilesIntoDeck(deck, piles, i);
#ifdef DEBUG_CARDS
		displayDeck(*deck);
#endif
		count++;
		if(isDeckInOrder(*deck))
			break;
		/**
		 * Handling the special case when number of cards will be four 
		 * as there will no 5th pile.
		 * Also, Handles the repeating pattern of piles varying from 3 to 5 
		 * for each round.
		 */
#ifdef DEBUG_CARDS
		printf("Piles limit: %d\n", i);
#endif
		i++;
		if(i > MAX_PILES || i >= num_cards)
		{
			i = MIN_PILES;
		}
	}
	return count;
}


int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Usage:     cards [Number of Elements in Deck]\n");
     	printf("Example:   cards 9\n");
     	return 0;
	}
	const uint32_t num_cards = atoi(*(argv+1));	
	card_t* deck = NULL;
#ifdef DEBUG_CARDS
	printf("Total number of cards in the given decks: %d\n",num_cards );
#endif
	deck = createDeck(num_cards);
#ifdef DEBUG_CARDS
	displayDeck(deck);
#endif
	
	/**
	 * Print the total number of rounds needed to bring the deck in-order 
	 * after dealing them.
	 */
	printf("%d\n", dealCards(&deck, num_cards));

	free(deck);
	deck = NULL;

	return 0;
}