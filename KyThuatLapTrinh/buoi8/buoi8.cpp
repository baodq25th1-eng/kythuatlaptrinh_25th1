
#include <iostream>
#include"Car.h"
#include "linkedlist.h"
#include "../buoi7/linkedlist.h"
int main()
{
	LinkedList<Car> car = { NULL };
	do {
		system("cls");
		cout << "-----------CAR MANAGEMENT---------" << endl;
		cout << "1. show all Car" << endl;
		cout << "2. Add a Car" << endl;
		cout << "3. Delete a Car" << endl;
		cout << "4. Update a Car " << endl;
		cout << "5. find a Car " << endl;
		cout << "6. export to file" << endl;
		cout << "7. inport from file" << endl;
		cout << "0. exit" << endl;
		cout << "------------------------------------------" << endl;
		cout << "enter choice: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: {
		}
		case 2: {
			Car c;
			cin >> c;
			car.Add(c);
			break;
		}
		case 3: {
			int removeId;
			cout << "enter Car id to remove: ";
			cin >> removeId;
			car.Remove(removeId);
			break;
		}
		case 4: {
			break;
		}
		case 5: {
			break;
		}
		case 6: {
			break;
		}
		case 7: {
			break;
		}
		case 0: {
			return 0;
		}
		default: {
			cout << "invalid choice, try again" << endl;
			system("pause");
		}


		}
		system("pause");
		cout << "Press any key to continue..." << endl;
	} while (true);
}