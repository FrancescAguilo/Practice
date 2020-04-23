#pragma once
#include <vector>
#include <queue>
#include "Card.h"
#include <string>

class Player
{
public:

	std::string id; 
	std::priority_queue<Card,std::vector<Card>, Card::Greater> hand;

	void InsertCard(Card c);
	Card GetCard();
	Card GetCard(Suit s);
	void PrintHand();

};

