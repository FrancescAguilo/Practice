#include "myList.h"




List::List() {

}

List::~List() {

}

void List::Push_back(int value) {
	if (first != nullptr) {
		node* tmp = new node;
		last->next = tmp;
		tmp->data = value;
		last = tmp;
		numElements++;
	}
	else {
		node* tmp = new node;
		tmp->next = nullptr;
		tmp->data = value;
		first = tmp;
		last = tmp;
	}
}

void List::Pop_back() {
	if (first != nullptr) {
		node* tmp = first;
		while (tmp != nullptr) {
			if (tmp->next == last) {
				tmp->next = nullptr;
				last = tmp;
				numElements--;
			}
			else {
				tmp = tmp->next;
			}
		}
	}
}

void List::Push_front(int value) {
	if (first != nullptr) {
		node* tmp = new node;
		tmp->data = value;
		tmp->next = first;
		first = tmp;
		numElements++;
	}
}

void List::Pop_front() {
	if (first != nullptr) {
		node* tmp = first;
		tmp = first;
		first = first->next;
		tmp->next = nullptr;
		delete tmp;
		numElements--;
	}
}

bool List::IsEmpty() const {
	int cont = 0;
	if (first != nullptr) {
		node* tmp = first;
		while (tmp != nullptr) {
			tmp = tmp->next;
			cont++;
		}
	}
	return (cont == 0);
}

int List::Front() const {
	if (first != nullptr) {
		return first->data;
	}

}

int List::Back() const {
	if (first != nullptr) {
		return last->data;
	}

}

int List::Size()const {
	/*int cont = 0;
	if (first != nullptr) {
		node* tmp = first;
		while (tmp != last) {
			tmp = tmp->next;
			cont++;
		}
	}*/
	return numElements;
}

void List::Erase(int value) {
	if (first != nullptr) {
		node* tmp = first;
		while (tmp != nullptr) {
			if (value == tmp->next->data) {
				//delete
				tmp->next = tmp->next->next;
				tmp = tmp->next;
				tmp->next = nullptr;
				numElements--;
			}
			else {
				tmp = tmp->next;
			}
		}
		delete tmp;
	}
}

void List::Insert(int value1, int value2) {
	if (first != nullptr) {
		node* tmp = first;
		node* tmp2 = first;//????
		while (tmp != nullptr) {
			if (value1 == tmp->next->data) {
				tmp = tmp2;
				tmp2->data = value2;
				tmp2->next = tmp->next;
				tmp->next = tmp2;
				numElements++;
			}
			else {
				tmp = tmp->next;
			}
		}
	}
}


//en la firma de la sobrecarga de este operador que nos habeis dado a traves del .h 
//faltaba poner el tipo (he supuesto que era bool), si no funciona al ejecutar es eso

bool operator==(const List& l1, const List& l2) {
	if (l1.first != nullptr && l2.first != nullptr) {
		int cont = 0;
		List::node* tmp = l1.first;
		List::node* tmp2 = l2.first;
		if (l1.numElements != l2.numElements) {
			return false;
		}
		else {
			while (tmp != nullptr) {
				if (tmp->data == tmp2->data) {
					cont++;
				}
				tmp = tmp->next;
				tmp2 = tmp2->next;
			}
			return (cont == l1.numElements);
		}
	}
}
std::ostream& operator<<(std::ostream& o, const List& l) {
	List::node *tmp = l.first;
	while (tmp != nullptr) {
		o << tmp->data << " ";
		tmp = tmp->next;
	}
	return o;
}


