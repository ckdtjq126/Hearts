#include <string>
#include <cassert>
#include <iostream>
#include "Card.h"

using namespace std;

const string Card::RankName = "23456789TJQKA";
const string Card::SuitName = "SDCH";
const int Card::numRanks = RankName.length();
const int Card::numSuits = SuitName.length();
const int Card::numCards = Card::numRanks * Card::numSuits;
const Card Card::TwoOfClubs (Card::Two, Card::Clubs);
const Card Card::QueenOfSpades (Card::Queen, Card::Spades);

// Default Constructor for Card
Card::Card() : rank(Ace), suit(Spades) {}

// Card Constructor consuming rank and suit as inputs
Card::Card (Rank r, Suit s):rank(r), suit(s){}

// Card Constructor consuming string as an input
Card::Card (string sCard){

	if(sCard[0] == Card::RankName[0])
		Card::rank = Two;
	else if(sCard[0] == Card::RankName[1])
		Card::rank = Three;
	else if(sCard[0] == Card::RankName[2])
		Card::rank = Four;
	else if(sCard[0] == Card::RankName[3])
		Card::rank = Five;
	else if(sCard[0] == Card::RankName[4])
		Card::rank = Six;
	else if(sCard[0] == Card::RankName[5])
		Card::rank = Seven;
	else if(sCard[0] == Card::RankName[6])
		Card::rank = Eight;
	else if(sCard[0] == Card::RankName[7])
		Card::rank = Nine;
	else if(sCard[0] == Card::RankName[8])
		Card::rank = Ten;
	else if(sCard[0] == Card::RankName[9])
		Card::rank = Jack;
	else if(sCard[0] == Card::RankName[10])
		Card::rank = Queen;
	else if(sCard[0] == Card::RankName[11])
		Card::rank = King;
	else if(sCard[0] == Card::RankName[12])
		Card::rank = Ace;

	if(sCard[1] == Card::SuitName[0])
		Card::suit = Spades;
	else if(sCard[1] == Card::SuitName[1])
		Card::suit = Diamonds;
	else if(sCard[1] == Card::SuitName[2])
		Card::suit = Clubs;
	else if(sCard[1] == Card::SuitName[3])
		Card::suit = Hearts;
}

// Card default destructor
Card::~Card (){
	rank = Ace;
	suit = Spades;
}

// gets rank of the card
Card::Rank Card::getRank () const{
	return Card::rank;
}

// gets suit of the card
Card::Suit Card::getSuit () const{
	return Card::suit;
}

// gets hearts value of the card
int Card::getHeartsValue () const{
	if(Card::suit == Hearts)
		return 1;
	else if (Card::rank == Queen && Card::suit == Spades)
		return 13;
	else return 0;
}

// checks if input string is a legal card
bool Card::stringIsALegalCard (string s){
	bool sRank = false;
	bool sSuit = false;

	// checks if string is of size 2
	if (s.size() != 2){
		return false;
	}

	// checks the rank is in the set enum Rank
	for(int i = 0; i < Card::numRanks;i++){
		if(s[0] == Card::RankName[i]){
			sRank = true;
			break;
		}
	}

	// checks the suit is in the set enum Suit
	for(int j = 0; j < Card::numSuits; j++){
		if(s[1] == Card::SuitName[j]){
			sSuit = true;
			break;
		}
	}

	// if rank and suit are legal then return true
	if(sRank && sSuit)
		return true;
	else return false;
}

// Overloaded operators: equlity
extern bool operator== (const Card& c1, const Card& c2){
	if(c1.getRank() == c2.getRank() && c1.getSuit() == c2.getSuit())
		return true;
	else return false;
}

// Overloaded operators: comparison return true if second card has larger value
extern bool operator< (const Card& c1, const Card& c2){
	if(c1.getRank() < c2.getRank() || (c1.getRank() == c2.getRank() && c1.getSuit() < c2.getSuit()))
		return true;
	else return false;
}

// Overloaded operators: output
extern ostream& operator<< (ostream &out, const Card &c){
	cout<<Card::RankName[c.getRank()]<<Card::SuitName[c.getSuit()];
	return out;
}

// Overloaded operators: input
extern istream& operator>> (istream& in, Card& c){
	string sCard;
	in>>sCard;

	// checks if card is legal
	if(!Card::stringIsALegalCard(sCard)){
		cerr<<"Error, "<<sCard<<" is not a legal card. Aborting."<<endl;
		exit(1);
	}

	// if card is legal then put input card to c
	c = Card::Card(sCard);

	return in;
}