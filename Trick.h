#ifndef __TRICK_H__
#define __TRICK_H__

#include <iostream>
#include "Player.h"

class Trick: public CardPile{
public:
	// plays single round consumes playerList, maxScore, currentHand
	void Play(vector<Player*>&, int, int);
};
#endif