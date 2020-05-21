#pragma once
#include <iostream>
class List
{
public:

	struct node {
	 int data;
	 node *next;
	 node() : data(0), next(nullptr) {};
	 node(int _data, node *_next) :data(_data), next(_next) {};
	 };
	node *first; 
	node *last; 
	int numElements; 


	public:
	 List();
	 ~List();

	void Push_back(int value);
	void Pop_back();
	void Push_front(int value);
	void Pop_front();
	bool IsEmpty() const;
	int Front() const;
	int Back() const;
	int Size()const;
	void Erase(int value);
	void Insert(int value1, int value2);
	friend bool operator==(const List& l1, const List& l2);
	friend std::ostream& operator<<(std::ostream& o, const List& l);



};

