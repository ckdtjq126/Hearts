#ifndef __OPTIONS_H__	
#define __OPTIONS_H__

#include "Deck.h"
#include "SmartPlayer.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include <cstdlib> // use of exit(1)
#include <fstream> // use of argument -d

class Options : public vector<const char*> {
private:
	int MaxPoints;
public:
	int getMaxPoints(); // return MaxPoints
	void includeOptions(Deck& deck, vector<Player*>& plist); // includes options in the game

	// vector member functions which will be used
	using vector<const char*>::push_back;
	using vector<const char*>::size;
	using vector<const char*>::at;
	using vector<const char*>::begin;
	using vector<const char*>::empty;
	using vector<const char*>::erase;
	using vector<const char*>::clear;
};

#endif