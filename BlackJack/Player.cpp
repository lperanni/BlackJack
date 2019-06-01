#include "Player.h"


Player::Player(string name) {
	this->win = false;
	this->name = name;
}


void Player::addToHand(Card newCard) {
	this->hand.push_back(newCard);
}

Player::~Player() {
	this->hand.clear();
}