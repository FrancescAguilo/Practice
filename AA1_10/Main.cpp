#include <stdio.h>
#include <string> 
#include <iostream>
#include <vector>
#include<Windows.h>
#include <time.h>
#include <list>
#include "myList.h"


void main() {
	List l;
	l.Push_back(3);
	l.Push_back(5);
	l.Push_back(6);
	l.Pop_front();
	l.Push_front(2);
	


	std::cout << l;
	std::cout << std::endl;
	system("pause");
}