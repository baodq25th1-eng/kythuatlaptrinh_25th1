#include <string>
using namespace std;
struct Account {
	string lnk, usr, pwd, desc;
	friend ostream& operator<<(ostream& os, Account& b) {
		os << "Account information: " << endl;
		os << "\t+ Link: " << b.lnk << endl;
		os << "\t+ User Name: " << b.usr << endl;
		os << "\t+ Author name: " << b.author.name << endl;
		return os;
	}
	friend ostream& operator<<(ostream& os, Account& b) {
		cout << "Account information: " << endl;
		cout << "\t+ Id: ";
		in >> b.id
			cout << "\t+ Link: ";
		in.ignore();
		getline(in, b.lnk);
		cout << "\t+ User name: ";
		in.ignore();
		getline(in, b.usr);
		cout << "\t+ Password: ";
		getline(in, b.pwd);
		cout << "\t+ Description: ";
		getline(in, b.desc);
		return in;
	}

};

