#ifndef __HUMANPLAYER_H__
#define __HUMANPLAYER_H__

#include "Player.h"

class HumanPlayer : public Player {
private:
	Card lead();			// pick leading card
	Card throwOff();		// if there is not suit-matching card, let the interactive player to choose any card
	Card followSuit(Card);	// let the interactive player to choose suit-matching card
public:
	// constructor for HumanPlayer
	HumanPlayer(string name);
};

#endif