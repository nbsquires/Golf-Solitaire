#ifndef CARDPILE_H
#define CARDPILE_H

#include "Card.h"
#include <vector>

/**
  * class CardPile
  * Represents a generic card pile, i.e. a collection 
	*	of playing cards
  */

class CardPile
{
public:

  // Constructors/Destructors
  //  

  /**
   * Constructor
   */
  CardPile ();

  /**
   * Empty Destructor
   */
  virtual ~CardPile ( );


protected:

  // Protected attributes
  //  
  vector<Card> thePile;


public:

  /**
	 * @return Card
	 * pops off the card from the pile (stack)
   */
  Card pop ( );

	 /**
	 * @return Card
	 * reveals the top card from the stack without
	 * removing it
   */
	Card top();

 /**
	 * @return bool
	 * returns true if the card pile is empty, false
	 * otherwise
   */
	bool isEmpty ( );

 /**
	 * clears the card pile
	 */
	void clear();


  /**
   * @param  aCard
	 * method which can be overloaded, since different card piles
	 * may need different criteria to add a card
   */
  virtual void addCard (Card aCard );


  /**
   * @return bool
   * @param  aCard
	 * method which can be overloaded depending on a pile's 
	 * acceptance conditions for a playing card
   */
  virtual bool canTake (Card aCard );

	void displayAll();

 /**
	* friend method which overloads the << operator as a general display
	*/
	friend ostream& operator << (ostream& os, CardPile aPile);

};

#endif // CARDPILE_H
