#include <iostream>

template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>       
struct LinkedList {
	Node<T>* head;
	void Show();
	void Add(T item);
	bool Remove(int id);
	bool Update(int id);
	void Find(string userName);
	void Export(string fileName);
	void Import(string fileName);

};

template<typename T>
void LinkedList<T>::Show() {
	if (head == NULL) {
		cout << "no item avalable" << endl;
		return;
	}
	Node<T>* item = head;
	while (item != NULL) {
		cout << item->data << endl;
		item = item->next;
	}
}
template<typename T>
void LinkedList<T>::Add(T item) {
	Node<T>* newNode = new Node<T>;
	newNode->data = item;
	newNode->next = nullptr;
	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node<T>* item = head;
		while (item->next != nullptr) {
			item = item->next;
		}
		item->next = newNode;
	}

}
template<typename T>
bool LinkedList<T>::Remove(int id) {
	if (!head) {
		cout << "no account available" << endl;
		return false;
	}
	Node<T>* item = head;
	if (item->data.id == id) {
		head = item->next;
		delete item;
		return true;
	}
	while (item->next != nullptr) {
		if (item->next->data.id == id) {
			Node<T>* temp = item->next;
			item->next = item->next->next;
			delete temp;
			return true;
		}
		item = item->next;
	}
	return false;
}