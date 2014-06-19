#include "CardPile.h"

// Constructors/Destructors
//  

CardPile::CardPile (  ){}

CardPile::~CardPile (  ) {//cout << "yo"; 
}

//  
// Methods
//  
/*
	returns the card at the back of the pile (top of the stack)
*/
Card CardPile::top(){
	return thePile.back();
}

/*
	Returns true if the deck is empty, false otherwise
*/
bool CardPile::isEmpty(){
	return thePile.empty();
}

/*
	Returns the card at the top of the stack and removes it from
	the stack
*/
Card CardPile::pop(){
	if(!thePile.empty()){
		Card poppedCard = thePile.back();
		thePile.pop_back();
		return poppedCard;
	}else{
		Card emptyCard(0,0);
		return emptyCard;
	}
}


/*
	Adds a card to the pile
*/
void CardPile::addCard (Card aCard ){
		thePile.push_back(aCard);
}

/*
	Returns false 
*/
bool CardPile::canTake (Card aCard ){
	return false;
}

/*
	clears the card pile
*/
void CardPile::clear(){
	if(!thePile.empty())
		thePile.clear();
	else return;
}

/*
	displays all of the cards
*/
void CardPile::displayAll(){
	for(vector<Card>::iterator it=thePile.begin(); it!=thePile.end(); it++)
		cout<<*it<<" ";
}

//
// Other Methods
//

/*
	General display method for a card pile, only reveals what's
	at the top of the stack
*/
ostream& operator << (ostream& os, CardPile aPile){
	os << aPile.top();
	return os;
}



