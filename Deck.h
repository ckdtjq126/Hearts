#ifndef __DECK_H__
#define __DECK_H__

#include<iostream>
#include "CardPile.h"
using namespace std;

class Deck : public CardPile {
    public:
	// Constructor creates an empty deck.
	Deck ();
	// Destructor delete all the cards in deck
	virtual ~Deck();
	// generate sorted order of cards
	void generate();
	// return true if deck is legal (no duplicate cards and 52 cards)
	bool playingWithAFullDeck () const;

	// prints deck
	void print() const;
};

// Take an existing (ideally, empty) deck and read in 52 cards from the
// indicated input stream, making use of operator>>(istream&, Card&).
// Make sure that you are playingWithAFullDeck at the end.
// The ordering should be so that the last card read in will be on the top
// of the deck.
extern istream& operator>> (istream& in, Deck& deck);

#endif
