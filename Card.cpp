#include "Card.h"


// Constructors/Destructors
//  

/*
	Constructor creates a playing card by setting its suit and rank
	and color.
*/
Card::Card (int suit, int rank ){
	this->rank = rank;
	this->suit = suit;

	if(suit==0 || suit==2)
		setColor(0);
	else
		setColor(1);
}

Card::~Card ( ) { }

//  
// Methods
//  

/*
	Value represents the numerical value of a Card rank
	i.e. a rank of king has a value of 13, Queen 12, etc.
*/
int Card::value(){
	int value;
	if(rank>0 && rank<=10)
		value = rank;
	else if(rank>10 && rank<=13)
		value = 10;
	else
		value = 0; //not a valid card value or a dummy card

	return value;
} 

/*
	returns true if the card is facing up, false otherwise
*/
bool Card::isFaceUp(){
	return faceUp;
}


/*
	flips the card
*/
void Card::flip(){
	faceUp=!faceUp;
}


//overloading << for Card output
ostream& operator << (ostream& os, Card aCard){
	string s;
	string r;
	stringstream ss;

	switch(aCard.suit){
		case 0 :
			s="H";break;
		case 1:
			s="S";break;
		case 2:
			s="D";break;
		case 3:
			s="C";break;
		default:
			s="Invalid card suit";break;
	}

	switch(aCard.rank){
		case 1:
			r="A";break;
		case 2:case 3:case 4:case 5:case 6:
		case 7:case 8: case 9: case 10:
			ss << aCard.rank;
			r=ss.str();
			break;
		case 11:
			r="J";break;
		case 12:
			r="Q";break;
		case 13:
			r="K";break;
		default:
			r="Invalid card rank";break;
	}
	if(aCard.faceUp) //We want to see the actual card
		os<<s<<r;
	else
		os<<"0"; //a flipped over card will just display as 0
	return os;
}
