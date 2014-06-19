#ifndef DISCARDPILE_H
#define DISCARDPILE_H
#include "CardPile.h" 

/**
  * class DiscardPile
  * A simple CardPile, it accepts playing cards
  */

class DiscardPile : public CardPile
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  DiscardPile ();

  /**
   * Empty Destructor
   */
  virtual ~DiscardPile ( );

	//Methods
	//

  /**
   * @param  aCard
	 * adds a card to the DiscardPile
   */
  void addCard (Card aCard);
 
  /**
	 * @param aCard
	 * @return bool
	 * Determines whether or not a card can be added
	 * to the discard pile
	 */
	bool canTake(Card aCard);

};

#endif // DISCARDPILE_H
