#include "Librarian.h"
librarian::librarian() :Account() {
}
librarian librarian::operator=(const librarian& M) {
	this->name = M.name;
	this->password = M.password;
	this->address = M.address;
	this->phone = M.phone;
	return *this;
}
void librarian::setInfo(string n, string pass, string add, long p) {
	this->name = n;
	this->password = pass;
	this->address = add;
	this->phone = p;
	card.set_card(n, pass, add, p);
}
void librarian::ShowCard() {
	cout << "--------------------------------------------\n";
	cout << " -  Name : " << this->name << "\n";  
	cout << " -  Address : " << this->address << "\n";
	cout << " -  Phone : " << this->phone << "\n"; 
	cout << "--------------------------------------------\n";
}