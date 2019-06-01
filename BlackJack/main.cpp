#include <iostream>
#include "Card.h"
#include <ctime>
#include <cstdlib>
#include "Game.h"





int main() {

	srand(time(NULL));
	int playerCount = 0;
	int choice = 1;



	while (choice == 1) {



		cout << "\t\t\t\t\t\tBLACKJACK" << endl << endl << endl;

		cout << "\t\t\t\t\t   #############" << endl;
		cout << "\t\t\t\t\t   ##         ##" << endl;
		cout << "\t\t\t\t\t   #  ~~   ~~  #" << endl;
		cout << "\t\t\t\t\t   #  ()   ()  #" << endl;
		cout << "\t\t\t\t\t   (     ^     ) " << endl;
		cout << "\t\t\t\t\t    |         | " << endl;
		cout << "\t\t\t\t\t    |  {===}  | " << endl;
		cout << "\t\t\t\t\t    \\         /  " << endl;
		cout << "\t\t\t\t\t       -----    " << endl << endl;

		cout << "I am your Dealer Today. My name is Luciano, pleased to meet you!" << endl << endl;


		
		while (true)
		{
			cout << "Enter number of players: ";
			if (cin >> playerCount) {
				break;
			}
			else {
				cout << "Invalid input. Try again" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			
		}
		
		Game* match = new Game(playerCount);


		match->play();
		delete match;

		cout << "Play another Game?" << endl;

		while (true)
		{
			cout << "1. Yes\t2.No" << endl;
			if (cin >> choice) {
				if(choice == 1 || choice == 2)
					break;
				else {
					cout << "Invalid input. Try again" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else {
				cout << "Invalid input. Try again" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

		}
		

		system("CLS");


	}


}