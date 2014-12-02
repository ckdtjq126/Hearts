#include "Deck.h"
#include <map>

// constructor and destructor
Deck::Deck(){}
Deck::~Deck(){
	for(unsigned int i = 0; i < size();i++){
		delete at(i);
	}
}

// generate sorted order of cards
void Deck::generate(){
	for(int i = 0; i < 4;i++){
		for(int j = 0; j < 13; j++){
			this->push_back(new Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(i)));
		}
	}
}

// checks if deck is legal return true if there are no duplicates within 52 cards
bool Deck::playingWithAFullDeck () const {
	map<Card, int> list;
	pair<map<Card, int>::iterator,bool> ret;

	// adding all the cards into list and see if duplicate exists
	list.insert(pair<Card, int>(*at(0), 0));
	for(int i = 1; i < 52; i++){
		ret = list.insert(pair<Card, int>(*at(i),i));

		// if duplicate found, then return false
		if(!ret.second)
			return false;
	}
	return true;
}

// prints deck
void Deck::print() const{
	for(unsigned int i = 0; i < size(); i++){
		cout<<*at(i)<<" ";
	}
	cout<<endl;
}

// Overloaded operators: input
extern istream& operator>> (istream& in, Deck& deck){
	Card *c;

	// inputs a card and put the card into deck
	for(int i = 0; i < 52; i++){
		c=new Card();
		cin>>*c;
		deck.push_back(c);
	}
	
	// if deck is not legal, print error message & deck and exit(1)
	if(!deck.playingWithAFullDeck()){
		cerr<<"Error, incomplete deck. Aborting."<<endl;
		cerr<<"    ";
		for(int i = 0; i < 52; i++){
			cout<<*deck.at(i)<<" ";
		}
		cerr<<endl;
		exit(1);
	}

	return in;
}
