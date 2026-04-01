#include <iostream>
#include <string>
using namespace std;
struct person {
    int id;
    string name;
	friend ostream& operator>> (ostream& os, const person& p) {
		os << "\t+ id:" << p.id << endl;
		os << "\t+ name:" << p.name << endl;
		return os;
	}
	friend istream& operator >> (istream& in, person& p) {
		cout << "input person infomation:" << endl;
		cout << " \t + id: ";
		in >> p.id;
		cout << " \t + name: ";
		in.ignore();
		getline(in, p.name);	
		in >> p.name;
		return in;
        

	}
};
struct node {
    person data;
    node* next;
	node(person x) : data(x), next(NULL) {}
};
struct linkedlist {
    node* head ;
	void show() {
		if (head == NULL) {
			cout << "empty list" << endl;
			return;
		}
		node* item = head;
		while (item != NULL) {
			cout << item->data;
			item = item->next;
		}
	}
	void add(person x) {
		node* newnode = new node(x);
		head = newnode;	
	}
	bool remove(int x) {
		if (head == NULL) {
			return false;
		}
		node* item = head;
		if (item->data.id == x) {
			head = item->next;
			delete item;
			return true;
		}
		while (item->next != NULL) {
			if (item->next->data.id == x) {
				node* temp = item->next;
				item->next = temp->next;
				delete temp;
				return true;
			}
			item = item->next;
		} 
	}
};

int main()
{
	linkedlist list = {NULL};
	do {
		system("cls");
		cout << "----human resoure---------" << endl;
		cout << "1. view person list" << endl;
		cout << "2. add a person" << endl;
		cout << "3. remove a person" << endl;
		cout << "4.find a person by name" << endl;
		cout << "5.export to file" << endl;
		cout << "6.import from file" << endl;
		cout << "0.exit" << endl;
		cout << "------------------------------" << endl;
		cout << "your command: ";
		int cmd;
		cin >> cmd;
		switch (cmd)
		{
		case 1: {
			list.show();
			
			break;
		}
		case 2: {
			person a;
			cin >> a;
			list.add(a);
			cout << "add a person successfully" << endl;
			break;
		}
		case 3: {
			int id;
			cout << "input id to remove: ";
			cin >> id;
			list.remove(id);
			break;
		}
		case 4: {
			string name;
			cout << "input name to find: ";
			cin.ignore();
			getline(cin, name);
			bool res = false;
			if (res)
				cout << "found person with name " << name << endl;
			else
				cout << " person isn't existed " << endl;
			break;
		}
		case 5: {
			
			cout << "export successfully" << endl;
			break;
		}
		case 6: {
			
			cout << "import successfully" << endl;
			break;
		}
		case 0: {
			return 0;
		}
		default:
			cout << "your command isn't found .try again..." << endl;
			break;
		}
		cout << "press enter to continue..." << endl;
		cin.ignore();
		cin.get();
	} while (true);
		return 0;
}

