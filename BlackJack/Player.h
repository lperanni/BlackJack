#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Card.h"
#include <vector>

using namespace std;


class Player
{
public:
	Player(string name);
	string getName() { return this->name; };
	void addToHand(Card newCard);
	int getHandVal() {
		return this->handValue;
	}
	void setHandVal(int val) {
		this->handValue += val;
	}
	bool win;
	~Player();
private:
	string name;
	vector<Card> hand;
	int handValue = 0;
};


#endif // !PLAYER_H
