#include "Dealer.h"

Dealer::Dealer() {
	this->win = false;
}


void Dealer::addToHand(Card newCard) {
	this->hand.push_back(newCard);
}

Dealer::~Dealer() {
	this->hand.clear();
	cout << "Dealer Destructor called" << endl;
}