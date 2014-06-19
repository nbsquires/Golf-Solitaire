#ifndef TABLEPILE_H
#define TABLEPILE_H
#include "CardPile.h"


/**
  * class TablePile
  * 
  */

class TablePile : public CardPile
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  TablePile ( int, vector<Card> );

  /**
   * Empty Destructor
   */
  virtual ~TablePile ( );

  /**
   * @return bool
   * @param  aCard
   */
  //bool canTake (Card aCard );


  /**
   * @return bool
   */

  /**
   */
  void display ( );

	int getNumCards(){
		return thePile.size();
	}

};

#endif // TABLEPILE_H
