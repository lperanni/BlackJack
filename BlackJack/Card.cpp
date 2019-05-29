#include "Card.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>


using namespace std;


char* Suits[] = { "Hearts", "Clubs", "Spades", "Diamonds" };

Card::Card(int suit, int val, string name) {

	this->name = name;
	this->cardSuit = Suits[suit];
	this->value = val;

	switch (suit)
	{
	case  0:
		symbol = "♥";
		break;
	case  1:
		symbol = "♣";
		break;
	case  2:
		symbol = "♠";
		break;
	case  3:
		symbol = "♦";
		break;
	}
}

void Card::cardImg() {



	cout << "\t\t___________" << endl;
	cout << "\t\t|"<<name<<"        |" << endl;
	cout << "\t\t|"<<symbol<<"        |" << endl;
	cout << "\t\t|         |" << endl;
	cout << "\t\t|         |" << endl;
	cout << "\t\t|        "<<value<<"|" << endl;
	cout << "\t\t|        "<<symbol<<"|" << endl;
	cout << "\t\t|_________|" << endl;


}