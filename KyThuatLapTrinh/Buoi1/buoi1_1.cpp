#include <iostream>
#include <vector>
#include<string>
#include<fstream>
#include <list>
using namespace std;


struct person {
	int id;	
	string name;	
	int age;	
	string address;
};


void viewperson(person p) {
	if (p.size() == 0) 
	cout <<" an empty list";
	else {
		for (int i = 0; i < p.size(); i++) {
			cout << "person " << (i + 1) << endl;
			cout << "\t+ id:" << p[i].id << endl;
			cout << "\t+ name:" << p[i].name << endl;
			cout << "\t+ age:" << p[i].age << endl;
			cout << "\t+ address:" << p[i].address << endl;
		}
	}
}
void addperson(vector<person>& p) {
	person a;
	cout << +id:;
	cin >> a.id;
	cout << "+name: ";
	cin.ignore();
	getline(cin, a.name);
	cout << "+age: ";
	cin >> a.age;
	cout << "+address: ";
	cin >> a.address;
	p.push_back(a);
	cout << " add a person successfully";
}
void removeperson(vector<person>& p, int id) {
	for (auto i = p.begin(); i != p.end(); i++) {
		if (i->id == id) {
			p.erase(i);
			cout << " remove a person successfully";
			return;
		}
	}
	cout << " not found person with id" << id <<endl;
}
int main() {
	vector<person> list;
	do {
		system("cls");
		cout << "------human resource ------" << endl;
		cout << "1. view person list " << endl;
		cout << "2. add a person " << endl;
		cout << "3. remove a person " << endl;
		cout << "4. find a person by name " << endl;
		cout << "5. export to file " << endl;
		cout << "6. import from file " << endl;
		cout << "0. exit " << endl;
		cout << "------------------------------" << endl;
		cout << "your command: ";
		int cmmd;
		cin >> cmmd;
		switch (cmmd)
		{
		case1: {
			break;
		}
	case2: {
		 break;
	    }
      case3: {
        break;
	  }
      case4: {
        break;
      }
      case5: {
        break;
      }
      case6: {
       break;
      }
      case0: {
       return 0;
      }
		default:
			cout << " your command isn't found .try again..." << endl;
			break;
		}
		cout << " press enter to continue...";
		cin.ignore();	
		cin.get();
																																							

	} while (true);
	return 0;


		
}
	

	
