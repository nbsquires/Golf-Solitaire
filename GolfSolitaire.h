#ifndef GOLFSOLITAIRE_H
#define GOLFSOLITAIRE_H
#include "CardPile.h"
#include "DeckPile.h"
#include "DiscardPile.h"
#include "TablePile.h"

/**
	* class GolfSolitaire
  */

class GolfSolitaire{
	public:
	 //Constructors/Desctructors
	 //

	  /**
		 * constructor
		 */
		GolfSolitaire();

	  /**
		 * empty destructor
		 */
		virtual ~GolfSolitaire();

	 //Public attributes
	 //
		DeckPile * deckPile;
		DiscardPile * discardPile;
		TablePile * tableau[7];

	 // Methods
	 //

	 /**
	  * initializes all of the tables in the game
	  */
		void initTables();

   /**
	  * The game mechanics
	  */
		void game();
		
	 /**
		* @param int
		* takes a card from a table pile and adds it to the 
		* discard pile
		*/
		void tableToDiscard(int n);

	 /**
		* adds a card from the deck pile to the 
		* discard pile
		*/
		void deckToDiscard();
	
	 /**
		* resets the game by clearing the table
		*/
		void reset();

	 /**
		* Handles the gameover condition i.e. when the 
		* deck pile runs out of cards
	  */		
		void gameOver();

	/**
	 * displays the rules for golf solitaire
	 */
		void rules();
};

#endif //GOLFSOLITAIRE_H

