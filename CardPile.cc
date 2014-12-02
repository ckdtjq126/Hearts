#include <vector>
#include <algorithm>
#include <iostream>
#include "CardPile.h"
#include "Card.h"

// set default seed value as 37
const uint32_t CardPile::DefaultRandomSeed = 37;

// Default CardPile Constructor
CardPile::CardPile() : prng(DefaultRandomSeed) {}

// CardPile constructor with input seed value
void CardPile::setRandomSeed(uint32_t randomSeed) {
	prng.seed(randomSeed);
}

// destructor
CardPile::~CardPile(){}

// shuffles deck
void CardPile::shuffle() {
	for (int i = size() - 1; i > 0; i--) {
		const int j = prng(i);
		Card* tmp = at(j);
		at(j) = at(i);
		at(i) = tmp;
	}
}

// get the sum of heartsvalues of each card
int CardPile::heartsValue() const{
	int sum = 0;

	// adds heart value of each card
	for(unsigned int i = 0; i < size(); i++){
		sum += at(i)->getHeartsValue();
	}

	return sum;
}

// print CardPile
void CardPile::print() const{}
