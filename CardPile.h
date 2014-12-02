#ifndef __CARDPILE_H__
#define __CARDPILE_H__

using namespace std;

#include <vector>
#include "Card.h"
#include "PRNG.h"

class CardPile : private vector<Card*> {
    public:
	// Constructors and destructor
	CardPile ();
	virtual ~CardPile ();

	// set seed value
	void setRandomSeed(uint32_t randomSeed);

	// vector members which will be used
	using vector<Card*>::push_back;
	using vector<Card*>::size;
	using vector<Card*>::at;
	using vector<Card*>::begin;
	using vector<Card*>::empty;
	using vector<Card*>::erase;
	using vector<Card*>::clear;

	// shuffles deck
	void shuffle();
	// get the sum of heartsvalues of each card
	int heartsValue() const;
	// print CardPile
	virtual void print() const;

    private:
	PRNG prng;
	static const uint32_t DefaultRandomSeed;
};

#endif