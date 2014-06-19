#ifndef DECKPILE_H
#define DECKPILE_H
#include "CardPile.h"

/**
  * class DeckPile
  * Represents a simple implementation of a CardPile
	* A DeckPile contains 52 playing cards, can be shuffled
  */

class DeckPile : public CardPile
{
public:

  // Constructors/Destructors
  //  


  /**
   * Constructor
   */
  DeckPile ( );

  /**
   * Empty Destructor
   */
  virtual ~DeckPile ( );


  /**
	 * shuffles the DeckPile
   */
	void shuffle();

  /**
	 * fills the deck
	 */
	void fillDeck( );

};

#endif // DECKPILE_H
