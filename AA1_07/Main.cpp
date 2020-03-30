#include <stdio.h>
#include <string> 
#include <random>
#include <iostream>
#include <time.h>
#include <Windows.h>


void main() {
	bool exit = false;
	while (!exit) {
		if (GetAsyncKeyState(VK_ESCAPE)) {
			exit = true;
		}
	

		system("CLS");
	}

}