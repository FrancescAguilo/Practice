#pragma once
#include <stack>
#include <queue>
#include "Player.h"

class Game
{
	Player p1, p2, p3, p4;
	std::stack<Card> deck;
	std::stack<Card> discarted;

	Game();
	Card GetNewCard();
	void DiscardeCard(Card c);
	void PrintDiscarded();
};

