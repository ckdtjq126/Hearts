#include "RandomPlayer.h"

extern Card leadingTrump;

// constructor for RandomPlayer with name and seed
RandomPlayer::RandomPlayer(string pname, unsigned int seed): Player(pname){
	rp.seed(seed);
}

// pick a lead card from RandomPlayer's Hand
Card RandomPlayer::lead(){
	Card result;	// picked card

	// choose random index
	int index = rp(0,size()-1);

	// set result card to index-th card
	result = *at(index);

	// print output
	cout<<"  "<<name<<" led "<<*at(index)<<endl;
	erase(begin()+index);

	return result;
}

// if there is not suit-matching card, pick random card
Card RandomPlayer::throwOff(){
	Card result;				// result card
	int index = rp(0,size()-1);	// random index
	result = *at(index);		// set result to index-th card

	// print result.
	cout<<"  "<<name<<" threw off "<<*at(index)<<endl;
	erase(begin()+index);

	return result;
}

// pick a suit-matching card from RandomPlayer's Hand
Card RandomPlayer::followSuit(Card c){
	Card result;	// picked card
	int total = 0;	// total number of cards with same leading suit
	int index;		// integer used to find index-th suit-matching card.

	// find the total number of suit-matching cards in hand
	for(unsigned int i = 0; i < size(); i++){
		if(at(i)->getSuit() == c.getSuit())
			total++;
	}

	// if no suit-matching card exists, throw random card
	if(total == 0)
		return RandomPlayer::throwOff();

	// if there is at least one suit-matching card, pick random suit-matching card
	else
		index = rp(1,total);

	// find index-th suit-matching card, print it
	for(unsigned int j = 0; j < size(); j++){
		if(at(j)->getSuit() == c.getSuit()){
			index--;
		}
		if(index == 0){
			result = *at(j);
			cout<<"  "<<name<<" followed suit with "<<*at(j)<<endl;
			erase(begin()+j);
			break;
		}
	}

	// if randomed card has larger rank than leadingTrump, replace it with result card
	if(leadingTrump < result)
		leadingTrump = result;

	return result;
}