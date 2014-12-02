#ifndef __CARD_H__
#define __CARD_H__

#include <string>
#include <cstdlib>
using namespace std;

class Card {
    public:
	// Some (static) constants and types for rank and suit.
	enum Rank {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
		    Jack, Queen, King, Ace};
	static const string RankName;
	static const int numRanks;

	enum Suit {Spades, Diamonds, Clubs, Hearts};
	static const string SuitName;
	static const int numSuits;
	static const int numCards;

	// Two special cards, which are compared by value in various places
	static const Card TwoOfClubs;
	static const Card QueenOfSpades;

	// Default Constructor
	Card ();
	// Constructor consuming rank and suit as inputs
	Card (Rank r, Suit s);
	// Constructor taking a char string as an input
	Card (string sCard);
	// Card destructor
	~Card ();

	// gets rank of the card
	Rank getRank () const;	
	// gets suit of the card
	Suit getSuit () const;
	// gets hearts value of the card
	int getHeartsValue () const;

	// checks if input string is a legal card
	static bool stringIsALegalCard (string s);

    private:
	Rank rank;
	Suit suit;
};

// Overloaded operators: equlity
extern bool operator== (const Card& c1, const Card& c2);
// Overloaded operators: comparison return true if second card has larger value
extern bool operator< (const Card& c1, const Card& c2);
// Overloaded operators: output
extern ostream& operator<< (ostream &out, const Card &c);
// Overloaded operators: input
extern istream& operator>> (istream& in, Card& c);

#endif /* __CARD_H__ */
