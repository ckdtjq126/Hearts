#ifndef __SMARTPLAYER_H__
#define __SMARTPLAYER_H__

#include "Player.h"

class SmartPlayer : public Player {
private:
	Card lead();			// pick leading card
	Card throwOff();		// if there is not suit-matching card, pick card with other method
	Card followSuit(Card);	// pick a suit-matching card from SmartPlayer's Hand
public:
	//constructor for SmartPlayer with name
	SmartPlayer(string name);
};

#endif