

#include <iostream>
#include "Account.h"
#include "LinkedList.h"
int main()
{
	linkedList books = { NULL };
	do {
		system("cls");
		cout << "-----------BOOK MANAGEMENT---------" << endl;
		cout << "1. show all Account" << endl;
		cout << "2. Add a Account" << endl;
		cout << "3. Delete a Account" << endl;
		cout << "4. Update a Account " << endl;
		cout << "5. find a Account " << endl;
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
			Account.show();
			break;
			
		}
		case 2: {
			Account a;
			cin >> a;
			account.add(a);
			break;

		}
		case 3: {
			int removeId;
			cout << "enter account Id to remove:";
			cin >> removeId;
			account.Remove(remove);
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
		case 0: {
			return;
		}
		default: {
			cout << "Invalid choice, try again" << endl;
			break;
		}
		}
		system("pause");
		cout << "Press any key to continue..";
	} while (true);
}


