
#include <iostream>
#include "Account.h"
#include "LinkedList.h"

int main()
{
	LinkedList<Account> account = { NULL };
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
			account.Add(a);
			break;




		}
		case 3: {
			int removeId;
			cout << "enter account id to remove: ";
			cin >> removeId;
			account.Remove(removeId);
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
			return 0;
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

