#include "Game.h"


using namespace std;


Game::Game(int players) {

	this->playerCount = players;

	
	for (int i = 0; i < this->playerCount; i++) {

		string tempName;
		cout << "Player " << i + 1 << ". Enter your name: " << endl;

		while (true) {
			if (cin >> tempName) {
				break;
			}
			else {
				cout << "Invalid input. Try again" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		

		Player* temp = new Player(tempName);

		this->players.push_back(*temp);
	}

	Dealer* newDealer = new Dealer();
	this->master = *newDealer;

	Deck* newDeck = new Deck();
	newDeck->shuffle();
	this->playingDeck = *newDeck;

}

void Game::checkWinners() {

	int max = 0;
	Player winner = players[0];

	for (int i = 0; i < playerCount; i++) {
		if (players[i].getHandVal() > max && players[i].getHandVal() <= 21) {
			max = players[i].getHandVal();
			winner = players[i];
		}
	}

	if ((master.getHandVal() >= winner.getHandVal() && master.getHandVal() <= 21) || winner.getHandVal() > 21) {
		cout << "Dealer wins! " << endl;
		return;
	}
	else if(master.getHandVal() > 21){
		cout << "Dealer busts. All players win!" << endl;
	}
	else {
		cout << "The winner is " << winner.getName() << " with " << winner.getHandVal() << " points!" << endl;
		return;
	}




}

void Game::play() {

	while (!this->end) {
		
		while (master.getHandVal() < 17) {

			cout << "Dealer plays Card!" << endl;
			Card temp = *playingDeck.draw();

			
			if (((master.getHandVal() + temp.getVal()) > 21) && (temp.getVal() == 11)) {
				temp.changeAceValue();
			}

			master.setHandVal(temp.getVal());
			temp.cardImg();
			master.addToHand(temp);

			cout << "Dealer Hand value is: " << master.getHandVal() << endl;
		
		}	

		cout << "Dealers Hand counts " << master.getHandVal() << endl;

		if (master.getHandVal() > 21) {
			return;
		}

		for (int i = 0; i < this->playerCount; i++) {

			bool choice = false;

			if (!players[i].getHandVal() >= 21) {
				continue;
			}

			cout << players[i].getName() << endl << "proceed with your Turn" << endl;

			while (!choice) {

			    choice = false;

				cout << "Player draws Card!" << endl;
				Card temp = *playingDeck.draw();
				players[i].setHandVal(temp.getVal());
				temp.cardImg();
				players[i].addToHand(temp);

				cout << "Current Hand Value is: " << players[i].getHandVal() << endl;
				cout << "Dealer Hand value is: " << master.getHandVal() << endl;

				if (players[i].getHandVal() > 21) {
					players[i].win = false;
					cout << players[i].getName() << " lost the game. You're busted!" << endl << endl;
					i++;
					break;
				}

				cout << "Do you want to continue drawing? (y/n) - ";
				char option;
				cin >> option;

				switch (option)
				{

					case 'y' :
						break;
					case 'n':
						choice = true;
						continue;
					default:
						cout << "Illegal input. Assuming draw" << endl;
						break;
				}

			}
		}

		this->end = true;

	}

	this->checkWinners();

}	 


Game::~Game() {

	this->players.clear();
	cout << "Game Destructor called" << endl;
}