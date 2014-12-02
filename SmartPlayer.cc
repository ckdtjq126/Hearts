#include "SmartPlayer.h"

extern Card leadingTrump;

// constructor for SmartPlayer with name
SmartPlayer::SmartPlayer(string pname): Player(pname) {}

// pick a lead card from SmartPlayer's Hand
Card SmartPlayer::lead(){
	Card result = *at(0);	// set current result Card to 0-th card
	int index=0;			// integer used to find index of result card

	// pick the lowest card from SmartPlayer's Hand
	for(unsigned int i = 1; i < size(); i++){
		if(*at(i) < result){
			result = *at(i);
			index = i;
		}
	}

	// Print leading Card
	cout<<"  "<<name<<" led "<<*at(index)<<endl;
	erase(begin()+index);

	return result;
}

// If there is no suit-matching card, throw card with certain option
Card SmartPlayer::throwOff(){
	int index = 0;			// integer used to find index of result card 
	Card result;
	for(unsigned int i = 0; i < size(); i++){

		// if Qeen of Spades exists, throw it immediately
		if(*at(i) == Card::QueenOfSpades){
			result = Card::QueenOfSpades;
			index = i;
			break;
		}

		// set current result card to first card in hand
		else if(i == 0)
			result = *at(0);

		// if current result card is not hearts, but card with Suit::Hearts exists, replace result card with it
		else if(at(i)->getSuit() == Card::Hearts && result.getSuit() != Card::Hearts){
			result = *at(i);
			index = i;
		}

		// both result card and hand card are Suit::Hearts then compare rank. Output lowest with heart suit. 
		else if(at(i)->getSuit() == Card::Hearts && result.getSuit() == Card::Hearts && result.getRank() < at(i)->getRank()){
			result = *at(i);
			index = i;
		}

		// if result card is not Suit::Hearts then just output highest card
		else if(result.getSuit() != Card::Hearts && result < *at(i)){
			result = *at(i);
			index = i;
		}
	}

	// print
	cout<<"  "<<name<<" threw off "<<*at(index)<<endl;
	erase(begin()+index);

	return result;
}

// pick a suit-matching card from SmartPlayer's Hand
Card SmartPlayer::followSuit(Card c){
	Card result;	// result card
	int total = 0;	// total number of suit-matching and/or lesser-ranked than leadingTrump.

	// Find and put cards from hand, which are suit-matching and lesser-ranked than leadingTrump, into vector
	for(unsigned int i = 0; i < size(); i++){
		if(at(i)->getSuit() == c.getSuit() && at(i)->getRank() < leadingTrump.getRank())
			total++;
	}

	// if there is no suit-matching AND lesser-ranked card in hand.
	if(total == 0){
		// calculate the number of just suit-matching cards
		for(unsigned int i = 0; i < size(); i++){
			if(at(i)->getSuit() == c.getSuit())
				total++;
		}

		// If there is no suit-matching cards in hand, smartly choose next card.
		if(total == 0)
			return SmartPlayer::throwOff();

		// If there exists at least one suit-matching card
		else{
			// compare ranks for all suit-matching cards, result should be the lowest card
			for(unsigned int i = 0, k = 0; i < size();i++){
				if(at(i)->getSuit() == c.getSuit()){
					// set result to first suit-matching card
					if(k == 0){
						result = *at(i);
						k++;
					}					
					// once result is set, compare it with next suit-matching card
					else if(at(i)->getRank() < result.getRank())
						result = *at(i);
				}
			}
			// set current leadingTrump to result card since the rank is higher.
			leadingTrump = result;
		}
	}

	// If there exists at least one suit-matching and lesser-ranked card
	else{
		// compare ranks for all suit-matching AND lesser-ranked cards, result should be the lowest card
		for(unsigned int j = 0, k = 0; j < size(); j++){
			if(at(j)->getSuit() == c.getSuit() && at(j)->getRank() < leadingTrump.getRank()){				
				// set result to first suit-matching card
				if(k == 0){
					result = *at(j);
					k++;
				}
				// once result is set, compare it with next suit-matching and lesser-ranked card
				else if(at(j)->getRank() > result.getRank())
					result = *at(j);
			}
		}
		// set current leadingTrump to result card.
	}

	// Find result card from hand then print
	for(unsigned int index = 0; index < size();index++){
		if(result == *at(index)){
			cout<<"  "<<name<<" followed suit with "<<*at(index)<<endl;
			erase(begin()+index);
			break;
		}
	}

	return result;
}