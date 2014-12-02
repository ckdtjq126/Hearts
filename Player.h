#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Deck.h"

class Player : private vector<Card*>{
private:
	// pure virtual functions used to pick a card
	virtual Card lead() = 0;
	virtual Card throwOff() = 0;
	virtual Card followSuit(Card) = 0;
protected:
	// name of the player
	string name;
public:
	// vector members which will be used
	using vector<Card*>::push_back;
	using vector<Card*>::size;
	using vector<Card*>::at;
	using vector<Card*>::begin;
	using vector<Card*>::empty;
	using vector<Card*>::erase;

	// Player Constructor
	Player(string name);

	// print cards which the player is holding
	void print() ;

	// returns the name of the player
	virtual string getName();
	
	// From hand, find Card::TwoOfClubs. return true if exists, else return false
	bool TwoClubs();

	// PlayerCard functions for lead() and followSuit(Card)
	Card PlayCard();
	Card PlayCard(Card);
};


#endif