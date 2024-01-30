#include "general_member_account.h"
Gmember::Gmember() :Account() {
	this->Nextmemb = NULL;
	this->maxBook = 0;
	DateOfTheBorrowingBook[0].SetDate(0, 0);
	DateOfTheBorrowingBook[1].SetDate(0, 0);
	DateOfTheBorrowingBookitem[0].SetDate(0, 0);
	DateOfTheBorrowingBookitem[1].SetDate(0, 0);
	this->indexb = 0;
	this->indexbi = 0;
	this->headbookaccount = NULL;
	this->headitemaccount = NULL;
	this->flagBorrow = true;
}
Gmember::Gmember(const Gmember& M) {
	headbookaccount = M.headbookaccount;
	headitemaccount = M.headitemaccount;
	this->name = M.name;
	this->password = M.password;
	this->address = M.address;
	this->phone = M.phone;
	this->maxBook = M.maxBook;
	this->flagBorrow = M.flagBorrow;
}
Gmember Gmember::operator=(const Gmember& M) {
	headbookaccount = M.headbookaccount;
	headitemaccount = M.headitemaccount;
	this->name = M.name;
	this->password = M.password;
	this->address = M.address;
	this->phone = M.phone;
	this->maxBook = M.maxBook;
	this->flagBorrow = M.flagBorrow;
	return *this;
}
void Gmember::Showcard(Gmember* p) {
	cout << "--------------------------------------------\n";
	cout << " -  Name : " << p->name << "\n";
	cout << " -  Address : " << p->address << "\n";
	cout << " -  Phone : " << p->phone << "\n";
	cout << "--------------------------------------------\n";
}
void Gmember::set_flagborrow(bool x) {
	this->flagBorrow = x;
}