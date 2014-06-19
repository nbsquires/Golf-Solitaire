#include "TablePile.h"

// Constructors/Destructors
//  

TablePile::TablePile ( int numCards, vector<Card> aPile ) : CardPile() {
	vector<Card>::iterator it;
	
	for(it = aPile.begin(); it!= aPile.end(); it++)
	{
		thePile.push_back(*it);
		thePile.back().flip();
	}
}

TablePile::~TablePile ( ) { }

//  
// Methods
// 

void TablePile::display(){
	for(vector<Card>::iterator it=thePile.begin(); it!=thePile.end(); it++)
		cout<<*it<<endl;
}

// Other methods
//  


