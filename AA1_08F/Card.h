#pragma once
#include <iostream>
enum Suit { SPADES, COINS, CUPS, CLUBS };

class Card
{
public:
	Suit palo;
	int valor;

	struct Greater {
		bool operator()(const Card&c1, const Card& c2);
	};
	bool operator==(const Card& c2);

	
	Card();
	Card(Suit, int);



};

