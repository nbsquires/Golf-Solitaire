#include "GolfSolitaire.h"

//Constuctors/Destructors
//
GolfSolitaire::GolfSolitaire(){
	rules();
	deckPile = new DeckPile();

	discardPile = new DiscardPile();
	
	initTables();
	game();
}

GolfSolitaire::~GolfSolitaire(){}

//Methods
//

/*
	Initializes all of the card piles
*/
void GolfSolitaire::initTables(){
	deckPile->fillDeck();
	deckPile->shuffle();

	vector<Card> aPile;
	for(int i=0; i<7; i++){
		for(int j=0; j<5; j++)
			aPile.push_back(deckPile->pop());	

		tableau[i] = new TablePile(5, aPile);

		aPile.clear();

	}	

	discardPile->addCard(deckPile->pop());
}

/*
	Main driving force of the game
*/
void GolfSolitaire::game(){
	cout<<"/*************************************************"<<
		"\n  Commands:"<<
		"\n  -n: Move card from table pile to deck pile"<<
		"\n  (n is a integer from 1 to 7 inclusive)"<<
		"\n  -0: Move card from deck pile to discard pile"
		"\n  --1: quit"<<
		"\n  --2: new game"<<
		"\n***************************************************/"<<endl;

	while(true){
	
		cout<<"Tableau piles:"<<endl;
		for(int i=0; i < 7; i++){
			cout<<"Table "<<i+1<<endl;
			tableau[i]->display();
			cout<<endl;
		}

		cout<<"Deck pile: "<<*deckPile<<" Discard pile: "<<*discardPile<<endl;

		int command;
		cout<<"Command: ";
		cin>>command;

		while(command!=-1){
			if(command>=1 && command<=7)
				tableToDiscard(command);
			else if(command==0)
				deckToDiscard();		
			else if(command==-1)
				break;
			else if(command==-2)
				reset();
			else
				cout<<"Invalid command"<<endl;

			cout<<"Tableau piles:"<<endl;
			for(int i=0; i < 7; i++){
				cout<<"Table "<<i+1<<endl;
				tableau[i]->display();
				cout<<endl;
			}

			if(!deckPile->isEmpty())
				cout<<"Deck pile: "<<*deckPile<<" Discard pile:"<<*discardPile<<endl;
			else{
				cout<<"Game Over!!"<<endl;
				gameOver();

				string play;
				cout<<"Play again? [y/n]: ";
				cin>>play;

				if(play.compare("y")==0)
					reset();
				else
					break;
			}

			cout<<"Command: ";
			cin>>command;		
		}
		break;
	}
}

/*
	Adds a card to the discard pile from a 
	specified table pile
*/
void GolfSolitaire::tableToDiscard(int n){
	if(!tableau[n-1]->isEmpty()){
		discardPile->addCard(tableau[n-1]->pop());
	}	
	else return;
}

/*
	adds card to the discard pile from the deck
*/
void GolfSolitaire::deckToDiscard(){
	if(!deckPile->isEmpty())
		discardPile->addCard(deckPile->pop());
	else return;
}

/*
	resets the game by clearing all the decks
*/
void GolfSolitaire::reset(){
	deckPile->clear(); //clear deck pile
	discardPile->clear();

	for(int i=0; i < 7; i++){ //clear table piles
		tableau[i]->clear();
	}


	initTables(); //initialize tables
	game(); //restart game
}

/*
	Gameover condition when the discard pile
	runs out of cards
*/
void GolfSolitaire::gameOver(){
	int par=0;
	for(int i=0; i < 7; i++){
		if(!tableau[i]->isEmpty()){
			int tbl = i+1;
			par+=tableau[i]->getNumCards();		
		}
	}

	cout<<"Congratulations! You scored "<<par<<" over par!"<<endl;
}

void GolfSolitaire::rules(){
		cout<<"~*~*~*~*Golf Solitaire*~*~*~*~*~*~*"<<endl;
	cout<<"How to play:"<<endl;
	cout<<"The card on the discard pile is the \"exposed\" card."<<endl; 
	cout<<"The bottom card of each table pile on the tableau is considered playable if it is one rank greater or one rank lesser than the exposed card."<<endl;
	cout<<"Try to clear all of the table piles by placing a playable card on the discard pile!"<<endl;
	cout<<"Use the deck pile command to move a card from the deckpile to the discard pile if you have no more moves."<<endl;

	cout<<"~*~*~~*~*~~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
}














