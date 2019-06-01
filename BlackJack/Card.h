#ifndef CARD_H
#define CARD_H

#include <string>


using namespace std;


class Card
{
public:
	Card(int suit, int val, string name);
	void cardImg();
	int getVal() { return this->value; };
	void changeAceValue();

private:
		
	string cardSuit;
	int value;
	string name;
	string symbol;
	

};


#endif // !CARD_H

