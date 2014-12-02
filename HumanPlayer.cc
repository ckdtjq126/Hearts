#include "HumanPlayer.h"

extern Card leadingTrump;


// HumanPlayer constructor
HumanPlayer::HumanPlayer(string pname): Player(pname) {}

// Let the interactive player choose any card to lead
Card HumanPlayer::lead(){
	string card; // temporary space for a string value
	// print current hand of the interactive player
	cout<<"Human Player ";
	this->print();

	// takes input until the input format is correct
	while(1){
		cout<<"What card would you like to play, "<<name<<"? ";
		cin>>card; // read input

		// if the input is not in legal Card format, produce an error message
		if(!Card::stringIsALegalCard(card)){
			cerr<<card<<" is not a card"<<endl;
		}

		// if the card is in legal Card format,
		else{
			Card result(card); // creates a Card using the input
			// finding the input(now it's a Card) is in the hand which the interactive player holds
			for(unsigned int i=0; i<size(); i++){
				// if the interactive player has the card
				if(result==*at(i)){
					result=*at(i); 
					cout<<"  "<<name<<" led "<<result<<endl;
					erase(begin()+i); // now the hand no longer has the picked up card
					return result; // returns the played card
				}
			}
			// the card which the interactive player has chosen is not in the his/her hand
			cerr<<result<<" is not in your hand"<<endl;
		}
	}
}

// Let the interactive player choose any card to throw off
Card HumanPlayer::throwOff(){
	string card; // temporary space for a string value

	// takes input until the input format is correct
	while(1){
		cout<<"What card would you like to play, "<<name<<"? ";
		cin>>card; // read input

		// if the input is not in legal Card format, produce an error message
		if(!Card::stringIsALegalCard(card)){
			cerr<<card<<" is not a card"<<endl;
		}

		// if the card is in legal Card format,
		else{
			Card result(card); // creates a Card using the input
			// finding the input(now it's a Card) is in the hand which the interactive player holds
			for(unsigned int i=0; i<size(); i++){
				// if the interactive player has the card
				if(result==*at(i)){
					result=*at(i); 
					cout<<"  "<<name<<" threw off "<<result<<endl;
					erase(begin()+i); // now the hand no longer has the picked up card
					return result; // returns the played card
				}
			}
			// the card which the interactive player has chosen is not in the his/her hand
			cerr<<result<<" is not in your hand"<<endl;
		}
	}
}

// Let the interactive player to choose suit-matching card
Card HumanPlayer::followSuit(Card c){
	string card; // temporary space for a string value
	bool SameSuitExist=false; // is the interactive player has the same suit card as leadingTrump?
	int index=-1; // use for finding index of his/her hand that matches the input 
	
	// print current hand of the interactive player
	cout<<"Human Player ";
	this->print();

	// check if the current hand of the interactive player has a card that has same suit as leadingTrump
	for(unsigned int i=0; i<size(); i++){
		if(at(i)->getSuit()==leadingTrump.getSuit()){
			SameSuitExist=true; 
			break;
		}
	}

	// if the interactive player does not have any card in his/her hand that has same suit as leadingTrump
	if(!SameSuitExist){
		return HumanPlayer::throwOff();
	}

	else{
		
		// takes input until the input format is correct
		while(1){
			cout<<"What card would you like to play, "<<name<<"? ";
			cin>>card; // read input

			// if the input is not in legal Card format, produce an error message 
			if(!Card::stringIsALegalCard(card)){
				cerr<<card<<" is not a card"<<endl;
			}

			// if the card is in legal Card format,
			else{
				Card result(card); // creates a Card using the input
				
				// finding the input(now it's a Card) is in the hand which the interactive player holds
				for(unsigned int i=0; i<size(); i++){
					
					// if the interactive player has the card
					if(result==*at(i)){
						index=i;
						break;
					}
				}

				// index is still -1 -> the interactive player does not have the same card as input card in his/her hand
				if(index==-1){
					cerr<<result<<" is not in your hand"<<endl;
				}

				// the interactive player has the same card as the input card
				else{

					// if the suit of the interactive player will play is different from the leadingTrump even though he/she has other cards
					// that has same suit as the leadingTrump
					if(result.getSuit()!=leadingTrump.getSuit()){
						cerr<<"You have at least one "<<Card::SuitName[leadingTrump.getSuit()]<<"; you must follow suit!"<<endl;
						index=-1;
					}
					// else play the card
					else{
						result=*at(index);
						cout<<"  "<<name<<" followed suit with "<<result<<endl;
						erase(begin()+index); // now the hand no longer has the picked up cards
						// compare leadingTrump and the card the interactive player has played, and reset the leadingTrump to that card if
						// the card he/she has played has higher value
						if(leadingTrump<result) 
							leadingTrump=result;
						return result; // returns the played card
					}
				}
			}
		}
	}
}