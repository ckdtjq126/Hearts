#include "Trick.h"

// current leadingTrump
Card leadingTrump;
extern int curScore[4];

// plays single round consumes playerList, maxScore, currentHand
void Trick::Play(vector<Player*>& playerList, int maxScore, int currentHand){

	int winner = 0;	// index of winner
	int leader = 0;	// index of player with leading card
	Card c[4];		// 4 cards used during a trick.
	
	// ROUND STARTS
	cout<<"Here are the hands for each player at the start of hand number "<<currentHand<<endl<<endl;

	// PRINT CARDS FOR EACH PLAYER
	for(int i=0; i<4; i++){
		playerList.at(i)->print();
		cout<<endl;
	}

	// HAND STARTS
	for(int handNum = 1; handNum < 14; handNum++){
		cout<<endl<<"Now starting round "<<handNum<<" of hand "<<currentHand<<endl;

		// FOR FIRST HAND, PLAYER WITH 2C LEADS
		if(handNum == 1){
			while(leader < 4){

				// if the player holds 2C, return its index.
				if(playerList.at(leader)->TwoClubs()){
					cout<<"  "<<playerList.at(leader)->getName()<<" has 2C and leads with it"<<endl;
					c[leader] = Card::TwoOfClubs;
					leadingTrump = Card::TwoOfClubs;
					break;
				}
				leader++;	// keep adding 1 to index to find player holding 2C
			}
		}

		// REST HANDS, THE WINNER OF THE PREVIOUS HAND LEADS
		else{
			c[leader] = playerList.at(leader)->PlayCard();
			leadingTrump = c[leader];
		}

		winner = leader;	// set current winner to Player leading the round.
		
		// PICK CARDS FROM THE REST OF PLAYERS (starts with leader + 1)
		for(int i = 0, j = leader+1; i < 3; i++, j++){
			if(j >= 4)
				j -= 4;
			c[j] = playerList.at(j)->PlayCard(c[leader]);

			// compare two Cards and set current winner
			if(c[winner].getSuit() == c[j].getSuit() && c[winner] < c[j]){
				winner = j;
			}
		}

		// PRINT WINNER
		cout<<"  "<<playerList.at(winner)->getName()<<" won the trick and added the following cards:"<<endl<<"    ";

		// WINNER COLLECTS 4 CARDS
		for(int i = 0; i < 4; i++){
			if(leader >= 4)
				leader -= 4;
			cout<<c[leader]<<" ";
			curScore[winner] += c[leader].getHeartsValue();	// adds heartsvalue to winner's score
			leader++;
		}

		cout<<endl;
		leader = winner;	// leader becomes winner of previous round
		
	// HAND ENDS
	}

	// PRINT SCORE
	cout<<endl<<"At the end of hand "<<currentHand<<", the score is:"<<endl;
	for(int k = 0; k < 4; k++){
		cout<<"    "<<playerList.at(k)->getName()<<"  "<<curScore[k]<<endl;
	}
}