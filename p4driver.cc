#include "Trick.h"
#include "Options.h"
#include <iostream>

using namespace std;

// current score of player1, player2, player3, player4
int curScore[4] = {0,0,0,0};

int main(int argc, char *argv[]){
	Deck newdeck;			// deck used to play HEARTS
	Trick trick;			// trick used to store dealt cards
	int currentHand = 1;	// current round of HEARTS
	int exceed=-1, win=0;	// index of player with exceeding op.getMaxPoints() and winner
	
	// list of players
	vector<Player*> playerlist;
	
	Options op; // option

	// takes all the argument and store them in op
	for(int arg_count=1; arg_count<argc; arg_count++){
		op.push_back((const char*)argv[arg_count]);
	}

	// include options to the game
	op.includeOptions(newdeck,playerlist);


	// ROUND STARTS
	while(1){
		// check if any player whose score is the biggest among 4 players exceeds op.getMaxPoints()
		for(int k = 0; k < 4;k++){
			if(k == 0 && op.getMaxPoints() < curScore[0])
				exceed = k;
			else if(exceed != -1 && exceed < k && curScore[exceed] < curScore[k]){
				exceed = k;		// if k-th player exceedes op.getMaxPoints(),
			}
			else if(exceed < k && op.getMaxPoints() < curScore[k]){
				exceed = k;
			}
		}
		
		// if game is over(i.e., someone exceeds op.getMaxPoints()), then print winner 
		// GOTO __GAMEOVER__:
		if(exceed != -1)
			break;
		// print list of cards in current deck
		cout<<endl<<endl;
		cout<<"At the beginning of hand "<<currentHand<<", here is the deck:"<<endl;
		cout<<"    ";
		newdeck.print();
		cout<<endl<<endl;
		
		// put cards into deck with certain order
		int index = currentHand+3;
		for(int i=51; i>=0;){
			for(int j = 0; j < 4; j++, i--, index++){
				if(index >= 4){
					index = index % 4;
				}
				playerlist.at(index)->push_back(newdeck.at(i));
			}
		}

		// PLAY
		trick.Play(playerlist,op.getMaxPoints(),currentHand);

		// HAND ENDED, CLEAR DECK and GENERATE NEW DECK and SHUFFLE
		for(unsigned int i = 0; i < newdeck.size();i++){
			delete newdeck.at(i);
		}
		newdeck.clear();
		newdeck.generate();
		newdeck.shuffle();	
		currentHand++;	// next HAND
	}

	// __GAMEOVER__
	cout<<endl<<"The game is over."<<endl;
	cout<<playerlist.at(exceed)->getName()<<" has exceeded "<<op.getMaxPoints()<<" points."<<endl;

	// determine winner with the lowest score
	for(int n = 0; n < 4; n++){
		if(curScore[n] < curScore[win]){
			win = n;
		}
	}

	// print winner
	cout<<"The winner is "<<playerlist.at(win)->getName()<<endl;

	// delete	
	for(int i=0; i<4; i++){
		delete playerlist.at(i);
	}
}