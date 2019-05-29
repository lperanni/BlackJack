#include "Deck.h"
#include <algorithm>


Deck::Deck() {

	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 13; j++) {

			string tempName;

			switch (j)
			{
			 case 10 :
				 tempName = "J";
				 break;
			 case 11:
				 tempName = "Q";
				 break;
			 case 12:
				 tempName = "K";
				 break;
			 case 0:
				 tempName = "A";
				 break;
			  default :
				 tempName = to_string(j + 1);
				 break;
			}

			Card* tempCard = new Card(i, j + 1, tempName);

			this->deck.push_back(tempCard);
		}
	}

	this->cardCount = 52;

}

Card* Deck::draw() {

	int randomIndex = (0 + (rand() % (int)(this->deck.size - 0 + 1)));

	Card* returnCard = this->deck[randomIndex];

	this->deck.erase(this->deck.begin() + randomIndex);

	this->cardCount--;

	return returnCard;

	
}

void Deck::shuffle() {


	random_shuffle(this->deck.begin(), this->deck.end());

}