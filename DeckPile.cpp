#include "DeckPile.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>

// Constructors/Destructors
//  

DeckPile::DeckPile (  ) : CardPile() {
}
DeckPile::~DeckPile ( ) { }

//  
// Methods
//  

/*
	fills the deck with playing cards
*/
void DeckPile::fillDeck(){
	//fill deck
	for(int i=0; i < 4; i++) //suit
		for(int j=1; j<=13; j++) { //rank 
			Card aCard(i, j);
			CardPile::addCard(aCard);
			//aCard.setFaceUp(false); //DeckPile is always face down
		}
}

/*
	shuffles the deck using a simple algorithm and 
	random generator
*/
void DeckPile::shuffle(){
	
	srand((unsigned)time(0)); //psuedo random seed
	int shuffle;
	for(int i=0; i < 52; i++){		
		shuffle = rand()%52;
		swap(thePile[i], thePile[shuffle]);
	}
}




