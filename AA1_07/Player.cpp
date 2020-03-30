#include "Player.h"

Player::Player() {

}

Ball Player::Gun::shoot() {
	std::vector<Ball>::iterator it = gunCharger.begin();
	Ball aux = gunCharger[0];
	gunCharger.erase(it);
	return aux;
}

Player::Player(std::string name, int position) {
	
	name = name;
	gun.pos = position;
	score = 0;
	gun.gunCharger.resize(20);
	
	for (int i = 0; i < 20; i++) {
		gun.gunCharger[i].color = static_cast<color> (rand() % 6);
	}
}
