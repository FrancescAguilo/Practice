#pragma once
#include "Player.h"

class Panel
{
	//Ball *panel;
	std::vector<Ball> panel;
	int size;

	void init() {
		//hacer cin para leerlo
		panel.resize(size);
	}

	void insert(int position, Ball ball);

	int verifier(int position, Ball ball);

	void deleteThree(int position);

	void insertThree();

};

