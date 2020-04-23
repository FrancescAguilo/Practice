#include "Player.h"


void Player::InsertCard(Card c) {
	hand.push(c);
}

Card Player::GetCard(Suit s) {
	Card tmp;
	return tmp;
}

Card Player::GetCard() {
	Card tmp;
	return tmp;
}

void Player::PrintHand() {
	std::priority_queue<Card, std::vector<Card>, Card::Greater> aux(hand);
	std::cout << "Cartas:\n";
	for (int i = 0; i < aux.size(); i++) {
		std::cout << i << "-" << aux.top().palo << "/" << aux.top().valor << std::endl;
		aux.pop();
	}
}