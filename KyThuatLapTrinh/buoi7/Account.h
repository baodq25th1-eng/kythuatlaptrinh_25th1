#include <string>
using namespace std;
struct Account {
	int id;
	string lnk, usr, pwd, desc;
	friend ostream& operator<<(ostream& os, Account& b) {
		os << "Account information: " << endl;
		os << "\t+ Id: " << b.id << endl;
		os << "\t+ Link: " << b.lnk << endl;
		os << "\t+ User Name: " << b.usr << endl;
		os << "\t+ Passord: " << b.pwd << endl;
		os << "\t+ Description: " << b.desc << endl;
		return os;
	}
	friend istream& operator>>(istream& in, Account& b) {
		cout << "Account information: " << endl;
		cout << "\t+ Id: ";
		in >> b.id;
		cout << "\t+ Link: ";
		in.ignore();
		in.getline( b.lnk,50);
		cout << "\t+ User name: ";
		in.ignore();
		in.getline( b.usr,50);
		cout << "\t+ Password: ";
		in.getline( b.pwd,50);
		cout << "\t+ Description: ";
		in.getline( b.desc,50);
		return in;
	}
};