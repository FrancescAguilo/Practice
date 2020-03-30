#pragma once
#include <string>
#include <vector>
#include <random>

enum color { RED, BLUE, YELLOW, GREEN, WHITE, BLACK };

struct Ball {
	color color;
};

class Player
{
	std::string name;
	int score;

	struct Gun {
		
		int pos;
		std::vector<Ball> gunCharger;
		Ball shoot();
	};

	Gun gun;



	Player();
	Player(std::string name, int position);
};

