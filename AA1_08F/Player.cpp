#include "Player.h"


void Player::InsertCard(Card c) {
	hand.push(c);
}

Card Player::GetCard() {//carta aleatoria de tu mano
	std::priority_queue<Card, std::vector<Card>, Card::Greater> tmp(hand);
	std::vector<Card> aux;
	int i = 0;
	while (!tmp.empty()) {
		aux[i] = tmp.top();
		tmp.pop();
		i++;
	}
	return aux[rand() % aux.size()];
}

Card Player::GetCard(Suit s) {//carta con valor mas alto del palo
	std::priority_queue<Card, std::vector<Card>, Card::Greater> tmp(hand);
	int i = 0;
	while (!tmp.empty()) {
		if (tmp.top().palo == s) {
			return tmp.top();
		}
		tmp.pop();
		i++;
	}

	
}

void Player::PrintHand() {
	std::priority_queue<Card, std::vector<Card>, Card::Greater> aux(hand);
	std::cout << "Cartas:\n";
	for (int i = 0; i < aux.size(); i++) {
		std::cout << i << "-" << aux.top().palo << "/" << aux.top().valor << std::endl;
		aux.pop();
	}
}