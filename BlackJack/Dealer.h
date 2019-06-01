#ifndef DEALER_H
#define DEALER_H

#include "Card.h"
#include <vector>
#include <iostream>


using namespace std;

class Dealer
{
public:

	Dealer();
	void addToHand(Card newCard);
	int getHandVal() {
		return this->handValue;
	}
	void setHandVal(int val) {
		this->handValue += val;
	}
	~Dealer();
	bool win;

private:

	vector<Card> hand;
	int handValue = 0;

};


#endif // !DEALER_H