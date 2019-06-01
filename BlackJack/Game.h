#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Dealer.h"
#include "Player.h"
#include <vector>
#include "Card.h"

class Game
{
public:
	
	Game(int players);
	void play();
	void checkWinners();
	~Game();
	

private:

	int playerCount;
	Deck playingDeck;
	vector<Player> players;
	Dealer master;
	bool end = false;
};



#endif // !GAME_H
