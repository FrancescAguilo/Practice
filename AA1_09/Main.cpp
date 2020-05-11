#include <stdio.h>
#include <string> 
#include <iostream>
#include <vector>
#include<Windows.h>
#include <time.h>
#include <list>

std::list<int> SuperMerge(std::list<int> l1, std::list<int> l2) {
	std::list<int> l = l1;
	l.sort();
	l2.sort();
	l.merge(l2);
	l.reverse();
	return l;
}

void PrintReverse(std::list<int> l1) {
	std::list<int> l = l1;
	l1.reverse();
	for (std::list<int>::iterator it = l1.begin(); it != l1.end(); it++) {
		std::cout << *it << ",";
	}
	std::cout << std::endl;
}

bool IsBalanced(std::list<char> l1) {
	int i = 0;
	for (std::list<char>::iterator it = l1.begin(); it != l1.end(); it++) {
		if (*it == '(') {
			i++;
		}
		if (*it == ')') {
			i--;
		}
	}

	return (i == 0);
}

std::ostream& operator<<(std::ostream& ostr, std::list<int> list)
{
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) {
		ostr << *it << ",";
	}
	return ostr;
}

void main() {
	std::list<int> l1, l2, l3;
	std::list<char> l4 = { '(',')',')','(' };
	
	l1.push_back(128);
	l1.push_back(4);
	l1.push_back(123);

	l2.push_back(712);
	l2.push_back(138);
	l2.push_back(92);



	l3 = SuperMerge(l1, l2);
	std::cout << "SuperMerge output: ";
	std::cout << l3;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "PrintReverse output: ";
	PrintReverse(l1);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "IsBalanced output: ";
	bool balanced = IsBalanced(l4);
	std::cout << balanced;

	std::cout << std::endl;
	std::cout << std::endl;
	system("pause");
}