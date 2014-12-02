#ifndef __RANDOMPLAYER_H__
#define __RANDOMPLAYER_H__

#include "Player.h"

class RandomPlayer : public Player {
private:
	PRNG rp;				// random seed used to pick card
	Card lead();			// pick leading card
	Card throwOff();		// if there is not suit-matching card, pick random card
	Card followSuit(Card);	// pick a suit-matching card from RandomPlayer's Hand
public:
	//constructor for RadnomPlayer with name and seed
	RandomPlayer(string name, unsigned int seed);
};

#endif