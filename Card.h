#ifndef CARD_H
#define CARD_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ostream> 
#include <sstream>
using namespace std;


/**
  * class Card
  * Represents a playing card
  */

class Card
{
public:


  // Constructors/Destructors
  //  


  /**
   * Constructor
   */
  Card ( int, int );

  /**
   * Empty Destructor
   */
  virtual ~Card ( );

  // Static Public attributes
  //    

  static const int heart=0;
  static const int spade=1;
  static const int diamond=2;
  static const int club=3;
  static const int red=0;
  static const int black=1;

  /**
   * @return int
   */
  int value ( );

  /**
   * @return bool
   */
  bool isFaceUp ( );


  /**
   */
  void flip ( );

	friend ostream& operator << (ostream& os, Card aCard);

private:  

  // Private attributes
  //  
  int suit;
  int rank;
  int color;
  bool faceUp;

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of suit
   * @param new_var the new value of suit
   */
  void setSuit ( int s )   {
      suit = s;
  }

  /**
   * Get the value of suit
   * @return the value of suit
   */
  int getSuit ( )   {
    return suit;
  }

  /**
   * Set the value of rank
   * @param new_var the new value of rank
   */
  void setRank ( int r )   {
      rank = r;
  }

  /**
   * Get the value of rank
   * @return the value of rank
   */
  int getRank ( )   {
    return rank;
  }

  /**
   * Set the value of color
   * @param new_var the new value of color
   */
  void setColor ( int c )   {
      color = c;
  }

  /**
   * Get the value of color
   * @return the value of color
   */
  int getColor ( )   {
    return color;
  }

  /**
   * Set the value of faceUp
   * @param new_var the new value of faceUp
   */
  void setFaceUp ( bool fu )   {
      faceUp = fu;
  }

	bool getFaceUp(){
		return faceUp;
	}

};

#endif // CARD_H
