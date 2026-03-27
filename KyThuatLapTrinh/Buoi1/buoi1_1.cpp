#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


struct person {
	int id;	
	string name;	
	int age;	
	string address;
};
void viewpersonlist(vector<person> p) {
	if (p.size() == 0)
		cout << " an empty list" << endl;
	else {
		for (int i = 0; i < p.size(); i++) {
			cout << "person " << (i + 1) << endl;
			cout << "\t+id: " << p[i].id << endl;
			cout << "\t+name: " << p[i].name << endl;
			cout << "\t+age: " << p[i].age << endl;
			cout << "\t+address: " << p[i].address << endl;
		}
	}
}
void addperson(vector<person> p) {
	person a;
	cout << "+ id:";
	cin >> a.id;
	cout << "+name:";
	cin.ignore();
	getline(cin, a.name);
	cout << "+age:";
	cin >> a.age;
	cout << "+address:";
	cin >> a.address;
	p.push_back(a);
	cout << "add a person successfully" << endl;
}
void removeperson(vector<person>& p, int id) {
	for (auto i = p.begin(); i != p.end(); i++) {
		if (i->id == id) {
			p.erase(i);
			cout << "remove a person successfully" << endl;
			return;
		}
	}
	cout << "not found person with id" << id << endl;
}
bool findperson(vector<person>p, string name) {
	for (person i : p) {
		if (i.name == name) {
			return true;
		}
	}
	return false;
}
void exporttofile(vector<person>p, string filename) {
	ofstream file(filename, ios::binary);
	if (!file) {
		cout << "can't open this file" << filename << endl;
		return;
	}
	for (person i : p) {
		file.write(reinterpret_cast<const char*>(&i), sizeof(i));

		size_t namelength = i.name.size();
		file.write(reinterpret_cast<const char*>(&namelength), sizeof(namelength));
		file.write(i.name.c_str(), namelength);

		file.write(reinterpret_cast<const char*>(&i.age), sizeof(i.age));

		size_t addresslength = i.address.size();
		file.write(reinterpret_cast<const char*>(&addresslength), sizeof(addresslength));
		file.write(i.address.c_str(), addresslength);
	}
}
void readfromfile(vector<person>&p, string filename) {
	ifstream file(filename, ios::binary);
	if (!file) {
		cout << "can't open this file"<< endl;
		return;
	}
	while (p.size() > 0)
	{
		p.pop_back();
	}
	person i;
	while (file.peek() != EOF) {
		file .read(reinterpret_cast<char*>(&i), sizeof(i));
		
		size_t namelength;
		file.read(reinterpret_cast<char*>(&namelength), sizeof(namelength));
		i.name.resize(namelength);
		file.read(&i.name[0], namelength);

		file.read(reinterpret_cast<char*>(&i.age), sizeof(i.age));

		size_t addresslength;
		file.read(reinterpret_cast<char*>(&addresslength), sizeof(addresslength));
		i.address.resize(addresslength);
		file.read(&i.address[0], addresslength);

		p.push_back(i);
	}
}
	
int main() {
	vector <person> list;
	do  {
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
			viewpersonlist(list);
			break;
		}
		case 2: {
			addperson(list);
			break;
		}
		case 3: {
			int id;
			cout << "input id to remove: ";
			cin >> id;
			removeperson(list, id);
			break;
		}
		case 4: {
			string name;
			cout << "input name to find: ";
			cin.ignore();
			getline(cin, name);
			bool res = findperson(list, name);
			if (res)
				cout << "found person with name " << name << endl;
			else
				cout << " person isn't existed " << endl;
			break;
		}
		case 5: {
			exporttofile(list, "25th1.dla");
			cout << "export successfully" << endl;
			break;
		}
		case 6: {
			readfromfile(list, "25th1.dla");
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
	}
	return 0;
}
