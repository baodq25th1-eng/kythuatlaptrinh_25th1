#include "LinkedList.h"
#include <iostream>

template <typename T>
void LinkedList<T>::Show() {
	if (head == NULL) {
		cout << "no data available" << endl;
		return;

	}
	Node<T>* item = head;
	while (item)
}