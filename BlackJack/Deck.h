#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>



class Deck
{
public:
	Card* draw();
	Deck();
	void shuffle();
	~Deck();

private:

	int cardCount;
	vector<Card *> deck;

};



#endif // !DECK_H
