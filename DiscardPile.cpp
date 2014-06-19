#include "DiscardPile.h"

// Constructors/Destructors
//  

DiscardPile::DiscardPile ( ) : CardPile() {
}

DiscardPile::~DiscardPile ( ) { }

//  
// Methods
// 

/*
	Determines whether the discard pile can accept a card
	based on GolfSolitaire rules. If the cards differ by 
	a value of |1|, it can be added to the pile. DeckPile
	cards are auto-accepted
*/
bool DiscardPile::canTake(Card aCard){

	if(thePile.empty())
		return true;
	if(!aCard.getFaceUp()){ //from the deck
		return true;
	}
	else{
		int rankDiff = aCard.getRank()-top().getRank();
		if(rankDiff==1 || rankDiff==-1 || thePile.empty())
			return true;
		else if((aCard.getRank()==13 && top().getRank()==1) || (aCard.getRank()==1 && top().getRank()==13)) //handles the case of Ace and King
			return true;
	}

	return false;
}

/*
	method to add a Card to the discard pile
*/
void DiscardPile::addCard(Card aCard){
	if(canTake(aCard))
	{	
		CardPile::addCard(aCard);
		if(!thePile.back().getFaceUp())
			thePile.back().flip();
	}
}


