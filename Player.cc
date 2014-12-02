#include "Player.h"

// constructor for default player with name
Player::Player(string name){
	this->name=name;
}

// From hand, find Card::TwoOfClubs. return true if exists, return false otherwise
bool Player::TwoClubs(){
	for(unsigned int i = 0; i < size(); i++){
		if(at(i)->getRank() == Card::TwoOfClubs.getRank() && at(i)->getSuit() == Card::TwoOfClubs.getSuit()){
			erase(begin()+i);
			return true;
		}
	}
	return false;
}

// print all the cards in player's hand
void Player::print(){
	cout<<name<<" has these cards:"<<endl<<"    ";
	for(unsigned int i = 0; i < size(); i++){
		cout<<*at(i)<<" ";
	}
	cout<<endl;
}

// gets the name of player
string Player::getName(){
	return name;
}

// PlayCard for Player::lead()
Card Player::PlayCard(){
	return lead();
}

// PlayCard for Player::followSuit(Card)
Card Player::PlayCard(Card c){
	return followSuit(c);
}

